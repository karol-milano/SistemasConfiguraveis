@@ -429,7 +429,6 @@ int yychar;])[
 
 enum { YYENOMEM = -2 };
 
-static const int YYEOF = 0;
 static const int YYEMPTY = -2;
 
 typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
@@ -833,9 +832,9 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 #endif // YY_EXCEPTIONS]], [[
       *yycharp = ]b4_lex[;]])[
     }
-  if (*yycharp <= YYEOF)
+  if (*yycharp <= ]b4_symbol(0, [id])[)
     {
-      *yycharp = YYEOF;
+      *yycharp = ]b4_symbol(0, [id])[;
       yytoken = ]b4_symbol_prefix[YYEOF;
       YY_DPRINTF ((stderr, "Now at end of input.\n"));
     }
@@ -2311,7 +2310,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       {
         yysymbol_kind_t yytoken;
         int yyj;
-        if (yychar == YYEOF)
+        if (yychar == ]b4_symbol(0, [id])[)
           yyFail (yystackp][]b4_lpure_args[, YY_NULLPTR);
         if (yychar != YYEMPTY)
           {]b4_locations_if([[
@@ -2724,6 +2723,7 @@ m4_if(b4_prefix, [yy], [],
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
 #define yylloc  ]b4_prefix[lloc]])])[
 
-]b4_percent_code_get([[epilogue]])[]dnl
+]m4_ifdef([b4_pre_epilogue], [b4_pre_epilogue])[]dnl This is a hack for glr.cc.  To remove when we have a better glr.cc.
+b4_percent_code_get([[epilogue]])[]dnl
 b4_epilogue[]dnl
 b4_output_end
