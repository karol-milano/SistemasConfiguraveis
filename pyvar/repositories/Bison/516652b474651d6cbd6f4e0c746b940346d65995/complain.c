@@ -153,10 +153,10 @@ warnings_argmatch (char *args)
         warnings_are_errors = false;
       else
         {
-          // The length of the possible 'no-' prefix: 3, or 0.
+          /* The length of the possible 'no-' prefix: 3, or 0.  */
           size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-          // The length of the possible 'error=' (possibly after
-          // 'no-') prefix: 6, or 0.
+          /* The length of the possible 'error=' (possibly after
+             'no-') prefix: 6, or 0. */
           size_t err = STRPREFIX_LIT ("error=", args + no) ? 6 : 0;
 
           warning_argmatch (args, no, err);
