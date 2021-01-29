@@ -1720,7 +1720,7 @@ packgram (void)
     fatal (_("too many items (max %d)"), MAXSHORT);
 
   ritem = XCALLOC (short, nitems + 1);
-  rule_table = XCALLOC (rule_t, nrules) - 1;
+  rules = XCALLOC (rule_t, nrules) - 1;
 
   itemno = 0;
   ruleno = 1;
@@ -1729,14 +1729,14 @@ packgram (void)
   while (p)
     {
       bucket *ruleprec = p->ruleprec;
-      rule_table[ruleno].lhs = p->sym->value;
-      rule_table[ruleno].rhs = itemno;
-      rule_table[ruleno].line = p->line;
-      rule_table[ruleno].useful = TRUE;
-      rule_table[ruleno].action = p->action;
-      rule_table[ruleno].action_line = p->action_line;
-      rule_table[ruleno].guard = p->guard;
-      rule_table[ruleno].guard_line = p->guard_line;
+      rules[ruleno].lhs = p->sym->value;
+      rules[ruleno].rhs = itemno;
+      rules[ruleno].line = p->line;
+      rules[ruleno].useful = TRUE;
+      rules[ruleno].action = p->action;
+      rules[ruleno].action_line = p->action_line;
+      rules[ruleno].guard = p->guard;
+      rules[ruleno].guard_line = p->guard_line;
 
       p = p->next;
       while (p && p->sym)
@@ -1746,8 +1746,8 @@ packgram (void)
 	     of the last token in it.  */
 	  if (p->sym->class == token_sym)
 	    {
-	      rule_table[ruleno].prec = p->sym->prec;
-	      rule_table[ruleno].assoc = p->sym->assoc;
+	      rules[ruleno].prec = p->sym->prec;
+	      rules[ruleno].assoc = p->sym->assoc;
 	    }
 	  if (p)
 	    p = p->next;
@@ -1757,9 +1757,9 @@ packgram (void)
          the specified symbol's precedence replaces the default.  */
       if (ruleprec)
 	{
-	  rule_table[ruleno].prec = ruleprec->prec;
-	  rule_table[ruleno].assoc = ruleprec->assoc;
-	  rule_table[ruleno].precsym = ruleprec->value;
+	  rules[ruleno].prec = ruleprec->prec;
+	  rules[ruleno].assoc = ruleprec->assoc;
+	  rules[ruleno].precsym = ruleprec->value;
 	}
 
       ritem[itemno++] = -ruleno;
