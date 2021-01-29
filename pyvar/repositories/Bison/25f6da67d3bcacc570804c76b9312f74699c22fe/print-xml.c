@@ -108,6 +108,7 @@ print_core (FILE *out, int level, state *s)
 
   for (i = 0; i < snritems; i++)
     {
+      bool printed = false;
       item_number *sp;
       item_number *sp1;
       rule_number r;
@@ -118,30 +119,33 @@ print_core (FILE *out, int level, state *s)
 	sp++;
 
       r = item_number_as_rule_number (*sp);
-
-      xml_printf (out, level + 1, "<rule number=\"%d\">",
-		  rules[r].number);
-
-      rule_lhs_print_xml (&rules[r], out, level + 2);
-
-      xml_puts (out, level + 2, "<rhs>");
-      for (sp = rules[r].rhs; sp < sp1; sp++)
-	xml_printf (out, level + 3, "<symbol class=\"%s\">%s</symbol>",
-		    symbol_class_get_string (symbols[*sp]),
-		    xml_escape (symbols[*sp]->tag));
-      xml_puts (out, level + 3, "<point/>");
-      for (/* Nothing */; *sp >= 0; ++sp)
-	xml_printf (out, level + 3, "<symbol class=\"%s\">%s</symbol>",
-		    symbol_class_get_string (symbols[*sp]),
-		    xml_escape (symbols[*sp]->tag));
-
-      xml_puts (out, level + 2, "</rhs>");
+      sp = rules[r].rhs;
 
       /* Display the lookahead tokens?  */
       if (report_flag & report_lookahead_tokens)
-	state_rule_lookahead_tokens_print_xml (s, &rules[r], out, level + 2);
+	{
+	  reductions *reds = s->reductions;
+	  int red = state_reduction_find (s, &rules[r]);
+	  /* Print item with lookaheads if there are. */
+	  if (reds->lookahead_tokens && red != -1)
+	    {
+	      xml_printf (out, level + 1,
+			  "<item rule-number=\"%d\" point=\"%d\">",
+			  rules[r].number, sp1 - sp);
+	      state_rule_lookahead_tokens_print_xml (s, &rules[r],
+						     out, level + 2);
+	      xml_puts (out, level + 1, "</item>");
+	      printed = true;
+	    }
+	}
 
-      xml_puts (out, level + 1, "</rule>");
+      if (!printed)
+	{
+	  xml_printf (out, level + 1,
+		      "<item rule-number=\"%d\" point=\"%d\"/>",
+		      rules[r].number,
+		      sp1 - sp);
+	}
     }
   xml_puts (out, level, "</itemset>");
 }
