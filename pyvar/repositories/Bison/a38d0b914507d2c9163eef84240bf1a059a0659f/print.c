@@ -198,8 +198,7 @@ print_reduction (FILE *out, size_t width,
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
-  const bool final = r->lhs->symbol == acceptsymbol;
-  if (final)
+  if (rule_is_initial (r))
     fprintf (out, _("accept"));
   else
     fprintf (out, _("reduce using rule %d (%s)"), r->number,
@@ -318,7 +317,7 @@ print_reductions (FILE *out, const state *s)
       aver (STREQ (default_reductions, "most")
             || (STREQ (default_reductions, "consistent")
                 && default_reduction_only)
-            || (reds->num == 1 && reds->rules[0]->number == 0));
+            || (reds->num == 1 && rule_is_initial (reds->rules[0])));
       (void) default_reduction_only;
       free (default_reductions);
     }
