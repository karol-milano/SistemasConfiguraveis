@@ -75,6 +75,7 @@ static void
 report_argmatch (char *args)
 {
   ARGMATCH_ASSERT (report_args, report_types);
+  args = strtok (args, ",");
   do
     {
       int report = XARGMATCH ("--report", args,
