@@ -83,10 +83,10 @@ nullable_compute (void)
 	  {
 	    /* This rule has a non empty RHS. */
 	    item_number *rp = NULL;
-	    int any_tokens = 0;
+	    bool any_tokens = false;
 	    for (rp = rules_ruleno->rhs; *rp >= 0; ++rp)
 	      if (ISTOKEN (*rp))
-		any_tokens = 1;
+		any_tokens = true;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
@@ -108,7 +108,7 @@ nullable_compute (void)
 	    if (rules_ruleno->useful
 		&& ! nullable[rules_ruleno->lhs->number - ntokens])
 	      {
-		nullable[rules_ruleno->lhs->number - ntokens] = 1;
+		nullable[rules_ruleno->lhs->number - ntokens] = true;
 		*s2++ = rules_ruleno->lhs->number;
 	      }
 	  }
@@ -121,7 +121,7 @@ nullable_compute (void)
 	if (--rcount[r->number] == 0)
 	  if (r->useful && ! nullable[r->lhs->number - ntokens])
 	    {
-	      nullable[r->lhs->number - ntokens] = 1;
+	      nullable[r->lhs->number - ntokens] = true;
 	      *s2++ = r->lhs->number;
 	    }
       }
