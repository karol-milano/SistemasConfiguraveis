@@ -370,7 +370,7 @@ static void
 print_state (FILE *out, state *s)
 {
   fputs ("\n\n", out);
-  fprintf (out, _("state %d"), s->number);
+  fprintf (out, _("State %d"), s->number);
   fputc ('\n', out);
   print_core (out, s);
   print_actions (out, s);
