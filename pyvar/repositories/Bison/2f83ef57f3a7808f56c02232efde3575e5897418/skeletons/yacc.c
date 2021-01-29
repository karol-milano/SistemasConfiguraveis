@@ -241,6 +241,38 @@ m4_define([b4_initialize_parser_state_variables],
 ]])
 
 
+m4_define([b4_macro_define],
+[[#]define $1 $2])
+
+m4_define([b4_macro_undef],
+[[#]undef $1])
+
+m4_define([b4_pstate_macro_define],
+[b4_macro_define([$1], [yyps->$1])])
+
+# b4_parse_state_variable_macros(b4_macro_define|b4_macro_undef)
+# --------------------------------------------------------------
+m4_define([b4_parse_state_variable_macros],
+[b4_pure_if([$1([b4_prefix[]nerrs])])
+$1([yystate])
+$1([yyerrstatus])
+$1([yyssa])
+$1([yyss])
+$1([yyssp])
+$1([yyvsa])
+$1([yyvs])
+$1([yyvsp])[]b4_locations_if([
+$1([yylsa])
+$1([yyls])
+$1([yylsp])
+$1([yyerror_range])])
+$1([yystacksize])[]b4_lac_if([
+$1([yyesa])
+$1([yyes])
+$1([yyes_capacity])])])
+
+
+
 
 # _b4_declare_yyparse_push
 # ------------------------
@@ -1447,23 +1479,7 @@ yypull_parse (yypstate *yyps]b4_user_formals[)
   return yystatus;
 }]])[
 
-]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs]])[
-#define yystate yyps->yystate
-#define yyerrstatus yyps->yyerrstatus
-#define yyssa yyps->yyssa
-#define yyss yyps->yyss
-#define yyssp yyps->yyssp
-#define yyvsa yyps->yyvsa
-#define yyvs yyps->yyvs
-#define yyvsp yyps->yyvsp]b4_locations_if([[
-#define yylsa yyps->yylsa
-#define yyls yyps->yyls
-#define yylsp yyps->yylsp
-#define yyerror_range yyps->yyerror_range]])[
-#define yystacksize yyps->yystacksize]b4_lac_if([[
-#define yyesa yyps->yyesa
-#define yyes yyps->yyes
-#define yyes_capacity yyps->yyes_capacity]])[
+]b4_parse_state_variable_macros([b4_pstate_macro_define])[
 
 /* Initialize the parser data structure.  */
 void
@@ -2067,6 +2083,7 @@ yypushreturn:]])[
     YYSTACK_FREE (yymsg);]])[
   return yyresult;
 }
+]b4_push_if([b4_parse_state_variable_macros([b4_macro_undef])])[
 ]b4_percent_code_get([[epilogue]])[]dnl
 b4_epilogue[]dnl
 b4_output_end
