@@ -298,8 +298,10 @@ nonterminals_reduce (void)
     if (!bitset_test (V, i))
       {
         nontermmap[i - ntokens] = n++;
-        warn_at (symbols[i]->location, _("nonterminal useless in grammar: %s"),
-                 symbols[i]->tag);
+        if (symbols[i]->status != used)
+          warn_at (symbols[i]->location,
+                   _("nonterminal useless in grammar: %s"),
+                   symbols[i]->tag);
       }
 
 
