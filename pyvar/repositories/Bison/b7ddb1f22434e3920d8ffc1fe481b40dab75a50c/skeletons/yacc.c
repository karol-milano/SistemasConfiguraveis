@@ -1183,10 +1183,10 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yyarg[yycount++] = yytname[yyx];
                 {
                   YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
-                  if (! (yysize <= yysize1
-                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
+                    yysize = yysize1;
+                  else
                     return 2;
-                  yysize = yysize1;
                 }
               }
         }]b4_lac_if([[
@@ -1214,9 +1214,10 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
   {
     YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
-    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
+      yysize = yysize1;
+    else
       return 2;
-    yysize = yysize1;
   }
 
   if (*yymsg_alloc < yysize)
