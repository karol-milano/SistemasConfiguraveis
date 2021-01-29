@@ -346,8 +346,7 @@ static YYSTYPE yyval_default;
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
 #define YYTRANSLATE(YYX)						\
-  ((YYX <= 0) ? YYEOF :							\
-   (unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
@@ -2040,11 +2039,19 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
 	    {
 	      YYDPRINTF ((stderr, "Reading a token: "));
 	      yychar = YYLEX;
+	    }
+
+	  if (yychar <= YYEOF)
+	    {
+	      yychar = yytoken = YYEOF;
+	      YYDPRINTF ((stderr, "Now at end of input.\n"));
+	    }
+	  else
+	    {
 	      yytoken = YYTRANSLATE (yychar);
 	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 	    }
-	  else
-	    yytoken = YYTRANSLATE (yychar);
+
 	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 
 	  while (*yyconflicts != 0)
@@ -2210,8 +2217,16 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
 	  }
 	YYDPRINTF ((stderr, "Reading a token: "));
 	yychar = YYLEX;
-	yytoken = YYTRANSLATE (yychar);
-	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+	if (yychar <= YYEOF)
+	  {
+	    yychar = yytoken = YYEOF;
+	    YYDPRINTF ((stderr, "Now at end of input.\n"));
+	  }
+	else
+	  {
+	    yytoken = YYTRANSLATE (yychar);
+	    YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+	  }
 	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
 	if (yyis_pact_ninf (yyj))
 	  return;
@@ -2363,11 +2378,19 @@ m4_popdef([b4_at_dollar])])dnl
 		{
 		  YYDPRINTF ((stderr, "Reading a token: "));
 		  yychar = YYLEX;
+		}
+
+	      if (yychar <= YYEOF)
+		{
+		  yychar = yytoken = YYEOF;
+		  YYDPRINTF ((stderr, "Now at end of input.\n"));
+		}
+	      else
+		{
 		  yytoken = YYTRANSLATE (yychar);
 		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
 		}
-	      else
-		yytoken = YYTRANSLATE (yychar);
+
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
 		break;
