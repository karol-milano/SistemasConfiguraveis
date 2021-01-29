@@ -1922,8 +1922,7 @@ packgram (void)
   bucket *ruleprec;
 
   ritem = XCALLOC (short, nitems + 1);
-  rlhs = XCALLOC (short, nrules) - 1;
-  rrhs = XCALLOC (short, nrules) - 1;
+  rule_table = XCALLOC (rule_t, nrules) - 1;
   rprec = XCALLOC (short, nrules) - 1;
   rprecsym = XCALLOC (short, nrules) - 1;
   rassoc = XCALLOC (short, nrules) - 1;
@@ -1934,8 +1933,8 @@ packgram (void)
   p = grammar;
   while (p)
     {
-      rlhs[ruleno] = p->sym->value;
-      rrhs[ruleno] = itemno;
+      rule_table[ruleno].lhs = p->sym->value;
+      rule_table[ruleno].rhs = itemno;
       ruleprec = p->ruleprec;
 
       p = p->next;
