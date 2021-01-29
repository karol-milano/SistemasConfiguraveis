@@ -54,15 +54,16 @@ static const char * const trace_args[] =
   /* In a series of synonyms, present the most meaningful first, so
      that argmatch_valid be more readable.  */
   "none       - no report",
-  "scan       - scanner traces",
-  "parse      - parser traces",
+  "scan       - grammar scanner traces",
+  "parse      - grammar parser traces",
   "automaton  - contruction of the automaton",
   "bitsets    - use of bitsets",
   "grammar    - reading, reducing of the grammar",
   "resource   - memory consumption (where available)",
   "sets       - grammar sets: firsts, nullable etc.",
-  "time       - time consumption",
   "tools      - m4 invocation and preserve the temporary file",
+  "skeleton   - skeleton postprocessing",
+  "time       - time consumption",
   "all        - all of the above",
   0
 };
@@ -77,8 +78,9 @@ static const int trace_types[] =
   trace_grammar,
   trace_resource,
   trace_sets,
-  trace_time,
   trace_tools,
+  trace_skeleton,
+  trace_time,
   trace_all
 };
 
