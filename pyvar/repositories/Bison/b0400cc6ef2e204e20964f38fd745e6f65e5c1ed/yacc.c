@@ -133,23 +133,6 @@ m4_define([b4_rhs_location],
 ## Defining symbol actions, e.g., printers and destructors.  ##
 ## --------------------------------------------------------- ##
 
-# b4_symbol_actions(FILENAME, LINENO,
-#                   SYMBOL-TAG, SYMBOL-NUM,
-#                   SYMBOL-ACTION, SYMBOL-TYPENAME)
-# -------------------------------------------------
-m4_define([b4_symbol_actions],
-[m4_pushdef([b4_dollar_dollar], [yyvalue.$6])dnl
-m4_pushdef([b4_at_dollar], [yylocation])dnl
-      case $4: /* $3 */
-b4_syncline([$2], [$1])
-        $5;
-b4_syncline([@oline@], [@ofile@])
-        break;
-m4_popdef([b4_at_dollar])dnl
-m4_popdef([b4_dollar_dollar])dnl
-])
-
-
 # We do want M4 expansion after # for CPP macros.
 m4_changecom()
 m4_divert(0)dnl
@@ -348,15 +331,16 @@ b4_location_if(
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  b4_undef_token_number
-#define YYMAXUTOK   b4_user_token_number_max
+#define YYMAXUTOK   b4_user_token_number_max[
 
-#define YYTRANSLATE(X) \
-  ((unsigned)(X) <= YYMAXUTOK ? yytranslate[[X]] : YYUNDEFTOK)
+#define YYTRANSLATE(YYX) 						\
+  ((YYX <= 0) ? YYEOF :							\
+   (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
-/* YYTRANSLATE[[YYLEX]] -- Bison symbol number corresponding to YYLEX.  */
-static const b4_int_type_for([b4_translate]) yytranslate[[]] =
+/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
+static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
-  b4_translate
+  ]b4_translate
 };
 
 #if YYDEBUG
@@ -477,7 +461,7 @@ static const b4_int_type_for([b4_stos]) yystos[[]] =
 #endif
 
 #define yyerrok		(yyerrstatus = 0)
-#define yyclearin	(yychar = YYEMPTY)
+#define yyclearin	(yytoken = YYEMPTY)
 #define YYEMPTY		-2
 #define YYEOF		0
 
@@ -495,11 +479,11 @@ static const b4_int_type_for([b4_stos]) yystos[[]] =
 
 #define YYBACKUP(Token, Value)					\
 do								\
-  if (yychar == YYEMPTY && yylen == 1)				\
+  if (yytoken == YYEMPTY && yylen == 1)				\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
-      yychar1 = YYTRANSLATE (yychar);				\
+      yytoken = YYTRANSLATE (yychar);				\
       YYPOPSTACK;						\
       goto yybackup;						\
     }								\
@@ -672,30 +656,7 @@ m4_map([b4_symbol_actions], m4_defn([b4_symbol_printers]))dnl
 }
 #endif /* YYDEBUG. */
 
-
-/*-----------------------------------------------.
-| Release the memory associated to this symbol.  |
-`-----------------------------------------------*/
-
-b4_c_function_def([yydestruct],
-	          [static void],
-	          [[int yytype],         [yytype]],
-	          [[YYSTYPE yyvalue],    [yyvalue]]b4_location_if([,
-	          [[YYLTYPE yylocation], [yylocation]]]))
-{
-  /* Pacify ``unused variable'' warnings.  */
-  (void) yyvalue;
-b4_location_if([  (void) yylocation;
-])dnl
-
-  switch (yytype)
-    {
-m4_map([b4_symbol_actions], m4_defn([b4_symbol_destructors]))dnl
-      default:
-        break;
-    }
-}
-
+b4_yydestruct_generate([b4_c_function_def])
 
 
 /* Prevent warnings from -Wmissing-prototypes.  */
@@ -756,7 +717,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   /* Number of tokens to shift before error messages enabled.  */
   int yyerrstatus;
   /* Lookahead token as an internal (translated) token number.  */
-  int yychar1 = 0;
+  int yytoken = 0;
 
   /* Three stacks and their tools:
      `yyss': related to states,
@@ -800,7 +761,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   yystate = 0;
   yyerrstatus = 0;
   yynerrs = 0;
-  yychar = YYEMPTY;		/* Cause a token to be read.  */
+  yychar = yytoken = YYEMPTY;		/* Cause a token to be read.  */
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
@@ -910,39 +871,31 @@ yybackup:
 
   /* Not known => get a lookahead token if don't already have one.  */
 
-  /* yychar is either YYEMPTY or YYEOF
-     or a valid token in external form.  */
-
-  if (yychar == YYEMPTY)
+  /* YYTOKEN is either YYEMPTY or YYEOF or a valid token.  */
+  if (yytoken == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
       yychar = YYLEX;
+      yytoken = YYTRANSLATE (yychar);
     }
 
-  /* Convert token to internal form (in yychar1) for indexing tables with.  */
-
-  if (yychar <= 0)		/* This means end of input.  */
+  if (yytoken == YYEOF)
     {
-      yychar1 = 0;
-      yychar = YYEOF;		/* Don't call YYLEX any more.  */
-
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
     {
-      yychar1 = YYTRANSLATE (yychar);
-
       /* We have to keep this `#if YYDEBUG', since we use variables
 	 which are defined only if `YYDEBUG' is set.  */
       YYDPRINTF ((stderr, "Next token is "));
-      YYDSYMPRINT ((stderr, yychar1, yylval]b4_location_if([, yyloc])[));
+      YYDSYMPRINT ((stderr, yytoken, yylval]b4_location_if([, yyloc])[));
       YYDPRINTF ((stderr, "\n"));
     }
 
-  /* If the proper action on seeing token YYCHAR1 is to reduce or to
+  /* If the proper action on seeing token YYTOKEN is to reduce or to
      detect an error, take that action.  */
-  yyn += yychar1;
-  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yychar1)
+  yyn += yytoken;
+  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
     goto yydefault;
   yyn = yytable[yyn];
   if (yyn <= 0)
@@ -958,11 +911,11 @@ yybackup:
 
   /* Shift the lookahead token.  */
   YYDPRINTF ((stderr, "Shifting token %d (%s), ",
-	      yychar, yytname[yychar1]));
+	      yytoken, yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
-  if (yychar != YYEOF)
-    yychar = YYEMPTY;
+  if (yytoken != YYEOF)
+    yytoken = YYEMPTY;
 
   *++yyvsp = yylval;
 ]b4_location_if([  *++yylsp = yylloc;])[
@@ -1134,7 +1087,7 @@ yyerrlab1:
 	 error, discard it.  */
 
       /* Return failure if at end of input.  */
-      if (yychar == YYEOF)
+      if (yytoken == YYEOF)
         {
 	  /* Pop the error token.  */
           YYPOPSTACK;
@@ -1153,9 +1106,9 @@ yyerrlab1:
         }
 
       YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
-		  yychar, yytname[yychar1]));
-      yydestruct (yychar1, yylval]b4_location_if([, yylloc])[);
-      yychar = YYEMPTY;
+		  yytoken, yytname[yytoken]));
+      yydestruct (yytoken, yylval]b4_location_if([, yylloc])[);
+      yytoken = YYEMPTY;
     }
 
   /* Else will try to reuse lookahead token after shifting the error
