@@ -41,9 +41,9 @@ bool warnings_are_errors = false;
 /** Whether -Werror/-Wno-error was applied to a warning.  */
 typedef enum
   {
-    errority_unset = 0,     /** No explict status.  */
-    errority_disabled = 1,  /** Explictly disabled with -Wno-error=foo.  */
-    errority_enabled = 2    /** Explictly enabled with -Werror=foo. */
+    errority_unset = 0,     /** No explicit status.  */
+    errority_disabled = 1,  /** Explicitly disabled with -Wno-error=foo.  */
+    errority_enabled = 2    /** Explicitly enabled with -Werror=foo. */
   } errority;
 
 /** For each warning type, its errority.  */
