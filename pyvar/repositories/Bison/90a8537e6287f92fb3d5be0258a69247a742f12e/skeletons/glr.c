@@ -23,6 +23,10 @@
 m4_if(b4_skeleton, ["glr.c"],
       [m4_include(b4_skeletonsdir/[c.m4])])
 
+m4_define([b4_glr_cc_if],
+          [m4_if(b4_skeleton, ["glr.cc"], [$1], [$2])])
+
+
 ## ---------------- ##
 ## Default values.  ##
 ## ---------------- ##
@@ -193,7 +197,7 @@ m4_if(b4_skeleton, ["glr.c"],
 # ----------------- #
 
 # glr.cc produces its own header.
-m4_if(b4_skeleton, ["glr.c"],
+b4_glr_cc_if([],
 [b4_defines_if(
 [b4_output_begin([b4_spec_defines_file])
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
@@ -769,8 +773,23 @@ yygetToken (int *yycharp][]b4_pure_if([, yyGLRStack* yystackp])[]b4_user_formals
 ]b4_parse_param_use()dnl
 [  if (*yycharp == YYEMPTY)
     {
-      YYDPRINTF ((stderr, "Reading a token: "));
-      *yycharp = ]b4_lex[;
+      YYDPRINTF ((stderr, "Reading a token: "));]b4_glr_cc_if([[
+#if YY_EXCEPTIONS
+      try
+        {
+#endif // YY_EXCEPTIONS
+          *yycharp = ]b4_lex[;
+#if YY_EXCEPTIONS
+        }
+      catch (const ]b4_namespace_ref[::]b4_parser_class_name[::syntax_error& yyexc)
+        {]b4_locations_if([
+          yylloc = yyexc.location;])[
+          yyerror (]b4_lyyerror_args[yyexc.what ());
+          // Map to the undef token.
+          *yycharp = YYMAXUTOK + 1;
+        }
+#endif // YY_EXCEPTIONS]], [[
+      *yycharp = ]b4_lex[;]])[
     }
   if (*yycharp <= YYEOF)
     {
@@ -842,12 +861,26 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   /* Default location. */
   YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
   yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
-]])[
+]])[]b4_glr_cc_if([[
+#if YY_EXCEPTIONS
+  typedef ]b4_namespace_ref[::]b4_parser_class_name[::syntax_error syntax_error;
+  try
+  {
+#endif // YY_EXCEPTIONS]])[
   switch (yyn)
     {
 ]b4_user_actions[
       default: break;
+    }]b4_glr_cc_if([[
+#if YY_EXCEPTIONS
+  }
+  catch (const syntax_error& yyexc)
+    {]b4_locations_if([
+      *yylocp = yyexc.location;])[
+      yyerror (]b4_yyerror_args[yyexc.what ());
+      YYERROR;
     }
+#endif // YY_EXCEPTIONS]])[
 
   return yyok;
 # undef yyerrok
