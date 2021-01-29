@@ -1,9 +1,9 @@
-/* A Bison parser, made by GNU Bison 3.4.92.  */
+/* A Bison parser, made by GNU Bison 3.5.22-948cd-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
+   Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.92"
+#define YYBISON_VERSION "3.5.22-948cd-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -99,14 +99,6 @@
 #  endif
 # endif
 
-/* Enabling verbose error messages.  */
-#ifdef YYERROR_VERBOSE
-# undef YYERROR_VERBOSE
-# define YYERROR_VERBOSE 1
-#else
-# define YYERROR_VERBOSE 1
-#endif
-
 #include "src/parse-gram.h"
 
 
@@ -424,7 +416,6 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 # define YYCOPY_NEEDED 1
 #endif
 
-
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
          || (defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL \
@@ -530,7 +521,7 @@ static const yytype_int16 yyrline[] =
 };
 #endif
 
-#if GRAM_DEBUG || YYERROR_VERBOSE || 1
+#if 1
 /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
    First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
 static const char *const yytname[] =
@@ -1169,7 +1160,7 @@ yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
-                       yystos[yyssp[yyi + 1 - yynrhs]],
+                       yystos[+yyssp[yyi + 1 - yynrhs]],
                        &yyvsp[(yyi + 1) - (yynrhs)]
                        , &(yylsp[(yyi + 1) - (yynrhs)])                       );
       YYFPRINTF (stderr, "\n");
@@ -1186,7 +1177,7 @@ do {                                    \
    multiple parsers can coexist.  */
 int yydebug;
 #else /* !GRAM_DEBUG */
-# define YYDPRINTF(Args)
+# define YYDPRINTF(Args) ((void) 0)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
@@ -1331,9 +1322,8 @@ do {                                                             \
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
@@ -1363,12 +1353,12 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
   while (1)
     {
-      int yyrule = yypact[*yyesp];
+      int yyrule = yypact[+*yyesp];
       if (yypact_value_is_default (yyrule)
           || (yyrule += yytoken) < 0 || YYLAST < yyrule
           || yycheck[yyrule] != yytoken)
         {
-          yyrule = yydefact[*yyesp];
+          yyrule = yydefact[+*yyesp];
           if (yyrule == 0)
             {
               YYDPRINTF ((stderr, " Err\n"));
@@ -1447,8 +1437,6 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
 }
 
 
-#if YYERROR_VERBOSE
-
 # ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
 #   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
@@ -1584,15 +1572,12 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[*yyssp];
-      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
-      yysize = yysize0;
+      int yyn = yypact[+*yyssp];
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
         {
           int yyx;
-
           for (yyx = 0; yyx < YYNTOKENS; ++yyx)
             if (yyx != YYTERROR && yyx != YYUNDEFTOK)
               {
@@ -1607,24 +1592,13 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                   {
                     yycount = 1;
-                    yysize = yysize0;
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                {
-                  YYPTRDIFF_T yysize1
-                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
-                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
-                    yysize = yysize1;
-                  else
-                    return 2;
-                }
               }
         }
-# if GRAM_DEBUG
-      else if (yydebug)
-        YYFPRINTF (stderr, "No expected tokens.\n");
-# endif
+      else
+        YYDPRINTF ((stderr, "No expected tokens.\n"));
     }
 
   switch (yycount)
@@ -1643,14 +1617,19 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
 # undef YYCASE_
     }
 
+  /* Compute error message size.  Don't count the "%s"s, but reserve
+     room for the terminator.  */
+  yysize = (yystrlen (yyformat) - 2 * yycount) + 1;
   {
-    /* Don't count the "%s"s in the final size, but reserve room for
-       the terminator.  */
-    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
-    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
-      yysize = yysize1;
-    else
-      return 2;
+    int yyi;
+    for (yyi = 0; yyi < yycount; ++yyi)
+      {
+        YYPTRDIFF_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yyarg[yyi]);
+        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
+          yysize = yysize1;
+        else
+          return 2;
+      }
   }
 
   if (*yymsg_alloc < yysize)
@@ -1682,7 +1661,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   }
   return 0;
 }
-#endif /* YYERROR_VERBOSE */
+
 
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
@@ -1819,12 +1798,10 @@ YYLTYPE yylloc = yyloc_default;
   YYSTYPE yyval;
   YYLTYPE yyloc;
 
-#if YYERROR_VERBOSE
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
   YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
-#endif
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
 
@@ -2643,9 +2620,6 @@ yyerrlab:
   if (!yyerrstatus)
     {
       ++yynerrs;
-#if ! YYERROR_VERBOSE
-      yyerror (&yylloc, YY_("syntax error"));
-#else
 # define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                         yyesa, &yyes, &yyes_capacity, \
                                         yyssp, yytoken)
@@ -2662,16 +2636,16 @@ yyerrlab:
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
             yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
-            if (!yymsg)
+            if (yymsg)
               {
-                yymsg = yymsgbuf;
-                yymsg_alloc = sizeof yymsgbuf;
-                yysyntax_error_status = 2;
+                yysyntax_error_status = YYSYNTAX_ERROR;
+                yymsgp = yymsg;
               }
             else
               {
-                yysyntax_error_status = YYSYNTAX_ERROR;
-                yymsgp = yymsg;
+                yymsg = yymsgbuf;
+                yymsg_alloc = sizeof yymsgbuf;
+                yysyntax_error_status = 2;
               }
           }
         yyerror (&yylloc, yymsgp);
@@ -2679,7 +2653,6 @@ yyerrlab:
           goto yyexhaustedlab;
       }
 # undef YYSYNTAX_ERROR
-#endif
     }
 
   yyerror_range[1] = yylloc;
@@ -2825,7 +2798,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-                  yystos[*yyssp], yyvsp, yylsp);
+                  yystos[+*yyssp], yyvsp, yylsp);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
@@ -2834,10 +2807,8 @@ yyreturn:
 #endif
   if (yyes != yyesa)
     YYSTACK_FREE (yyes);
-#if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
-#endif
   return yyresult;
 }
 
