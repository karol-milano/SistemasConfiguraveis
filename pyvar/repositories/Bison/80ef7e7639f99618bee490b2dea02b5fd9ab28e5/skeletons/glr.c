@@ -778,11 +778,12 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 #if YY_EXCEPTIONS
         }
       catch (const ]b4_namespace_ref[::]b4_parser_class[::syntax_error& yyexc)
-        {]b4_locations_if([
+        {
+          YYDPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
           yylloc = yyexc.location;])[
           yyerror (]b4_lyyerror_args[yyexc.what ());
-          // Map to the undef token.
-          *yycharp = YYMAXUTOK + 1;
+          // Leave yytoken/yychar to YYEMPTY.
+          return YYEMPTY;
         }
 #endif // YY_EXCEPTIONS]], [[
       *yycharp = ]b4_lex[;]])[
@@ -871,7 +872,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 #if YY_EXCEPTIONS
   }
   catch (const syntax_error& yyexc)
-    {]b4_locations_if([
+    {
+      YYDPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));]b4_locations_if([
       *yylocp = yyexc.location;])[
       yyerror (]b4_yyerror_args[yyexc.what ());
       YYERROR;
@@ -2353,7 +2355,10 @@ b4_dollar_popdef])[]dnl
               else if (yyisErrorAction (yyaction))
                 {]b4_locations_if([[
                   yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-                  yyreportSyntaxError (&yystack]b4_user_args[);
+                  /* If yylex returned no token (YYEMPTY), it already
+                     issued an error message.  */
+                  if (yytoken != YYEMPTY)
+                    yyreportSyntaxError (&yystack]b4_user_args[);
                   goto yyuser_error;
                 }
               else
