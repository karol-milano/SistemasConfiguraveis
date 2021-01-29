@@ -1191,9 +1191,9 @@ b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
   int yytoken;
   /* The variables used to return semantic value and location from the
      action routines.  */
-  YYSTYPE yyval;
-]b4_locations_if([[  YYLTYPE yyloc;
-]])[
+  YYSTYPE yyval;]b4_locations_if([[
+  YYLTYPE yyloc;]])[
+
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
@@ -1205,19 +1205,18 @@ b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
 
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
-  int yylen = 0;
-]b4_push_if([[
+  int yylen = 0;]b4_push_if([[
+
   if (!yyps->yynew)
     {
       yyn = yypact[yystate];
       goto yyread_pushed_token;
-    }
-]])[
+    }]])[
+
   yytoken = 0;
   yyss = yyssa;
-  yyvs = yyvsa;
-]b4_locations_if([[  yyls = yylsa;
-]])[
+  yyvs = yyvsa;]b4_locations_if([[
+  yyls = yylsa;]])[
   yystacksize = YYINITDEPTH;
 
   YYDPRINTF ((stderr, "Starting parse\n"));
@@ -1354,33 +1353,29 @@ yybackup:
 
   /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
-    {
-]b4_push_if([[      if (!yyps->yynew)
-        {
-]b4_use_push_for_pull_if([],
-[[          YYDPRINTF ((stderr, "Return for a new token:\n"));
-]])[          yyresult = YYPUSH_MORE;
+    {]b4_push_if([[
+      if (!yyps->yynew)
+        {]b4_use_push_for_pull_if([], [[
+          YYDPRINTF ((stderr, "Return for a new token:\n"));]])[
+          yyresult = YYPUSH_MORE;
           goto yypushreturn;
         }
-      yyps->yynew = 0;
-]b4_pure_if([], [[
+      yyps->yynew = 0;]b4_pure_if([], [[
       /* Restoring the pushed token is only necessary for the first
          yypush_parse invocation since subsequent invocations don't overwrite
          it before jumping to yyread_pushed_token.  */
       yychar = yypushed_char;
-      yylval = yypushed_val;
-      ]b4_locations_if([[yylloc = yypushed_loc;
-]])])[
-yyread_pushed_token:
-]])[      YYDPRINTF ((stderr, "Reading a token: "));
-]b4_push_if([b4_pure_if([[      yychar = yypushed_char;
+      yylval = yypushed_val;]b4_locations_if([[
+      yylloc = yypushed_loc;]])])[
+yyread_pushed_token:]])[
+      YYDPRINTF ((stderr, "Reading a token: "));]b4_push_if([b4_pure_if([[
+      yychar = yypushed_char;
       if (yypushed_val)
-        yylval = *yypushed_val;
-]b4_locations_if([[      if (yypushed_loc)
-        yylloc = *yypushed_loc;
-]])])],
-[[      yychar = YYLEX;
-]])[    }
+        yylval = *yypushed_val;]b4_locations_if([[
+      if (yypushed_loc)
+        yylloc = *yypushed_loc;]])])], [[
+      yychar = YYLEX;]])[
+    }
 
   if (yychar <= YYEOF)
     {
