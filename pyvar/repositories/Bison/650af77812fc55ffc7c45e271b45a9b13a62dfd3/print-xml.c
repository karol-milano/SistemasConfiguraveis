@@ -417,7 +417,7 @@ print_grammar (FILE *out, int level)
                   "<nonterminal symbol-number=\"%d\" name=\"%s\""
                   " usefulness=\"%s\"/>",
                   i, xml_escape (tag),
-                  reduce_nonterminal_useless_in_grammar (i)
+                  reduce_nonterminal_useless_in_grammar (symbols[i]->content)
                     ? "useless-in-grammar" : "useful");
     }
   xml_puts (out, level + 1, "</nonterminals>");
