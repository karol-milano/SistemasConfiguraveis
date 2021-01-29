@@ -213,6 +213,8 @@ closure (item_number *core, size_t n)
     if (ISVAR (ritem[core[c]]))
       bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
 
+  /* core is sorted on item number from ritem, which is sorted on rule number.
+     Compute itemset with the same sort.  */
   nitemset = 0;
   c = 0;
   BITSET_FOR_EACH (iter, ruleset, ruleno, 0)
