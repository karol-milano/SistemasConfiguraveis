@@ -1064,8 +1064,8 @@ b4_c_function_def([yyparse], [int], b4_parse_param)
 ]b4_locations_if([[  yylsp = yyls;
 #if YYLTYPE_IS_TRIVIAL
   /* Initialize the default location before parsing starts.  */
-  yylloc.first_line   = yylloc.last_line   = 1;
-  yylloc.first_column = yylloc.last_column = 0;
+  yylloc.first_line   = yylloc.last_line   = ]b4_location_initial_line[;
+  yylloc.first_column = yylloc.last_column = ]b4_location_initial_column[;
 #endif
 ]])
 m4_ifdef([b4_initial_action], [
