@@ -65,12 +65,6 @@ muscle_init (void)
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
   MUSCLE_INSERT_STRING ("filename", infile);
-
-  /* FIXME: there should probably be no default here, only in the
-     skeletons.  */
-
-  /* Default #line formatting.  */
-  MUSCLE_INSERT_STRING ("linef", "#line %d %s\n");
 }
 
 
