@@ -973,7 +973,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
 ]b4_push_if([
 struct yypvars;
-#define YYPUSH_MORE 4
+enum { YYPUSH_MORE = 4 };
 ]b4_c_function_decl([yychar_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[int yychar], [yychar]])[
 ]b4_c_function_decl([yylval_set], [void], [[struct yypvars *YYPVARS], [YYPVARS]], [[YYSTYPE yylval], [yylval]])[
 #ifdef YYLTYPE_IS_TRIVIAL
@@ -1055,18 +1055,16 @@ m4_define([b4_declare_yyparse_variables],
     /* The variables used to return semantic value and location from the
        action routines.  */
     YYSTYPE yyval;
-    /* Used to determine if this is the first time this instance has 
+    /* Used to determine if this is the first time this instance has
        been used.  */
     int yynew;]b4_locations_if([YYLTYPE yyloc;])[
   };
 
-/* Init the parser data structure. Use malloc, should perhaps use a 
-   system dependent equivalent function.  */
-void* 
+/* Initialize the parser data structure.  */
+void *
 yypvarsinit (void)
 {
-  struct yypvars *pv;
-  pv= (struct yypvars *) malloc(sizeof(struct yypvars));
+  struct yypvars *pv = (struct yypvars *) malloc (sizeof *pv);
   pv->yystate = 0;
   pv->yyresult = -1;
   pv->yyerrstatus = 0;
@@ -1098,9 +1096,8 @@ yypvarsinit (void)
   pv->yynew = 1;
 
 ]b4_locations_if([  pv->yylsp = pv->yyls;])[
-  /* Init parser variables */
-    
-  return (void*) pv;
+
+  return (void *) pv;
 }
 
 void
@@ -1239,41 +1236,41 @@ m4_ifdef([b4_dollar_dollar_used],[[  yyvsp[0] = yylval;
 m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 ]])dnl
 [  ]b4_push_if([
-        /* Initialize the locals to the current context. */
-	yychar	      = pv->yychar;
-	yylval	      = pv->yylval;
-	yynerrs       = pv->yynerrs;
+	/* Initialize the locals to the current context. */
+	yychar = pv->yychar;
+	yylval = pv->yylval;
+	yynerrs = pv->yynerrs;
 	]b4_locations_if([
-	yylloc	      = pv->yylloc;])[
+	yylloc = pv->yylloc;])[
 
-        yystate	      = pv->yystate;
-	yyn	      = pv->yyn;
-	yyresult      = pv->yyresult;
-	yyerrstatus   = pv->yyerrstatus;
-	yytoken       = pv->yytoken;
+	yystate = pv->yystate;
+	yyn = pv->yyn;
+	yyresult = pv->yyresult;
+	yyerrstatus = pv->yyerrstatus;
+	yytoken = pv->yytoken;
 #if YYERROR_VERBOSE
-	yymsgbuf_ptr  = pv->yymsgbuf_ptr;
-	yymsg         = pv->yymsg;;
-	yymsg_alloc   = pv->yymsg_alloc;
+	yymsgbuf_ptr = pv->yymsgbuf_ptr;
+	yymsg = pv->yymsg;;
+	yymsg_alloc = pv->yymsg_alloc;
 #endif
-	yyssa_ptr     = pv->yyssa_ptr;
-	yyss          = pv->yyss;
-	yyssp         = pv->yyssp;
+	yyssa_ptr = pv->yyssa_ptr;
+	yyss = pv->yyss;
+	yyssp = pv->yyssp;
 
-	yyvs          = pv->yyvs;
-	yyvsp	      = pv->yyvsp;
+	yyvs = pv->yyvs;
+	yyvsp = pv->yyvsp;
 
 	]b4_locations_if([[  /* The location stack.  */
-	yyls	      = pv->yyls;
-	yylsp         = pv->yylsp;
+	yyls = pv->yyls;
+	yylsp = pv->yylsp;
 
 	yyerror_range_ptr = pv->yyerror_range_ptr;]])[
 
-        yystacksize   = pv->yystacksize;
-	yylen         = pv->yylen;
-	yyval         = pv->yyval;
+	yystacksize = pv->yystacksize;
+	yylen = pv->yylen;
+	yyval = pv->yyval;
 	]b4_locations_if([yyloc = pv->yyloc;])[
-      if (pv->yynew == 0) 
+      if (pv->yynew == 0)
       {
 	goto gottoken;
       }
@@ -1382,46 +1379,46 @@ yybackup:
   if (yychar == YYEMPTY)
     {
       ]b4_push_if([
-        YYDPRINTF ((stderr, "Return for a new token:\n"));
-        yyresult= 4;
-        /* Initialize the locals to the current context. */
-	pv->yychar	      = yychar;
-	pv->yylval	      = yylval;
-	pv->yynerrs	      = yynerrs;
+	YYDPRINTF ((stderr, "Return for a new token:\n"));
+	yyresult = YYPUSH_MORE;
+	/* Initialize the locals to the current context. */
+	pv->yychar = yychar;
+	pv->yylval = yylval;
+	pv->yynerrs = yynerrs;
 	]b4_locations_if([
-	pv->yylloc	      = yylloc;])[
+	pv->yylloc = yylloc;])[
 
-        pv->yystate	      = yystate;
-	pv->yyn		      = yyn;
-	pv->yyresult	      = yyresult;
-	pv->yyerrstatus	      = yyerrstatus;
-	pv->yytoken	      = yytoken;
+	pv->yystate = yystate;
+	pv->yyn = yyn;
+	pv->yyresult = yyresult;
+	pv->yyerrstatus = yyerrstatus;
+	pv->yytoken = yytoken;
 #if YYERROR_VERBOSE
-	pv->yymsgbuf_ptr      = yymsgbuf_ptr;
-	pv->yymsg	      = yymsg;;
-	pv->yymsg_alloc	      = yymsg_alloc;
+	pv->yymsgbuf_ptr = yymsgbuf_ptr;
+	pv->yymsg = yymsg;;
+	pv->yymsg_alloc = yymsg_alloc;
 #endif
-	pv->yyssa_ptr         = yyssa_ptr;
-	pv->yyss	      = yyss;
-	pv->yyssp	      = yyssp;
+	pv->yyssa_ptr = yyssa_ptr;
+	pv->yyss = yyss;
+	pv->yyssp = yyssp;
 
-	pv->yyvs	      = yyvs;
-	pv->yyvsp	      = yyvsp;
+	pv->yyvs = yyvs;
+	pv->yyvsp = yyvsp;
 
 	]b4_locations_if([[  /* The location stack.  */
-	pv->yyls	      = yyls;
-	pv->yylsp	      = yylsp;
+	pv->yyls = yyls;
+	pv->yylsp = yylsp;
 	pv->yyerror_range_ptr = yyerror_range_ptr;]])[
 
-        pv->yystacksize	      = yystacksize;
-	pv->yylen	      = yylen;
-	pv->yyval	      = yyval;
+	pv->yystacksize = yystacksize;
+	pv->yylen = yylen;
+	pv->yyval = yyval;
 	]b4_locations_if([pv->yyloc = yyloc;])[
-        return yyresult;
+	return yyresult;
 gottoken:
-        YYDPRINTF((stderr, "Reading a token: "));],[
+	YYDPRINTF((stderr, "Reading a token: "));],[
 	YYDPRINTF ((stderr, "Reading a token: "));
-        yychar = YYLEX;])[
+	yychar = YYLEX;])[
     }
 
   if (yychar <= YYEOF)
@@ -1781,7 +1778,7 @@ typedef struct YYLTYPE
 #endif
 
 ]b4_push_if([struct ]b4_prefix[pvars;
-#define YYPUSH_MORE 4])[
+enum { YYPUSH_MORE = 4 };])[
 ]b4_pure_if([],
 	   [extern YYLTYPE b4_prefix[]lloc;])
 )dnl b4_locations_if
