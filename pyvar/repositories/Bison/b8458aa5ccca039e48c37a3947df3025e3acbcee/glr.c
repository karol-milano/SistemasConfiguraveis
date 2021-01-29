@@ -427,9 +427,9 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)			\
-   ((yyCurrent).first_line = YYRHSLOC(yyRhs, 1).first_line,	\
+   ((yyCurrent).first_line   = YYRHSLOC(yyRhs, 1).first_line,	\
     (yyCurrent).first_column = YYRHSLOC(yyRhs, 1).first_column,	\
-    (yyCurrent).last_line = YYRHSLOC(yyRhs, YYN).last_line,	\
+    (yyCurrent).last_line    = YYRHSLOC(yyRhs, YYN).last_line,	\
     (yyCurrent).last_column  = YYRHSLOC(yyRhs, YYN).last_column)
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
@@ -720,7 +720,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   if (yyrhslen == 0)
     {
       *yyvalp = yyval_default;
-      *yylocp = yyloc_default;
+      *yylocp = yyvsp[0].yystate.yyloc;
     }
   else
     {
@@ -1825,7 +1825,24 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   if (setjmp (yystack.yyexception_buffer) != 0)
     goto yyDone;
 
-  yyglrShift (&yystack, 0, 0, 0, yyval_default, &yyloc_default]b4_user_args[);
+  yylval = yyval_default;
+]b4_location_if([
+#if YYLTYPE_IS_TRIVIAL
+  yylloc.first_line   = yylloc.last_line   = 1;
+  yylloc.first_column = yylloc.last_column = 0;
+#endif
+])
+m4_ifdef([b4_initial_action], [
+m4_pushdef([b4_at_dollar],     [(yylval)])dnl
+m4_pushdef([b4_dollar_dollar], [(yylloc)])dnl
+  /* User initialization code. */
+  b4_initial_action
+m4_popdef([b4_dollar_dollar])dnl
+m4_popdef([b4_at_dollar])dnl
+/* Line __line__ of glr.c.  */
+b4_syncline([@oline@], [@ofile@])])dnl
+[
+  yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc]b4_user_args[);
   yytoken = YYEMPTY;
   yyposn = 0;
 
