@@ -211,10 +211,7 @@ m4_define([b4_declare_parser_state_variables],
     /* The location stack.  */
     YYLTYPE yylsa[YYINITDEPTH];
     YYLTYPE *yyls;
-    YYLTYPE *yylsp;
-
-    /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[3];]])[]b4_lac_if([[
+    YYLTYPE *yylsp;]])[]b4_lac_if([[
 
     yy_state_t yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
     yy_state_t *yyes;
@@ -264,8 +261,7 @@ $1([yyvs])
 $1([yyvsp])[]b4_locations_if([
 $1([yylsa])
 $1([yyls])
-$1([yylsp])
-$1([yyerror_range])])
+$1([yylsp])])
 $1([yystacksize])[]b4_lac_if([
 $1([yyesa])
 $1([yyes])
@@ -1559,7 +1555,10 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   /* The variables used to return semantic value and location from the
      action routines.  */
   YYSTYPE yyval;]b4_locations_if([[
-  YYLTYPE yyloc;]])[
+  YYLTYPE yyloc;
+
+  /* The locations where the error started and ended.  */
+  YYLTYPE yyerror_range[3];]])[
 
 ]b4_parse_error_bmatch([detailed\|verbose],
 [[  /* Buffer for error messages, and its allocated size.  */
