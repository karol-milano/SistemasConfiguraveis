@@ -59,41 +59,41 @@ muscle_init (void)
   muscle_insert ("ltype", "yyltype");
 
   /* Tokens.  */
-  muscle_insert ("tokendef", "");
+  muscle_insert ("tokendef", NULL);
 
   /* Tables.  */
-  muscle_insert ("rhs", "0");
-  muscle_insert ("pact", "0");
-  muscle_insert ("prhs", "0");
-  muscle_insert ("stos", "0");
-  muscle_insert ("check", "0");
-  muscle_insert ("pgoto", "0");
-  muscle_insert ("table", "0");
-  muscle_insert ("tname", "0");
-  muscle_insert ("defact", "0");
-  muscle_insert ("toknum", "0");
-  muscle_insert ("defgoto", "0");
-  muscle_insert ("translate", "0");
+  muscle_insert ("rhs", NULL);
+  muscle_insert ("pact", NULL);
+  muscle_insert ("prhs", NULL);
+  muscle_insert ("stos", NULL);
+  muscle_insert ("check", NULL);
+  muscle_insert ("pgoto", NULL);
+  muscle_insert ("table", NULL);
+  muscle_insert ("tname", NULL);
+  muscle_insert ("defact", NULL);
+  muscle_insert ("toknum", NULL);
+  muscle_insert ("defgoto", NULL);
+  muscle_insert ("translate", NULL);
 
   /* Various macros.  */
-  muscle_insert ("flag", "0");
-  muscle_insert ("last", "0");
-  muscle_insert ("pure", "0");
-  muscle_insert ("nsym", "0");
-  muscle_insert ("debug", "0");
-  muscle_insert ("final", "0");
-  muscle_insert ("maxtok", "0");
-  muscle_insert ("ntbase", "0");
-  muscle_insert ("error-verbose", "0");
+  muscle_insert ("flag", NULL);
+  muscle_insert ("last", NULL);
+  muscle_insert ("pure", NULL);
+  muscle_insert ("nsym", NULL);
+  muscle_insert ("debug", NULL);
+  muscle_insert ("final", NULL);
+  muscle_insert ("maxtok", NULL);
+  muscle_insert ("ntbase", NULL);
+  muscle_insert ("error-verbose", NULL);
   muscle_insert ("prefix", "yy");
   /* Default #line formatting.  */
   muscle_insert ("linef", "#line %d %s\n");
 
   /* No parser macros.  */
-  muscle_insert ("nnts", "0");
-  muscle_insert ("nrules", "0");
-  muscle_insert ("nstates", "0");
-  muscle_insert ("ntokens", "0");
+  muscle_insert ("nnts", NULL);
+  muscle_insert ("nrules", NULL);
+  muscle_insert ("nstates", NULL);
+  muscle_insert ("ntokens", NULL);
 
   /* Stack parameters.  */
   muscle_insert ("maxdepth", "10000");
