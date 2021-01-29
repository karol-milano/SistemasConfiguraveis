@@ -46,70 +46,65 @@ nullable_print (FILE *out)
 void
 set_nullable (void)
 {
-  short *r;
+  int ruleno;
   short *s1;
   short *s2;
   shorts *p;
 
-  short *squeue;
-  short *rcount;
-  shorts **rsets;
-  shorts *relts;
+  short *squeue = XCALLOC (short, nvars);
+  short *rcount = XCALLOC (short, nrules + 1);
+  /* RITEM contains all the rules, including useless productions.
+     Hence we must allocate room for useless nonterminals too.  */
+  shorts **rsets = XCALLOC (shorts *, nvars) - ntokens;
+  /* This is said to be more elements than we actually use.
+     Supposedly nitems - nrules is enough.  But why take the risk?  */
+  shorts *relts = XCALLOC (shorts, nitems + nvars + 1);
 
   if (trace_flag)
     fprintf (stderr, "Entering set_nullable\n");
 
   nullable = XCALLOC (char, nvars) - ntokens;
 
-  squeue = XCALLOC (short, nvars);
   s1 = s2 = squeue;
-
-  rcount = XCALLOC (short, nrules + 1);
-
-  /* RITEM contains all the rules, including useless productions.
-     Hence we must allocate room for useless nonterminals too.  */
-  rsets = XCALLOC (shorts *, nvars + nuseless_nonterminals) - ntokens;
-  /* This is said to be more elements than we actually use.
-     Supposedly nitems - nrules is enough.
-     But why take the risk?  */
-  relts = XCALLOC (shorts, nitems + nvars + nuseless_nonterminals + 1);
   p = relts;
 
-  for (r = ritem; *r; ++r)
-    {
-      /* Walk RITEM to find (i), if there are any tokens in the
-	 RHS, and (ii), to find RULENO. */
-      int ruleno;
-      int any_tokens = 0;
-      short *r1;
-      for (r1 = r; *r1 > 0; ++r1)
-	if (ISTOKEN (*r1))
-	  any_tokens = 1;
-      ruleno = -*r1;
-
-      /* Examine the RHS of the rule.  */
-      if (!any_tokens)
-	for (/* Nothing. */; *r > 0; ++r)
+  for (ruleno = 1; ruleno < nrules + 1; ++ruleno)
+    if (ritem[rule_table[ruleno].rhs] > 0)
+      {
+	/* This rule has a non empty RHS. */
+	short *r;
+	int any_tokens = 0;
+	for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
+	  if (ISTOKEN (*r))
+	    any_tokens = 1;
+
+	/* This rule has only nonterminals: schedule it for the second
+	   pass.  */
+	if (!any_tokens)
+	  for (r = ritem + rule_table[ruleno].rhs; *r > 0; ++r)
+	    {
+	      rcount[ruleno]++;
+	      p->next = rsets[*r];
+	      p->value = ruleno;
+	      rsets[*r] = p;
+	      p++;
+	    }
+      }
+    else
+      {
+	/* This rule has an empty RHS. */
+	assert (ritem[rule_table[ruleno].rhs] == -ruleno);
+	if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
 	  {
-	    rcount[ruleno]++;
-	    p->next = rsets[*r];
-	    p->value = ruleno;
-	    rsets[*r] = p;
-	    p++;
+	    nullable[rule_table[ruleno].lhs] = 1;
+	    *s2++ = rule_table[ruleno].lhs;
 	  }
-
-      /* Examine its LHS. */
-      if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
-	{
-	  nullable[rule_table[ruleno].lhs] = 1;
-	  *s2++ = rule_table[ruleno].lhs;
-        }
-    }
+      }
 
   while (s1 < s2)
     for (p = rsets[*s1++]; p; p = p->next)
       {
-	int ruleno = p->value;
+	ruleno = p->value;
 	if (--rcount[ruleno] == 0)
 	  if (rule_table[ruleno].useful && !nullable[rule_table[ruleno].lhs])
 	    {
