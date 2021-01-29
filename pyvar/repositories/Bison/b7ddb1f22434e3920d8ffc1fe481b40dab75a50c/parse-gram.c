@@ -1800,10 +1800,10 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
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
         }
@@ -1831,9 +1831,10 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 
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
