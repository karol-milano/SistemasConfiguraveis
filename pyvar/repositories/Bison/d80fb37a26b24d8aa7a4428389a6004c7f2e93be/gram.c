@@ -197,45 +197,41 @@ grammar_rules_partial_print (FILE *out, const char *title,
 }
 
 void
-grammar_rules_partial_print_xml (FILE *out, int level, bool rtag,
-				 rule_filter filter)
+grammar_rules_print (FILE *out)
+{
+  grammar_rules_partial_print (out, _("Grammar"), rule_useful_in_grammar_p);
+}
+
+void
+grammar_rules_print_xml (FILE *out, int level)
 {
   rule_number r;
   bool first = true;
 
   for (r = 0; r < nrules + nuseless_productions; r++)
     {
-      if (filter && !filter (&rules[r]))
-	continue;
-      if (rtag && first)
+      if (first)
 	xml_puts (out, level + 1, "<rules>");
       first = false;
-
-      xml_printf (out, level + 2, "<rule number=\"%d\">",
-		  rules[r].number);
+      {
+        char const *usefulness;
+        if (rule_useless_in_grammar_p (&rules[r]))
+          usefulness = "useless-in-grammar";
+        else if (rule_useless_in_parser_p (&rules[r]))
+          usefulness = "useless-in-parser";
+        else
+          usefulness = "useful";
+        xml_printf (out, level + 2, "<rule number=\"%d\" usefulness=\"%s\">",
+                    rules[r].number, usefulness);
+      }
       rule_lhs_print_xml (&rules[r], out, level + 3);
       rule_rhs_print_xml (&rules[r], out, level + 3);
       xml_puts (out, level + 2, "</rule>");
     }
-  if (rtag)
-    {
-      if (!first)
-	xml_puts (out, level + 1, "</rules>");
-      else
-	xml_puts (out, level + 1, "<rules/>");
-    }
-}
-
-void
-grammar_rules_print (FILE *out)
-{
-  grammar_rules_partial_print (out, _("Grammar"), rule_useful_in_grammar_p);
-}
-
-void
-grammar_rules_print_xml (FILE *out, int level)
-{
-  grammar_rules_partial_print_xml (out, level, true, rule_useful_in_grammar_p);
+  if (!first)
+    xml_puts (out, level + 1, "</rules>");
+  else
+   xml_puts (out, level + 1, "<rules/>");
 }
 
 void
