@@ -1112,9 +1112,10 @@ yyerrlab:
 yyerrlab1:
 
   /* Suppress GCC warning that yyerrlab1 is unused when no action
-     invokes YYERROR.  */
+     invokes YYERROR.  MacOS 10.2.3's buggy "smart preprocessor"
+     insists on the trailing semicolon.  */
 #if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
-  __attribute__ ((__unused__))
+  __attribute__ ((__unused__));
 #endif
 
 ]b4_location_if([  yylerrsp = yylsp;
