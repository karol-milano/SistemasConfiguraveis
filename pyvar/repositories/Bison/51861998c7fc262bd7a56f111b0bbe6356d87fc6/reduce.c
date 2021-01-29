@@ -320,7 +320,7 @@ reduce_output (FILE *out)
     {
       fprintf (out, "%s\n\n", _("Nonterminals useless in grammar"));
       for (int i = 0; i < nuseless_nonterminals; ++i)
-        fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
+        fprintf (out, "    %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
     }
 
@@ -332,7 +332,7 @@ reduce_output (FILE *out)
           if (!b)
             fprintf (out, "%s\n\n", _("Terminals unused in grammar"));
           b = true;
-          fprintf (out, "   %s\n", symbols[i]->tag);
+          fprintf (out, "    %s\n", symbols[i]->tag);
         }
     if (b)
       fputs ("\n\n", out);
