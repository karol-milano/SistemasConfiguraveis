@@ -547,6 +547,50 @@ do {								\
     }								\
 } while (0)
 
+/*------------------------------------------------------------------.
+| yy_stack_print -- Print the state stack from its BOTTOM up to its |
+| TOP (cinluded).                                                   |
+`------------------------------------------------------------------*/
+
+]b4_c_function_def([yy_stack_print], [static void],
+                   [[short *bottom], [bottom]],
+                   [[short *top],    [top]])[
+{
+  YYFPRINTF (stderr, "Stack now");
+  for (/* Nothing. */; bottom <= top; ++bottom)
+    YYFPRINTF (stderr, " %d", *bottom);
+  YYFPRINTF (stderr, "\n");
+}
+
+# define YY_STACK_PRINT(Bottom, Top)				\
+do {								\
+  if (yydebug)							\
+    yy_stack_print ((Bottom), (Top));				\
+} while (0)
+
+
+/*------------------------------------------------.
+| Report that the YYRULE is going to be reduced.  |
+`------------------------------------------------*/
+
+]b4_c_function_def([yy_reduce_print], [static void],
+                   [[int yyrule], [yyrule]])[
+{
+  int yyi;
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d), ",
+             yyrule - 1, yyrline[yyrule]);
+  /* Print the symbols being reduced, and their result.  */
+  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
+    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
+  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
+}
+
+# define YY_REDUCE_PRINT(Rule)		\
+do {					\
+  if (yydebug)				\
+    yy_reduce_print (Rule);		\
+} while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
@@ -554,8 +598,11 @@ int yydebug;
 # define YYDPRINTF(Args)
 # define YYDSYMPRINT(Args)
 # define YYDSYMPRINTF(Title, Token, Value, Location)
+# define YY_STACK_PRINT(Bottom, Top)
+# define YY_REDUCE_PRINT(Rule)
 #endif /* !YYDEBUG */
 
+
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
 #ifndef	YYINITDEPTH
 # define YYINITDEPTH ]b4_stack_depth_init[
@@ -936,23 +983,7 @@ yyreduce:
 ]b4_location_if(
 [  /* Default location. */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);])[
-
-#if YYDEBUG
-  /* We have to keep this `#if YYDEBUG', since we use variables which
-     are defined only if `YYDEBUG' is set.  */
-  if (yydebug)
-    {
-      int yyi;
-
-      YYFPRINTF (stderr, "Reducing by rule %d (line %d), ",
-		 yyn - 1, yyrline[yyn]);
-
-      /* Print the symbols being reduced, and their result.  */
-      for (yyi = yyprhs[yyn]; 0 <= yyrhs[yyi]; yyi++)
-	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
-      YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyn]]);
-    }
-#endif
+  YY_REDUCE_PRINT (yyn);
   switch (yyn)
     ]{
       b4_actions
@@ -965,16 +996,7 @@ b4_syncline([@oline@], [@ofile@])
   yyssp -= yylen;
 ]b4_location_if([  yylsp -= yylen;])[
 
-#if YYDEBUG
-  if (yydebug)
-    {
-      short *yyssp1 = yyss - 1;
-      YYFPRINTF (stderr, "state stack now");
-      while (yyssp1 != yyssp)
-	YYFPRINTF (stderr, " %d", *++yyssp1);
-      YYFPRINTF (stderr, "\n");
-    }
-#endif
+  YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;
 ]b4_location_if([  *++yylsp = yyloc;])[
@@ -1111,17 +1133,7 @@ yyerrlab1:
       yyvsp--;
       yystate = *--yyssp;
 ]b4_location_if([      yylsp--;])[
-
-#if YYDEBUG
-      if (yydebug)
-	{
-	  short *yyssp1 = yyss - 1;
-	  YYFPRINTF (stderr, "Error: state stack now");
-	  while (yyssp1 != yyssp)
-	    YYFPRINTF (stderr, " %d", *++yyssp1);
-	  YYFPRINTF (stderr, "\n");
-	}
-#endif
+      YY_STACK_PRINT (yyss, yyssp);
     }
 
   if (yyn == YYFINAL)
