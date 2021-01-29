@@ -104,8 +104,8 @@ nullable_compute (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    assert (item_number_as_rule_number (rules_ruleno->rhs[0])
-		    == ruleno);
+	    aver (item_number_as_rule_number (rules_ruleno->rhs[0])
+		  == ruleno);
 	    if (rules_ruleno->useful
 		&& ! nullable[rules_ruleno->lhs->number - ntokens])
 	      {
