@@ -700,7 +700,6 @@ prepare (void)
     use_push_for_pull_flag = true;
 
   /* Flags. */
-  MUSCLE_INSERT_BOOL ("debug_flag", debug_flag);
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
