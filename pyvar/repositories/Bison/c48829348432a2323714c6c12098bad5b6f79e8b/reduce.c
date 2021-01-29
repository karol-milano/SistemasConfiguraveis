@@ -1,4 +1,5 @@
 /* Grammar reduction for Bison.
+
    Copyright (C) 1988, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -245,7 +246,7 @@ reduce_grammar_tables (void)
   {
     int useful = 0;
     int useless = nrules - nuseless_productions;
-    rule *rules_sorted = XMALLOC (rule, nrules);
+    rule *rules_sorted = MALLOC (rules_sorted, nrules);
     rule_number r;
     for (r = 0; r < nrules; ++r)
       rules_sorted[rules[r].useful ? useful++ : useless++] = rules[r];
@@ -289,15 +290,15 @@ nonterminals_reduce (void)
   /* Map the nonterminals to their new index: useful first, useless
      afterwards.  Kept for later report.  */
 
-  symbol_number *nontermmap = XCALLOC (symbol_number, nvars) - ntokens;
+  symbol_number *nontermmap = CALLOC (nontermmap, nvars);
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
     if (bitset_test (V, i))
-      nontermmap[i] = n++;
+      nontermmap[i - ntokens] = n++;
   for (i = ntokens; i < nsyms; i++)
     if (!bitset_test (V, i))
       {
-	nontermmap[i] = n++;
+	nontermmap[i - ntokens] = n++;
 	warn_at (symbols[i]->location, _("useless nonterminal: %s"),
 		 symbols[i]->tag);
       }
@@ -305,15 +306,15 @@ nonterminals_reduce (void)
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
-    symbol **symbols_sorted = XMALLOC (symbol *, nvars) - ntokens;
+    symbol **symbols_sorted = MALLOC (symbols_sorted, nvars);
 
     for (i = ntokens; i < nsyms; i++)
-      symbols[i]->number = nontermmap[i];
+      symbols[i]->number = nontermmap[i - ntokens];
     for (i = ntokens; i < nsyms; i++)
-      symbols_sorted[nontermmap[i]] = symbols[i];
+      symbols_sorted[nontermmap[i - ntokens] - ntokens] = symbols[i];
     for (i = ntokens; i < nsyms; i++)
-      symbols[i] = symbols_sorted[i];
-    free (symbols_sorted + ntokens);
+      symbols[i] = symbols_sorted[i - ntokens];
+    free (symbols_sorted);
   }
 
   {
@@ -323,15 +324,16 @@ nonterminals_reduce (void)
 	item_number *rhsp;
 	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
 	  if (ISVAR (*rhsp))
-	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp]);
+	    *rhsp =  symbol_number_as_item_number (nontermmap[*rhsp
+							      - ntokens]);
       }
-    accept->number = nontermmap[accept->number];
+    accept->number = nontermmap[accept->number - ntokens];
   }
 
   nsyms -= nuseless_nonterminals;
   nvars -= nuseless_nonterminals;
 
-  free (nontermmap + ntokens);
+  free (nontermmap);
 }
 
 
