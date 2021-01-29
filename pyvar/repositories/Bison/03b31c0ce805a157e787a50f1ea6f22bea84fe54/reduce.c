@@ -218,7 +218,7 @@ inaccessable_symbols (void)
   /* A token that was used in %prec should not be warned about.  */
   for (i = 1; i < nrules + 1; i++)
     if (rules[i].precsym != 0)
-      bitset_set (V1, rules[i].precsym);
+      bitset_set (V1, rules[i].precsym->number);
 }
 
 
@@ -310,15 +310,6 @@ nonterminals_reduce (void)
     free (symbols_sorted + ntokens);
   }
 
-  /* Replace all symbol numbers in valid data structures.  */
-
-  for (i = 1; i < nrules + 1; i++)
-    {
-      if (ISVAR (rules[i].precsym))
-	/* Can this happen?  */
-	rules[i].precsym = nontermmap[rules[i].precsym];
-    }
-
   for (i = 0; i < nritems; ++i)
     if (ISVAR (ritem[i]))
       ritem[i] = nontermmap[ritem[i]];
@@ -412,8 +403,11 @@ dump_grammar (FILE *out)
 	++rhs_count;
       fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
 	       i - 1,
-	       rules[i].prec, rules[i].assoc, rules[i].useful,
-	       rules[i].rhs - ritem, rules[i].rhs - ritem + rhs_count - 1,
+	       rules[i].prec->prec,
+	       rules[i].prec->assoc,
+	       rules[i].useful,
+	       rules[i].rhs - ritem,
+	       rules[i].rhs - ritem + rhs_count - 1,
 	       rules[i].lhs->number);
       /* Dumped the RHS. */
       for (r = rules[i].rhs; *r >= 0; r++)
