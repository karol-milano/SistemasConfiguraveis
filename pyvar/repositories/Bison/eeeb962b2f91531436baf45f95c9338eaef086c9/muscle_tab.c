@@ -87,6 +87,7 @@ muscle_init (void)
   muscle_insert ("maxtok", "0");
   muscle_insert ("ntbase", "0");
   muscle_insert ("verbose", "0");
+  muscle_insert ("error_verbose", "0");
   muscle_insert ("prefix", "yy");
   /* Default #line formatting.  */
   muscle_insert ("linef", "#line %d %s\n");
