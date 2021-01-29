@@ -58,40 +58,9 @@ muscle_init (void)
   muscle_insert ("stype", "int");
   muscle_insert ("ltype", "yyltype");
 
-  /* Tables.  */
-  muscle_insert ("rhs", NULL);
-  muscle_insert ("pact", NULL);
-  muscle_insert ("prhs", NULL);
-  muscle_insert ("stos", NULL);
-  muscle_insert ("check", NULL);
-  muscle_insert ("pgoto", NULL);
-  muscle_insert ("table", NULL);
-  muscle_insert ("tname", NULL);
-  muscle_insert ("defact", NULL);
-  muscle_insert ("toknum", NULL);
-  muscle_insert ("defgoto", NULL);
-  muscle_insert ("translate", NULL);
-
-  /* Various macros.  */
-  muscle_insert ("flag", NULL);
-  muscle_insert ("last", NULL);
-  muscle_insert ("pure", NULL);
-  muscle_insert ("nsym", NULL);
-  muscle_insert ("debug", NULL);
-  muscle_insert ("final", NULL);
-  muscle_insert ("maxtok", NULL);
-  muscle_insert ("ntbase", NULL);
-  muscle_insert ("error-verbose", NULL);
-  muscle_insert ("prefix", NULL);
   /* Default #line formatting.  */
   muscle_insert ("linef", "#line %d %s\n");
 
-  /* No parser macros.  */
-  muscle_insert ("nnts", NULL);
-  muscle_insert ("nrules", NULL);
-  muscle_insert ("nstates", NULL);
-  muscle_insert ("ntokens", NULL);
-
   /* Stack parameters.  */
   muscle_insert ("maxdepth", "10000");
   muscle_insert ("initdepth", "200");
