@@ -91,6 +91,8 @@ muscle_init (void)
   muscle_insert ("ntbase", "0");
   muscle_insert ("verbose", "0");
   muscle_insert ("prefix", "yy");
+  /* Default #line formatting.  */
+  muscle_insert ("linef", "#line %d %s\n");
 
   /* No parser macros.  */
   muscle_insert ("nnts", "0");
