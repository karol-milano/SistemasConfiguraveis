@@ -96,7 +96,7 @@ print_fderives (void)
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
-	    for (rhsp = &ritem[rules[j].rhs]; *rhsp >= 0; ++rhsp)
+	    for (rhsp = rules[j].rhs; *rhsp >= 0; ++rhsp)
 	      fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	    fputc ('\n', stderr);
 	  }
@@ -173,7 +173,7 @@ set_firsts (void)
   for (i = ntokens; i < nsyms; i++)
     for (j = 0; derives[i][j] >= 0; ++j)
       {
-	int symbol = ritem[rules[derives[i][j]].rhs];
+	int symbol = rules[derives[i][j]].rhs[0];
 	if (ISVAR (symbol))
 	  bitset_set (FIRSTS (i), symbol - ntokens);
       }
@@ -262,7 +262,7 @@ closure (short *core, int n)
   for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
     if (bitset_test (ruleset, ruleno))
       {
-	int itemno = rules[ruleno].rhs;
+	int itemno = rules[ruleno].rhs - ritem;
 	while (c < n && core[c] < itemno)
 	  {
 	    itemset[nitemset] = core[c];
