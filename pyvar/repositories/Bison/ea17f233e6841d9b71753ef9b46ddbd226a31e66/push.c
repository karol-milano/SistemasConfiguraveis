@@ -970,7 +970,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 ]b4_push_if([
 struct yypvars;
 enum { YYPUSH_MORE = 4 };
-]b4_c_function_decl([yypvarsinit], [void *], [[void], []])[
+]b4_c_function_decl([yypvarsinit], [struct yypvars *], [[void], []])[
 ]b4_c_function_decl([yypushparse], [int],
    [[struct yypvars *yypvars], [yypvars]],
    [[int yynchar], [yynchar]],
@@ -1038,7 +1038,6 @@ m4_define([b4_declare_yyparse_variables],
     /* The locations where the error started and ended.  */
     YYLTYPE yyerror_range[2];]]])[
     YYSIZE_T yystacksize;
-    int yylen;
     /* The variables used to return semantic value and location from the
        action routines.  */
     YYSTYPE yyval;
@@ -1048,7 +1047,7 @@ m4_define([b4_declare_yyparse_variables],
   };
 
 /* Initialize the parser data structure.  */
-void *
+struct yypvars*
 yypvarsinit (void)
 {
   struct yypvars *pv = (struct yypvars *) malloc (sizeof *pv);
@@ -1071,7 +1070,7 @@ yypvarsinit (void)
 
 ]b4_locations_if([  pv->yylsp = pv->yyls;])[
 
-  return (void *) pv;
+  return pv;
 }])
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
@@ -1208,7 +1207,6 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	yylsp = pv->yylsp;]])[
 
 	yystacksize = pv->yystacksize;
-	yylen = pv->yylen;
 	yyval = pv->yyval;
 	]b4_locations_if([yyloc = pv->yyloc;])[
       if (pv->yynew == 0)
@@ -1339,7 +1337,6 @@ yybackup:
 	pv->yylsp = yylsp;]])[
 
 	pv->yystacksize = yystacksize;
-	pv->yylen = yylen;
 	pv->yyval = yyval;
 	]b4_locations_if([pv->yyloc = yyloc;])[
 	goto yypushreturn;
