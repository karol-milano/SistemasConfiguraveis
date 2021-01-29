@@ -126,16 +126,12 @@ useless_nonterminals (void)
     {
       bitset_copy (Np, N);
       for (i = 1; i <= nrules; i++)
-	{
-	  if (!bitset_test (P, i))
-	    {
-	      if (useful_production (i, N))
-		{
-		  bitset_set (Np, rules[i].lhs - ntokens);
-		  bitset_set (P, i);
-		}
-	    }
-	}
+	if (!bitset_test (P, i)
+	    && useful_production (i, N))
+	  {
+	    bitset_set (Np, rules[i].lhs - ntokens);
+	    bitset_set (P, i);
+	  }
       if (bitset_equal_p (N, Np))
 	break;
       Ns = Np;
