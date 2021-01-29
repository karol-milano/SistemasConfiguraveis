@@ -430,6 +430,8 @@ YYLTYPE yylloc;]])[
 int yynerrs;
 int yychar;])[
 
+enum { YYNOMEM = -2 };
+
 static const int YYEOF = 0;
 static const int YYEMPTY = -2;
 
@@ -2186,8 +2188,8 @@ yysyntax_error_arguments (const yyGLRStack* yystackp,
       int yyn;
       yyarg[yycount++] = yytoken;
       yyn = yyexpected_tokens (yystackp, yyarg ? yyarg + 1 : yyarg, yyargn - 1);
-      if (yyn == -2)
-        return -2;
+      if (yyn == YYNOMEM)
+        return YYNOMEM;
       else
         yycount += yyn;
     }
@@ -2222,7 +2224,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   /* Actual size of YYARG. */
   int yycount
     = yysyntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
-  if (yycount == -2)
+  if (yycount == YYNOMEM)
     yyMemoryExhausted (yystackp);
 
   switch (yycount)
