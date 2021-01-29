@@ -624,23 +624,23 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
-#define YYBACKUP(Token, Value)                                  \
-do                                                              \
-  if (yychar == YYEMPTY)                                        \
-    {                                                           \
-      yychar = (Token);                                         \
-      yylval = (Value);                                         \
-      YYPOPSTACK (yylen);                                       \
-      yystate = *yyssp;                                         \]b4_lac_if([[
-      YY_LAC_DISCARD ("YYBACKUP");                              \]])[
-      goto yybackup;                                            \
-    }                                                           \
-  else                                                          \
-    {                                                           \
-      yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
-      YYERROR;                                                  \
-    }                                                           \
-while (0)
+#define YYBACKUP(Token, Value)                                    \
+  do                                                              \
+    if (yychar == YYEMPTY)                                        \
+      {                                                           \
+        yychar = (Token);                                         \
+        yylval = (Value);                                         \
+        YYPOPSTACK (yylen);                                       \
+        yystate = *yyssp;                                         \]b4_lac_if([[
+        YY_LAC_DISCARD ("YYBACKUP");                              \]])[
+        goto yybackup;                                            \
+      }                                                           \
+    else                                                          \
+      {                                                           \
+        yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
+        YYERROR;                                                  \
+      }                                                           \
+  while (0)
 
 /* Error token number */
 #define YYTERROR        1
@@ -1436,15 +1436,20 @@ b4_locations_if([[  yylsp[0] = ]b4_push_if([b4_pure_if([*])yypushed_loc], [yyllo
 ]])dnl
 [  goto yysetstate;
 
+
 /*------------------------------------------------------------.
-| yynewstate -- Push a new state, which is found in yystate.  |
+| yynewstate -- push a new state, which is found in yystate.  |
 `------------------------------------------------------------*/
- yynewstate:
+yynewstate:
   /* In all cases, when you get here, the value and location stacks
      have just been pushed.  So pushing a state here evens the stacks.  */
   yyssp++;
 
- yysetstate:
+
+/*--------------------------------------------------------------------.
+| yynewstate -- set current state (the top of the stack) to yystate.  |
+`--------------------------------------------------------------------*/
+yysetstate:
   *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
@@ -1519,11 +1524,11 @@ b4_locations_if([[  yylsp[0] = ]b4_push_if([b4_pure_if([*])yypushed_loc], [yyllo
 
   goto yybackup;
 
+
 /*-----------.
 | yybackup.  |
 `-----------*/
 yybackup:
-
   /* Do appropriate processing given the current state.  Read a
      lookahead token if we need one and don't already have one.  */
 
@@ -1621,7 +1626,7 @@ yydefault:
 
 
 /*-----------------------------.
-| yyreduce -- Do a reduction.  |
+| yyreduce -- do a reduction.  |
 `-----------------------------*/
 yyreduce:
   /* yyn is the number of a rule to reduce with.  */
@@ -1772,7 +1777,6 @@ yyerrlab:
 | yyerrorlab -- error raised explicitly by YYERROR.  |
 `---------------------------------------------------*/
 yyerrorlab:
-
   /* Pacify compilers like GCC when the user code never invokes
      YYERROR and the label yyerrorlab therefore never appears in user
      code.  */
@@ -1848,6 +1852,7 @@ yyacceptlab:
   yyresult = 0;
   goto yyreturn;
 
+
 /*-----------------------------------.
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
@@ -1855,6 +1860,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
+
 #if ]b4_lac_if([[1]], [[!defined yyoverflow || YYERROR_VERBOSE]])[
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
@@ -1865,6 +1871,10 @@ yyexhaustedlab:
   /* Fall through.  */
 #endif
 
+
+/*-----------------------------------------------------.
+| yyreturn -- parsing is finished, return the result.  |
+`-----------------------------------------------------*/
 yyreturn:
   if (yychar != YYEMPTY)
     {
@@ -1892,6 +1902,10 @@ yyreturn:
     YYSTACK_FREE (yyes);]])b4_push_if([[
   yyps->yynew = 1;
 
+
+/*-----------------------------------------.
+| yypushreturn -- ask for the next token.  |
+`-----------------------------------------*/
 yypushreturn:]])[
 #if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
