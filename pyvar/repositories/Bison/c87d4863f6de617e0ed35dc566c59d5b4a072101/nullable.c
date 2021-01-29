@@ -49,7 +49,7 @@ set_nullable (void)
   short *r1;
 
   if (trace_flag)
-    fprintf (stderr, "Entering set_nullable");
+    fprintf (stderr, "Entering set_nullable\n");
 
   nullable = XCALLOC (char, nvars) - ntokens;
 
