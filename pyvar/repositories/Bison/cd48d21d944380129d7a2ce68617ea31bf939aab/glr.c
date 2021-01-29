@@ -2303,8 +2303,8 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
   yylval = yyval_default;
 ]b4_locations_if([
 #if YYLTYPE_IS_TRIVIAL
-  yylloc.first_line   = yylloc.last_line   = 1;
-  yylloc.first_column = yylloc.last_column = 0;
+  yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
+  yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
 #endif
 ])
 m4_ifdef([b4_initial_action], [
