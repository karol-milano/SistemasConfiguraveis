@@ -377,11 +377,11 @@ print_terminal_symbols (FILE *out)
   for (int i = 0; i < max_code + 1; ++i)
     if (token_translations[i] != undeftoken->content->number)
       {
-        const char *tag = symbols[token_translations[i]]->tag;
+        const symbol *sym = symbols[token_translations[i]];
+        const char *tag = sym->tag;
         fprintf (out, "%4s%s", "", tag);
-        if (symbols[token_translations[i]]->content->type_name)
-          fprintf (out, " <%s>",
-                   symbols[token_translations[i]]->content->type_name);
+        if (sym->content->type_name)
+          fprintf (out, " <%s>", sym->content->type_name);
         fprintf (out, " (%d)", i);
 
         for (rule_number r = 0; r < nrules; r++)
@@ -403,7 +403,8 @@ print_nonterminal_symbols (FILE *out)
   fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
   for (symbol_number i = ntokens; i < nsyms; i++)
     {
-      const char *tag = symbols[i]->tag;
+      const symbol *sym = symbols[i];
+      const char *tag = sym->tag;
       bool on_left = false;
       bool on_right = false;
 
@@ -418,9 +419,9 @@ print_nonterminal_symbols (FILE *out)
 
       int column = 4 + mbswidth (tag, 0);
       fprintf (out, "%4s%s", "", tag);
-      if (symbols[i]->content->type_name)
+      if (sym->content->type_name)
         column += fprintf (out, " <%s>",
-                           symbols[i]->content->type_name);
+                           sym->content->type_name);
       fprintf (out, " (%d)\n", i);
 
       if (on_left)
