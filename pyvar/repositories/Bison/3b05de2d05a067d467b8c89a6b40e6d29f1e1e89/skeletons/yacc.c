@@ -746,6 +746,9 @@ enum { YYENOMEM = -2 };
       }                                                           \
   while (0)
 
+/* Backward compatibility with an undocumented macro.
+   Use ]b4_symbol(1, id)[ or ]b4_symbol(2, id)[. */
+#define YYERRCODE ]b4_symbol(2, id)[
 ]b4_locations_if([[
 ]b4_yylloc_default_define[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
