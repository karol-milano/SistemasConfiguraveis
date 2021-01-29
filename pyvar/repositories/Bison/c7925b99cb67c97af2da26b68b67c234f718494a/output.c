@@ -125,6 +125,8 @@ static int high;
 struct obstack muscle_obstack;
 struct obstack output_obstack;
 
+int error_verbose = 0;
+
 /* FIXME. */
 
 static inline void
@@ -1052,7 +1054,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("final", final_state);
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
   MUSCLE_INSERT_INT ("ntbase", ntokens);
-  MUSCLE_INSERT_INT ("error-verbose", error_verbose_flag);
+  MUSCLE_INSERT_INT ("error-verbose", error_verbose);
 
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
