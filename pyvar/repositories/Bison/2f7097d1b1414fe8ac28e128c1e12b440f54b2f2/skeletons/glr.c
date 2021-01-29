@@ -2071,18 +2071,18 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 #else
   {
   yySymbol yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);
-  ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
-  ptrdiff_t yysize = yysize0;
   yybool yysize_overflow = yyfalse;
   char* yymsg = YY_NULLPTR;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
-  /* Arguments of yyformat. */
+  /* Arguments of yyformat: reported tokens (one for the "unexpected",
+     one per "expected"). */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  /* Number of reported tokens (one for the "unexpected", one per
-     "expected").  */
+  /* Actual size of YYARG. */
   int yycount = 0;
+  /* Cumulated lengths of YYARG.  */
+  ptrdiff_t yysize = 0;
 
   /* There are many possibilities here to consider:
      - If this state is a consistent state with a default action, then
@@ -2110,6 +2110,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   if (yytoken != YYEMPTY)
     {
       int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
+      ptrdiff_t yysize0 = yytnamerr (YY_NULLPTR, yytokenName (yytoken));
+      yysize = yysize0;
       yyarg[yycount++] = yytokenName (yytoken);
       if (!yypact_value_is_default (yyn))
         {
@@ -2160,7 +2162,9 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     }
 
   {
-    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat));
+    /* Don't count the "%s"s in the final size, but reserve room for
+       the terminator.  */
+    ptrdiff_t yysz = YY_CAST (ptrdiff_t, strlen (yyformat)) - 2 * yycount + 1;
     if (YYSIZEMAX - yysize < yysz)
       yysize_overflow = yytrue;
     else
@@ -2183,8 +2187,8 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
             }
           else
             {
-              yyp++;
-              yyformat++;
+              ++yyp;
+              ++yyformat;
             }
         }
       yyerror (]b4_lyyerror_args[yymsg);
