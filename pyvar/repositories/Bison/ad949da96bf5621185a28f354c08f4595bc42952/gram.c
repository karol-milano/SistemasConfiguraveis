@@ -67,7 +67,7 @@ ritem_print (FILE *out)
   fputs ("RITEM\n", out);
   for (i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
-      fprintf (out, "  %s", tags[ritem[i]]);
+      fprintf (out, "  %s", symbols[ritem[i]]->tag);
     else
       fprintf (out, "  (rule %d)\n", -ritem[i] - 1);
   fputs ("\n\n", out);
