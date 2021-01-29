@@ -960,23 +960,22 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
    current lookahead, then check if that lookahead can eventually be
    shifted if syntactic actions continue from the current context.
    Report a syntax error if it cannot.  */
-#define YY_LAC_ESTABLISH                                         \
-do {                                                             \
-  if (!yy_lac_established)                                       \
-    {                                                            \
-      YYDPRINTF ((stderr,                                        \
-                  "LAC: initial context established for %s\n",   \
-                  yysymbol_name (yytoken)));                     \
-      yy_lac_established = 1;                                    \
-      {                                                          \
-        int yy_lac_status =                                      \
-          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
-        if (yy_lac_status == 2)                                  \
-          goto yyexhaustedlab;                                   \
-        if (yy_lac_status == 1)                                  \
-          goto yyerrlab;                                         \
-      }                                                          \
-    }                                                            \
+#define YY_LAC_ESTABLISH                                                \
+do {                                                                    \
+  if (!yy_lac_established)                                              \
+    {                                                                   \
+      YYDPRINTF ((stderr,                                               \
+                  "LAC: initial context established for %s\n",          \
+                  yysymbol_name (yytoken)));                            \
+      yy_lac_established = 1;                                           \
+      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
+        {                                                               \
+        case 2:                                                         \
+          goto yyexhaustedlab;                                          \
+        case 1:                                                         \
+          goto yyerrlab;                                                \
+        }                                                               \
+    }                                                                   \
 } while (0)
 
 /* Discard any previous initial lookahead context because of Event,
@@ -1147,23 +1146,21 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     if (yyx != YYTERROR && yyx != YYUNDEFTOK)
-      {
+      switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
+                                  [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[))
         {
-          int yy_lac_status
-            = yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yyx]],
-                                  [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx]])[);
-          if (yy_lac_status == 2)
-            return -2;
-          if (yy_lac_status == 1)
-            continue;
-        }
-        if (!yyarg)
-          ++yycount;
-        else if (yycount == yyargn)
-          return 0;
-        else
-          yyarg[yycount++] = yyx;
-      }]],
+        case 2:
+          return -2;
+        case 1:
+          continue;
+        default:
+          if (!yyarg)
+            ++yycount;
+          else if (yycount == yyargn)
+            return 0;
+          else
+            yyarg[yycount++] = yyx;
+        }]],
 [[  int yyn = yypact@{+*]b4_push_if([yyps], [yyctx])[->yyssp@};
   if (!yypact_value_is_default (yyn))
     {
