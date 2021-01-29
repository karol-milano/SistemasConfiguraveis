@@ -1971,6 +1971,7 @@ packgram (void)
       rule_table[ruleno].lhs = p->sym->value;
       rule_table[ruleno].rhs = itemno;
       rule_table[ruleno].line = p->line;
+      rule_table[ruleno].useful = TRUE;
 
       p = p->next;
       while (p && p->sym)
