@@ -235,15 +235,8 @@ reduce_grammar_tables (void)
   {
     rule_number_t r;
     for (r = 0; r < nrules; r++)
-      {
-	rules[r].useful = bitset_test (P, r);
-	if (!rules[r].useful)
-	  {
-	    LOCATION_PRINT (stderr, rules[r].location);
-	    fprintf (stderr, ": %s: %s: ", _("warning"), _("useless rule"));
-	    rule_print (&rules[r], stderr);
-	  }
-      }
+      rules[r].useful = bitset_test (P, r);
+    grammar_rules_never_reduced_report (_("useless rule"));
   }
 
   /* Map the nonterminals to their new index: useful first, useless
@@ -353,7 +346,7 @@ reduce_output (FILE *out)
   if (nuseless_nonterminals > 0)
     {
       int i;
-      fprintf (out, "%s\n\n", _("Useless nonterminals:"));
+      fprintf (out, "%s\n\n", _("Useless nonterminals"));
       for (i = 0; i < nuseless_nonterminals; ++i)
 	fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
@@ -366,7 +359,7 @@ reduce_output (FILE *out)
       if (!bitset_test (V, i) && !bitset_test (V1, i))
 	{
 	  if (!b)
-	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
+	    fprintf (out, "%s\n\n", _("Terminals which are not used"));
 	  b = TRUE;
 	  fprintf (out, "   %s\n", symbols[i]->tag);
 	}
@@ -376,8 +369,7 @@ reduce_output (FILE *out)
 
   if (nuseless_productions > 0)
     grammar_rules_partial_print (out, _("Useless rules"),
-				 nrules,
-				 nrules + nuseless_productions);
+				 rule_useless_p);
 }
 
 
