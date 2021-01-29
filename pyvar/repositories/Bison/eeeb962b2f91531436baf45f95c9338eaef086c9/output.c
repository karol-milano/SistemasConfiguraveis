@@ -1053,6 +1053,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
   MUSCLE_INSERT_INT ("ntbase", ntokens);
   MUSCLE_INSERT_INT ("verbose", 0);
+  MUSCLE_INSERT_INT ("error_verbose", error_verbose_flag);
 
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
