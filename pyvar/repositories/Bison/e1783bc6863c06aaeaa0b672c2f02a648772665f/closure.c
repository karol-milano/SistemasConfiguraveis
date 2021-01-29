@@ -192,12 +192,12 @@ closure (item_number const *core, size_t n)
 
   /* core is sorted on item index in ritem, which is sorted on rule number.
      Compute itemset with the same sort.  */
+  nitemset = 0;
+  size_t c = 0;
+
   /* A bit index over RULESET. */
   rule_number ruleno;
   bitset_iterator iter;
-
-  nitemset = 0;
-  size_t c = 0;
   BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
     {
       item_number itemno = rules[ruleno].rhs - ritem;
