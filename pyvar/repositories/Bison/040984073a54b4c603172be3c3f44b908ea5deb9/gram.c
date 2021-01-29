@@ -269,7 +269,7 @@ grammar_dump (FILE *out, const char *title)
 	rule *rule_i = &rules[i];
 	item_number *rp = NULL;
 	unsigned int rhs_itemno = rule_i->rhs - ritem;
-  	unsigned int rhs_count = 0;
+	unsigned int rhs_count = 0;
 	/* Find the last RHS index in ritems. */
 	for (rp = rule_i->rhs; *rp >= 0; ++rp)
 	  ++rhs_count;
