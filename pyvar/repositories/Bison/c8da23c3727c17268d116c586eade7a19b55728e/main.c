@@ -81,7 +81,7 @@ main (int argc, char *argv[])
   getargs (argc, argv);
 
   timevar_report = trace_flag & trace_time;
-  init_timevar ();
+  timevar_init ();
   timevar_start (TV_TOTAL);
 
   if (trace_flag & trace_bitsets)
