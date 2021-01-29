@@ -47,7 +47,7 @@ nullable_print (FILE *out)
   int i;
   fputs ("NULLABLE\n", out);
   for (i = ntokens; i < nsyms; i++)
-    fprintf (out, "\t%s: %s\n", symbols[i]->tag,
+    fprintf (out, "  %s: %s\n", symbols[i]->tag,
              nullable[i - ntokens] ? "yes" : "no");
   fputs ("\n\n", out);
 }
