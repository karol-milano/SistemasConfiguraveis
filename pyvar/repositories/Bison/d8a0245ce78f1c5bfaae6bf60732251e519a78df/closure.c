@@ -25,8 +25,8 @@
 #include "reader.h"
 #include "closure.h"
 #include "derives.h"
-#include "warshall.h"
 #include "bitset.h"
+#include "warshall.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
 short *itemset;
@@ -35,15 +35,12 @@ int nitemset;
 static bitset ruleset;
 
 /* internal data.  See comments before set_fderives and set_firsts.  */
-static bitset *fderives;
-static unsigned int *firsts;
+static bitset *fderives = NULL;
+static bitset *firsts = NULL;
 
 /* Retrieve the FDERIVES/FIRSTS sets of the nonterminals numbered Var.  */
 #define FDERIVES(Var)   fderives[(Var) - ntokens]
-#define   FIRSTS(Var)   (firsts   + ((Var) - ntokens) * varsetsize)
-
-/* number of words required to hold a bit for each variable */
-static int varsetsize;
+#define   FIRSTS(Var)   firsts[(Var) - ntokens]
 
 
 /*-----------------.
@@ -77,7 +74,7 @@ print_firsts (void)
     {
       fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
       for (j = 0; j < nvars; j++)
-	if (BITISSET (FIRSTS (i), j))
+	if (bitset_test (FIRSTS (i), j))
 	  fprintf (stderr, "\t\t%d (%s)\n",
 		   j + ntokens, symbols[j + ntokens]->tag);
     }
@@ -88,11 +85,9 @@ print_firsts (void)
 static void
 print_fderives (void)
 {
-  int i;
-  int j;
+  int i, j;
 
   fprintf (stderr, "FDERIVES\n");
-
   for (i = ntokens; i < nsyms; i++)
     {
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
@@ -109,32 +104,34 @@ print_fderives (void)
   fprintf (stderr, "\n\n");
 }
 
-/*-------------------------------------------------------------------.
-| Set FIRSTS to be an NVARS by NVARS bit matrix indicating which     |
-| items can represent the beginning of the input corresponding to    |
-| which other items.                                                 |
-|                                                                    |
-| For example, if some rule expands symbol 5 into the sequence of    |
-| symbols 8 3 20, the symbol 8 can be the beginning of the data for  |
-| symbol 5, so the bit [8 - ntokens, 5 - ntokens] in firsts is set.  |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Set FIRSTS to be an NVARS array of NVARS bitsets indicating which |
+| items can represent the beginning of the input corresponding to   |
+| which other items.                                                |
+|                                                                   |
+| For example, if some rule expands symbol 5 into the sequence of   |
+| symbols 8 3 20, the symbol 8 can be the beginning of the data for |
+| symbol 5, so the bit [8 - ntokens] in first[5 - ntokens] (= FIRST |
+| (5)) is set.                                                      |
+`------------------------------------------------------------------*/
 
 static void
 set_firsts (void)
 {
   int i, j;
 
-  varsetsize = WORDSIZE (nvars);
-
-  firsts = XCALLOC (unsigned, nvars * varsetsize);
-
+  firsts = XCALLOC (bitset, nvars);
   for (i = ntokens; i < nsyms; i++)
-    for (j = 0; derives[i][j] >= 0; ++j)
-      {
-	int symbol = ritem[rules[derives[i][j]].rhs];
-	if (ISVAR (symbol))
-	  SETBIT (FIRSTS (i), symbol - ntokens);
-      }
+    {
+      FIRSTS (i) = bitset_create (nvars, BITSET_FIXED);
+      bitset_zero (FIRSTS (i));
+      for (j = 0; derives[i][j] >= 0; ++j)
+	{
+	  int symbol = ritem[rules[derives[i][j]].rhs];
+	  if (ISVAR (symbol))
+	    bitset_set (FIRSTS (i), symbol - ntokens);
+	}
+    }
 
   RTC (firsts, nvars);
 
@@ -169,13 +166,15 @@ set_fderives (void)
 
   for (i = ntokens; i < nsyms; ++i)
     for (j = ntokens; j < nsyms; ++j)
-      if (BITISSET (FIRSTS (i), j - ntokens))
+      if (bitset_test (FIRSTS (i), j - ntokens))
 	for (k = 0; derives[j][k] > 0; ++k)
 	  bitset_set (FDERIVES (i), derives[j][k]);
 
   if (trace_flag)
     print_fderives ();
 
+  for (i = ntokens; i < nsyms; ++i)
+    bitset_free (FIRSTS (i));
   XFREE (firsts);
 }
 
