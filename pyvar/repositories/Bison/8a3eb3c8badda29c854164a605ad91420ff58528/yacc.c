@@ -465,7 +465,15 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 #define YYACCEPT	goto yyacceptlab
 #define YYABORT		goto yyabortlab
-#define YYERROR		goto yyerrlab1
+#define YYERROR		]b4_location_if([do				\
+			  {				\
+			    yylerrsp = yylsp;		\
+			    *++yylerrsp = yyloc;	\
+			    goto yyerrlab1;		\
+			  }				\
+			while (0)],
+			[goto yyerrlab1])[
+
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
    to ease the transition to the new meaning of YYERROR, for GCC.
@@ -1103,33 +1111,13 @@ yyerrlab:
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
-  goto yyerrlab2;
+  goto yyerrlab1;
 
 
 /*----------------------------------------------------.
 | yyerrlab1 -- error raised explicitly by an action.  |
 `----------------------------------------------------*/
 yyerrlab1:
-
-  /* Suppress GCC warning that yyerrlab1 is unused when no action
-     invokes YYERROR.  MacOS 10.2.3's buggy "smart preprocessor"
-     insists on the trailing semicolon.  */
-#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
-  /* GNU C++ (as of version 3.2.1) does not allow attributes on labels.  */
-# ifndef __cplusplus
-  __attribute__ ((__unused__));
-# endif
-#endif
-
-]b4_location_if([  yylerrsp = yylsp;
-  *++yylerrsp = yyloc;])[
-  goto yyerrlab2;
-
-
-/*---------------------------------------------------------------.
-| yyerrlab2 -- pop states until the error token can be shifted.  |
-`---------------------------------------------------------------*/
-yyerrlab2:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
