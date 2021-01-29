@@ -743,9 +743,6 @@ enum { YYENOMEM = -2 };
       }                                                           \
   while (0)
 
-/* Error token external number. */
-#define YYERRCODE       ]b4_symbol(1, user_number)[
-
 ]b4_locations_if([[
 ]b4_yylloc_default_define[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
