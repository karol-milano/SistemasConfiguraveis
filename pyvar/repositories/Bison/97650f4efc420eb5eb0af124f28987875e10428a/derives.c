@@ -45,7 +45,7 @@ print_derives (void)
 	  item_number_t *rhsp;
 	  fprintf (stderr, "\t\t%d:", *rp);
 	  for (rhsp = rules[*rp].rhs; *rhsp >= 0; ++rhsp)
-	    fprintf (stderr, " %s", symbol_tag_get (symbols[*rhsp]));
+	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	  fprintf (stderr, " (rule %d)\n",
 		   rule_number_of_item_number (*rhsp) - 1);
 	}
