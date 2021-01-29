@@ -196,11 +196,12 @@ b4_percent_code_get([[top]])[
 #define yyparse ]b4_prefix[parse
 #define yylex   ]b4_prefix[lex
 #define yyerror ]b4_prefix[error
+#define yydebug ]b4_prefix[debug
+]]b4_pure_if([], [[
 #define yylval  ]b4_prefix[lval
 #define yychar  ]b4_prefix[char
-#define yydebug ]b4_prefix[debug
 #define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
-#define yylloc  ]b4_prefix[lloc]])])[
+#define yylloc  ]b4_prefix[lloc]])]))[
 
 /* First part of user declarations.  */
 ]b4_user_pre_prologue[
@@ -2543,6 +2544,23 @@ yypdumpstack (yyGLRStack* yystackp)
   YYFPRINTF (stderr, "\n");
 }
 #endif
+
+#undef yylval
+#undef yychar
+#undef yynerrs]b4_locations_if([
+#undef yylloc])
+
+m4_if(b4_prefix, [yy], [],
+[[/* Substitute the variable and function names.  */
+#define yyparse ]b4_prefix[parse
+#define yylex   ]b4_prefix[lex
+#define yyerror ]b4_prefix[error
+#define yylval  ]b4_prefix[lval
+#define yychar  ]b4_prefix[char
+#define yydebug ]b4_prefix[debug
+#define yynerrs ]b4_prefix[nerrs]b4_locations_if([[
+#define yylloc  ]b4_prefix[lloc]])])[
+
 ]b4_epilogue[]dnl
 b4_output_end()
 
