@@ -32,7 +32,7 @@
 #include "symtab.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
-item_number *itemset;
+item_index *itemset;
 size_t nitemset;
 
 /* RULESET contains a bit for each rule.  CLOSURE sets the bits for
@@ -54,13 +54,13 @@ static bitsetv firsts = NULL;
 `-----------------*/
 
 static void
-closure_print (char const *title, item_number const *array, size_t size)
+closure_print (char const *title, item_index const *array, size_t size)
 {
   fprintf (stderr, "Closure: %s\n", title);
   for (size_t i = 0; i < size; ++i)
     {
       fprintf (stderr, "  %2d: .", array[i]);
-      item_number *rp;
+      item_index *rp;
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
         fprintf (stderr, " %s", symbols[*rp]->tag);
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
@@ -182,7 +182,7 @@ closure_new (int n)
 
 
 void
-closure (item_number const *core, size_t n)
+closure (item_index const *core, size_t n)
 {
   if (trace_flag & trace_closure)
     closure_print ("input", core, n);
@@ -203,7 +203,7 @@ closure (item_number const *core, size_t n)
   bitset_iterator iter;
   BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
     {
-      item_number itemno = rules[ruleno].rhs - ritem;
+      item_index itemno = rules[ruleno].rhs - ritem;
       while (c < n && core[c] < itemno)
         {
           itemset[nitemset] = core[c];
