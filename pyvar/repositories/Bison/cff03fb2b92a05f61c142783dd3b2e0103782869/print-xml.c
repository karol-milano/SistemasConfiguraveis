@@ -51,19 +51,19 @@ struct escape_buf
 static struct escape_buf escape_bufs[2];
 
 
-/*----------------------------.
-| Print rules never reduced.  |
-`-----------------------------*/
+/*--------------------------------.
+| Print rules useless in parser.  |
+`--------------------------------*/
 
 static void
-print_rules_never_reduced (FILE *out, int level)
+print_rules_useless_in_parser (FILE *out, int level)
 {
   rule_number r;
   bool count = false;
 
   for (r = 0; r < nrules + nuseless_productions; r++)
     {
-      if (rule_never_reduced_p (&rules[r]))
+      if (rule_useless_in_parser_p (&rules[r]))
 	{
 	  count = true;
 	  break;
@@ -71,13 +71,13 @@ print_rules_never_reduced (FILE *out, int level)
     }
 
   if (count) {
-    xml_puts (out, level, "<rules-never-reduced>");
+    xml_puts (out, level, "<rules-useless-in-parser>");
     grammar_rules_partial_print_xml (out, level - 1,
-				     false, rule_never_reduced_p);
-    xml_puts (out, level, "</rules-never-reduced>");
+				     false, rule_useless_in_parser_p);
+    xml_puts (out, level, "</rules-useless-in-parser>");
   }
   else
-    xml_puts (out, level, "<rules-never-reduced/>");
+    xml_puts (out, level, "<rules-useless-in-parser/>");
 }
 
 /*--------------------------------.
@@ -587,8 +587,8 @@ print_xml (void)
   /* print reductions */
   reduce_xml (out, level + 1);
 
-  /* print rules never reduced */
-  print_rules_never_reduced (out, level + 1);
+  /* print rules useless in parser */
+  print_rules_useless_in_parser (out, level + 1);
 
   /* print grammar */
   print_grammar (out, level + 1);
