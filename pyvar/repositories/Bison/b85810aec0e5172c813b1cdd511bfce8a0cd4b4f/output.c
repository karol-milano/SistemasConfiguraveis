@@ -995,6 +995,11 @@ prepare (void)
   MUSCLE_INSERT_INT ("error-verbose", error_verbose);
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
 
+  /* FIXME: This is wrong: the muscles should decide whether they hold
+     a copy or not, but the situation is too obscure currently.  */
+  MUSCLE_INSERT_STRING ("output-infix", output_infix ? output_infix : "");
+  MUSCLE_INSERT_STRING ("output-prefix", short_base_name);
+
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
   MUSCLE_INSERT_INT ("nstates", nstates);
