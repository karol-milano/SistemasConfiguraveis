@@ -220,7 +220,6 @@ static const argmatch_report_arg argmatch_report_args[] =
   { "states",      report_states },
   { "itemsets",    report_states | report_itemsets },
   { "lookaheads",  report_states | report_lookahead_tokens },
-  { "look-ahead",  report_states | report_lookahead_tokens },
   { "solved",      report_states | report_solved_conflicts },
   { "all",         report_all },
   { NULL, report_none },
