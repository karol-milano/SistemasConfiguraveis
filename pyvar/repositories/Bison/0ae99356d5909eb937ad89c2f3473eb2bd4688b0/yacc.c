@@ -501,11 +501,11 @@ while (0)
    are run).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)         \
-  Current.first_line   = Rhs[1].first_line;      \
-  Current.first_column = Rhs[1].first_column;    \
-  Current.last_line    = Rhs[N].last_line;       \
-  Current.last_column  = Rhs[N].last_column;
+# define YYLLOC_DEFAULT(Current, Rhs, N)		\
+   ((Current).first_line   = (Rhs)[1].first_line,	\
+    (Current).first_column = (Rhs)[1].first_column,	\
+    (Current).last_line    = (Rhs)[N].last_line,	\
+    (Current).last_column  = (Rhs)[N].last_column)
 #endif
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
@@ -983,7 +983,7 @@ yyreduce:
 
 ]b4_location_if(
 [  /* Default location. */
-  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);])[
+  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);])[
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     ]{
@@ -1180,7 +1180,7 @@ yyerrlab1:
   YYDPRINTF ((stderr, "Shifting error token, "));
 
   *++yyvsp = yylval;
-]b4_location_if([  YYLLOC_DEFAULT (yyloc, yylsp, (yylerrsp - yylsp));
+]b4_location_if([  YYLLOC_DEFAULT (yyloc, yylsp, yylerrsp - yylsp);
   *++yylsp = yyloc;])[
 
   yystate = yyn;
