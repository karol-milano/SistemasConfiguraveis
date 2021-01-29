@@ -685,12 +685,8 @@ prepare (void)
 {
   /* BISON_USE_PUSH_FOR_PULL is for the test suite and should not be documented
      for the user.  */
-  char const *use_push_for_pull_env = getenv ("BISON_USE_PUSH_FOR_PULL");
-  bool use_push_for_pull_flag = false;
-  if (use_push_for_pull_env != NULL
-      && use_push_for_pull_env[0] != '\0'
-      && STRNEQ (use_push_for_pull_env, "0"))
-    use_push_for_pull_flag = true;
+  char const *cp = getenv ("BISON_USE_PUSH_FOR_PULL");
+  bool use_push_for_pull_flag = cp && *cp && STRNEQ (cp, "0");
 
   /* Flags. */
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
