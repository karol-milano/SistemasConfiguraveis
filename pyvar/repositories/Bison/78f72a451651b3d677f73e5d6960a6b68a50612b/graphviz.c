@@ -184,9 +184,9 @@ output_red (state const *s, reductions const *reds, FILE *fout)
       bool firste = true;
       rule_number ruleno = reds->rules[j]->number;
 
-      if (reds->lookahead_tokens)
+      if (reds->lookaheads)
         for (int i = 0; i < ntokens; i++)
-          if (bitset_test (reds->lookahead_tokens[j], i))
+          if (bitset_test (reds->lookaheads[j], i))
             {
               if (bitset_test (no_reduce_set, i))
                 firstd = print_token (&dout, firstd, symbols[i]->tag);
