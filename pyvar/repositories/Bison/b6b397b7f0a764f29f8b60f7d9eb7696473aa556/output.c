@@ -665,7 +665,7 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("tag_seen_flag", tag_seen);
   MUSCLE_INSERT_BOOL ("token_table_flag", token_table_flag);
   MUSCLE_INSERT_BOOL ("use_push_for_pull_flag", use_push_for_pull_flag);
-  MUSCLE_INSERT_BOOL ("yacc_flag", yacc_flag);
+  MUSCLE_INSERT_BOOL ("yacc_flag", !location_empty (yacc_loc));
 
   /* File names.  */
   if (spec_name_prefix)
