@@ -119,7 +119,7 @@ main (int argc, char *argv[])
 
   output_files ();
 
-  exit (complain_message_count ? 1 : 0);
+  return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
 }
 
 /* Abort for an internal error denoted by string S.  */
