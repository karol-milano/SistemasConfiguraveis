@@ -55,8 +55,9 @@ static const char * const trace_args[] =
   "automaton  - contruction of the automaton",
   "bitsets    - use of bitsets",
   "grammar    - reading, reducing of the grammar",
-  "resource   - time and memory (where available)",
+  "resource   - memory consumption (where available)",
   "sets       - grammar sets: firsts, nullable etc.",
+  "time       - time consumption",
   "tools      - m4 invocation and preserve the temporary file",
   "all        - all of the above",
   0
@@ -70,6 +71,7 @@ static const int trace_types[] =
   trace_grammar,
   trace_resource,
   trace_sets,
+  trace_time,
   trace_tools,
   trace_all
 };
