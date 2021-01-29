@@ -66,7 +66,7 @@ ritem_print (FILE *out)
     if (ritem[i] >= 0)
       fprintf (out, "  %s", tags[ritem[i]]);
     else
-      fprintf (out, "  (rule %d)\n", -ritem[i]);
+      fprintf (out, "  (rule %d)\n", -ritem[i] - 1);
   fputs ("\n\n", out);
 }
 
