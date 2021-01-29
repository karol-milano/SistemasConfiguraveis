@@ -65,7 +65,7 @@ muscle_init (void)
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
-  MUSCLE_INSERT_C_STRING ("filename", infile);
+  MUSCLE_INSERT_C_STRING ("filename", grammar_file);
 }
 
 
