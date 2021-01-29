@@ -80,7 +80,7 @@ main (int argc, char *argv[])
 
   getargs (argc, argv);
 
-  timevar_report = trace_flag & trace_time;
+  timevar_enabled = trace_flag & trace_time;
   timevar_init ();
   timevar_start (TV_TOTAL);
 
