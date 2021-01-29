@@ -239,7 +239,7 @@ reduce_grammar_tables (void)
     rule_number r;
     for (r = 0; r < nrules; r++)
       rules[r].useful = bitset_test (P, r);
-    grammar_rules_never_reduced_report (_("useless rule"));
+    grammar_rules_useless_report (_("rule useless in grammar"));
   }
 
   /* Map the nonterminals to their new index: useful first, useless
@@ -300,7 +300,7 @@ nonterminals_reduce (void)
     if (!bitset_test (V, i))
       {
 	nontermmap[i - ntokens] = n++;
-	warn_at (symbols[i]->location, _("useless nonterminal: %s"),
+	warn_at (symbols[i]->location, _("nonterminal useless in grammar: %s"),
 		 symbols[i]->tag);
       }
 
@@ -348,7 +348,7 @@ reduce_output (FILE *out)
   if (nuseless_nonterminals > 0)
     {
       int i;
-      fprintf (out, "%s\n\n", _("Useless nonterminals"));
+      fprintf (out, "%s\n\n", _("Nonterminals useless in grammar"));
       for (i = 0; i < nuseless_nonterminals; ++i)
 	fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
@@ -370,8 +370,8 @@ reduce_output (FILE *out)
   }
 
   if (nuseless_productions > 0)
-    grammar_rules_partial_print (out, _("Useless rules"),
-				 rule_useless_p);
+    grammar_rules_partial_print (out, _("Rules useless in grammar"),
+				 rule_useless_in_grammar_p);
 }
 
 
@@ -384,7 +384,7 @@ reduce_xml (FILE *out, int level)
 {
   fputc ('\n', out);
   xml_puts (out, level, "<reductions>");
-  xml_puts (out, level + 1, "<useless>");
+  xml_puts (out, level + 1, "<useless-in-grammar>");
 
   if (nuseless_nonterminals > 0)
     {
@@ -400,11 +400,12 @@ reduce_xml (FILE *out, int level)
     xml_puts (out, level + 2, "<nonterminals/>");
 
   if (nuseless_productions > 0)
-    grammar_rules_partial_print_xml (out, level + 1, true, rule_useless_p);
+    grammar_rules_partial_print_xml (out, level + 1, true,
+                                     rule_useless_in_grammar_p);
   else
     xml_puts (out, level + 2, "<rules/>");
 
-  xml_puts (out, level + 1, "</useless>");
+  xml_puts (out, level + 1, "</useless-in-grammar>");
   xml_puts (out, level + 1, "<unused>");
 
   {
@@ -439,17 +440,11 @@ reduce_xml (FILE *out, int level)
 static void
 reduce_print (void)
 {
-  if (yacc_flag && nuseless_productions)
-    fprintf (stderr, ngettext ("%d rule never reduced\n",
-			       "%d rules never reduced\n",
-			       nuseless_productions),
-	     nuseless_productions);
-
   fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
 
   if (nuseless_nonterminals > 0)
-    fprintf (stderr, ngettext ("%d useless nonterminal",
-			       "%d useless nonterminals",
+    fprintf (stderr, ngettext ("%d nonterminal",
+			       "%d nonterminals",
 			       nuseless_nonterminals),
 	     nuseless_nonterminals);
 
@@ -457,10 +452,13 @@ reduce_print (void)
     fprintf (stderr, _(" and "));
 
   if (nuseless_productions > 0)
-    fprintf (stderr, ngettext ("%d useless rule",
-			       "%d useless rules",
+    fprintf (stderr, ngettext ("%d rule",
+			       "%d rules",
 			       nuseless_productions),
 	     nuseless_productions);
+
+  if (nuseless_nonterminals > 0 || nuseless_productions > 0)
+    fprintf (stderr, _(" useless in grammar"));
   fprintf (stderr, "\n");
 }
 
