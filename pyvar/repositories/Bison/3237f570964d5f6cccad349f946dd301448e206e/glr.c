@@ -475,28 +475,10 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 #define YYTERROR 1
 
 ]b4_locations_if([[
-#ifndef YYLLOC_DEFAULT
 ]b4_yylloc_default_define[
 # define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
-
-/* YY_LOCATION_PRINT -- Print the location on the stream.
-   This macro was not mandated originally: define only if we know
-   we won't break user code: when these are the locations we know.  */
-
-# define YY_LOCATION_PRINT(File, Loc)                   \
-    fprintf (File, "%d.%d-%d.%d",                       \
-             (Loc).first_line, (Loc).first_column,      \
-             (Loc).last_line,  (Loc).last_column)
-#endif
-]],[
-#ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N) ((void) 0)
-#endif
-])[
-
-#ifndef YY_LOCATION_PRINT
-# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
-#endif
+]])[
+]b4_yy_location_print_define[
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 #define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
