@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.1.51-6ada9.  */
+/* A Bison parser, made by GNU Bison 3.5.1.3-1587-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.1.51-6ada9"
+#define YYBISON_VERSION "3.5.1.3-1587-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1558,135 +1558,18 @@ yysyntax_error_arguments (const yyparse_context_t *yyctx,
 }
 
 
-# ifndef yystrlen
-#  if defined __GLIBC__ && defined _STRING_H
-#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
-#  else
-/* Return the length of YYSTR.  */
-static YYPTRDIFF_T
-yystrlen (const char *yystr)
-{
-  YYPTRDIFF_T yylen;
-  for (yylen = 0; yystr[yylen]; yylen++)
-    continue;
-  return yylen;
-}
-#  endif
-# endif
+/*  The location of this context.  */
+static YYLTYPE *
+yyparse_context_location (const yyparse_context_t *yyctx) YY_ATTRIBUTE_UNUSED;
 
-# ifndef yystpcpy
-#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
-#   define yystpcpy stpcpy
-#  else
-/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
-   YYDEST.  */
-static char *
-yystpcpy (char *yydest, const char *yysrc)
+static YYLTYPE *
+yyparse_context_location (const yyparse_context_t *yyctx)
 {
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
-
-
-/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
-   about the unexpected token YYTOKEN for the state stack whose top is
-   YYSSP.  In order to see if a particular token T is a
-   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).
-
-   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
-   not large enough to hold the message.  In that case, also set
-   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
-   required number of bytes is too large to store or if
-   yy_lac returned 2.  */
-static int
-yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
-                const yyparse_context_t *yyctx)
-{
-  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
-  /* Internationalized format string. */
-  const char *yyformat = YY_NULLPTR;
-  /* Arguments of yyformat: reported tokens (one for the "unexpected",
-     one per "expected"). */
-  int yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
-  /* Cumulated lengths of YYARG.  */
-  YYPTRDIFF_T yysize = 0;
-
-  /* Actual size of YYARG. */
-  int yycount
-    = yysyntax_error_arguments (yyctx, yyarg, YYERROR_VERBOSE_ARGS_MAXIMUM);
-  if (yycount == -2)
-    return 2;
-
-  switch (yycount)
-    {
-# define YYCASE_(N, S)                      \
-      case N:                               \
-        yyformat = S;                       \
-      break
-    default: /* Avoid compiler warnings. */
-      YYCASE_(0, YY_("syntax error"));
-      YYCASE_(1, YY_("syntax error, unexpected %s"));
-      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
-      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
-      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
-      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
-# undef YYCASE_
-    }
-
-  /* Compute error message size.  Don't count the "%s"s, but reserve
-     room for the terminator.  */
-  yysize = (yystrlen (yyformat) - 2 * yycount) + 1;
-  {
-    int yyi;
-    for (yyi = 0; yyi < yycount; ++yyi)
-      {
-        YYPTRDIFF_T yysize1
-          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
-        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
-          yysize = yysize1;
-        else
-          return 2;
-      }
-  }
-
-  if (*yymsg_alloc < yysize)
-    {
-      *yymsg_alloc = 2 * yysize;
-      if (! (yysize <= *yymsg_alloc
-             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
-        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
-      return 1;
-    }
-
-  /* Avoid sprintf, as that infringes on the user's name space.
-     Don't have undefined behavior even if the translation
-     produced a string with the wrong number of "%s"s.  */
-  {
-    char *yyp = *yymsg;
-    int yyi = 0;
-    while ((*yyp = *yyformat) != '\0')
-      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-        {
-          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
-          yyformat += 2;
-        }
-      else
-        {
-          ++yyp;
-          ++yyformat;
-        }
-  }
-  return 0;
+  return yyctx->yylloc;
 }
 
+/* User defined function to report a syntax error.  */
+static int yyreport_syntax_error (const yyparse_context_t *yyctx);
 
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
@@ -1825,10 +1708,7 @@ YYLTYPE yylloc = yyloc_default;
   YYSTYPE yyval;
   YYLTYPE yyloc;
 
-  /* Buffer for error messages, and its allocated size.  */
-  char yymsgbuf[128];
-  char *yymsg = yymsgbuf;
-  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
+
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
 
@@ -2660,36 +2540,11 @@ yyerrlab:
     {
       ++yynerrs;
       {
-        char const *yymsgp = YY_("syntax error");
         yyparse_context_t yyctx
           = {yyssp, yytoken, &yylloc, yyesa, &yyes, &yyes_capacity};
-        int yysyntax_error_status;
         if (yychar != YYEMPTY)
           YY_LAC_ESTABLISH;
-        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
-        if (yysyntax_error_status == 0)
-          yymsgp = yymsg;
-        else if (yysyntax_error_status == 1)
-          {
-            if (yymsg != yymsgbuf)
-              YYSTACK_FREE (yymsg);
-            yymsg = YY_CAST (char *,
-                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
-            if (yymsg)
-              {
-                yysyntax_error_status
-                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
-                yymsgp = yymsg;
-              }
-            else
-              {
-                yymsg = yymsgbuf;
-                yymsg_alloc = sizeof yymsgbuf;
-                yysyntax_error_status = 2;
-              }
-          }
-        yyerror (&yylloc, yymsgp);
-        if (yysyntax_error_status == 2)
+        if (yyreport_syntax_error (&yyctx) == 2)
           goto yyexhaustedlab;
       }
     }
@@ -2846,12 +2701,70 @@ yyreturn:
 #endif
   if (yyes != yyesa)
     YYSTACK_FREE (yyes);
-  if (yymsg != yymsgbuf)
-    YYSTACK_FREE (yymsg);
+
   return yyresult;
 }
 
 
+int
+yyreport_syntax_error (const yyparse_context_t *ctx)
+{
+  if (complaint_status < status_complaint)
+    complaint_status = status_complaint;
+  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+  /* Internationalized format string. */
+  const char *format = YY_NULLPTR;
+  /* Arguments of format: reported tokens (one for the "unexpected",
+     one per "expected"). */
+  int arg[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  int n = yysyntax_error_arguments (ctx, arg, YYERROR_VERBOSE_ARGS_MAXIMUM);
+  switch (n)
+    {
+    case -2:
+      return 2;
+# define YYCASE_(N, S)                      \
+      case N:                               \
+        format = S;                         \
+      break
+    default: /* Avoid compiler warnings. */
+      YYCASE_(0, YY_("syntax error"));
+      YYCASE_(1, YY_("syntax error, unexpected %s"));
+      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
+      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
+      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
+      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
+# undef YYCASE_
+    }
+  location_print (*yyparse_context_location (ctx), stderr);
+  fputs (": ", stderr);
+  begin_use_class ("error", stderr);
+  fputs ("error:", stderr);
+  end_use_class ("error", stderr);
+  fputc (' ', stderr);
+  {
+    int i = 0;
+    while (*format)
+      if (format[0] == '%' && format[1] == 's' && i < n)
+        {
+          const char *style = i == 0 ? "unexpected" : "expected";
+          begin_use_class (style, stderr);
+          fputs (yysymbol_name (arg[i]), stderr);
+          end_use_class (style, stderr);
+          format += 2;
+          ++i;
+        }
+      else
+        {
+          fputc (*format, stderr);
+          ++format;
+        }
+  }
+  fputc ('\n', stderr);
+  location_caret (*yyparse_context_location (ctx), "error", stderr);
+  return 0;
+}
+
+
 /* Return the location of the left-hand side of a rule whose
    right-hand side is RHS[1] ... RHS[N].  Ignore empty nonterminals in
    the right-hand side, and return an empty location equal to the end
