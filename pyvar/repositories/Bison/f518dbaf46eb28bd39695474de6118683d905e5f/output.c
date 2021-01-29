@@ -689,7 +689,7 @@ prepare (void)
   bool use_push_for_pull_flag = false;
   if (use_push_for_pull_env != NULL
       && use_push_for_pull_env[0] != '\0'
-      && 0 != strcmp (use_push_for_pull_env, "0"))
+      && STRNEQ (use_push_for_pull_env, "0"))
     use_push_for_pull_flag = true;
 
   /* Flags. */
