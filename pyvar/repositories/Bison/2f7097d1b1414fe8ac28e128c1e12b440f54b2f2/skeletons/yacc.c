@@ -1137,16 +1137,16 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 ]b4_lac_if([[yy_state_t *yyesa, yy_state_t **yyes,
                 YYPTRDIFF_T *yyes_capacity, ]])[yy_state_t *yyssp, int yytoken)
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
@@ -1178,7 +1178,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[*yyssp];]b4_lac_if([[
+      int yyn = yypact[*yyssp];
+      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
+      yysize = yysize0;]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
@@ -1217,8 +1219,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
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
@@ -1249,7 +1251,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
     }
 
   {
-    YYPTRDIFF_T yysize1 = yysize + yystrlen (yyformat);
+    /* Don't count the "%s"s in the final size, but reserve room for
+       the terminator.  */
+    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
     if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
       yysize = yysize1;
     else
@@ -1279,8 +1283,8 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
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
