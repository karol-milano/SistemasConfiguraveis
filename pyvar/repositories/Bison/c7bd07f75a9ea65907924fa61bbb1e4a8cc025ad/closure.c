@@ -1,4 +1,5 @@
-/* Subroutines for bison
+/* Closures for Bison
+
    Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -19,19 +20,21 @@
    02111-1307, USA.  */
 
 #include "system.h"
-#include "quotearg.h"
-#include "bitset.h"
-#include "bitsetv.h"
-#include "bitsetv-print.h"
+
+#include <bitset.h>
+#include <bitsetv-print.h>
+#include <bitsetv.h>
+#include <quotearg.h>
+
+#include "closure.h"
+#include "derives.h"
 #include "getargs.h"
-#include "symtab.h"
 #include "gram.h"
 #include "reader.h"
-#include "closure.h"
-#include "derives.h"
+#include "symtab.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
-item_number_t *itemset;
+item_number *itemset;
 int nritemset;
 
 static bitset ruleset;
@@ -50,13 +53,13 @@ static bitsetv firsts = NULL;
 `-----------------*/
 
 static void
-print_closure (const char *title, item_number_t *array, size_t size)
+print_closure (char const *title, item_number *array, size_t size)
 {
   size_t i;
   fprintf (stderr, "Closure: %s\n", title);
   for (i = 0; i < size; ++i)
     {
-      item_number_t *rp;
+      item_number *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
 	fprintf (stderr, " %s", symbols[*rp]->tag);
@@ -69,7 +72,7 @@ print_closure (const char *title, item_number_t *array, size_t size)
 static void
 print_firsts (void)
 {
-  symbol_number_t i, j;
+  symbol_number i, j;
 
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
@@ -90,7 +93,7 @@ static void
 print_fderives (void)
 {
   int i;
-  rule_number_t r;
+  rule_number r;
 
   fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
@@ -120,16 +123,16 @@ print_fderives (void)
 static void
 set_firsts (void)
 {
-  symbol_number_t i, j;
+  symbol_number i, j;
 
   firsts = bitsetv_create (nvars, nvars, BITSET_FIXED);
 
   for (i = ntokens; i < nsyms; i++)
     for (j = 0; derives[i][j]; ++j)
       {
-	int symbol = derives[i][j]->rhs[0];
-	if (ISVAR (symbol))
-	  bitset_set (FIRSTS (i), symbol - ntokens);
+	item_number sym = derives[i][j]->rhs[0];
+	if (ISVAR (sym))
+	  bitset_set (FIRSTS (i), sym - ntokens);
       }
 
   if (trace_flag & trace_sets)
@@ -155,8 +158,8 @@ set_firsts (void)
 static void
 set_fderives (void)
 {
-  symbol_number_t i, j;
-  rule_number_t k;
+  symbol_number i, j;
+  rule_number k;
 
   fderives = bitsetv_create (nvars, nrules, BITSET_FIXED);
 
@@ -179,7 +182,7 @@ set_fderives (void)
 void
 new_closure (int n)
 {
-  itemset = XCALLOC (item_number_t, n);
+  itemset = XCALLOC (item_number, n);
 
   ruleset = bitset_create (nrules, BITSET_FIXED);
 
@@ -189,13 +192,13 @@ new_closure (int n)
 
 
 void
-closure (item_number_t *core, int n)
+closure (item_number *core, int n)
 {
   /* Index over CORE. */
   int c;
 
   /* A bit index over RULESET. */
-  rule_number_t ruleno;
+  rule_number ruleno;
 
   bitset_iterator iter;
 
@@ -212,7 +215,7 @@ closure (item_number_t *core, int n)
   c = 0;
   BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
     {
-      item_number_t itemno = rules[ruleno].rhs - ritem;
+      item_number itemno = rules[ruleno].rhs - ritem;
       while (c < n && core[c] < itemno)
 	{
 	  itemset[nritemset] = core[c];
