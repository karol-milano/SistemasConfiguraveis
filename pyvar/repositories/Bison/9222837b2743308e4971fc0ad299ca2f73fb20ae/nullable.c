@@ -46,7 +46,7 @@ nullable_print (FILE *out)
 void
 set_nullable (void)
 {
-  int ruleno;
+  rule_number_t ruleno;
   symbol_number_t *s1;
   symbol_number_t *s2;
   shorts *p;
@@ -71,19 +71,20 @@ set_nullable (void)
   for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
     if (rules[ruleno].useful)
       {
-	if (rules[ruleno].rhs[0] >= 0)
+	rule_t *rule = &rules[ruleno];
+	if (rule->rhs[0] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
-	    item_number_t *r;
+	    item_number_t *r = NULL;
 	    int any_tokens = 0;
-	    for (r = rules[ruleno].rhs; *r >= 0; ++r)
+	    for (r = rule->rhs; *r >= 0; ++r)
 	      if (ISTOKEN (*r))
 		any_tokens = 1;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
 	    if (!any_tokens)
-	      for (r = rules[ruleno].rhs; *r >= 0; ++r)
+	      for (r = rule->rhs; *r >= 0; ++r)
 		{
 		  rcount[ruleno]++;
 		  p->next = rsets[*r];
@@ -95,11 +96,11 @@ set_nullable (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    assert (rules[ruleno].rhs[0] == -ruleno);
-	    if (rules[ruleno].useful && !nullable[rules[ruleno].lhs->number])
+	    assert (rule_number_of_item_number (rule->rhs[0]) == ruleno);
+	    if (rule->useful && !nullable[rule->lhs->number])
 	      {
-		nullable[rules[ruleno].lhs->number] = 1;
-		*s2++ = rules[ruleno].lhs->number;
+		nullable[rule->lhs->number] = 1;
+		*s2++ = rule->lhs->number;
 	      }
 	  }
       }
