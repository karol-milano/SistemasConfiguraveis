@@ -1248,8 +1248,15 @@ counterexample_report_shift_reduce (state_item_number itm1, state_item_number it
                                     symbol_number next_sym,
                                     FILE *out, const char *prefix)
 {
-  fputs (prefix, out);
-  fprintf (out, _("Shift/reduce conflict on token %s:\n"), symbols[next_sym]->tag);
+  if (out == stderr)
+    complain (NULL, Wcounterexamples,
+              _("shift/reduce conflict on token %s"), symbols[next_sym]->tag);
+  else
+    {
+      fputs (prefix, out);
+      fprintf (out, _("shift/reduce conflict on token %s"), symbols[next_sym]->tag);
+      fprintf (out, "%s\n", _(":"));
+    }
   // In the report, print the items.
   if (*prefix || trace_flag & trace_cex)
     {
