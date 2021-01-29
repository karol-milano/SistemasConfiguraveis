@@ -668,10 +668,10 @@ output_skeleton (void)
 static void
 prepare (void)
 {
-  /* BISON_USE_PUSH_FOR_PULL is for the test suite and should not be documented
-     for the user.  */
+  /* BISON_USE_PUSH_FOR_PULL is for the test suite and should not be
+     documented for the user.  */
   char const *cp = getenv ("BISON_USE_PUSH_FOR_PULL");
-  bool use_push_for_pull_flag = cp && *cp && STRNEQ (cp, "0");
+  bool use_push_for_pull_flag = cp && *cp && strtol (cp, 0, 10);
 
   /* Flags. */
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
