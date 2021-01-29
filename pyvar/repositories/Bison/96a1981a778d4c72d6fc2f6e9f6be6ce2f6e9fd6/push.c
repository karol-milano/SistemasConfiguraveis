@@ -1017,14 +1017,6 @@ m4_define([b4_declare_yyparse_variables],
     /* Look-ahead token as an internal (translated) token number.  */
     int yytoken;
 
-#if YYERROR_VERBOSE
-    /* Buffer for error messages, and its allocated size.  */
-    char yymsgbuf[128];
-    char *yymsgbuf_ptr;
-    char *yymsg;
-    YYSIZE_T yymsg_alloc;
-#endif
-
     /* Three stacks and their tools:
        `yyss': related to states,
        `yyvs': related to semantic values,
@@ -1070,12 +1062,6 @@ yypvarsinit (void)
   pv->yyerrstatus = 0;
   pv->yytoken = 0;
 
-#if YYERROR_VERBOSE
-  pv->yymsgbuf_ptr = pv->yymsgbuf;
-  pv->yymsg = pv->yymsgbuf;
-  pv->yymsg_alloc = sizeof pv->yymsgbuf;
-#endif
-
   pv->yyssa_ptr = pv->yyssa;
   pv->yyss = pv->yyssa;
   pv->yyvs = pv->yyvsa;
@@ -1153,7 +1139,6 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
-  char *yymsgbuf_ptr = yymsgbuf;
   char *yymsg = yymsgbuf;
   YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
 #endif
@@ -1248,11 +1233,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	yyresult = pv->yyresult;
 	yyerrstatus = pv->yyerrstatus;
 	yytoken = pv->yytoken;
-#if YYERROR_VERBOSE
-	yymsgbuf_ptr = pv->yymsgbuf_ptr;
-	yymsg = pv->yymsg;;
-	yymsg_alloc = pv->yymsg_alloc;
-#endif
+
 	yyssa_ptr = pv->yyssa_ptr;
 	yyss = pv->yyss;
 	yyssp = pv->yyssp;
@@ -1390,14 +1371,9 @@ yybackup:
 
 	pv->yystate = yystate;
 	pv->yyn = yyn;
-	pv->yyresult = yyresult;
 	pv->yyerrstatus = yyerrstatus;
 	pv->yytoken = yytoken;
-#if YYERROR_VERBOSE
-	pv->yymsgbuf_ptr = yymsgbuf_ptr;
-	pv->yymsg = yymsg;;
-	pv->yymsg_alloc = yymsg_alloc;
-#endif
+
 	pv->yyssa_ptr = yyssa_ptr;
 	pv->yyss = yyss;
 	pv->yyssp = yyssp;
@@ -1414,11 +1390,10 @@ yybackup:
 	pv->yylen = yylen;
 	pv->yyval = yyval;
 	]b4_locations_if([pv->yyloc = yyloc;])[
-	return yyresult;
-gottoken:
-	YYDPRINTF((stderr, "Reading a token: "));],[
-	YYDPRINTF ((stderr, "Reading a token: "));
-	yychar = YYLEX;])[
+	goto yypushreturn;
+gottoken:])
+      YYDPRINTF ((stderr, "Reading a token: "));
+      ]b4_push_if([], [yychar = YYLEX;])[
     }
 
   if (yychar <= YYEOF)
@@ -1541,14 +1516,14 @@ yyerrlab:
 	    YYSIZE_T yyalloc = 2 * yysize;
 	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
 	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
-	    if (yymsg != yymsgbuf_ptr)
+	    if (yymsg != yymsgbuf)
 	      YYSTACK_FREE (yymsg);
 	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
 	    if (yymsg)
 	      yymsg_alloc = yyalloc;
 	    else
 	      {
-		yymsg = yymsgbuf_ptr;
+		yymsg = yymsgbuf;
 		yymsg_alloc = sizeof yymsgbuf;
 	      }
 	  }
@@ -1704,13 +1679,14 @@ yyreturn:
   if (yyss != yyssa_ptr)
     YYSTACK_FREE (yyss);
 #endif
+]b4_push_if([yypushreturn:])[
 #if YYERROR_VERBOSE
-  if (yymsg != yymsgbuf_ptr)
+  if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
   ]b4_push_if([pv->yyresult = YYID (yyresult);])[
-    /* Make sure YYID is used.  */
-    return YYID (yyresult);
+  /* Make sure YYID is used.  */
+  return YYID (yyresult);
 ]}
 
 b4_push_if([
