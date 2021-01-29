@@ -136,7 +136,8 @@ print_counterexample (const counterexample *cex, FILE *out, const char *prefix)
            prefix, cex->shift_reduce ? _("Reduce derivation") : _("Second derivation"));
   derivation_print (cex->d2, out, prefix);
 
-  fputc ('\n', out);
+  if (out != stderr)
+    putc ('\n', out);
 }
 
 /*
@@ -1258,7 +1259,7 @@ counterexample_report_shift_reduce (state_item_number itm1, state_item_number it
       fprintf (out, "%s\n", _(":"));
     }
   // In the report, print the items.
-  if (*prefix || trace_flag & trace_cex)
+  if (out != stderr || trace_flag & trace_cex)
     {
       print_state_item (&state_items[itm1], out, prefix);
       print_state_item (&state_items[itm2], out, prefix);
