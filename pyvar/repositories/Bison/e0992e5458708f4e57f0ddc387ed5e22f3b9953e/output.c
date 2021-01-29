@@ -628,7 +628,7 @@ prepare (void)
     use_push_for_pull_flag = true;
 
   /* Flags. */
-  MUSCLE_INSERT_BOOL ("debug_flag", debug_flag);
+  MUSCLE_INSERT_BOOL ("debug_flag", debug);
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
   MUSCLE_INSERT_BOOL ("error_verbose_flag", error_verbose);
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
