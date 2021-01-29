@@ -35,6 +35,9 @@
 item_number *itemset;
 size_t nitemset;
 
+/* RULESET contains a bit for each rule.  CLOSURE sets the bits for
+   all rules which could potentially describe the next input to be
+   read.  */
 static bitset ruleset;
 
 /* internal data.  See comments before set_fderives and set_firsts.  */
