@@ -102,7 +102,7 @@ set_nullable (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    assert (rule_number_of_item_number (rule->rhs[0]) == ruleno);
+	    assert (item_number_as_rule_number (rule->rhs[0]) == ruleno);
 	    if (rule->useful && !nullable[rule->lhs->number])
 	      {
 		nullable[rule->lhs->number] = 1;
