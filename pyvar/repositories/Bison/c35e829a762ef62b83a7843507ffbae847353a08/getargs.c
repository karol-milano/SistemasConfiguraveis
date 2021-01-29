@@ -206,23 +206,26 @@ ARGMATCH_DEFINE_GROUP (report, enum report)
 
 static const argmatch_report_doc argmatch_report_docs[] =
 {
-  { "states",     N_("describe the states") },
-  { "itemsets",   N_("complete the core item sets with their closure") },
-  { "lookaheads", N_("explicitly associate lookahead tokens to items") },
-  { "solved",     N_("describe shift/reduce conflicts solving") },
-  { "all",        N_("include all the above information") },
-  { "none",       N_("disable the report") },
+  { "states",          N_("describe the states") },
+  { "itemsets",        N_("complete the core item sets with their closure") },
+  { "lookaheads",      N_("explicitly associate lookahead tokens to items") },
+  { "solved",          N_("describe shift/reduce conflicts solving") },
+  { "counterexamples", N_("generate conflict counterexamples") },
+  { "all",             N_("include all the above information") },
+  { "none",            N_("disable the report") },
   { NULL, NULL },
 };
 
 static const argmatch_report_arg argmatch_report_args[] =
 {
-  { "none",        report_none },
-  { "states",      report_states },
-  { "itemsets",    report_states | report_itemsets },
-  { "lookaheads",  report_states | report_lookahead_tokens },
-  { "solved",      report_states | report_solved_conflicts },
-  { "all",         report_all },
+  { "none",            report_none },
+  { "states",          report_states },
+  { "itemsets",        report_states | report_itemsets },
+  { "lookaheads",      report_states | report_lookahead_tokens },
+  { "solved",          report_states | report_solved_conflicts },
+  { "counterexamples", report_cex },
+  { "cex",             report_cex },
+  { "all",             report_all },
   { NULL, report_none },
 };
 
