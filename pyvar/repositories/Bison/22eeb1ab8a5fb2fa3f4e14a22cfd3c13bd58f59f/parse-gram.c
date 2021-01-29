@@ -1018,13 +1018,13 @@ yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
 # endif /* !defined YY_LOCATION_PRINT */
 
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
+# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
 do {                                                                      \
   if (yydebug)                                                            \
     {                                                                     \
       YYFPRINTF (stderr, "%s ", Title);                                   \
       yy_symbol_print (stderr,                                            \
-                  Type, Value, Location); \
+                  Kind, Value, Location); \
       YYFPRINTF (stderr, "\n");                                           \
     }                                                                     \
 } while (0)
@@ -1318,7 +1318,7 @@ do {                                    \
 int yydebug;
 #else /* !GRAM_DEBUG */
 # define YYDPRINTF(Args) ((void) 0)
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
+# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
 #endif /* !GRAM_DEBUG */
