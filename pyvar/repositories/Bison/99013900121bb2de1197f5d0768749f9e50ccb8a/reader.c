@@ -1688,7 +1688,7 @@ packgram (void)
     {
       bucket *ruleprec = p->ruleprec;
       rules[ruleno].lhs = p->sym->value;
-      rules[ruleno].rhs = itemno;
+      rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].line = p->line;
       rules[ruleno].useful = TRUE;
       rules[ruleno].action = p->action;
