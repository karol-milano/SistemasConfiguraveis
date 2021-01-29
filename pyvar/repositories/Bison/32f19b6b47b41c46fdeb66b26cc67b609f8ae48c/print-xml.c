@@ -429,8 +429,9 @@ print_grammar (FILE *out, int level)
 	item_number *rhsp;
 
 	xml_printf (out, level + 2,
-		    "<terminal number=\"%d\" name=\"%s\">",
-		    i, xml_escape (tag));
+		    "<terminal symbol-number=\"%d\" token-number=\"%d\""
+                    " name=\"%s\">",
+		    token_translations[i], i, xml_escape (tag));
 
 	for (r = 0; r < nrules; r++)
 	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
@@ -465,7 +466,7 @@ print_grammar (FILE *out, int level)
 	}
 
       xml_printf (out, level + 2,
-		  "<nonterminal number=\"%d\" name=\"%s\">",
+		  "<nonterminal symbol-number=\"%d\" name=\"%s\">",
 		  i, xml_escape (tag));
 
       if (left_count > 0)
