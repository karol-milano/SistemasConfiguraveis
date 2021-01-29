@@ -625,6 +625,8 @@ prepare (void)
   char const *cp = getenv ("BISON_USE_PUSH_FOR_PULL");
   bool use_push_for_pull_flag = cp && *cp && strtol (cp, 0, 10);
 
+  MUSCLE_INSERT_INT ("required_version", required_version);
+
   /* Flags. */
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
