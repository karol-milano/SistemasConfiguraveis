@@ -503,79 +503,6 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 #endif
 
 
-]m4_case(b4_percent_define_get([parse.error]), [verbose],
-[[# ifndef yystpcpy
-#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
-#   define yystpcpy stpcpy
-#  else
-/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
-   YYDEST.  */
-static char *
-yystpcpy (char *yydest, const char *yysrc)
-{
-  char *yyd = yydest;
-  const char *yys = yysrc;
-
-  while ((*yyd++ = *yys++) != '\0')
-    continue;
-
-  return yyd - 1;
-}
-#  endif
-# endif
-
-# ifndef yytnamerr
-/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
-   quotes and backslashes, so that it's suitable for yyerror.  The
-   heuristic is that double-quoting is unnecessary unless the string
-   contains an apostrophe, a comma, or backslash (other than
-   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
-   null, do not copy; instead, return the length of what the result
-   would have been.  */
-static ptrdiff_t
-yytnamerr (char *yyres, const char *yystr)
-{
-  if (*yystr == '"')
-    {
-      ptrdiff_t yyn = 0;
-      char const *yyp = yystr;
-
-      for (;;)
-        switch (*++yyp)
-          {
-          case '\'':
-          case ',':
-            goto do_not_strip_quotes;
-
-          case '\\':
-            if (*++yyp != '\\')
-              goto do_not_strip_quotes;
-            else
-              goto append;
-
-          append:
-          default:
-            if (yyres)
-              yyres[yyn] = *yyp;
-            yyn++;
-            break;
-
-          case '"':
-            if (yyres)
-              yyres[yyn] = '\0';
-            return yyn;
-          }
-    do_not_strip_quotes: ;
-    }
-
-  if (yyres)
-    return yystpcpy (yyres, yystr) - yyres;
-  else
-    return YY_CAST (ptrdiff_t, strlen (yystr));
-}
-# endif
-]])[
-
 /** State numbers. */
 typedef int yy_state_t;
 
@@ -742,10 +669,9 @@ yysymbol_name (yySymbol yytoken)
    multiple parsers can coexist.  */
 int yydebug;
 
-struct yyGLRStack;
-static void yypstack (struct yyGLRStack* yystackp, ptrdiff_t yyk)
+static void yypstack (yyGLRStack* yystackp, ptrdiff_t yyk)
   YY_ATTRIBUTE_UNUSED;
-static void yypdumpstack (struct yyGLRStack* yystackp)
+static void yypdumpstack (yyGLRStack* yystackp)
   YY_ATTRIBUTE_UNUSED;
 
 #else /* !]b4_api_PREFIX[DEBUG */
@@ -755,6 +681,79 @@ static void yypdumpstack (struct yyGLRStack* yystackp)
 
 #endif /* !]b4_api_PREFIX[DEBUG */
 
+]m4_case(b4_percent_define_get([parse.error]), [verbose],
+[[# ifndef yystpcpy
+#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
+#   define yystpcpy stpcpy
+#  else
+/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
+   YYDEST.  */
+static char *
+yystpcpy (char *yydest, const char *yysrc)
+{
+  char *yyd = yydest;
+  const char *yys = yysrc;
+
+  while ((*yyd++ = *yys++) != '\0')
+    continue;
+
+  return yyd - 1;
+}
+#  endif
+# endif
+
+# ifndef yytnamerr
+/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
+   quotes and backslashes, so that it's suitable for yyerror.  The
+   heuristic is that double-quoting is unnecessary unless the string
+   contains an apostrophe, a comma, or backslash (other than
+   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
+   null, do not copy; instead, return the length of what the result
+   would have been.  */
+static ptrdiff_t
+yytnamerr (char *yyres, const char *yystr)
+{
+  if (*yystr == '"')
+    {
+      ptrdiff_t yyn = 0;
+      char const *yyp = yystr;
+
+      for (;;)
+        switch (*++yyp)
+          {
+          case '\'':
+          case ',':
+            goto do_not_strip_quotes;
+
+          case '\\':
+            if (*++yyp != '\\')
+              goto do_not_strip_quotes;
+            else
+              goto append;
+
+          append:
+          default:
+            if (yyres)
+              yyres[yyn] = *yyp;
+            yyn++;
+            break;
+
+          case '"':
+            if (yyres)
+              yyres[yyn] = '\0';
+            return yyn;
+          }
+    do_not_strip_quotes: ;
+    }
+
+  if (yyres)
+    return yystpcpy (yyres, yystr) - yyres;
+  else
+    return YY_CAST (ptrdiff_t, strlen (yystr));
+}
+# endif
+]])[
+
 /** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
  *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
  *  containing the pointer to the next state in the chain.  */
