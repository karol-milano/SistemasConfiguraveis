@@ -508,7 +508,7 @@ reader (void)
   /* If something went wrong during the parsing, don't try to
      continue.  */
   if (complaint_issued)
-    exit (EXIT_FAILURE);
+    return;
 
   /* Grammar has been read.  Do some checking */
   if (nrules == 0)
