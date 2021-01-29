@@ -52,7 +52,7 @@ int error_token_number;
 /* This is to avoid linker problems which occur on VMS when using GCC,
    when the file in question contains data definitions only.  */
 
-void
-dummy()
+static void
+dummy (void)
 {
 }
