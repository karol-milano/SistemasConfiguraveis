@@ -429,7 +429,7 @@ print_grammar (FILE *out, int level)
 	item_number *rhsp;
 
 	xml_printf (out, level + 2,
-		    "<terminal type=\"%d\" symbol=\"%s\">",
+		    "<terminal number=\"%d\" name=\"%s\">",
 		    i, xml_escape (tag));
 
 	for (r = 0; r < nrules; r++)
@@ -465,7 +465,7 @@ print_grammar (FILE *out, int level)
 	}
 
       xml_printf (out, level + 2,
-		  "<nonterminal type=\"%d\" symbol=\"%s\">",
+		  "<nonterminal number=\"%d\" name=\"%s\">",
 		  i, xml_escape (tag));
 
       if (left_count > 0)
