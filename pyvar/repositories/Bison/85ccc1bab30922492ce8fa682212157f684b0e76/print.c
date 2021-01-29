@@ -196,11 +196,12 @@ print_reduction (FILE *out, size_t width,
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
-  if (r->number)
+  const bool final = r->lhs->symbol == acceptsymbol;
+  if (final)
+    fprintf (out, _("accept"));
+  else
     fprintf (out, _("reduce using rule %d (%s)"), r->number,
              r->lhs->symbol->tag);
-  else
-    fprintf (out, _("accept"));
   if (!enabled)
     fputc (']', out);
   fputc ('\n', out);
