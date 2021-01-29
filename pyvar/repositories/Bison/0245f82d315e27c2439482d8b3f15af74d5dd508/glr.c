@@ -38,7 +38,12 @@ m4_dquote(b4_pure_if([[[[YYSTYPE *]], [[yylvalp]]][]dnl
 b4_location_if([, [[YYLTYPE *], [yyllocp]]])])dnl
 m4_ifdef([b4_lex_param], [, ]b4_lex_param)))
 
-m4_define_default([b4_parse_param])
+# Yes, this is quite ugly...
+  m4_define_default([b4_parse_param])
+m4_ifdef([b4_parse_param],
+[m4_define([b4_parse_param],
+	   b4_parse_param)])
+
 
 
 ## ----------------- ##
@@ -377,26 +382,8 @@ static const ]b4_int_type_for([b4_check])[ yycheck[] =
 };
 
 
-/* The user can define YYPARSE_PARAM as the name of an argument to be passed
-   into yyparse.  The argument should have type void *.
-   It should actually point to an object.
-   Grammar actions can access the variable by casting it
-   to the proper pointer type.  */
-
-#ifdef YYPARSE_PARAM
-#  define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
-#else /* !YYPARSE_PARAM */
-# define YYPARSE_PARAM_ARG void
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
+/* Prevent warning if -Wmissing-prototypes.  */
+]b4_c_ansi_function_decl([yyparse], [int], b4_parse_param)[
 
 /* Error token number */
 #define YYTERROR 1
@@ -1660,8 +1647,12 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     }									     \
   } while (0)
 
-int
-yyparse (YYPARSE_PARAM_ARG)
+
+/*----------.
+| yyparse.  |
+`----------*/
+
+]b4_c_ansi_function_def([yyparse], [int], b4_parse_param)[
 {
   yySymbol yytoken;
   yyGLRStack yystack;
