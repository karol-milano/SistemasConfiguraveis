@@ -427,7 +427,7 @@ YYLTYPE yylloc;]])[
 int yynerrs;
 int yychar;])[
 
-enum { YYNOMEM = -2 };
+enum { YYENOMEM = -2 };
 
 static const int YYEOF = 0;
 static const int YYEMPTY = -2;
@@ -2192,8 +2192,8 @@ yy_syntax_error_arguments (const yyGLRStack* yystackp,
         yyarg[yycount] = yytoken;
       ++yycount;
       yyn = yyexpected_tokens (yystackp, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
-      if (yyn == YYNOMEM)
-        return YYNOMEM;
+      if (yyn == YYENOMEM)
+        return YYENOMEM;
       else
         yycount += yyn;
     }
@@ -2228,7 +2228,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   /* Actual size of YYARG. */
   int yycount
     = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
-  if (yycount == YYNOMEM)
+  if (yycount == YYENOMEM)
     yyMemoryExhausted (yystackp);
 
   switch (yycount)
