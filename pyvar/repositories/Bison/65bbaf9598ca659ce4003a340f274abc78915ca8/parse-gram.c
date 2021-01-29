@@ -1606,21 +1606,24 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-    if (yyx != YYSYMBOL_YYERROR && yyx != YYSYMBOL_YYUNDEF)
-      switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx))
-        {
-        case YYNOMEM:
-          return YYNOMEM;
-        case 1:
-          continue;
-        default:
-          if (!yyarg)
-            ++yycount;
-          else if (yycount == yyargn)
-            return 0;
-          else
-            yyarg[yycount++] = yyx;
-        }
+    {
+      yysymbol_type_t yysym = YY_CAST (yysymbol_type_t, yyx);
+      if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
+        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
+          {
+          case YYNOMEM:
+            return YYNOMEM;
+          case 1:
+            continue;
+          default:
+            if (!yyarg)
+              ++yycount;
+            else if (yycount == yyargn)
+              return 0;
+            else
+              yyarg[yycount++] = yysym;
+          }
+    }
   return yycount;
 }
 
