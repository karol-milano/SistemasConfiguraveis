@@ -994,22 +994,22 @@ int yychar;
 
 /* The semantic value of the lookahead symbol.  */
 YYSTYPE yylval;
-
-/* Number of syntax errors so far.  */
-]b4_push_if([],[
-int yynerrs;])b4_locations_if([[
+]b4_locations_if([[
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc;]])
-])
-
-m4_define([b4_yyerror_range],b4_push_if([yyps->yyerror_range],[yyerror_range]))
+YYLTYPE yylloc;
+]])b4_pure_if([], [[
+/* Number of syntax errors so far.  */
+int yynerrs;
+]])])
 
 # b4_declare_parser_state_variables
 # ---------------------------------
 # Declare all the variables that are needed to maintain the parser state
 # between calls to yypush_parse.
 m4_define([b4_declare_parser_state_variables],
-[[
+[b4_pure_if([[    /* Number of syntax errors so far.  */
+    int yynerrs;
+]])[
     int yystate;
     int yyn;
     int yyresult;
@@ -1040,13 +1040,16 @@ m4_define([b4_declare_parser_state_variables],
     YYLTYPE yylsa[YYINITDEPTH];
     YYLTYPE *yyls;
     YYLTYPE *yylsp;
+
     /* The locations where the error started and ended.  */
-    YYLTYPE yyerror_range[2];]])[
+    YYLTYPE yyerror_range[2];
+]])[
     YYSIZE_T yystacksize;
+
     /* The variables used to return semantic value and location from the
        action routines.  */
     YYSTYPE yyval;
-]b4_locations_if([[  YYLTYPE yyloc;
+]b4_locations_if([[    YYLTYPE yyloc;
 ]])])
 
 m4_divert_pop([KILL])dnl# ====================== End of M4 code.
@@ -1077,7 +1080,8 @@ b4_push_if(
   free (yyps);
 }
 
-#define yystate yyps->yystate
+]b4_pure_if([[#define ]b4_prefix[nerrs yyps->]b4_prefix[nerrs
+]])[#define yystate yyps->yystate
 #define yyn yyps->yyn
 #define yyresult yyps->yyresult
 #define yyerrstatus yyps->yyerrstatus
@@ -1091,6 +1095,7 @@ b4_push_if(
 ]b4_locations_if([[#define yylsa yyps->yylsa
 #define yyls yyps->yyls
 #define yylsp yyps->yylsp
+#define yyerror_range yyps->yyerror_range
 ]])[#define yystacksize yyps->yystacksize
 #define yyval yyps->yyval
 ]b4_locations_if([[#define yyloc yyps->yyloc
@@ -1142,7 +1147,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 
   yystate = 0;
   yyerrstatus = 0;
-]b4_push_if([], [[  yynerrs = 0;]])[
+  yynerrs = 0;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
   /* Initialize stack pointers.
@@ -1401,7 +1406,7 @@ yyerrlab:
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
-]b4_push_if([],[ ++yynerrs;])[
+      ++yynerrs;
 #if ! YYERROR_VERBOSE
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
@@ -1439,7 +1444,7 @@ yyerrlab:
 #endif
     }
 
-]b4_locations_if([[  ]b4_yyerror_range[[0] = yylloc;]])[
+]b4_locations_if([[  yyerror_range[0] = yylloc;]])[
 
   if (yyerrstatus == 3)
     {
@@ -1476,7 +1481,7 @@ yyerrorlab:
   if (/*CONSTCOND*/ 0)
      goto yyerrorlab;
 
-]b4_locations_if([[  ]b4_yyerror_range[[0] = yylsp[1-yylen];
+]b4_locations_if([[  yyerror_range[0] = yylsp[1-yylen];
 ]])[  /* Do not reclaim the symbols of the rule which action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
@@ -1510,7 +1515,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-]b4_locations_if([[      ]b4_yyerror_range[[0] = *yylsp;]])[
+]b4_locations_if([[      yyerror_range[0] = *yylsp;]])[
       yydestruct ("Error: popping",
 		  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
@@ -1520,10 +1525,10 @@ yyerrlab1:
 
   *++yyvsp = yylval;
 ]b4_locations_if([[
-  ]b4_yyerror_range[[1] = yylloc;
+  yyerror_range[1] = yylloc;
   /* Using YYLLOC is tempting, but would change the location of
      the lookahead.  YYLOC is available though.  */
-  YYLLOC_DEFAULT (yyloc, (]b4_yyerror_range[- 1), 2);
+  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
   *++yylsp = yyloc;]])[
 
   /* Shift the error token.  */
@@ -1609,8 +1614,7 @@ b4_token_enums_defines(b4_tokens)
 # define YYSTYPE_IS_DECLARED 1
 #endif
 
-]b4_pure_if([],
-[extern YYSTYPE b4_prefix[]lval;])
+]b4_pure_if([], [[extern YYSTYPE ]b4_prefix[lval;]])
 
 b4_locations_if(
 [#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
@@ -1626,8 +1630,7 @@ typedef struct YYLTYPE
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
-]b4_pure_if([],
-	   [extern YYLTYPE b4_prefix[]lloc;])
+]b4_pure_if([], [[extern YYLTYPE ]b4_prefix[lloc;]])
 )dnl b4_locations_if
 
 b4_push_if([[#ifndef YYPUSH_DECLS
