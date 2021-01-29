@@ -911,7 +911,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	   data in use in that stack, in bytes.  This used to be a
 	   conditional around just the two extra args, but that might
 	   be undefined if yyoverflow is a macro.  */
-	yyoverflow (YY_("parser stack overflow"),
+	yyoverflow (YY_("memory exhausted"),
 		    &yyss1, yysize * sizeof (*yyssp),
 		    &yyvs1, yysize * sizeof (*yyvsp),
 ]b4_location_if([		    &yyls1, yysize * sizeof (*yylsp),])[
@@ -922,11 +922,11 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
       }
 #else /* no yyoverflow */
 # ifndef YYSTACK_RELOCATE
-      goto yyoverflowlab;
+      goto yyexhaustedlab;
 # else
       /* Extend the stack our own way.  */
       if (YYMAXDEPTH <= yystacksize)
-	goto yyoverflowlab;
+	goto yyexhaustedlab;
       yystacksize *= 2;
       if (YYMAXDEPTH < yystacksize)
 	yystacksize = YYMAXDEPTH;
@@ -936,7 +936,7 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 	union yyalloc *yyptr =
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
-	  goto yyoverflowlab;
+	  goto yyexhaustedlab;
 	YYSTACK_RELOCATE (yyss);
 	YYSTACK_RELOCATE (yyvs);
 ]b4_location_if([	YYSTACK_RELOCATE (yyls);])[
@@ -1201,7 +1201,10 @@ yyerrlab:
 	      YYSTACK_FREE (yymsg);
 	    }
 	  else
-	    yyerror (]b4_yyerror_args[YY_("syntax error; also memory exhausted"));
+	    {
+	      yyerror (]b4_yyerror_args[YY_("syntax error"));
+	      goto yyexhaustedlab;
+	    }
 	}
       else
 #endif /* YYERROR_VERBOSE */
@@ -1317,11 +1320,11 @@ yyabortlab:
   goto yyreturn;
 
 #ifndef yyoverflow
-/*----------------------------------------------.
-| yyoverflowlab -- parser overflow comes here.  |
-`----------------------------------------------*/
-yyoverflowlab:
-  yyerror (]b4_yyerror_args[YY_("parser stack overflow"));
+/*-------------------------------------------------.
+| yyexhaustedlab -- memory exhaustion comes here.  |
+`-------------------------------------------------*/
+yyexhaustedlab:
+  yyerror (]b4_yyerror_args[YY_("memory exhausted"));
   yyresult = 2;
   /* Fall through.  */
 #endif
