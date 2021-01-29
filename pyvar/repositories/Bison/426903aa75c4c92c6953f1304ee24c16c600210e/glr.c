@@ -467,34 +467,13 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
   ]b4_stos[
 };
 
-
 /* Error token number */
 #define YYTERROR 1
 
-/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
-   If N is 0, then set CURRENT to the empty location which ends
-   the previous symbol: RHS[0] (always defined).  */
-
 ]b4_locations_if([[
-#define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
-    do                                                                  \
-      if (YYID (N))                                                     \
-        {                                                               \
-          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
-          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
-          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
-          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
-        }                                                               \
-      else                                                              \
-        {                                                               \
-          (Current).first_line   = (Current).last_line   =              \
-            YYRHSLOC (Rhs, 0).last_line;                                \
-          (Current).first_column = (Current).last_column =              \
-            YYRHSLOC (Rhs, 0).last_column;                              \
-        }                                                               \
-    while (YYID (0))
+]b4_yylloc_default_define[
+# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
