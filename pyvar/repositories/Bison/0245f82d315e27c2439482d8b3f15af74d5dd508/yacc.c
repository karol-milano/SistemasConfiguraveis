@@ -40,6 +40,12 @@ m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[&yylval]]][]dnl
 b4_location_if([, [[YYLTYPE *], [&yylloc]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
+# Yes, this is quite ugly...
+m4_define_default([b4_parse_param])
+m4_ifdef([b4_parse_param],
+[m4_define([b4_parse_param],
+	   b4_parse_param)])
+
 
 ## ----------------- ##
 ## Semantic Values.  ##
@@ -625,12 +631,12 @@ yystpcpy (yydest, yysrc)
 | Print this symbol on YYOUT.  |
 `-----------------------------*/
 
-b4_c_function([yysymprint],
-	      [static void],
-	      [[FILE*],   [yyout]],
-	      [[int],     [yytype]],
-	      [[YYSTYPE], [yyvalue]]b4_location_if([,
-	      [[YYLTYPE], [yylocation]]]))
+b4_c_function_def([yysymprint],
+  	          [static void],
+	          [[FILE *yyout],        [yyout]],
+	          [[int yytype],         [yytype]],
+	          [[YYSTYPE yyvalue],    [yyvalue]]b4_location_if([,
+	          [[YYLTYPE yylocation], [yylocation]]]))
 {
   /* Pacify ``unused variable'' warnings.  */
   (void) yyvalue;
@@ -662,11 +668,11 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
-b4_c_function([yydestruct],
-	      [static void],
-	      [[int],     [yytype]],
-	      [[YYSTYPE], [yyvalue]]b4_location_if([,
-	      [[YYLTYPE], [yylocation]]]))
+b4_c_function_def([yydestruct],
+	          [static void],
+	          [[int yytype],         [yytype]],
+	          [[YYSTYPE yyvalue],    [yyvalue]]b4_location_if([,
+	          [[YYLTYPE yylocation], [yylocation]]]))
 {
   /* Pacify ``unused variable'' warnings.  */
   (void) yyvalue;
@@ -683,39 +689,24 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_destructors]))dnl
 
 
 
-/* The user can define YYPARSE_PARAM as the name of an argument to be passed
-   into yyparse.  The argument should have type void *.
-   It should actually point to an object.
-   Grammar actions can access the variable by casting it
-   to the proper pointer type.  */
+/* Prevent warnings from -Wmissing-prototypes.  */
 
 #ifdef YYPARSE_PARAM
 # if defined (__STDC__) || defined (__cplusplus)
-#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
-#  define YYPARSE_PARAM_DECL
-# else
-#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
-#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
-# endif
-#else /* !YYPARSE_PARAM */
-# define YYPARSE_PARAM_ARG
-# define YYPARSE_PARAM_DECL
-#endif /* !YYPARSE_PARAM */
-
-/* Prevent warning if -Wstrict-prototypes.  */
-#ifdef __GNUC__
-# ifdef YYPARSE_PARAM
-int yyparse (void *);
+int yyparse (void *YYPARSE_PARAM);
 # else
-int yyparse (void);
+int yyparse ();
 # endif
+#else /* ! YYPARSE_PARAM */
+b4_c_function_decl([yyparse], [int], b4_parse_param)
 #endif
 
+
 m4_divert_push([KILL])# ======================== M4 code.
 # b4_declare_parser_variables
 # ---------------------------
 # Declare the variables that are global, or local to YYPARSE if
-#  pure-parser
+# pure-parser.
 m4_define([b4_declare_parser_variables],
 [/* The lookahead symbol.  */
 int yychar;
@@ -733,9 +724,21 @@ m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 b4_pure_if([],
            [b4_declare_parser_variables])
 
-int
-yyparse (YYPARSE_PARAM_ARG)
-     YYPARSE_PARAM_DECL
+
+/*----------.
+| yyparse.  |
+`----------*/
+
+#ifdef YYPARSE_PARAM
+# if defined (__STDC__) || defined (__cplusplus)
+int yyparse (void *YYPARSE_PARAM)
+# else
+int yyparse (YYPARSE_PARAM)
+  void *YYPARSE_PARAM;
+# endif
+#else /* ! YYPARSE_PARAM */
+b4_c_function_def([yyparse], [int], b4_parse_param)
+#endif
 {[
   ]b4_pure_if([b4_declare_parser_variables])[
   register int yystate;
