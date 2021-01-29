@@ -286,7 +286,7 @@ union yyalloc
 #   define YYCOPY(To, From, Count)		\
       do					\
 	{					\
-	  register YYSIZE_T yyi;		\
+	  YYSIZE_T yyi;				\
 	  for (yyi = 0; yyi < (Count); yyi++)	\
 	    (To)[yyi] = (From)[yyi];		\
 	}					\
@@ -666,7 +666,7 @@ yystrlen (yystr)
      const char *yystr;
 #   endif
 {
-  register const char *yys = yystr;
+  const char *yys = yystr;
 
   while (*yys++ != '\0')
     continue;
@@ -691,8 +691,8 @@ yystpcpy (yydest, yysrc)
      const char *yysrc;
 #   endif
 {
-  register char *yyd = yydest;
-  register const char *yys = yysrc;
+  char *yyd = yydest;
+  const char *yys = yysrc;
 
   while ((*yyd++ = *yys++) != '\0')
     continue;
@@ -764,8 +764,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif
 {[
   ]b4_pure_if([b4_declare_parser_variables])[
-  register int yystate;
-  register int yyn;
+  int yystate;
+  int yyn;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
@@ -783,12 +783,12 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   /* The state stack.  */
   short int yyssa[YYINITDEPTH];
   short int *yyss = yyssa;
-  register short int *yyssp;
+  short int *yyssp;
 
   /* The semantic value stack.  */
   YYSTYPE yyvsa[YYINITDEPTH];
   YYSTYPE *yyvs = yyvsa;
-  register YYSTYPE *yyvsp;
+  YYSTYPE *yyvsp;
 
 ]b4_location_if(
 [[  /* The location stack.  */
