@@ -227,9 +227,9 @@ b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])
 b4_c_function_decl([[yypush_parse]], [[int]],
   [[[yypstate *yyps]], [[yyps]]],
-  [[[int yynchar]], [[yynchar]]],
-  [[[YYSTYPE const *yynlval]], [[yynlval]]]b4_locations_if([,
-  [[[YYLTYPE const *yynlloc]], [[yynlloc]]]])m4_ifset([b4_parse_param], [,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 #endif
 ]])
@@ -1102,9 +1102,9 @@ b4_push_if(
 
 ]b4_push_if([
 b4_c_function_def([[yypush_parse]], [[int]], [[[yypstate *yyps]], [[yyps]]], 
-  [[[int yynchar]], [[yynchar]]],
-  [[[YYSTYPE const *yynlval]], [[yynlval]]]b4_locations_if([,
-  [[[YYLTYPE const *yynlloc]], [[yynlloc]]]])m4_ifset([b4_parse_param], [,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])m4_ifset([b4_parse_param], [,
   b4_parse_param]))], [
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
@@ -1127,20 +1127,10 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
   /* The number of symbols on the RHS of the reduced rule.
      Keep to zero when no symbol should be popped.  */
   int yylen = 0;
-]b4_push_if([  yychar = yynchar;
-  if (yynlval)
-    yylval = *yynlval;
-]b4_locations_if([  if (yynlloc)
-     yylloc = *yynlloc;])[],[yynerrs = 0;
-  yychar = YYEMPTY; /* Cause a token to be read.  */])[
-
-  ]b4_push_if([
-      if (yyps->yynew == 0)
-      {
-	goto gottoken;
-      }
-      yyps->yynew= 0;])[
-
+]b4_push_if([[
+  if (!yyps->yynew)
+    goto yyread_pushed_token;
+]])[
   yytoken = 0;
   yyss = yyssa;
   yyvs = yyvsa;
@@ -1152,6 +1142,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 
   yystate = 0;
   yyerrstatus = 0;
+]b4_push_if([], [[  yynerrs = 0;]])[
+  yychar = YYEMPTY; /* Cause a token to be read.  */
 
   /* Initialize stack pointers.
      Waste one element of value and location stack
@@ -1170,7 +1162,7 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 m4_ifdef([b4_initial_action], [
 m4_pushdef([b4_at_dollar],     [m4_define([b4_at_dollar_used])yylloc])dnl
 m4_pushdef([b4_dollar_dollar], [m4_define([b4_dollar_dollar_used])yylval])dnl
-  /* User initialization code.  */
+/* User initialization code.  */
 b4_user_initial_action
 m4_popdef([b4_dollar_dollar])dnl
 m4_popdef([b4_at_dollar])])dnl
@@ -1282,14 +1274,23 @@ yybackup:
   /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
   if (yychar == YYEMPTY)
     {
-      ]b4_push_if([
-	YYDPRINTF ((stderr, "Return for a new token:\n"));
-	yyresult = YYPUSH_MORE;
-	goto yypushreturn;
-gottoken:])[
-      YYDPRINTF ((stderr, "Reading a token: "));
-      ]b4_push_if([], [yychar = YYLEX;])[
-    }
+]b4_push_if([[      if (!yyps->yynew)
+        {
+          YYDPRINTF ((stderr, "Return for a new token:\n"));
+          yyresult = YYPUSH_MORE;
+          goto yypushreturn;
+        }
+      yyps->yynew = 0;
+
+yyread_pushed_token:
+]])[      YYDPRINTF ((stderr, "Reading a token: "));
+]b4_push_if([[      yychar = yypushed_char;
+      if (yypushed_val)
+        yylval = *yypushed_val;
+]b4_locations_if([[      if (yypushed_loc)
+        yylloc = *yypushed_loc;]])],
+[[      yychar = YYLEX;
+]])[    }
 
   if (yychar <= YYEOF)
     {
@@ -1640,9 +1641,9 @@ b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *yyps]], [[yyps]]])
 b4_c_function_decl([b4_prefix[push_parse]], [[int]],
   [[b4_prefix[pstate *yyps]], [[yyps]]],
-  [[[int yynchar]], [[yynchar]]],
-  [[[YYSTYPE const *yynlval]], [[yynlval]]]b4_locations_if([,
-  [[[YYLTYPE const *yynlloc]], [[yynlloc]]]])m4_ifset([b4_parse_param], [,
+  [[[int yypushed_char]], [[yypushed_char]]],
+  [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 #endif
 ]])
