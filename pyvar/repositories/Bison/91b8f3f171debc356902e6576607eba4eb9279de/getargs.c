@@ -185,6 +185,7 @@ ARGMATCH_VERIFY (report_args, report_types);
 static const char * const trace_args[] =
 {
   "none       - no traces",
+  "locations  - full display of the locations",
   "scan       - grammar scanner traces",
   "parse      - grammar parser traces",
   "automaton  - construction of the automaton",
@@ -206,6 +207,7 @@ static const char * const trace_args[] =
 static const int trace_types[] =
 {
   trace_none,
+  trace_locations,
   trace_scan,
   trace_parse,
   trace_automaton,
