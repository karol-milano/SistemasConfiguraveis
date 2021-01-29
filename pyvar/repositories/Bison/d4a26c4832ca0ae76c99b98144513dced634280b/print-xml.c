@@ -392,24 +392,12 @@ print_grammar (FILE *out, int level)
     if (token_translations[i] != undeftoken->number)
       {
 	char const *tag = symbols[token_translations[i]]->tag;
-	rule_number r;
-	item_number *rhsp;
-
 	xml_printf (out, level + 2,
 		    "<terminal symbol-number=\"%d\" token-number=\"%d\""
-                    " name=\"%s\" usefulness=\"%s\">",
+                    " name=\"%s\" usefulness=\"%s\"/>",
 		    token_translations[i], i, xml_escape (tag),
                     reduce_token_unused_in_grammar (token_translations[i])
                       ? "unused-in-grammar" : "useful");
-
-	for (r = 0; r < nrules; r++)
-	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-	    if (item_number_as_symbol_number (*rhsp) == token_translations[i])
-	      {
-		xml_printf (out, level + 3, "<rule>%d</rule>", r);
-		break;
-	      }
-	xml_puts (out, level + 2, "</terminal>");
       }
   xml_puts (out, level + 1, "</terminals>");
 
@@ -417,58 +405,13 @@ print_grammar (FILE *out, int level)
   xml_puts (out, level + 1, "<nonterminals>");
   for (i = ntokens; i < nsyms + nuseless_nonterminals; i++)
     {
-      int left_count = 0, right_count = 0;
-      rule_number r;
       char const *tag = symbols[i]->tag;
-
-      for (r = 0; r < nrules; r++)
-	{
-	  item_number *rhsp;
-	  if (rules[r].lhs->number == i)
-	    left_count++;
-	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-	    if (item_number_as_symbol_number (*rhsp) == i)
-	      {
-		right_count++;
-		break;
-	      }
-	}
-
       xml_printf (out, level + 2,
 		  "<nonterminal symbol-number=\"%d\" name=\"%s\""
-                  " usefulness=\"%s\">",
+                  " usefulness=\"%s\"/>",
 		  i, xml_escape (tag),
                   reduce_nonterminal_useless_in_grammar (i)
                     ? "useless-in-grammar" : "useful");
-
-      if (left_count > 0)
-	{
-	  xml_puts (out, level + 3, "<left>");
-	  for (r = 0; r < nrules; r++)
-	    {
-	      if (rules[r].lhs->number == i)
-		xml_printf (out, level + 4, "<rule>%d</rule>", r);
-	    }
-	  xml_puts (out, level + 3, "</left>");
-	}
-
-      if (right_count > 0)
-	{
-	  xml_puts (out, level + 3, "<right>");
-	  for (r = 0; r < nrules; r++)
-	    {
-	      item_number *rhsp;
-	      for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-		if (item_number_as_symbol_number (*rhsp) == i)
-		  {
-		    xml_printf (out, level + 4, "<rule>%d</rule>", r);
-		    break;
-		  }
-	    }
-	  xml_puts (out, level + 3, "</right>");
-	}
-
-      xml_puts (out, level + 2, "</nonterminal>");
     }
   xml_puts (out, level + 1, "</nonterminals>");
   xml_puts (out, level, "</grammar>");
