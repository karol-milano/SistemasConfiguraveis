@@ -334,10 +334,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 #define YYMAXLEFT ]b4_max_left_semantic_context[
 
 /* YYMAXUTOK -- Last valid token number (for yychar).  */
-#define YYMAXUTOK   ]b4_user_token_number_max[]b4_glr_cc_if([[
-/* YYFAULTYTOK -- Token number (for yychar) that denotes a
-   syntax_error thrown from the scanner.  */
-#define YYFAULTYTOK (YYMAXUTOK + 1)]])[
+#define YYMAXUTOK   ]b4_user_token_number_max[
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
@@ -830,7 +827,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
           // Map errors caught in the scanner to the undefined token,
           // so that error handling is started.  However, record this
           // with this special value of yychar.
-          *yycharp = YYFAULTYTOK;
+          *yycharp = ]b4_symbol(1, id)[;
         }
 #endif // YY_EXCEPTIONS]], [[
       *yycharp = ]b4_lex[;]])[
@@ -1035,8 +1032,14 @@ static inline int
 yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
-  if (yyisDefaultedState (yystate)
-      || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
+  if (yytoken == ]b4_symbol(1, kind)[)
+    {
+      // This is the error token.
+      *yyconflicts = yyconfl;
+      return 0;
+    }
+  else if (yyisDefaultedState (yystate)
+           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
     {
       *yyconflicts = yyconfl;
       return -yydefact[yystate];
@@ -2486,12 +2489,11 @@ b4_dollar_popdef])[]dnl
                 }
               else if (yyisErrorAction (yyaction))
                 {]b4_locations_if([[
-                  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[]b4_glr_cc_if([[
-                  /* Don't issue an error message again for exceptions
-                     thrown from the scanner.  */
-                  if (yychar != YYFAULTYTOK)
-  ]], [[
-]])[                  yyreportSyntaxError (&yystack]b4_user_args[);
+                  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                  /* Issue an error message unless the scanner already
+                     did. */
+                  if (yychar != ]b4_symbol(1, id)[)
+                    yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
               else
