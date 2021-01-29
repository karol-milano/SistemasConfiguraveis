@@ -777,7 +777,7 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
           *yycharp = ]b4_lex[;
 #if YY_EXCEPTIONS
         }
-      catch (const ]b4_namespace_ref[::]b4_parser_class_name[::syntax_error& yyexc)
+      catch (const ]b4_namespace_ref[::]b4_parser_class[::syntax_error& yyexc)
         {]b4_locations_if([
           yylloc = yyexc.location;])[
           yyerror (]b4_lyyerror_args[yyexc.what ());
@@ -859,7 +859,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
 ]])[]b4_glr_cc_if([[
 #if YY_EXCEPTIONS
-  typedef ]b4_namespace_ref[::]b4_parser_class_name[::syntax_error syntax_error;
+  typedef ]b4_namespace_ref[::]b4_parser_class[::syntax_error syntax_error;
   try
   {
 #endif // YY_EXCEPTIONS]])[
