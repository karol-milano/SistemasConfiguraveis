@@ -420,6 +420,12 @@ print_terminal_symbols (FILE *out)
         buffer[0] = 0;
         fputs (tag, out);
         END_TEST (65);
+        if (symbols[token_translations[i]]->content->type_name)
+          {
+            column += fprintf (out, " <%s>",
+                               symbols[token_translations[i]]->content->type_name);
+            END_TEST (65);
+          }
         sprintf (buffer, " (%d)", i);
 
         for (r = 0; r < nrules; r++)
@@ -465,6 +471,9 @@ print_nonterminal_symbols (FILE *out)
         }
 
       fputs (tag, out);
+      if (symbols[i]->content->type_name)
+        column += fprintf (out, " <%s>",
+                           symbols[i]->content->type_name);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
 
