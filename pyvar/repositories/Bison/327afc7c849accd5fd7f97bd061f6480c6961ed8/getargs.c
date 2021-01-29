@@ -84,7 +84,8 @@ static const char * const trace_args[] =
   "grammar    - reading, reducing of the grammar",
   "resource   - memory consumption (where available)",
   "sets       - grammar sets: firsts, nullable etc.",
-  "tools      - m4 invocation and preserve the temporary file",
+  "tools      - m4 invocation",
+  "m4         - m4 traces",
   "skeleton   - skeleton postprocessing",
   "time       - time consumption",
   "all        - all of the above",
@@ -102,6 +103,7 @@ static const int trace_types[] =
   trace_resource,
   trace_sets,
   trace_tools,
+  trace_m4,
   trace_skeleton,
   trace_time,
   trace_all
