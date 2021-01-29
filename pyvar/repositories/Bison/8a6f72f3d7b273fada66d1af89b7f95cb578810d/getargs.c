@@ -103,11 +103,11 @@ static const int trace_types[] =
   trace_all
 };
 
+ARGMATCH_VERIFY (trace_args, trace_types);
 
 static void
 trace_argmatch (char *args)
 {
-  verify (trace_constraint, ARGMATCH_CONSTRAINT (trace_args, trace_types));
   if (args)
     {
       args = strtok (args, ",");
@@ -156,11 +156,11 @@ static const int report_types[] =
   report_all
 };
 
+ARGMATCH_VERIFY (report_args, report_types);
 
 static void
 report_argmatch (char *args)
 {
-  verify (report_constraint, ARGMATCH_CONSTRAINT (report_args, report_types));
   args = strtok (args, ",");
   do
     {
