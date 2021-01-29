@@ -88,7 +88,7 @@ static const int trace_types[] =
 static void
 trace_argmatch (char *args)
 {
-  ARGMATCH_ASSERT (trace_args, trace_types);
+  verify (trace_constraint, ARGMATCH_CONSTRAINT (trace_args, trace_types));
   if (args)
     {
       args = strtok (args, ",");
@@ -139,7 +139,7 @@ static const int report_types[] =
 static void
 report_argmatch (char *args)
 {
-  ARGMATCH_ASSERT (report_args, report_types);
+  verify (report_constraint, ARGMATCH_CONSTRAINT (report_args, report_types));
   args = strtok (args, ",");
   do
     {