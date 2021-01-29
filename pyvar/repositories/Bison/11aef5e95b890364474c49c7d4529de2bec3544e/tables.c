@@ -395,7 +395,7 @@ save_row (state_number s)
       base_number *sp1 = froms[s] = xnmalloc (count, sizeof *sp1);
       base_number *sp2 = tos[s] = xnmalloc (count, sizeof *sp2);
       unsigned int *sp3 = conflict_tos[s] =
-        nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;;
+        nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;
 
       /* Store non defaulted actions.  */
       for (i = 0; i < ntokens; i++)
@@ -513,37 +513,38 @@ save_column (symbol_number sym, state_number default_state)
 }
 
 
-/*-------------------------------------------------------------.
-| Return `the' most common destination GOTO on SYM (a nterm).  |
-`-------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| The default state for SYM: the state which is 'the' most common |
+| GOTO destination on SYM (an nterm).                             |
+`----------------------------------------------------------------*/
 
 static state_number
 default_goto (symbol_number sym, size_t state_count[])
 {
-  state_number s;
-  goto_number i;
-  goto_number m = goto_map[sym - ntokens];
-  goto_number n = goto_map[sym - ntokens + 1];
-  state_number default_state = -1;
-  size_t max = 0;
-
-  if (m == n)
-    return -1;
+  goto_number begin = goto_map[sym - ntokens];
+  goto_number end = goto_map[sym - ntokens + 1];
+  state_number res = -1;
 
-  for (s = 0; s < nstates; s++)
-    state_count[s] = 0;
+  if (begin != end)
+    {
+      size_t max = 0;
+      goto_number i;
+      state_number s;
 
-  for (i = m; i < n; i++)
-    state_count[to_state[i]]++;
+      for (s = 0; s < nstates; s++)
+        state_count[s] = 0;
 
-  for (s = 0; s < nstates; s++)
-    if (state_count[s] > max)
-      {
-        max = state_count[s];
-        default_state = s;
-      }
+      for (i = begin; i < end; i++)
+        state_count[to_state[i]]++;
 
-  return default_state;
+      for (s = 0; s < nstates; s++)
+        if (max < state_count[s])
+          {
+            max = state_count[s];
+            res = s;
+          }
+    }
+  return res;
 }
 
 
