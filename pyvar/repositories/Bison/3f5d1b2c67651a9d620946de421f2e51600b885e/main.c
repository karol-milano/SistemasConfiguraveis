@@ -216,5 +216,7 @@ main (int argc, char *argv[])
   timevar_stop (TV_TOTAL);
   timevar_print (stderr);
 
+  cleanup_caret ();
+
   return complaint_issued ? EXIT_FAILURE : EXIT_SUCCESS;
 }
