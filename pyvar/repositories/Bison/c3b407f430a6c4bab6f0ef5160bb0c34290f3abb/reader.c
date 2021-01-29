@@ -1687,6 +1687,7 @@ packgram (void)
   while (p)
     {
       bucket *ruleprec = p->ruleprec;
+      rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym->number;
       rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].line = p->line;
