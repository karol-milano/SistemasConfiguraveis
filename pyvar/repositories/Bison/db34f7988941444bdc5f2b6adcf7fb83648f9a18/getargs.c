@@ -186,6 +186,7 @@ static const char * const trace_args[] =
   "m4         - m4 traces",
   "skeleton   - skeleton postprocessing",
   "time       - time consumption",
+  "ielr       - IELR conversion",
   "all        - all of the above",
   0
 };
@@ -205,6 +206,7 @@ static const int trace_types[] =
   trace_m4,
   trace_skeleton,
   trace_time,
+  trace_ielr,
   trace_all
 };
 
