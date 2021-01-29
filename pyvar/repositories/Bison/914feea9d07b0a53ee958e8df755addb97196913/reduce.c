@@ -57,15 +57,6 @@ static int nuseless_productions;
 static int nuseful_nonterminals;
 int nuseless_nonterminals;
 
-static int
-bits_size (bitset S)
-{
-  int i, count = 0;
-
-  BITSET_EXECUTE (S, 0, i, { ++count; });
-  return count;
-}
-
 /*-------------------------------------------------------------------.
 | Another way to do this would be with a set for each production and |
 | then do subset tests against N0, but even for the C grammar the    |
@@ -82,9 +73,8 @@ useful_production (int i, bitset N0)
      in the set of useful nonterminals.  */
 
   for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
-    if (ISVAR (n = *r))
-      if (!bitset_test (N0, n - ntokens))
-	return FALSE;
+    if (ISVAR (n = *r) && !bitset_test (N0, n - ntokens))
+      return FALSE;
   return TRUE;
 }
 
@@ -215,7 +205,7 @@ inaccessable_symbols (void)
   bitset_free (P);
   P = Pp;
 
-  nuseful_productions = bits_size (P);
+  nuseful_productions = bitset_count (P);
   nuseless_productions = nrules - nuseful_productions;
 
   nuseful_nonterminals = 0;
