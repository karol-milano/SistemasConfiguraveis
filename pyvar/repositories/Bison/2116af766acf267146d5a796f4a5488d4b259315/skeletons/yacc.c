@@ -764,7 +764,7 @@ do {                                    \
    multiple parsers can coexist.  */
 int yydebug;
 #else /* !]b4_api_PREFIX[DEBUG */
-# define YYDPRINTF(Args)
+# define YYDPRINTF(Args) ((void) 0)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
@@ -914,9 +914,8 @@ do {                                                             \
 do {                                                                     \
   if (yy_lac_established)                                                \
     {                                                                    \
-      if (yydebug)                                                       \
-        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
-                   Event "\n");                                          \
+      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
+                  Event "\n"));                                          \
       yy_lac_established = 0;                                            \
     }                                                                    \
 } while (0)
@@ -1211,10 +1210,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 yyarg[yycount++] = yytname[yyx];
               }
         }]b4_lac_if([[
-# if ]b4_api_PREFIX[DEBUG
-      else if (yydebug)
-        YYFPRINTF (stderr, "No expected tokens.\n");
-# endif]])[
+      else
+        YYDPRINTF ((stderr, "No expected tokens.\n"));]])[
     }
 
   switch (yycount)
