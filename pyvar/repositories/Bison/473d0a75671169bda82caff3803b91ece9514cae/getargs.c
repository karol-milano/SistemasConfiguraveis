@@ -52,6 +52,8 @@ static const char * const trace_args[] =
   /* In a series of synonyms, present the most meaningful first, so
      that argmatch_valid be more readable.  */
   "none       - no report",
+  "scan       - scanner traces",
+  "parse      - parser traces",
   "automaton  - contruction of the automaton",
   "bitsets    - use of bitsets",
   "grammar    - reading, reducing of the grammar",
@@ -66,6 +68,8 @@ static const char * const trace_args[] =
 static const int trace_types[] =
 {
   trace_none,
+  trace_scan,
+  trace_parse,
   trace_automaton,
   trace_bitsets,
   trace_grammar,
