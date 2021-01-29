@@ -1,5 +1,5 @@
 /* Subroutines for bison
-   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,13 +19,14 @@
    02111-1307, USA.  */
 
 #include "system.h"
+#include "bitset.h"
+#include "bitsetv.h"
 #include "getargs.h"
 #include "symtab.h"
 #include "gram.h"
 #include "reader.h"
 #include "closure.h"
 #include "derives.h"
-#include "bitset.h"
 #include "warshall.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
@@ -35,8 +36,8 @@ int nitemset;
 static bitset ruleset;
 
 /* internal data.  See comments before set_fderives and set_firsts.  */
-static bitset *fderives = NULL;
-static bitset *firsts = NULL;
+static bitsetv fderives = NULL;
+static bitsetv firsts = NULL;
 
 /* Retrieve the FDERIVES/FIRSTS sets of the nonterminals numbered Var.  */
 #define FDERIVES(Var)   fderives[(Var) - ntokens]
@@ -120,19 +121,17 @@ set_firsts (void)
 {
   int i, j;
 
-  firsts = XCALLOC (bitset, nvars);
+  firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
+
   for (i = ntokens; i < nsyms; i++)
-    {
-      FIRSTS (i) = bitset_create (nvars, BITSET_FIXED);
-      for (j = 0; derives[i][j] >= 0; ++j)
-	{
-	  int symbol = ritem[rules[derives[i][j]].rhs];
-	  if (ISVAR (symbol))
-	    bitset_set (FIRSTS (i), symbol - ntokens);
-	}
-    }
+    for (j = 0; derives[i][j] >= 0; ++j)
+      {
+	int symbol = ritem[rules[derives[i][j]].rhs];
+	if (ISVAR (symbol))
+	  bitset_set (FIRSTS (i), symbol - ntokens);
+      }
 
-  RTC (firsts, nvars);
+  RTC (firsts);
 
   if (trace_flag)
     print_firsts ();
@@ -153,10 +152,7 @@ set_fderives (void)
 {
   int i, j, k;
 
-  fderives = XCALLOC (bitset, nvars);
-  bitset_stats_init ();
-  for (i = 0 ; i < nvars; ++i)
-    fderives[i] = bitset_create (nrules + 1, BITSET_FIXED);
+  fderives = bitsetv_create (nvars, nrules + 1, BITSET_FIXED);
 
   set_firsts ();
 
@@ -169,9 +165,7 @@ set_fderives (void)
   if (trace_flag)
     print_fderives ();
 
-  for (i = ntokens; i < nsyms; ++i)
-    bitset_free (FIRSTS (i));
-  XFREE (firsts);
+  bitsetv_free (firsts);
 }
 
 
@@ -246,12 +240,7 @@ closure (short *core, int n)
 void
 free_closure (void)
 {
-  int i;
   XFREE (itemset);
-
   bitset_free (ruleset);
-
-  for (i = 0 ; i < nvars; ++i)
-    bitset_free (fderives[i]);
-  free (fderives);
+  bitsetv_free (fderives);
 }
