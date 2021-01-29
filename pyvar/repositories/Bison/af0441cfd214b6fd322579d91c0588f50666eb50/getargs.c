@@ -261,6 +261,7 @@ static const argmatch_trace_doc argmatch_trace_docs[] =
   { "skeleton",   "skeleton postprocessing" },
   { "time",       "time consumption" },
   { "ielr",       "IELR conversion" },
+  { "cex",        "counterexample generation"},
   { "all",        "all of the above" },
   { NULL, NULL},
 };
@@ -283,6 +284,7 @@ static const argmatch_trace_arg argmatch_trace_args[] =
   { "skeleton",  trace_skeleton },
   { "time",      trace_time },
   { "ielr",      trace_ielr },
+  { "cex",       trace_cex },
   { "all",       trace_all },
   { NULL,        trace_none},
 };
