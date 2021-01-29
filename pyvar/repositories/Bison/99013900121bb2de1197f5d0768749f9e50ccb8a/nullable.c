@@ -71,19 +71,19 @@ set_nullable (void)
   for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
     if (rules[ruleno].useful)
       {
-	if (ritem[rules[ruleno].rhs] >= 0)
+	if (rules[ruleno].rhs[0] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
 	    short *r;
 	    int any_tokens = 0;
-	    for (r = &ritem[rules[ruleno].rhs]; *r >= 0; ++r)
+	    for (r = rules[ruleno].rhs; *r >= 0; ++r)
 	      if (ISTOKEN (*r))
 		any_tokens = 1;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
 	    if (!any_tokens)
-	      for (r = &ritem[rules[ruleno].rhs]; *r >= 0; ++r)
+	      for (r = rules[ruleno].rhs; *r >= 0; ++r)
 		{
 		  rcount[ruleno]++;
 		  p->next = rsets[*r];
@@ -95,7 +95,7 @@ set_nullable (void)
 	else
 	  {
 	    /* This rule has an empty RHS. */
-	    assert (ritem[rules[ruleno].rhs] == -ruleno);
+	    assert (rules[ruleno].rhs[0] == -ruleno);
 	    if (rules[ruleno].useful && !nullable[rules[ruleno].lhs])
 	      {
 		nullable[rules[ruleno].lhs] = 1;
