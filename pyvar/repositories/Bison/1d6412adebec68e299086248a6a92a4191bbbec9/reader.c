@@ -481,6 +481,7 @@ reader (void)
 
   gram_debug = !!getenv ("parse");
   gram__flex_debug = !!getenv ("scan");
+  scanner_initialize ();
   gram_parse (&gram_control);
 
   /* Grammar has been read.  Do some checking */
