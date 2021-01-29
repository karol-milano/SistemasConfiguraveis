@@ -1184,15 +1184,12 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[+*yyssp];
-      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
-      yysize = yysize0;]b4_lac_if([[
+      int yyn = yypact[+*yyssp];]b4_lac_if([[
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
         {]b4_lac_if([[
           int yyx;
-
           for (yyx = 0; yyx < YYNTOKENS; ++yyx)
             if (yyx != YYTERROR && yyx != YYUNDEFTOK)
               {
@@ -1212,7 +1209,6 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
           int yychecklim = YYLAST - yyn + 1;
           int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
           int yyx;
-
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
@@ -1220,18 +1216,9 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
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
         }]b4_lac_if([[
 # if ]b4_api_PREFIX[DEBUG
@@ -1256,14 +1243,19 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
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
