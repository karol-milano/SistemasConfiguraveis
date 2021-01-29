@@ -36,7 +36,7 @@
 
 /* NITEMSET is the size of the array ITEMSET.  */
 item_number *itemset;
-int nritemset;
+size_t nritemset;
 
 static bitset ruleset;
 
@@ -193,10 +193,10 @@ new_closure (unsigned int n)
 
 
 void
-closure (item_number *core, int n)
+closure (item_number *core, size_t n)
 {
   /* Index over CORE. */
-  int c;
+  size_t c;
 
   /* A bit index over RULESET. */
   rule_number ruleno;
