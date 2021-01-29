@@ -1688,7 +1688,7 @@ packgram (void)
     {
       bucket *ruleprec = p->ruleprec;
       rules[ruleno].number = ruleno;
-      rules[ruleno].lhs = p->sym->number;
+      rules[ruleno].lhs = p->sym;
       rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].line = p->line;
       rules[ruleno].useful = TRUE;
