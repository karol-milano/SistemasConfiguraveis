@@ -38,11 +38,18 @@ typedef unsigned *BSet;
 typedef short *rule;
 
 
-/* N is set of all nonterminals which are not useless.  P is set of
-   all rules which have no useless nonterminals in their RHS.  V is
-   the set of all accessible symbols.  */
+/* Set of all nonterminals which are not useless.  */
+static BSet N;
 
-static BSet N, P, V, V1;
+/* Set of all rules which have no useless nonterminals in their RHS.  */
+static BSet P;
+
+/* Set of all accessible symbols.  */
+static BSet V;
+
+/* Set of symbols used to define rule precedence (so they are
+   `useless', but no warning should be issued).  */
+static BSet V1;
 
 static int nuseful_productions;
 static int nuseless_productions;
@@ -318,71 +325,72 @@ reduce_grammar_tables (void)
 	    }
 	}
     }
+}
 
-  /* remove useless symbols */
-  if (nuseless_nonterminals > 0)
-    {
 
-      int i, n;
-/*      short  j; JF unused */
-      short *nontermmap;
-      rule r;
+/*------------------------------.
+| Remove useless nonterminals.  |
+`------------------------------*/
 
-      /* Create a map of nonterminal number to new nonterminal
-	 number. -1 in the map means it was useless and is being
-	 eliminated.  */
+static void
+nonterminals_reduce (void)
+{
+  int i, n;
+  rule r;
 
-      nontermmap = XCALLOC (short, nvars) - ntokens;
-      for (i = ntokens; i < nsyms; i++)
-	nontermmap[i] = -1;
+  /* Create a map of nonterminal number to new nonterminal number. -1
+     in the map means it was useless and is being eliminated.  */
 
-      n = ntokens;
-      for (i = ntokens; i < nsyms; i++)
-	if (BITISSET (V, i))
-	  nontermmap[i] = n++;
+  short *nontermmap = XCALLOC (short, nvars) - ntokens;
+  for (i = ntokens; i < nsyms; i++)
+    nontermmap[i] = -1;
 
-      /* Shuffle elements of tables indexed by symbol number.  */
+  n = ntokens;
+  for (i = ntokens; i < nsyms; i++)
+    if (BITISSET (V, i))
+      nontermmap[i] = n++;
 
-      for (i = ntokens; i < nsyms; i++)
+  /* Shuffle elements of tables indexed by symbol number.  */
+
+  for (i = ntokens; i < nsyms; i++)
+    {
+      n = nontermmap[i];
+      if (n >= 0)
 	{
-	  n = nontermmap[i];
-	  if (n >= 0)
-	    {
-	      sassoc[n] = sassoc[i];
-	      sprec[n] = sprec[i];
-	      tags[n] = tags[i];
-	    }
+	  sassoc[n] = sassoc[i];
+	  sprec[n] = sprec[i];
+	  tags[n] = tags[i];
 	}
+    }
 
-      /* Replace all symbol numbers in valid data structures.  */
+  /* Replace all symbol numbers in valid data structures.  */
 
-      for (i = 1; i <= nrules; i++)
-	{
-	  /* Ignore the rules disabled above.  */
-	  if (rule_table[i].lhs >= 0)
-	    rule_table[i].lhs = nontermmap[rule_table[i].lhs];
-	  if (ISVAR (rule_table[i].precsym))
-	    /* Can this happen?  */
-	    rule_table[i].precsym = nontermmap[rule_table[i].precsym];
-	}
+  for (i = 1; i <= nrules; i++)
+    {
+      /* Ignore the rules disabled above.  */
+      if (rule_table[i].lhs >= 0)
+	rule_table[i].lhs = nontermmap[rule_table[i].lhs];
+      if (ISVAR (rule_table[i].precsym))
+	/* Can this happen?  */
+	rule_table[i].precsym = nontermmap[rule_table[i].precsym];
+    }
 
-      for (r = ritem; *r; r++)
-	if (ISVAR (*r))
-	  *r = nontermmap[*r];
+  for (r = ritem; *r; r++)
+    if (ISVAR (*r))
+      *r = nontermmap[*r];
 
-      start_symbol = nontermmap[start_symbol];
+  start_symbol = nontermmap[start_symbol];
 
-      nsyms -= nuseless_nonterminals;
-      nvars -= nuseless_nonterminals;
+  nsyms -= nuseless_nonterminals;
+  nvars -= nuseless_nonterminals;
 
-      free (&nontermmap[ntokens]);
-    }
+  free (&nontermmap[ntokens]);
 }
 
 
-/*-----------------------------------------------------------------.
-| Ouput the detailed results of the reductions.  For FILE.output.  |
-`-----------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Output the detailed results of the reductions.  For FILE.output.  |
+`------------------------------------------------------------------*/
 
 void
 reduce_output (FILE *out)
@@ -537,6 +545,8 @@ reduce_grammar (void)
 	   tags[start_symbol]);
 
   reduce_grammar_tables ();
+  if (nuseless_nonterminals > 0)
+    nonterminals_reduce ();
 
   if (trace_flag)
     {
