@@ -74,7 +74,7 @@ muscle_init (void)
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
-  MUSCLE_INSERT_C_STRING ("filename", grammar_file);
+  MUSCLE_INSERT_C_STRING ("file_name", grammar_file);
 }
 
 
