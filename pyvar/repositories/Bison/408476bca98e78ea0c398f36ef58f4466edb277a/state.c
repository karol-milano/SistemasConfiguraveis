@@ -262,8 +262,7 @@ state_rule_lookahead_tokens_print_xml (state *s, rule *r,
       xml_puts (out, level, "<lookaheads>");
       BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
 	{
-	  xml_printf (out, level + 1, "<symbol class=\"%s\">%s</symbol>",
-		      symbol_class_get_string (symbols[k]),
+	  xml_printf (out, level + 1, "<symbol>%s</symbol>",
 		      xml_escape (symbols[k]->tag));
 	}
       xml_puts (out, level, "</lookaheads>");
