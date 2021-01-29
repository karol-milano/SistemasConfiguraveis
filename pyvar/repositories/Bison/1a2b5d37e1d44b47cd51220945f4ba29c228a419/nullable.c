@@ -69,21 +69,21 @@ set_nullable (void)
   p = relts;
 
   for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
-    if (rule_table[ruleno].useful)
+    if (rules[ruleno].useful)
       {
-	if (ritem[rule_table[ruleno].rhs] >= 0)
+	if (ritem[rules[ruleno].rhs] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
 	    short *r;
 	    int any_tokens = 0;
-	    for (r = &ritem[rule_table[ruleno].rhs]; *r >= 0; ++r)
+	    for (r = &ritem[rules[ruleno].rhs]; *r >= 0; ++r)
 	      if (ISTOKEN (*r))
 		any_tokens = 1;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
 	    if (!any_tokens)
-	      for (r = &ritem[rule_table[ruleno].rhs]; *r >= 0; ++r)
+	      for (r = &ritem[rules[ruleno].rhs]; *r >= 0; ++r)
 		{
 		  rcount[ruleno]++;
 		  p->next = rsets[*r];
@@ -95,11 +95,11 @@ set_nullable (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    assert (ritem[rule_table[ruleno].rhs] == -ruleno);
-	    if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
+	    assert (ritem[rules[ruleno].rhs] == -ruleno);
+	    if (rules[ruleno].useful && !nullable[rules[ruleno].lhs])
 	      {
-		nullable[rule_table[ruleno].lhs] = 1;
-		*s2++ = rule_table[ruleno].lhs;
+		nullable[rules[ruleno].lhs] = 1;
+		*s2++ = rules[ruleno].lhs;
 	      }
 	  }
       }
@@ -109,10 +109,10 @@ set_nullable (void)
       {
 	ruleno = p->value;
 	if (--rcount[ruleno] == 0)
-	  if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
+	  if (rules[ruleno].useful && !nullable[rules[ruleno].lhs])
 	    {
-	      nullable[rule_table[ruleno].lhs] = 1;
-	      *s2++ = rule_table[ruleno].lhs;
+	      nullable[rules[ruleno].lhs] = 1;
+	      *s2++ = rules[ruleno].lhs;
 	    }
       }
 
