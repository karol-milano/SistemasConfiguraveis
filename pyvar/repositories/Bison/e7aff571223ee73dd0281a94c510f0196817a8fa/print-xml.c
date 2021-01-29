@@ -379,7 +379,7 @@ print_grammar (FILE *out, int level)
 
   /* Terminals */
   xml_puts (out, level + 1, "<terminals>");
-  for (symbol_number i = 0; i < max_user_token_number + 1; i++)
+  for (int i = 0; i < max_code + 1; i++)
     if (token_translations[i] != undeftoken->content->number)
       {
         char const *tag = symbols[token_translations[i]]->tag;
