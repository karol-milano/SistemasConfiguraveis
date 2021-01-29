@@ -56,9 +56,6 @@ muscle_init (void)
   muscle_insert ("version", VERSION);
   muscle_insert ("filename", infile);
 
-  /* Skeleton use.  */
-  muscle_insert ("skeleton", skeleton);
-
   /* Types.  */
   muscle_insert ("stype", "int");
   muscle_insert ("ltype", "yyltype");
