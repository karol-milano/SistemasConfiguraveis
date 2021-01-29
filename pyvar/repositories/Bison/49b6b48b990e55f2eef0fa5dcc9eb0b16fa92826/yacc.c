@@ -1115,7 +1115,10 @@ yyerrlab1:
      invokes YYERROR.  MacOS 10.2.3's buggy "smart preprocessor"
      insists on the trailing semicolon.  */
 #if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
+  /* GNU C++ (as of version 3.2.1) does not allow attributes on labels.  */
+# ifndef __cplusplus
   __attribute__ ((__unused__));
+# endif
 #endif
 
 ]b4_location_if([  yylerrsp = yylsp;
