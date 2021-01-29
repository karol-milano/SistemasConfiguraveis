@@ -1247,7 +1247,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 {
   YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
-  YYSIZE_T yysize1;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULL;
@@ -1328,11 +1327,13 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
-                if (! (yysize <= yysize1
-                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-                  return 2;
-                yysize = yysize1;
+                {
+                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
+                  if (! (yysize <= yysize1
+                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                    return 2;
+                  yysize = yysize1;
+                }
               }
         }]b4_lac_if([[
 # if ]b4_api_PREFIX[DEBUG
@@ -1356,10 +1357,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 # undef YYCASE_
     }
 
-  yysize1 = yysize + yystrlen (yyformat);
-  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-    return 2;
-  yysize = yysize1;
+  {
+    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
+    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+      return 2;
+    yysize = yysize1;
+  }
 
   if (*yymsg_alloc < yysize)
     {
