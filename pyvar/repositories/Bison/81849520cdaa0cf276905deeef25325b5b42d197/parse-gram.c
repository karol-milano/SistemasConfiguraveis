@@ -2709,58 +2709,17 @@ yyreturn:
 int
 yyreport_syntax_error (const yyparse_context_t *ctx)
 {
-  if (complaint_status < status_complaint)
-    complaint_status = status_complaint;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
-  /* Internationalized format string. */
-  const char *format = YY_NULLPTR;
   /* Arguments of format: reported tokens (one for the "unexpected",
      one per "expected"). */
   int arg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   int n = yysyntax_error_arguments (ctx, arg, YYERROR_VERBOSE_ARGS_MAXIMUM);
-  switch (n)
-    {
-    case -2:
-      return 2;
-# define YYCASE_(N, S)                      \
-      case N:                               \
-        format = S;                         \
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
-  location_print (*yyparse_context_location (ctx), stderr);
-  fputs (": ", stderr);
-  begin_use_class ("error", stderr);
-  fputs ("error:", stderr);
-  end_use_class ("error", stderr);
-  fputc (' ', stderr);
-  {
-    int i = 0;
-    while (*format)
-      if (format[0] == '%' && format[1] == 's' && i < n)
-        {
-          const char *style = i == 0 ? "unexpected" : "expected";
-          begin_use_class (style, stderr);
-          fputs (yysymbol_name (arg[i]), stderr);
-          end_use_class (style, stderr);
-          format += 2;
-          ++i;
-        }
-      else
-        {
-          fputc (*format, stderr);
-          ++format;
-        }
-  }
-  fputc ('\n', stderr);
-  location_caret (*yyparse_context_location (ctx), "error", stderr);
+  if (n == -2)
+    return 2;
+  const char *argv[YYERROR_VERBOSE_ARGS_MAXIMUM];
+  for (int i = 0; i < n; ++i)
+    argv[i] = yysymbol_name (arg[i]);
+  syntax_error (*yyparse_context_location (ctx), n, argv);
   return 0;
 }
 
