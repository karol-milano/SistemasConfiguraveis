@@ -332,7 +332,8 @@ typedef short int yytype_int16;
 
 #if ! defined yyoverflow || YYERROR_VERBOSE
 
-/* The parser invokes alloca or malloc; define the necessary symbols.  */
+]b4_push_if([],
+[[/* The parser invokes alloca or malloc; define the necessary symbols.  */
 
 # ifdef YYSTACK_USE_ALLOCA
 #  if YYSTACK_USE_ALLOCA
@@ -357,7 +358,8 @@ typedef short int yytype_int16;
 #  endif
 # endif
 
-# ifdef YYSTACK_ALLOC
+]])dnl
+[# ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
 #  ifndef YYSTACK_ALLOC_MAXIMUM
@@ -1089,13 +1091,13 @@ b4_push_if(
 ]b4_locations_if([[  YYLTYPE yylloc;
 ]])])[
   if (yyps == 0)
-     yyps_local = yypstate_new ();
-   else
-     yyps_local = yyps;
-   do {
-     yychar = YYLEX;
-     yystatus =
-       yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
+    yyps_local = yypstate_new ();
+  else
+    yyps_local = yyps;
+  do {
+    yychar = YYLEX;
+    yystatus =
+      yypush_parse (yyps_local]b4_pure_if([[, yychar, &yylval]b4_locations_if([[, &yylloc]])])m4_ifset([b4_parse_param], [, b4_c_args(b4_parse_param)])[);
   } while (yystatus == YYPUSH_MORE);
   if (yyps == 0)
     yypstate_delete (yyps_local);
@@ -1149,8 +1151,8 @@ b4_c_function_def([yyparse], [int], [[void *YYPARSE_PARAM], [YYPARSE_PARAM]])
 b4_c_function_def([yyparse], [int], b4_parse_param)
 #endif])[
 {
-  ]b4_pure_if([b4_declare_scanner_communication_variables])
-  b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
+]b4_pure_if([b4_declare_scanner_communication_variables])
+b4_push_if([b4_pure_if([], [[  int yypushed_char = yychar;
   YYSTYPE yypushed_val = yylval;
   ]b4_locations_if([[YYLTYPE yypushed_loc = yylloc;
 ]])])],
