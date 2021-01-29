@@ -327,7 +327,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 #define YYNNTS  ]b4_nterms_number[
 /* YYNRULES -- Number of rules.  */
 #define YYNRULES  ]b4_rules_number[
-/* YYNRULES -- Number of states.  */
+/* YYNSTATES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
 /* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
 #define YYMAXRHS ]b4_r2_max[
@@ -335,8 +335,14 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
    accessed by $0, $-1, etc., in any rule.  */
 #define YYMAXLEFT ]b4_max_left_semantic_context[
 
+/* YYMAXUTOK -- Last valid token number (for yychar).  */
+#define YYMAXUTOK   ]b4_user_token_number_max[]b4_glr_cc_if([[
+/* YYFAULTYTOK -- Token number (for yychar) that denotes a
+   syntax_error thrown from the scanner.  */
+#define YYFAULTYTOK (YYMAXUTOK + 1)]])[
+/* YYUNDEFTOK -- Symbol number (for yytoken) that denotes an unknown
+   token.  */
 #define YYUNDEFTOK  ]b4_undef_token_number[
-#define YYMAXUTOK   ]b4_user_token_number_max[
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
@@ -782,8 +788,10 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
           YYDPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
           yylloc = yyexc.location;])[
           yyerror (]b4_lyyerror_args[yyexc.what ());
-          // Leave yytoken/yychar to YYEMPTY.
-          return YYEMPTY;
+          // Map errors caught in the scanner to the undefined token
+          // (YYUNDEFTOK), so that error handling is started.
+          // However, record this with this special value of yychar.
+          *yycharp = YYFAULTYTOK;
         }
 #endif // YY_EXCEPTIONS]], [[
       *yycharp = ]b4_lex[;]])[
@@ -2352,11 +2360,11 @@ b4_dollar_popdef])[]dnl
                 }
               else if (yyisErrorAction (yyaction))
                 {]b4_locations_if([[
-                  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-                  /* If yylex returned no token (YYEMPTY), it already
-                     issued an error message.  */
-                  if (yytoken != YYEMPTY)
-                    yyreportSyntaxError (&yystack]b4_user_args[);
+                  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[]b4_glr_cc_if([[
+                  /* Don't issue an error message again for exceptions
+                     thrown from the scanner.  */
+                  if (yychar != YYFAULTYTOK)
+  ]])[                  yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
               else
