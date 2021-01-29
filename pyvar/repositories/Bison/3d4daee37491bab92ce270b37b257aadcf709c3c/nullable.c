@@ -71,19 +71,19 @@ set_nullable (void)
   for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
     if (rule_table[ruleno].useful)
       {
-	if (ritem[rule_table[ruleno].rhs] > 0)
+	if (ritem[rule_table[ruleno].rhs] >= 0)
 	  {
 	    /* This rule has a non empty RHS. */
 	    short *r;
 	    int any_tokens = 0;
-	    for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
+	    for (r = &ritem[rule_table[ruleno].rhs]; *r >= 0; ++r)
 	      if (ISTOKEN (*r))
 		any_tokens = 1;
 
 	    /* This rule has only nonterminals: schedule it for the second
 	       pass.  */
 	    if (!any_tokens)
-	      for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
+	      for (r = &ritem[rule_table[ruleno].rhs]; *r >= 0; ++r)
 		{
 		  rcount[ruleno]++;
 		  p->next = rsets[*r];
