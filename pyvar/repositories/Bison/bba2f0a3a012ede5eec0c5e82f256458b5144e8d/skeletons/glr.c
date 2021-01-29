@@ -824,7 +824,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 ]b4_parse_param_use()dnl
 [  if (*yycharp == YYEMPTY)
     {
-      YY_DPRINTF ((stderr, "Reading a token: "));]b4_glr_cc_if([[
+      YY_DPRINTF ((stderr, "Reading a token\n"));]b4_glr_cc_if([[
 #if YY_EXCEPTIONS
       try
         {
