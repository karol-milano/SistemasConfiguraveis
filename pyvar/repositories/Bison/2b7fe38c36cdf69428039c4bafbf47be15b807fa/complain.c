@@ -38,11 +38,11 @@ bool warnings_are_errors = false;
 /** Diagnostics severity.  */
 typedef enum
   {
-    severity_disabled = 0,
-    severity_unset = 1,
-    severity_warning = 2,
-    severity_error = 3,
-    severity_fatal = 4
+    severity_disabled = 0, /**< Explicitly disabled via -Wno-foo.  */
+    severity_unset = 1,    /**< Unspecified status.  */
+    severity_warning = 2,  /**< A warning.  */
+    severity_error = 3,    /**< An error (continue, but die soon).  */
+    severity_fatal = 4     /**< Fatal error (die now).  */
   } severity;
 
 
@@ -151,7 +151,10 @@ warnings_argmatch (char *args)
         }
       else
         {
+          // The length of the possible 'no-' prefix: 3, or 0.
           size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+          // The length of the possible 'error=' (possibly after
+          // 'no-') prefix: 6, or 0.
           size_t err = STRPREFIX_LIT ("error=", args + no) ? 6 : 0;
 
           warning_argmatch (args, no, err);
