@@ -99,7 +99,8 @@ nullable_compute (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    assert (item_number_as_rule_number (rule->rhs[0]) == ruleno);
+	    if (item_number_as_rule_number (rule->rhs[0]) != ruleno)
+	      abort ();
 	    if (rule->useful && !nullable[rule->lhs->number])
 	      {
 		nullable[rule->lhs->number] = 1;
