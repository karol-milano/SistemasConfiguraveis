@@ -121,8 +121,7 @@ rule_rhs_print_xml (rule *r, FILE *out, int level)
       item_number *rp;
       xml_puts (out, level, "<rhs>");
       for (rp = r->rhs; *rp >= 0; rp++)
-	xml_printf (out, level + 1, "<symbol class=\"%s\">%s</symbol>",
-		    symbol_class_get_string (symbols[*rp]),
+	xml_printf (out, level + 1, "<symbol>%s</symbol>",
 		    xml_escape (symbols[*rp]->tag));
       xml_puts (out, level, "</rhs>");
     }
@@ -221,8 +220,12 @@ grammar_rules_print_xml (FILE *out, int level)
           usefulness = "useless-in-parser";
         else
           usefulness = "useful";
-        xml_printf (out, level + 2, "<rule number=\"%d\" usefulness=\"%s\">",
-                    rules[r].number, usefulness);
+        xml_indent (out, level + 2);
+        fprintf (out, "<rule number=\"%d\" usefulness=\"%s\"",
+                 rules[r].number, usefulness);
+        if (rules[r].precsym)
+          fprintf (out, " percent_prec=\"%s\"", rules[r].precsym->tag);
+        fputs (">\n", out);
       }
       rule_lhs_print_xml (&rules[r], out, level + 3);
       rule_rhs_print_xml (&rules[r], out, level + 3);
