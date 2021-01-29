@@ -218,13 +218,10 @@ grammar_rules_print_xml (FILE *out, int level)
         xml_puts (out, level + 1, "<rules>");
       first = false;
       {
-        char const *usefulness;
-        if (rule_useless_in_grammar_p (&rules[r]))
-          usefulness = "useless-in-grammar";
-        else if (rule_useless_in_parser_p (&rules[r]))
-          usefulness = "useless-in-parser";
-        else
-          usefulness = "useful";
+        char const *usefulness
+          = rule_useless_in_grammar_p (&rules[r]) ? "useless-in-grammar"
+          : rule_useless_in_parser_p (&rules[r])  ? "useless-in-parser"
+          :                                         "useful";
         xml_indent (out, level + 2);
         fprintf (out, "<rule number=\"%d\" usefulness=\"%s\"",
                  rules[r].number, usefulness);
