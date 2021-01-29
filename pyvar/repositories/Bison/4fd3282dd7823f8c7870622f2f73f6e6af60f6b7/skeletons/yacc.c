@@ -178,7 +178,8 @@ int yynerrs;]])])
 # ---------------------------------
 # Declare all the variables that are needed to maintain the parser state
 # between calls to yypush_parse.
-m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
+m4_define([b4_declare_parser_state_variables],
+[b4_pure_if([[
     /* Number of syntax errors so far.  */
     int yynerrs;
 ]])[
@@ -1414,11 +1415,10 @@ yypull_parse (yypstate *yyps]b4_user_formals[)
         }
     }
   int yystatus;
-  do {]b4_pure_if([[
-    YYSTYPE yylval;
+  do {
+]b4_pure_if([[    YYSTYPE yylval;
     int ]])[yychar = ]b4_lex[;
-    yystatus =
-      yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
+    yystatus = yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
   if (!yyps)
     yypstate_delete (yyps_local);
