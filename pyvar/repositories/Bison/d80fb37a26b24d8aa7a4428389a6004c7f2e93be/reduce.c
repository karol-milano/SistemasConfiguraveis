@@ -358,10 +358,10 @@ reduce_output (FILE *out)
     bool b = false;
     int i;
     for (i = 0; i < ntokens; i++)
-      if (!bitset_test (V, i) && !bitset_test (V1, i))
+      if (reduce_token_unused_in_grammar (i))
 	{
 	  if (!b)
-	    fprintf (out, "%s\n\n", _("Terminals which are not used"));
+	    fprintf (out, "%s\n\n", _("Terminals unused in grammar"));
 	  b = true;
 	  fprintf (out, "   %s\n", symbols[i]->tag);
 	}
@@ -375,64 +375,6 @@ reduce_output (FILE *out)
 }
 
 
-/*--------------------------------------------------------------.
-| Output the detailed results of the reductions.  For FILE.xml. |
-`---------------------------------------------------------------*/
-
-void
-reduce_xml (FILE *out, int level)
-{
-  fputc ('\n', out);
-  xml_puts (out, level, "<reductions>");
-  xml_puts (out, level + 1, "<useless-in-grammar>");
-
-  if (nuseless_nonterminals > 0)
-    {
-      int i;
-      xml_puts (out, level + 2, "<nonterminals>");
-      for (i = 0; i < nuseless_nonterminals; ++i)
-	xml_printf (out, level + 3,
-		    "<nonterminal>%s</nonterminal>",
-		    symbols[nsyms + i]->tag);
-      xml_puts (out, level + 2, "</nonterminals>");
-    }
-  else
-    xml_puts (out, level + 2, "<nonterminals/>");
-
-  if (nuseless_productions > 0)
-    grammar_rules_partial_print_xml (out, level + 1, true,
-                                     rule_useless_in_grammar_p);
-  else
-    xml_puts (out, level + 2, "<rules/>");
-
-  xml_puts (out, level + 1, "</useless-in-grammar>");
-  xml_puts (out, level + 1, "<unused>");
-
-  {
-    bool b = false;
-    int i;
-    for (i = 0; i < ntokens; i++)
-      if (!bitset_test (V, i) && !bitset_test (V1, i))
-	{
-	  if (!b)
-	    xml_puts (out, level + 2, "<terminals>");
-	  b = true;
-	  xml_printf (out, level + 3,
-		      "<terminal>%s</terminal>",
-		      xml_escape (symbols[i]->tag));
-	}
-    if (b)
-      xml_puts (out, level + 2, "</terminals>");
-    else
-      xml_puts (out, level + 2, "<terminals/>");
-  }
-
-  xml_puts (out, level + 1, "</unused>");
-  xml_puts (out, level, "</reductions>");
-  fputc ('\n', out);
-}
-
-
 /*-------------------------------.
 | Report the results to STDERR.  |
 `-------------------------------*/
@@ -506,6 +448,19 @@ reduce_grammar (void)
     }
 }
 
+bool
+reduce_token_unused_in_grammar (symbol_number i)
+{
+  aver (i < ntokens);
+  return !bitset_test (V, i) && !bitset_test (V1, i);
+}
+
+bool
+reduce_nonterminal_useless_in_grammar (symbol_number i)
+{
+  aver (ntokens <= i && i < nsyms + nuseless_nonterminals);
+  return nsyms <= i;
+}
 
 /*-----------------------------------------------------------.
 | Free the global sets used to compute the reduced grammar.  |
