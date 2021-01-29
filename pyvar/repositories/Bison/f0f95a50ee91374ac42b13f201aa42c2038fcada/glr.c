@@ -396,7 +396,6 @@ dnl We probably ought to introduce a type for confl.
 ]b4_yylloc_default_define[
 # define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
 ]])[
-]b4_yy_location_print_define[
 
 ]b4_pure_if(
 [
@@ -437,6 +436,8 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 #  define YYFPRINTF fprintf
 # endif
 
+]b4_yy_location_print_define[
+
 # define YYDPRINTF(Args)                        \
   do {                                          \
     if (yydebug)                                \
