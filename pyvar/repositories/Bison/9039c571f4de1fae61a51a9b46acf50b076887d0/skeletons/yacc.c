@@ -1149,22 +1149,25 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 ]b4_lac_if([[
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-    if (yyx != YYSYMBOL_YYERROR && yyx != YYSYMBOL_YYUNDEF)
-      switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
-                                  [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[))
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
-        }]],
+    {
+      yysymbol_type_t yysym = YY_CAST (yysymbol_type_t, yyx);
+      if (yysym != YYSYMBOL_YYERROR && yysym != YYSYMBOL_YYUNDEF)
+        switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym]],
+                                    [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym]])[))
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
+    }]],
 [[  int yyn = yypact@{+*]b4_push_if([yyps], [yyctx])[->yyssp@};
   if (!yypact_value_is_default (yyn))
     {
@@ -1185,7 +1188,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
             else if (yycount == yyargn)
               return 0;
             else
-              yyarg[yycount++] = yyx;
+              yyarg[yycount++] = YY_CAST (yysymbol_type_t, yyx);
           }
     }]])[
   return yycount;
