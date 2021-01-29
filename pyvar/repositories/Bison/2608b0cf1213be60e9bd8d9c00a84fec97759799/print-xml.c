@@ -382,9 +382,10 @@ print_grammar (FILE *out, int level)
   for (int i = 0; i < max_code + 1; i++)
     if (token_translations[i] != undeftoken->content->number)
       {
-        char const *tag = symbols[token_translations[i]]->tag;
-        int precedence = symbols[token_translations[i]]->content->prec;
-        assoc associativity = symbols[token_translations[i]]->content->assoc;
+        symbol const *sym = symbols[token_translations[i]];
+        char const *tag = sym->tag;
+        int precedence = sym->content->prec;
+        assoc associativity = sym->content->assoc;
         xml_indent (out, level + 2);
         fprintf (out,
                  "<terminal symbol-number=\"%d\" token-number=\"%d\""
@@ -404,7 +405,8 @@ print_grammar (FILE *out, int level)
   xml_puts (out, level + 1, "<nonterminals>");
   for (symbol_number i = ntokens; i < nsyms + nuseless_nonterminals; i++)
     {
-      char const *tag = symbols[i]->tag;
+      symbol const *sym = symbols[i];
+      char const *tag = sym->tag;
       xml_printf (out, level + 2,
                   "<nonterminal symbol-number=\"%d\" name=\"%s\""
                   " usefulness=\"%s\"/>",
