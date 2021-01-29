@@ -53,7 +53,7 @@ macro_init (void)
 
   /* Version and input file.  */
   macro_insert ("version", VERSION);
-  macro_insert ("filename", "a.y");
+  macro_insert ("filename", infile);
 
   /* Types.  */
   macro_insert ("stype", "int");
