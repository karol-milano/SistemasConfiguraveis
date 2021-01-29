@@ -264,7 +264,7 @@ reduce_grammar_tables (void)
 	item_number_t *rhsp = rules[r].rhs;
 	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
 	  /* Nothing. */;
-	*rhsp = item_number_of_rule_number (r);
+	*rhsp = rule_number_as_item_number (r);
 	rules[r].number = r;
       }
     nrules -= nuseless_productions;
