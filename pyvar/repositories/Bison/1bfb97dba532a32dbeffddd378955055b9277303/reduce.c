@@ -439,8 +439,9 @@ reduce_grammar (void)
   reduce_print ();
 
   if (!bitset_test (N, axiom->number - ntokens))
-    fatal (_("Start symbol %s does not derive any sentence"),
-	   symbols[axiom->number]->tag);
+    fatal_at (startsymbol_location,
+	      _("start symbol %s does not derive any sentence"),
+	      startsymbol->tag);
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
