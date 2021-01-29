@@ -103,7 +103,7 @@ print_fderives (void)
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
-	    for (rhsp = &ritem[rule_table[j].rhs]; *rhsp >= 0; ++rhsp)
+	    for (rhsp = &ritem[rules[j].rhs]; *rhsp >= 0; ++rhsp)
 	      fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	    fputc ('\n', stderr);
 	  }
@@ -133,7 +133,7 @@ set_firsts (void)
   for (i = ntokens; i < nsyms; i++)
     for (j = 0; derives[i][j] >= 0; ++j)
       {
-	int symbol = ritem[rule_table[derives[i][j]].rhs];
+	int symbol = ritem[rules[derives[i][j]].rhs];
 	if (ISVAR (symbol))
 	  SETBIT (FIRSTS (i), symbol - ntokens);
       }
@@ -225,7 +225,7 @@ closure (short *core, int n)
   for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
     if (BITISSET (ruleset, ruleno))
       {
-	int itemno = rule_table[ruleno].rhs;
+	int itemno = rules[ruleno].rhs;
 	while (c < n && core[c] < itemno)
 	  {
 	    itemset[nitemset] = core[c];
