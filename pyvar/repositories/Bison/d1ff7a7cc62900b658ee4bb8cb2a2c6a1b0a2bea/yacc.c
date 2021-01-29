@@ -102,7 +102,7 @@ m4_define([b4_lhs_value],
 # Expansion of $<TYPE>NUM, where the current rule has RULE-LENGTH
 # symbols on RHS.
 m4_define([b4_rhs_value],
-[(yyvsp@{m4_eval([$2 - $1])@}m4_ifval([$3], [.$3]))])
+[(yyvsp@{($2) - ($1)@}m4_ifval([$3], [.$3]))])
 
 
 
@@ -122,7 +122,7 @@ m4_define([b4_lhs_location],
 # Expansion of @NUM, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-[(yylsp@{m4_eval([$2 - $1])@})])
+[(yylsp@{($2) - ($1)@})])
 
 
 
@@ -639,6 +639,8 @@ do {									  \
     }									  \
 } while (/*CONSTCOND*/ 0)
 
+]b4_yysymprint_generate([b4_c_function_def])[
+
 /*------------------------------------------------------------------.
 | yy_stack_print -- Print the state stack from its BOTTOM up to its |
 | TOP (included).                                                   |
@@ -666,22 +668,32 @@ do {								\
 `------------------------------------------------*/
 
 ]b4_c_function_def([yy_reduce_print], [static void],
-                   [[int yyrule], [yyrule]])[
+                   [[YYSTYPE *yyvsp], [yyvsvp]],
+   b4_location_if([[[YYLTYPE *yylsp], [yyvlvp]],])
+                   [[int yyrule],     [yyrule]]
+                   b4_parse_param)[
 {
+  int yynrhs = yyr2[yyrule];
   int yyi;
   unsigned long int yylno = yyrline[yyrule];
-  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
              yyrule - 1, yylno);
-  /* Print the symbols being reduced, and their result.  */
-  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
-    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
-  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
+  /* The symbols being reduced.  */
+  for (yyi = 0; yyi < yynrhs; yyi++)
+    {
+      fprintf (stderr, "   $%d = ", yyi + 1);
+      yysymprint (stderr, yyrhs[yyprhs[yyrule] + yyi],
+                  &]b4_rhs_value(yynrhs, yyi + 1)[
+                  ]b4_location_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+	          b4_user_args[);
+      fprintf (stderr, "\n");
+    }
 }
 
-# define YY_REDUCE_PRINT(Rule)		\
-do {					\
-  if (yydebug)				\
-    yy_reduce_print (Rule);		\
+# define YY_REDUCE_PRINT(Args)					\
+do {								\
+  if (yydebug)							\
+    yy_reduce_print (yyvsp, ]b4_location_if([yylsp, ])[Args);	\
 } while (/*CONSTCOND*/ 0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
@@ -691,7 +703,7 @@ int yydebug;
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
-# define YY_REDUCE_PRINT(Rule)
+# define YY_REDUCE_PRINT(Args)
 #endif /* !YYDEBUG */
 
 
@@ -922,10 +934,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 #endif /* YYERROR_VERBOSE */
 
 
-#if YYDEBUG
-]b4_yysymprint_generate([b4_c_function_def])[
-#endif /* ! YYDEBUG */
-]b4_yydestruct_generate([b4_c_function_def])
+]b4_yydestruct_generate([b4_c_function_def])[
 
 
 /* Prevent warnings from -Wmissing-prototypes.  */
@@ -937,11 +946,11 @@ int yyparse (void *YYPARSE_PARAM);
 int yyparse ();
 # endif
 #else /* ! YYPARSE_PARAM */
-b4_c_function_decl([yyparse], [int], b4_parse_param)
+]b4_c_function_decl([yyparse], [int], b4_parse_param)[
 #endif /* ! YYPARSE_PARAM */
 
 
-m4_divert_push([KILL])# ======================== M4 code.
+]m4_divert_push([KILL])# ======================== M4 code.
 # b4_declare_parser_variables
 # ---------------------------
 # Declare the variables that are global, or local to YYPARSE if
@@ -1252,17 +1261,18 @@ yyreduce:
 ]b4_location_if(
 [[  /* Default location. */
   YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);]])[
-  YY_REDUCE_PRINT (yyn);
+  YY_REDUCE_PRINT ((yyn]b4_user_args[));
   switch (yyn)
-    ]{
-      b4_actions
+    {
+      ]b4_actions[
       default: break;
     }
+  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
 /* Line __line__ of yacc.c.  */
-b4_syncline([@oline@], [@ofile@])
+]b4_syncline([@oline@], [@ofile@])[
 
-[  yyvsp -= yylen;
+  yyvsp -= yylen;
   yyssp -= yylen;
 ]b4_location_if([  yylsp -= yylen;])[
 
