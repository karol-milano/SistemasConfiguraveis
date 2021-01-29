@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.90.26-44cd.  */
+/* A Bison parser, made by GNU Bison 3.4.91.18-42a6c.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.90.26-44cd"
+#define YYBISON_VERSION "3.4.91.18-42a6c"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -348,12 +348,19 @@ typedef int yy_state_fast_t;
 
 #if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
-# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
-    _Pragma ("GCC diagnostic push") \
-    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
+    _Pragma ("GCC diagnostic push")                                     \
+    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
     _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
-# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
     _Pragma ("GCC diagnostic pop")
+# if defined __cplusplus
+#  define YY_IGNORE_USELESS_CAST_BEGIN                          \
+     _Pragma ("GCC diagnostic push")                            \
+     _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
+#  define YY_IGNORE_USELESS_CAST_END            \
+     _Pragma ("GCC diagnostic pop")
+# endif
 #else
 # define YY_INITIAL_VALUE(Value) Value
 #endif
@@ -361,6 +368,10 @@ typedef int yy_state_fast_t;
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
 #endif
+#ifndef YY_IGNORE_USELESS_CAST_BEGIN
+# define YY_IGNORE_USELESS_CAST_BEGIN
+# define YY_IGNORE_USELESS_CAST_END
+#endif
 #ifndef YY_INITIAL_VALUE
 # define YY_INITIAL_VALUE(Value) /* Nothing. */
 #endif
@@ -1410,7 +1421,9 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
+            YY_IGNORE_USELESS_CAST_BEGIN
             *yyesp = YY_CAST (yy_state_t, yystate);
+            YY_IGNORE_USELESS_CAST_END
           }
         else
           {
@@ -1423,7 +1436,9 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
+            YY_IGNORE_USELESS_CAST_BEGIN
             *++yyesp = YY_CAST (yy_state_t, yystate);
+            YY_IGNORE_USELESS_CAST_END
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1535,16 +1550,16 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 yy_state_t *yyesa, yy_state_t **yyes,
                 YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
 {
-  YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
-  YYPTRDIFF_T yysize = yysize0;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
-  /* Arguments of yyformat. */
+  /* Arguments of yyformat: reported tokens (one for the "unexpected",
+     one per "expected"). */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  /* Number of reported tokens (one for the "unexpected", one per
-     "expected"). */
+  /* Actual size of YYARG. */
   int yycount = 0;
+  /* Cumulated lengths of YYARG.  */
+  YYPTRDIFF_T yysize = 0;
 
   /* There are many possibilities here to consider:
      - If this state is a consistent state with a default action, then
@@ -1569,6 +1584,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   if (yytoken != YYEMPTY)
     {
       int yyn = yypact[*yyssp];
+      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
+      yysize = yysize0;
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
@@ -1594,8 +1611,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 {
-                  YYPTRDIFF_T yysize1 = yysize + yytnamerr (YY_NULLPTR,
-                                                            yytname[yyx]);
+                  YYPTRDIFF_T yysize1
+                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                   if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                     yysize = yysize1;
                   else
@@ -1626,7 +1643,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     }
 
   {
-    YYPTRDIFF_T yysize1 = yysize + yystrlen (yyformat);
+    /* Don't count the "%s"s in the final size, but reserve room for
+       the terminator.  */
+    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
     if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
       yysize = yysize1;
     else
@@ -1656,8 +1675,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
         }
       else
         {
-          yyp++;
-          yyformat++;
+          ++yyp;
+          ++yyformat;
         }
   }
   return 0;
@@ -1857,7 +1876,9 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-   *yyssp = YY_CAST (yy_state_t, yystate);
+  YY_IGNORE_USELESS_CAST_BEGIN
+  *yyssp = YY_CAST (yy_state_t, yystate);
+  YY_IGNORE_USELESS_CAST_END
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1917,8 +1938,10 @@ yysetstate:
       yyvsp = yyvs + yysize - 1;
       yylsp = yyls + yysize - 1;
 
+      YY_IGNORE_USELESS_CAST_BEGIN
       YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                   YY_CAST (long, yystacksize)));
+      YY_IGNORE_USELESS_CAST_END
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
