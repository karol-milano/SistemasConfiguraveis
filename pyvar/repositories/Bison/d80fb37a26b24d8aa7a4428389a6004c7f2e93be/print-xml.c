@@ -51,35 +51,6 @@ struct escape_buf
 static struct escape_buf escape_bufs[2];
 
 
-/*--------------------------------.
-| Print rules useless in parser.  |
-`--------------------------------*/
-
-static void
-print_rules_useless_in_parser (FILE *out, int level)
-{
-  rule_number r;
-  bool count = false;
-
-  for (r = 0; r < nrules + nuseless_productions; r++)
-    {
-      if (rule_useless_in_parser_p (&rules[r]))
-	{
-	  count = true;
-	  break;
-	}
-    }
-
-  if (count) {
-    xml_puts (out, level, "<rules-useless-in-parser>");
-    grammar_rules_partial_print_xml (out, level - 1,
-				     false, rule_useless_in_parser_p);
-    xml_puts (out, level, "</rules-useless-in-parser>");
-  }
-  else
-    xml_puts (out, level, "<rules-useless-in-parser/>");
-}
-
 /*--------------------------------.
 | Report information on a state.  |
 `--------------------------------*/
@@ -430,8 +401,10 @@ print_grammar (FILE *out, int level)
 
 	xml_printf (out, level + 2,
 		    "<terminal symbol-number=\"%d\" token-number=\"%d\""
-                    " name=\"%s\">",
-		    token_translations[i], i, xml_escape (tag));
+                    " name=\"%s\" usefulness=\"%s\">",
+		    token_translations[i], i, xml_escape (tag),
+                    reduce_token_unused_in_grammar (token_translations[i])
+                      ? "unused-in-grammar" : "useful");
 
 	for (r = 0; r < nrules; r++)
 	  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
@@ -446,7 +419,7 @@ print_grammar (FILE *out, int level)
 
   /* Nonterminals */
   xml_puts (out, level + 1, "<nonterminals>");
-  for (i = ntokens; i < nsyms; i++)
+  for (i = ntokens; i < nsyms + nuseless_nonterminals; i++)
     {
       int left_count = 0, right_count = 0;
       rule_number r;
@@ -466,8 +439,11 @@ print_grammar (FILE *out, int level)
 	}
 
       xml_printf (out, level + 2,
-		  "<nonterminal symbol-number=\"%d\" name=\"%s\">",
-		  i, xml_escape (tag));
+		  "<nonterminal symbol-number=\"%d\" name=\"%s\""
+                  " usefulness=\"%s\">",
+		  i, xml_escape (tag),
+                  reduce_nonterminal_useless_in_grammar (i)
+                    ? "useless-in-grammar" : "useful");
 
       if (left_count > 0)
 	{
@@ -584,12 +560,6 @@ print_xml (void)
   xml_printf (out, level + 1, "<filename>%s</filename>",
 	      xml_escape (grammar_file));
 
-  /* print reductions */
-  reduce_xml (out, level + 1);
-
-  /* print rules useless in parser */
-  print_rules_useless_in_parser (out, level + 1);
-
   /* print grammar */
   print_grammar (out, level + 1);
 
