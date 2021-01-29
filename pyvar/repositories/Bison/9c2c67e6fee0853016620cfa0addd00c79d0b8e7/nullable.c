@@ -69,35 +69,38 @@ set_nullable (void)
   p = relts;
 
   for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
-    if (ritem[rule_table[ruleno].rhs] > 0)
+    if (rule_table[ruleno].useful)
       {
-	/* This rule has a non empty RHS. */
-	short *r;
-	int any_tokens = 0;
-	for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
-	  if (ISTOKEN (*r))
-	    any_tokens = 1;
-
-	/* This rule has only nonterminals: schedule it for the second
-	   pass.  */
-	if (!any_tokens)
-	  for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
-	    {
-	      rcount[ruleno]++;
-	      p->next = rsets[*r];
-	      p->value = ruleno;
-	      rsets[*r] = p;
-	      p++;
-	    }
-      }
-    else
-      {
-	/* This rule has an empty RHS. */
-	assert (ritem[rule_table[ruleno].rhs] == -ruleno);
-	if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
+	if (ritem[rule_table[ruleno].rhs] > 0)
+	  {
+	    /* This rule has a non empty RHS. */
+	    short *r;
+	    int any_tokens = 0;
+	    for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
+	      if (ISTOKEN (*r))
+		any_tokens = 1;
+
+	    /* This rule has only nonterminals: schedule it for the second
+	       pass.  */
+	    if (!any_tokens)
+	      for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
+		{
+		  rcount[ruleno]++;
+		  p->next = rsets[*r];
+		  p->value = ruleno;
+		  rsets[*r] = p;
+		  p++;
+		}
+	  }
+	else
 	  {
-	    nullable[rule_table[ruleno].lhs] = 1;
-	    *s2++ = rule_table[ruleno].lhs;
+	    /* This rule has an empty RHS. */
+	    assert (ritem[rule_table[ruleno].rhs] == -ruleno);
+	    if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
+	      {
+		nullable[rule_table[ruleno].lhs] = 1;
+		*s2++ = rule_table[ruleno].lhs;
+	      }
 	  }
       }
 
