@@ -1042,12 +1042,8 @@ m4_define([b4_declare_parser_state_variables],
     int yynerrs;
 ]])[
     int yystate;
-    int yyn;
-    int yyresult;
     /* Number of tokens to shift before error messages enabled.  */
     int yyerrstatus;
-    /* Look-ahead token as an internal (translated) token number.  */
-    int yytoken;
 
     /* Three stacks and their tools:
        `yyss': related to states,
@@ -1076,12 +1072,7 @@ m4_define([b4_declare_parser_state_variables],
     YYLTYPE yyerror_range[2];
 ]])[
     YYSIZE_T yystacksize;
-
-    /* The variables used to return semantic value and location from the
-       action routines.  */
-    YYSTYPE yyval;
-]b4_locations_if([[    YYLTYPE yyloc;
-]])])
+]])
 
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
 
@@ -1125,7 +1116,6 @@ b4_push_if(
 ]b4_c_function_def([[yypstate_new]], [[yypstate *]])[
 {
   yypstate *yyps = (yypstate *) malloc (sizeof *yyps);
-  yyps->yyresult = -1;
   yyps->yynew = 1;
   return yyps;
 }
@@ -1138,10 +1128,7 @@ b4_push_if(
 
 ]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs
 ]])[#define yystate yyps->yystate
-#define yyn yyps->yyn
-#define yyresult yyps->yyresult
 #define yyerrstatus yyps->yyerrstatus
-#define yytoken yyps->yytoken
 #define yyssa yyps->yyssa
 #define yyss yyps->yyss
 #define yyssp yyps->yyssp
@@ -1153,9 +1140,7 @@ b4_push_if(
 #define yylsp yyps->yylsp
 #define yyerror_range yyps->yyerror_range
 ]])[#define yystacksize yyps->yystacksize
-#define yyval yyps->yyval
-]b4_locations_if([[#define yyloc yyps->yyloc
-]])])[
+]])[
 
 /*-------------------------.
 | yyparse or yypush_parse.  |
@@ -1180,7 +1165,15 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   ]b4_locations_if([[YYLTYPE yypushed_loc = yylloc;
 ]])])],
   [b4_declare_parser_state_variables])[
-
+  int yyn;
+  int yyresult;
+  /* Look-ahead token as an internal (translated) token number.  */
+  int yytoken;
+  /* The variables used to return semantic value and location from the
+     action routines.  */
+  YYSTYPE yyval;
+]b4_locations_if([[  YYLTYPE yyloc;
+]])[
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
@@ -1195,7 +1188,10 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   int yylen = 0;
 ]b4_push_if([[
   if (!yyps->yynew)
-    goto yyread_pushed_token;
+    {
+      yyn = yypact[yystate];
+      goto yyread_pushed_token;
+    }
 ]])[
   yytoken = 0;
   yyss = yyssa;
