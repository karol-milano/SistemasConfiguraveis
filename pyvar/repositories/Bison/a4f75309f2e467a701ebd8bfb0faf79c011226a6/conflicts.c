@@ -145,7 +145,7 @@ log_resolution (rule *r, symbol_number token,
 	    case shift_resolution:
 	    case right_resolution:
 	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "<resolution rule=\"%d\" symbol=\"%s\""
+			      "        <resolution rule=\"%d\" symbol=\"%s\""
 			      " type=\"shift\">",
 			      r->number,
 			      xml_escape (symbols[token]->tag));
@@ -154,7 +154,7 @@ log_resolution (rule *r, symbol_number token,
 	    case reduce_resolution:
 	    case left_resolution:
 	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "<resolution rule=\"%d\" symbol=\"%s\""
+			      "        <resolution rule=\"%d\" symbol=\"%s\""
 			      " type=\"reduce\">",
 			      r->number,
 			      xml_escape (symbols[token]->tag));
@@ -162,7 +162,7 @@ log_resolution (rule *r, symbol_number token,
 
 	    case nonassoc_resolution:
 	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "<resolution rule=\"%d\" symbol=\"%s\""
+			      "        <resolution rule=\"%d\" symbol=\"%s\""
 			      " type=\"error\">",
 			      r->number,
 			      xml_escape (symbols[token]->tag));
