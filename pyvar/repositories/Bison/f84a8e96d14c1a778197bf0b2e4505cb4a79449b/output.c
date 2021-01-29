@@ -603,7 +603,7 @@ output_skeleton (void)
   }
 
   /* Read and process m4's output.  */
-  timevar_push (TV_M4);
+  timevar_push (tv_m4);
   {
     FILE *in = xfdopen (filter_fd[0], "r");
     scan_skel (in);
@@ -614,7 +614,7 @@ output_skeleton (void)
     xfclose (in);
   }
   wait_subprocess (pid, "m4", false, false, true, true, NULL);
-  timevar_pop (TV_M4);
+  timevar_pop (tv_m4);
 }
 
 static void
