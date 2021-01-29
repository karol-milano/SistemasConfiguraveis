@@ -676,7 +676,6 @@ while (0)
 ]b4_yylloc_default_define[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
 ]])[
-]b4_yy_location_print_define[
 
 /* Enable debugging if requested.  */
 #if ]b4_api_PREFIX[DEBUG
@@ -692,6 +691,8 @@ do {                                            \
     YYFPRINTF Args;                             \
 } while (0)
 
+]b4_yy_location_print_define[
+
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
 do {                                                                      \
   if (yydebug)                                                            \
