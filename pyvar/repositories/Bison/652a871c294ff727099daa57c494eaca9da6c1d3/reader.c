@@ -1923,9 +1923,6 @@ packgram (void)
 
   ritem = XCALLOC (short, nitems + 1);
   rule_table = XCALLOC (rule_t, nrules) - 1;
-  rprec = XCALLOC (short, nrules) - 1;
-  rprecsym = XCALLOC (short, nrules) - 1;
-  rassoc = XCALLOC (short, nrules) - 1;
 
   itemno = 0;
   ruleno = 1;
@@ -1945,8 +1942,8 @@ packgram (void)
 	     of the last token in it.  */
 	  if (p->sym->class == token_sym)
 	    {
-	      rprec[ruleno] = p->sym->prec;
-	      rassoc[ruleno] = p->sym->assoc;
+	      rule_table[ruleno].prec = p->sym->prec;
+	      rule_table[ruleno].assoc = p->sym->assoc;
 	    }
 	  if (p)
 	    p = p->next;
@@ -1956,9 +1953,9 @@ packgram (void)
          the specified symbol's precedence replaces the default.  */
       if (ruleprec)
 	{
-	  rprec[ruleno] = ruleprec->prec;
-	  rassoc[ruleno] = ruleprec->assoc;
-	  rprecsym[ruleno] = ruleprec->value;
+	  rule_table[ruleno].prec = ruleprec->prec;
+	  rule_table[ruleno].assoc = ruleprec->assoc;
+	  rule_table[ruleno].precsym = ruleprec->value;
 	}
 
       ritem[itemno++] = -ruleno;
