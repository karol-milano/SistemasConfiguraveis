@@ -502,6 +502,11 @@ reader (void)
   scanner_initialize ();
   gram_parse (&gram_control);
 
+  /* If something went wrong during the parsing, don't try to
+     continue.  */
+  if (complain_message_count)
+    exit (1);
+
   /* Grammar has been read.  Do some checking */
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
