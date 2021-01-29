@@ -85,7 +85,7 @@ muscle_init (void)
   muscle_insert ("maxtok", NULL);
   muscle_insert ("ntbase", NULL);
   muscle_insert ("error-verbose", NULL);
-  muscle_insert ("prefix", "yy");
+  muscle_insert ("prefix", NULL);
   /* Default #line formatting.  */
   muscle_insert ("linef", "#line %d %s\n");
 
