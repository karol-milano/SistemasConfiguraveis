@@ -30,7 +30,7 @@
 #include "derives.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
-short *itemset;
+item_number_t *itemset;
 int nritemset;
 
 static bitset ruleset;
@@ -49,13 +49,13 @@ static bitsetv firsts = NULL;
 `-----------------*/
 
 static void
-print_closure (const char *title, short *array, size_t size)
+print_closure (const char *title, item_number_t *array, size_t size)
 {
   size_t i;
   fprintf (stderr, "Closure: %s\n", title);
   for (i = 0; i < size; ++i)
     {
-      short *rp;
+      item_number_t *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
 	fprintf (stderr, " %s",
@@ -100,7 +100,7 @@ print_fderives (void)
       for (j = 0; j < nrules + 1; j++)
 	if (bitset_test (FDERIVES (i), j))
 	  {
-	    short *rhsp;
+	    item_number_t *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
 	    for (rhsp = rules[j].rhs; *rhsp >= 0; ++rhsp)
 	      fprintf (stderr, " %s",
@@ -231,7 +231,7 @@ set_fderives (void)
 void
 new_closure (int n)
 {
-  itemset = XCALLOC (short, n);
+  itemset = XCALLOC (item_number_t, n);
 
   ruleset = bitset_create (nrules + 1, BITSET_FIXED);
 
@@ -241,7 +241,7 @@ new_closure (int n)
 
 
 void
-closure (short *core, int n)
+closure (item_number_t *core, int n)
 {
   /* Index over CORE. */
   int c;
@@ -263,7 +263,7 @@ closure (short *core, int n)
   for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
     if (bitset_test (ruleset, ruleno))
       {
-	int itemno = rules[ruleno].rhs - ritem;
+	item_number_t itemno = rules[ruleno].rhs - ritem;
 	while (c < n && core[c] < itemno)
 	  {
 	    itemset[nritemset] = core[c];
