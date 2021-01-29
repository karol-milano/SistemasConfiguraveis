@@ -221,7 +221,7 @@ static const argmatch_report_arg argmatch_report_args[] =
   { "none",            report_none },
   { "states",          report_states },
   { "itemsets",        report_states | report_itemsets },
-  { "lookaheads",      report_states | report_lookahead_tokens },
+  { "lookaheads",      report_states | report_lookaheads },
   { "solved",          report_states | report_solved_conflicts },
   { "counterexamples", report_cex },
   { "cex",             report_cex },
