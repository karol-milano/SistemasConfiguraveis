@@ -769,10 +769,9 @@ while (YYID (0))
 #define YYTERROR	1
 #define YYERRCODE	256
 
+]b4_locations_if([[
 ]b4_yylloc_default_define[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
-]b4_locations_if([[
-
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -787,18 +786,14 @@ while (YYID (0))
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
-#endif]], [[
-
-
-/* This macro is provided for backward compatibility. */
-
+#endif]],
+[[/* This macro is provided for backward compatibility. */
 #ifndef YY_LOCATION_PRINT
 # define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 #endif]])[
 
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
-
 #ifdef YYLEX_PARAM
 # define YYLEX yylex (]b4_pure_if([&yylval[]b4_locations_if([, &yylloc]), ])[YYLEX_PARAM)
 #else
