@@ -1687,6 +1687,7 @@ packgram (void)
   while (p)
     {
       bucket *ruleprec = p->ruleprec;
+      rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym;
       rules[ruleno].rhs = ritem + itemno;
