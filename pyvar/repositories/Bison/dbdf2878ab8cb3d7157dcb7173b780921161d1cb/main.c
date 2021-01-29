@@ -234,7 +234,7 @@ main (int argc, char *argv[])
   timevar_stop (tv_total);
   timevar_print (stderr);
 
-  cleanup_caret ();
+  caret_free ();
 
   /* Fix input file now, even if there are errors: that's less
      warnings in the following runs.  */
