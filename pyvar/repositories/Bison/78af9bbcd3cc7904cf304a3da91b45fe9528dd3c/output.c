@@ -1034,6 +1034,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
   MUSCLE_INSERT_INT ("ntbase", ntokens);
   MUSCLE_INSERT_INT ("error-verbose", error_verbose);
+  MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
 
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
@@ -1046,8 +1047,6 @@ prepare (void)
   obstack_1grow (&action_obstack, 0);
   muscle_insert ("action", obstack_finish (&action_obstack));
 
-  if (spec_name_prefix)
-    MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
 }
 
 /*----------------------------------------------------------.
