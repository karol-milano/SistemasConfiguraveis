@@ -384,13 +384,15 @@ print_grammar (FILE *out, int level)
       {
         symbol const *sym = symbols[token_translations[i]];
         char const *tag = sym->tag;
+        char const *type = sym->content->type_name;
         int precedence = sym->content->prec;
         assoc associativity = sym->content->assoc;
         xml_indent (out, level + 2);
         fprintf (out,
                  "<terminal symbol-number=\"%d\" token-number=\"%d\""
-                 " name=\"%s\" usefulness=\"%s\"",
-                 token_translations[i], i, xml_escape (tag),
+                 " name=\"%s\" type=\"%s\" usefulness=\"%s\"",
+                 token_translations[i], i, xml_escape_n (0, tag),
+                 type ? xml_escape_n (1, type) : "",
                  reduce_token_unused_in_grammar (token_translations[i])
                    ? "unused-in-grammar" : "useful");
         if (precedence)
@@ -407,11 +409,14 @@ print_grammar (FILE *out, int level)
     {
       symbol const *sym = symbols[i];
       char const *tag = sym->tag;
+      char const *type = sym->content->type_name;
       xml_printf (out, level + 2,
                   "<nonterminal symbol-number=\"%d\" name=\"%s\""
+                  " type=\"%s\""
                   " usefulness=\"%s\"/>",
-                  i, xml_escape (tag),
-                  reduce_nonterminal_useless_in_grammar (symbols[i]->content)
+                  i, xml_escape_n (0, tag),
+                  type ? xml_escape_n (1, type) : "",
+                  reduce_nonterminal_useless_in_grammar (sym->content)
                     ? "useless-in-grammar" : "useful");
     }
   xml_puts (out, level + 1, "</nonterminals>");
