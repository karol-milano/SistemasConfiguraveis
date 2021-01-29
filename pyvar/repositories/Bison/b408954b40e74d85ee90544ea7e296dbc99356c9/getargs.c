@@ -55,6 +55,7 @@ static const char * const report_args[] =
   "state", "states",
   "itemset", "itemsets",
   "lookahead", "lookaheads",
+  "solved",
   "all",
   0
 };
@@ -65,6 +66,7 @@ static const int report_types[] =
   report_states, report_states,
   report_states | report_itemsets, report_states | report_itemsets,
   report_states | report_lookaheads, report_states | report_lookaheads,
+  report_states | report_solved_conflicts,
   report_all
 };
 
@@ -140,6 +142,7 @@ THINGS is a list of comma separated words that can include:\n\
   `state'        describe the states\n\
   `itemset'      complete the core item sets with their closure\n\
   `lookahead'    explicitly associate lookaheads to items\n\
+  `solved'       describe shift/reduce conflicts solving\n\
   `all'          include all the above information\n\
   `none'         disable the report\n\
 "), stream);
