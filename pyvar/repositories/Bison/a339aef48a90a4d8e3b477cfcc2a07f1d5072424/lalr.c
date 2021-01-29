@@ -67,17 +67,13 @@ static goto_number **includes;
 static goto_list **lookback;
 
 
-
-
 void
 set_goto_map (void)
 {
   state_number s;
-  goto_number *temp_map;
+  goto_number *temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
 
   goto_map = xcalloc (nvars + 1, sizeof *goto_map);
-  temp_map = xnmalloc (nvars + 1, sizeof *temp_map);
-
   ngotos = 0;
   for (s = 0; s < nstates; ++s)
     {
@@ -132,16 +128,13 @@ set_goto_map (void)
 goto_number
 map_goto (state_number s0, symbol_number sym)
 {
-  goto_number high;
-  goto_number low;
-  goto_number middle;
-  state_number s;
-
-  low = goto_map[sym - ntokens];
-  high = goto_map[sym - ntokens + 1] - 1;
+  goto_number low = goto_map[sym - ntokens];
+  goto_number high = goto_map[sym - ntokens + 1] - 1;
 
   for (;;)
     {
+      goto_number middle;
+      state_number s;
       aver (low <= high);
       middle = (low + high) / 2;
       s = from_state[middle];
@@ -412,7 +405,6 @@ static void
 lookahead_tokens_print (FILE *out)
 {
   state_number i;
-  int j, k;
   fprintf (out, "Lookahead tokens: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
@@ -421,21 +413,25 @@ lookahead_tokens_print (FILE *out)
       int n_lookahead_tokens = 0;
 
       if (reds->lookahead_tokens)
-        for (k = 0; k < reds->num; ++k)
-          if (reds->lookahead_tokens[k])
-            ++n_lookahead_tokens;
+        {
+          int j;
+          for (j = 0; j < reds->num; ++j)
+            if (reds->lookahead_tokens[j])
+              ++n_lookahead_tokens;
+        }
 
       fprintf (out, "State %d: %d lookahead tokens\n",
                i, n_lookahead_tokens);
 
       if (reds->lookahead_tokens)
-        for (j = 0; j < reds->num; ++j)
-          BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
-          {
-            fprintf (out, "   on %d (%s) -> rule %d\n",
-                     k, symbols[k]->tag,
-                     reds->rules[j]->number);
-          };
+        {
+          int j, k;
+          for (j = 0; j < reds->num; ++j)
+            BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
+              fprintf (out, "   on %d (%s) -> rule %d\n",
+                       k, symbols[k]->tag,
+                       reds->rules[j]->number);
+        }
     }
   fprintf (out, "Lookahead tokens: END\n");
 }
