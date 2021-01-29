@@ -700,14 +700,14 @@ static void yypdumpstack (yyGLRStack* yystackp)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
 
-]m4_case(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_case(
          [simple],
 [[]],
 [[#ifndef yystrlen
 # define yystrlen(S) (YY_CAST (ptrdiff_t, strlen (S)))
 #endif
 
-]m4_bmatch(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_bmatch(
            [detailed\|verbose],
 [[#ifndef yystpcpy
 # if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
@@ -729,7 +729,7 @@ yystpcpy (char *yydest, const char *yysrc)
 # endif
 #endif]])[
 
-]m4_case(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_case(
          [verbose],
 [[#ifndef yytnamerr
 /* Copy to YYRES the contents of YYSTR after stripping away unnecessary
@@ -2089,7 +2089,7 @@ yyprocessOneStack (yyGLRStack* yystackp, ptrdiff_t yyk,
   return yyok;
 }
 
-]m4_if(b4_percent_define_get([[parse.error]]), [simple], [],
+]b4_parse_error_case([simple], [],
 [[/* Put in YYARG at most YYARGN of the expected tokens given the
    current YYSTACKP, and return the number of tokens stored in YYARG.  If
    YYARG is null, return the number of expected tokens (guaranteed to
@@ -2175,7 +2175,7 @@ yysyntax_error_arguments (const yyGLRStack* yystackp,
 }
 ]])[
 
-]m4_case(b4_percent_define_get([[parse.error]]),
+]b4_parse_error_case(
          [custom],
 [[/* User defined function to report a syntax error.  */
 typedef yyGLRStack yyparse_context_t;
@@ -2199,7 +2199,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 {
   if (yystackp->yyerrState != 0)
     return;
-]m4_case(b4_percent_define_get([parse.error]),
+]b4_parse_error_case(
          [custom],
 [[  if (yyreport_syntax_error (yystackp]b4_user_args[))
     yyMemoryExhausted (yystackp);]],
@@ -2247,7 +2247,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     for (yyi = 0; yyi < yycount; ++yyi)
       {
         ptrdiff_t yysz
-          = ]m4_case(b4_percent_define_get([[parse.error]]),
+          = ]b4_parse_error_case(
                      [verbose], [[yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]])]],
                      [[yystrlen (yysymbol_name (yyarg[yyi]))]]);[
         if (YYSIZEMAX - yysize < yysz)
@@ -2267,7 +2267,7 @@ yyreportSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       while ((*yyp = *yyformat))
         {
           if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-            {]m4_case(b4_percent_define_get([[parse.error]]), [verbose], [[
+            {]b4_parse_error_case([verbose], [[
               yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);]], [[
               yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));]])[
               yyformat += 2;
