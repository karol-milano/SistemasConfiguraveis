@@ -1705,10 +1705,7 @@ packgram (void)
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
 	  if (p->sym->class == token_sym)
-	    {
-	      rules[ruleno].prec = p->sym->prec;
-	      rules[ruleno].assoc = p->sym->assoc;
-	    }
+	    rules[ruleno].prec = p->sym;
 	  if (p)
 	    p = p->next;
 	}
@@ -1717,11 +1714,9 @@ packgram (void)
          the specified symbol's precedence replaces the default.  */
       if (ruleprec)
 	{
-	  rules[ruleno].prec = ruleprec->prec;
-	  rules[ruleno].assoc = ruleprec->assoc;
-	  rules[ruleno].precsym = ruleprec->number;
+	  rules[ruleno].precsym = ruleprec;
+	  rules[ruleno].prec = ruleprec;
 	}
-
       ritem[itemno++] = -ruleno;
       ruleno++;
 
