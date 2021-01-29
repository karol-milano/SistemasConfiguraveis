@@ -346,11 +346,12 @@ m4_if(b4_api_prefix, [yy], [],
 #define yypstate        ]b4_prefix[pstate]])[
 #define yylex           ]b4_prefix[lex
 #define yyerror         ]b4_prefix[error
-#define yylval          ]b4_prefix[lval
-#define yychar          ]b4_prefix[char
 #define yydebug         ]b4_prefix[debug
-#define yynerrs         ]b4_prefix[nerrs]b4_locations_if([[
-#define yylloc          ]b4_prefix[lloc]])])[
+#define yynerrs         ]b4_prefix[nerrs
+]]b4_pure_if([], [[
+#define yylval          ]b4_prefix[lval
+#define yychar          ]b4_prefix[char]b4_locations_if([[
+#define yylloc          ]b4_prefix[lloc]])]))[
 
 /* Copy the first part of user declarations.  */
 ]b4_user_pre_prologue[
