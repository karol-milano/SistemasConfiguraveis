@@ -138,7 +138,7 @@ static const char * const report_args[] =
   "none",
   "state", "states",
   "itemset", "itemsets",
-  "lookahead", "lookaheads",
+  "look-ahead", "lookahead", "lookaheads",
   "solved",
   "all",
   0
@@ -149,7 +149,9 @@ static const int report_types[] =
   report_none,
   report_states, report_states,
   report_states | report_itemsets, report_states | report_itemsets,
-  report_states | report_lookaheads, report_states | report_lookaheads,
+  report_states | report_look_ahead_tokens,
+  report_states | report_look_ahead_tokens,
+  report_states | report_look_ahead_tokens,
   report_states | report_solved_conflicts,
   report_all
 };
@@ -237,7 +239,7 @@ Output:\n\
 THINGS is a list of comma separated words that can include:\n\
   `state'        describe the states\n\
   `itemset'      complete the core item sets with their closure\n\
-  `lookahead'    explicitly associate lookaheads to items\n\
+  `look-ahead'   explicitly associate look-ahead tokens to items\n\
   `solved'       describe shift/reduce conflicts solving\n\
   `all'          include all the above information\n\
   `none'         disable the report\n\
