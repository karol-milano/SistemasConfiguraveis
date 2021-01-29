@@ -603,52 +603,17 @@ yystpcpy (yydest, yysrc)
 
 
 
-/* The user can define YYPARSE_PARAM as the name of an argument to be passed
-   into yyparse.  The argument should have type void *.
-   It should actually point to an object.
-   Grammar actions can access the variable by casting it
-   to the proper pointer type.  */
-
-#ifdef YYPARSE_PARAM
-# if defined (__STDC__) || defined (__cplusplus)
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
-# else
-int yyparse (void);
-# endif
-#endif
-
-
 #if YYDEBUG
 /*-----------------------------.
 | Print this symbol on YYOUT.  |
 `-----------------------------*/
 
-static void
-#if defined (__STDC__) || defined (__cplusplus)
-yysymprint (FILE* yyout, int yytype,
-	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
-#else
-yysymprint (yyout, yytype,
-	    yyvalue[]b4_location_if([, yylocation]))
-  FILE* yyout;
-  int yytype;
-  YYSTYPE yyvalue;
-  b4_location_if([YYLTYPE yylocation;])
-#endif
+b4_c_function([yysymprint],
+	      [static void],
+	      [[FILE*],   [yyout]],
+	      [[int],     [yytype]],
+	      [[YYSTYPE], [yyvalue]]b4_location_if([,
+	      [[YYLTYPE], [yylocation]]]))
 {
   /* Pacify ``unused variable'' warnings.  */
   (void) yyvalue;
@@ -680,18 +645,12 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
 | yyreport_parse_error -- report a parse error in YYSTATE.  |
 `----------------------------------------------------------*/
 
-static void
-#if defined (__STDC__) || defined (__cplusplus)
-yyreport_parse_error (int yystate, int yychar,
-		      YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
-#else
-yyreport_parse_error (yystate, yychar,
-		      yyvalue[]b4_location_if([, yylocation]))
-  int yystate;
-  int yychar;
-  YYSTYPE yyvalue;
-  b4_location_if([YYLTYPE yylocation;])
-#endif
+b4_c_function([yyreport_parse_error],
+	      [static void],
+	      [[int],     [yystate]],
+	      [[int],     [yychar]],
+	      [[YYSTYPE], [yyvalue]]b4_location_if([,
+	      [[YYLTYPE], [yylocation]]]))
 [{
 #if YYERROR_VERBOSE
   int yyn = yypact[yystate];
@@ -754,17 +713,11 @@ yyreport_parse_error (yystate, yychar,
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
 
-static void
-#if defined (__STDC__) || defined (__cplusplus)
-yydestruct (int yytype,
-	    YYSTYPE yyvalue[]b4_location_if([, YYLTYPE yylocation]))
-#else
-yydestruct (yytype,
-	    yyvalue[]b4_location_if([, yylocation]))
-  int yytype;
-  YYSTYPE yyvalue;
-  b4_location_if([YYLTYPE yylocation;])
-#endif
+b4_c_function([yydestruct],
+	      [static void],
+	      [[int],     [yytype]],
+	      [[YYSTYPE], [yyvalue]]b4_location_if([,
+	      [[YYLTYPE], [yylocation]]]))
 {
   /* Pacify ``unused variable'' warnings.  */
   (void) yyvalue;
@@ -779,6 +732,35 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_destructors]))dnl
     }
 }
 
+
+
+/* The user can define YYPARSE_PARAM as the name of an argument to be passed
+   into yyparse.  The argument should have type void *.
+   It should actually point to an object.
+   Grammar actions can access the variable by casting it
+   to the proper pointer type.  */
+
+#ifdef YYPARSE_PARAM
+# if defined (__STDC__) || defined (__cplusplus)
+#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
+#  define YYPARSE_PARAM_DECL
+# else
+#  define YYPARSE_PARAM_ARG YYPARSE_PARAM
+#  define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
+# endif
+#else /* !YYPARSE_PARAM */
+# define YYPARSE_PARAM_ARG
+# define YYPARSE_PARAM_DECL
+#endif /* !YYPARSE_PARAM */
+
+/* Prevent warning if -Wstrict-prototypes.  */
+#ifdef __GNUC__
+# ifdef YYPARSE_PARAM
+int yyparse (void *);
+# else
+int yyparse (void);
+# endif
+#endif
 
 m4_divert_push([KILL])# ======================== M4 code.
 # b4_declare_parser_variables
