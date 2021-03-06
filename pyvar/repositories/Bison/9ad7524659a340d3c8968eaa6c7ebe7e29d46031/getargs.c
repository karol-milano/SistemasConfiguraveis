@@ -188,6 +188,7 @@ static const char * const trace_args[] =
   "parse      - grammar parser traces",
   "automaton  - construction of the automaton",
   "bitsets    - use of bitsets",
+  "closure    - input/output of closure",
   "grammar    - reading, reducing the grammar",
   "resource   - memory consumption (where available)",
   "sets       - grammar sets: firsts, nullable etc.",
@@ -208,6 +209,7 @@ static const int trace_types[] =
   trace_parse,
   trace_automaton,
   trace_bitsets,
+  trace_closure,
   trace_grammar,
   trace_resource,
   trace_sets,
