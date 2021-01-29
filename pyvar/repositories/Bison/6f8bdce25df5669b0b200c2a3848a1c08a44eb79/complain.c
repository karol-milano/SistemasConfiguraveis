@@ -94,7 +94,7 @@ error_message (location *loc,
 | Report a warning, and proceed.  |
 `--------------------------------*/
 
-static void
+void
 set_warning_issued (void)
 {
   static bool warning_issued = false;
