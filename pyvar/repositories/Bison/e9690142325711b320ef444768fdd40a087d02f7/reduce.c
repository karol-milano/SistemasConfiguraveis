@@ -115,14 +115,14 @@ useless_nonterminals (void)
     {
       bitset_copy (Np, N);
       for (r = 0; r < nrules; r++)
-	if (!bitset_test (P, r)
-	    && useful_production (r, N))
-	  {
-	    bitset_set (Np, rules[r].lhs->number - ntokens);
-	    bitset_set (P, r);
-	  }
+        if (!bitset_test (P, r)
+            && useful_production (r, N))
+          {
+            bitset_set (Np, rules[r].lhs->number - ntokens);
+            bitset_set (P, r);
+          }
       if (bitset_equal_p (N, Np))
-	break;
+        break;
       Ns = Np;
       Np = N;
       N = Ns;
@@ -169,37 +169,37 @@ inaccessable_symbols (void)
       bitset_set (V, accept->number);
 
       while (1)
-	{
-	  rule_number r;
-	  bitset_copy (Vp, V);
-	  for (r = 0; r < nrules; r++)
-	    {
-	      if (!bitset_test (Pp, r)
-		  && bitset_test (P, r)
-		  && bitset_test (V, rules[r].lhs->number))
-		{
-		  item_number *rhsp;
-		  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
-		    if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
-		      bitset_set (Vp, *rhsp);
-		  bitset_set (Pp, r);
-		}
-	    }
-	  if (bitset_equal_p (V, Vp))
-	    break;
-	  Vs = Vp;
-	  Vp = V;
-	  V = Vs;
-	}
+        {
+          rule_number r;
+          bitset_copy (Vp, V);
+          for (r = 0; r < nrules; r++)
+            {
+              if (!bitset_test (Pp, r)
+                  && bitset_test (P, r)
+                  && bitset_test (V, rules[r].lhs->number))
+                {
+                  item_number *rhsp;
+                  for (rhsp = rules[r].rhs; *rhsp >= 0; rhsp++)
+                    if (ISTOKEN (*rhsp) || bitset_test (N, *rhsp - ntokens))
+                      bitset_set (Vp, *rhsp);
+                  bitset_set (Pp, r);
+                }
+            }
+          if (bitset_equal_p (V, Vp))
+            break;
+          Vs = Vp;
+          Vp = V;
+          V = Vs;
+        }
     }
 
   bitset_free (V);
   V = Vp;
 
   /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
-  bitset_set (V, endtoken->number);		/* end-of-input token */
-  bitset_set (V, errtoken->number);		/* error token */
-  bitset_set (V, undeftoken->number);		/* some undefined token */
+  bitset_set (V, endtoken->number);             /* end-of-input token */
+  bitset_set (V, errtoken->number);             /* error token */
+  bitset_set (V, undeftoken->number);           /* some undefined token */
 
   bitset_free (P);
   P = Pp;
@@ -212,7 +212,7 @@ inaccessable_symbols (void)
     symbol_number i;
     for (i = ntokens; i < nsyms; i++)
       if (bitset_test (V, i))
-	nuseful_nonterminals++;
+        nuseful_nonterminals++;
   }
   nuseless_nonterminals = nvars - nuseful_nonterminals;
 
@@ -221,7 +221,7 @@ inaccessable_symbols (void)
     rule_number r;
     for (r = 0; r < nrules; ++r)
       if (rules[r].precsym != 0)
-	bitset_set (V1, rules[r].precsym->number);
+        bitset_set (V1, rules[r].precsym->number);
   }
 }
 
@@ -257,11 +257,11 @@ reduce_grammar_tables (void)
     /* Renumber the rules markers in RITEMS.  */
     for (r = 0; r < nrules; ++r)
       {
-	item_number *rhsp = rules[r].rhs;
-	for (/* Nothing. */; *rhsp >= 0; ++rhsp)
-	  /* Nothing. */;
-	*rhsp = rule_number_as_item_number (r);
-	rules[r].number = r;
+        item_number *rhsp = rules[r].rhs;
+        for (/* Nothing. */; *rhsp >= 0; ++rhsp)
+          /* Nothing. */;
+        *rhsp = rule_number_as_item_number (r);
+        rules[r].number = r;
       }
     nrules -= nuseless_productions;
   }
@@ -272,8 +272,8 @@ reduce_grammar_tables (void)
     int length;
     for (r = nrules; r < nrules + nuseless_productions; ++r)
       {
-	length = rule_rhs_length (&rules[r]);
-	nritems -= length + 1;
+        length = rule_rhs_length (&rules[r]);
+        nritems -= length + 1;
       }
   }
 }
@@ -299,9 +299,9 @@ nonterminals_reduce (void)
   for (i = ntokens; i < nsyms; i++)
     if (!bitset_test (V, i))
       {
-	nontermmap[i - ntokens] = n++;
-	warn_at (symbols[i]->location, _("nonterminal useless in grammar: %s"),
-		 symbols[i]->tag);
+        nontermmap[i - ntokens] = n++;
+        warn_at (symbols[i]->location, _("nonterminal useless in grammar: %s"),
+                 symbols[i]->tag);
       }
 
 
@@ -322,11 +322,11 @@ nonterminals_reduce (void)
     rule_number r;
     for (r = 0; r < nrules; ++r)
       {
-	item_number *rhsp;
-	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	  if (ISVAR (*rhsp))
-	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
-							      - ntokens]);
+        item_number *rhsp;
+        for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+          if (ISVAR (*rhsp))
+            *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
+                                                              - ntokens]);
       }
     accept->number = nontermmap[accept->number - ntokens];
   }
@@ -350,7 +350,7 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Nonterminals useless in grammar"));
       for (i = 0; i < nuseless_nonterminals; ++i)
-	fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
+        fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
     }
 
@@ -359,19 +359,19 @@ reduce_output (FILE *out)
     int i;
     for (i = 0; i < ntokens; i++)
       if (reduce_token_unused_in_grammar (i))
-	{
-	  if (!b)
-	    fprintf (out, "%s\n\n", _("Terminals unused in grammar"));
-	  b = true;
-	  fprintf (out, "   %s\n", symbols[i]->tag);
-	}
+        {
+          if (!b)
+            fprintf (out, "%s\n\n", _("Terminals unused in grammar"));
+          b = true;
+          fprintf (out, "   %s\n", symbols[i]->tag);
+        }
     if (b)
       fputs ("\n\n", out);
   }
 
   if (nuseless_productions > 0)
     grammar_rules_partial_print (out, _("Rules useless in grammar"),
-				 rule_useless_in_grammar_p);
+                                 rule_useless_in_grammar_p);
 }
 
 
@@ -417,8 +417,8 @@ reduce_grammar (void)
 
   if (!bitset_test (N, accept->number - ntokens))
     fatal_at (startsymbol_location,
-	      _("start symbol %s does not derive any sentence"),
-	      startsymbol->tag);
+              _("start symbol %s does not derive any sentence"),
+              startsymbol->tag);
 
   /* First reduce the nonterminals, as they renumber themselves in the
      whole grammar.  If you change the order, nonterms would be
@@ -434,7 +434,7 @@ reduce_grammar (void)
 
       fprintf (stderr, "reduced %s defines %d terminals, %d nonterminals\
 , and %d productions.\n",
-	       grammar_file, ntokens, nvars, nrules);
+               grammar_file, ntokens, nvars, nrules);
     }
 }
 
