@@ -514,18 +514,21 @@ while (0)
     (Current).first_column = (Rhs)[1].first_column,	\
     (Current).last_line    = (Rhs)[N].last_line,	\
     (Current).last_column  = (Rhs)[N].last_column)
+#endif
+
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
 
-# define YY_LOCATION_PRINT(File, Loc)			\
-    fprintf (File, "%d.%d-%d.%d",			\
-             (Loc).first_line, (Loc).first_column,	\
-             (Loc).last_line,  (Loc).last_column)
-#endif
-
 #ifndef YY_LOCATION_PRINT
+# if YYLTYPE_IS_TRIVIAL
+#  define YY_LOCATION_PRINT(File, Loc)			\
+     fprintf (File, "%d.%d-%d.%d",			\
+              (Loc).first_line, (Loc).first_column,	\
+              (Loc).last_line,  (Loc).last_column)
+# endif
+#else
 # define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 #endif
 
@@ -815,8 +818,14 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 
   yyssp = yyss;
   yyvsp = yyvs;
-]b4_location_if([  yylsp = yyls;])[
-]m4_ifdef([b4_initial_action], [
+]b4_location_if([[  yylsp = yyls;
+#if YYLTYPE_IS_TRIVIAL
+  /* Initialize the default location before parsing starts.  */
+  yyls[0].first_line   = yyls[0].last_line   = 1;
+  yyls[0].first_column = yyls[0].last_column = 0;
+#endif
+]])
+m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [(*yylsp)])dnl
 m4_pushdef([b4_dollar_dollar], [(*yyvsp)])dnl
   /* User initialization code. */
@@ -1008,8 +1017,11 @@ yyreduce:
   yyval = yyvsp[1-yylen];
 
 ]b4_location_if(
-[  /* Default location. */
-  YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);])[
+[[  /* Default location. */
+  if (yylen)
+    YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);
+  else
+    yyloc = yylsp[0];]])[
   YY_REDUCE_PRINT (yyn);
   switch (yyn)
     ]{
