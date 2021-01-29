@@ -345,7 +345,7 @@ union yyalloc
 #   define YYCOPY(To, From, Count)		\
       do					\
 	{					\
-	  register YYSIZE_T yyi;		\
+	  YYSIZE_T yyi;				\
 	  for (yyi = 0; yyi < (Count); yyi++)	\
 	    (To)[yyi] = (From)[yyi];		\
 	}					\
@@ -901,7 +901,7 @@ yystrlen (yystr)
      const char *yystr;
 #   endif
 {
-  register const char *yys = yystr;
+  const char *yys = yystr;
 
   while (*yys++ != '\0')
     continue;
@@ -926,8 +926,8 @@ yystpcpy (yydest, yysrc)
      const char *yysrc;
 #   endif
 {
-  register char *yyd = yydest;
-  register const char *yys = yysrc;
+  char *yyd = yydest;
+  const char *yys = yysrc;
 
   while ((*yyd++ = *yys++) != '\0')
     continue;
@@ -1070,8 +1070,8 @@ int yynerrs;
 /* Location data for the look-ahead symbol.  */
 YYLTYPE yylloc;
 
-  register int yystate;
-  register int yyn;
+  int yystate;
+  int yyn;
   int yyresult;
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
@@ -1089,12 +1089,12 @@ YYLTYPE yylloc;
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
 
   /* The location stack.  */
   YYLTYPE yylsa[YYINITDEPTH];
