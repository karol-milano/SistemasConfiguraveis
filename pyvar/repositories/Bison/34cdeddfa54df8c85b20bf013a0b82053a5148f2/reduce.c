@@ -418,7 +418,7 @@ reduce_xml (FILE *out, int level)
 	  b = true;
 	  xml_printf (out, level + 3,
 		      "<terminal>%s</terminal>",
-		      symbols[i]->tag);
+		      xml_escape (symbols[i]->tag));
 	}
     if (b)
       xml_puts (out, level + 2, "</terminals>");
