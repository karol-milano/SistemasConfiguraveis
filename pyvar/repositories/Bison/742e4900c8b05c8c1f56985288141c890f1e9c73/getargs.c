@@ -145,7 +145,7 @@ static const char * const report_args[] =
   "none",
   "state", "states",
   "itemset", "itemsets",
-  "look-ahead", "lookahead", "lookaheads",
+  "lookahead", "lookaheads", "look-ahead",
   "solved",
   "all",
   0
@@ -156,9 +156,9 @@ static const int report_types[] =
   report_none,
   report_states, report_states,
   report_states | report_itemsets, report_states | report_itemsets,
-  report_states | report_look_ahead_tokens,
-  report_states | report_look_ahead_tokens,
-  report_states | report_look_ahead_tokens,
+  report_states | report_lookahead_tokens,
+  report_states | report_lookahead_tokens,
+  report_states | report_lookahead_tokens,
   report_states | report_solved_conflicts,
   report_all
 };
@@ -247,7 +247,7 @@ Output:\n\
 THINGS is a list of comma separated words that can include:\n\
   `state'        describe the states\n\
   `itemset'      complete the core item sets with their closure\n\
-  `look-ahead'   explicitly associate look-ahead tokens to items\n\
+  `lookahead'    explicitly associate lookahead tokens to items\n\
   `solved'       describe shift/reduce conflicts solving\n\
   `all'          include all the above information\n\
   `none'         disable the report\n\
