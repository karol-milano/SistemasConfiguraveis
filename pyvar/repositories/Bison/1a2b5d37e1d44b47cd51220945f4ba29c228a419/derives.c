@@ -44,7 +44,7 @@ print_derives (void)
 	{
 	  short *rhsp;
 	  fprintf (stderr, "\t\t%d:", *sp);
-	  for (rhsp = &ritem[rule_table[*sp].rhs]; *rhsp >= 0; ++rhsp)
+	  for (rhsp = &ritem[rules[*sp].rhs]; *rhsp >= 0; ++rhsp)
 	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	  fprintf (stderr, " (rule %d)\n", -*rhsp - 1);
 	}
@@ -68,9 +68,9 @@ set_derives (void)
 
   p = delts;
   for (i = nrules; i > 0; i--)
-    if (rule_table[i].useful)
+    if (rules[i].useful)
       {
-	int lhs = rule_table[i].lhs;
+	int lhs = rules[i].lhs;
 	p->next = dset[lhs];
 	p->value = i;
 	dset[lhs] = p;
