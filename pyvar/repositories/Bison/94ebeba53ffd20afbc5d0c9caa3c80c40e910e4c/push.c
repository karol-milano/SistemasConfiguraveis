@@ -226,10 +226,10 @@ enum { YYPUSH_MORE = 4 };
 b4_c_function_decl([[yypstate_delete]], [[void]],
                    [[[yypstate *yyps]], [[yyps]]])
 b4_c_function_decl([[yypush_parse]], [[int]],
-  [[[yypstate *yyps]], [[yyps]]],
+  [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])m4_ifset([b4_parse_param], [,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 #endif
 ]])
@@ -1106,10 +1106,11 @@ b4_push_if(
 `-------------------------*/
 
 ]b4_push_if([
-b4_c_function_def([[yypush_parse]], [[int]], [[[yypstate *yyps]], [[yyps]]], 
+b4_c_function_def([[yypush_parse]], [[int]],
+  [[[yypstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])m4_ifset([b4_parse_param], [,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))], [
 #ifdef YYPARSE_PARAM
 b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
@@ -1118,7 +1119,11 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif])[
 {
   ]b4_pure_if([b4_declare_scanner_communication_variables])
-  b4_push_if([], [b4_declare_parser_state_variables])[
+  b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
+  YYSTYPE yypushed_val = yylval;
+  ]b4_locations_if([[YYLTYPE yypushed_loc = yylloc;
+]])])],
+  [b4_declare_parser_state_variables])[
 
 #if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
@@ -1286,14 +1291,22 @@ yybackup:
           goto yypushreturn;
         }
       yyps->yynew = 0;
-
+]b4_pure_if([], [[
+      /* Restoring the pushed token is only necessary for the first
+         yypush_parse invocation since subsequent invocations don't overwrite
+         it before jumping to yyread_pushed_token.  */
+      yychar = yypushed_char;
+      yylval = yypushed_val;
+      ]b4_locations_if([[yylloc = yypushed_loc;
+]])])[
 yyread_pushed_token:
 ]])[      YYDPRINTF ((stderr, "Reading a token: "));
-]b4_push_if([[      yychar = yypushed_char;
+]b4_push_if([b4_pure_if([[      yychar = yypushed_char;
       if (yypushed_val)
         yylval = *yypushed_val;
 ]b4_locations_if([[      if (yypushed_loc)
-        yylloc = *yypushed_loc;]])],
+        yylloc = *yypushed_loc;
+]])])],
 [[      yychar = YYLEX;
 ]])[    }
 
@@ -1643,10 +1656,10 @@ enum { YYPUSH_MORE = 4 };
 b4_c_function_decl([b4_prefix[pstate_delete]], [[void]],
                    [[b4_prefix[pstate *yyps]], [[yyps]]])
 b4_c_function_decl([b4_prefix[push_parse]], [[int]],
-  [[b4_prefix[pstate *yyps]], [[yyps]]],
+  [[b4_prefix[pstate *yyps]], [[yyps]]]b4_pure_if([,
   [[[int yypushed_char]], [[yypushed_char]]],
   [[[YYSTYPE const *yypushed_val]], [[yypushed_val]]]b4_locations_if([,
-  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])m4_ifset([b4_parse_param], [,
+  [[[YYLTYPE const *yypushed_loc]], [[yypushed_loc]]]])])m4_ifset([b4_parse_param], [,
   b4_parse_param]))[
 #endif
 ]])
