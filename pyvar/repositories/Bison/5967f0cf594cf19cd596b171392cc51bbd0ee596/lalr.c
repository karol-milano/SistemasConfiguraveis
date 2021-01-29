@@ -453,6 +453,37 @@ lalr (void)
 }
 
 
+void
+lalr_update_state_numbers (state_number old_to_new[], state_number nstates_old)
+{
+  goto_number ngotos_reachable = 0;
+  symbol_number nonterminal = 0;
+  aver (nsyms == nvars + ntokens);
+  for (goto_number i = 0; i < ngotos; ++i)
+    {
+      while (i == goto_map[nonterminal])
+        goto_map[nonterminal++] = ngotos_reachable;
+      /* If old_to_new[from_state[i]] = nstates_old, remove this goto
+         entry.  */
+      if (old_to_new[from_state[i]] != nstates_old)
+        {
+          /* from_state[i] is not removed, so it and thus to_state[i] are
+             reachable, so to_state[i] != nstates_old.  */
+          aver (old_to_new[to_state[i]] != nstates_old);
+          from_state[ngotos_reachable] = old_to_new[from_state[i]];
+          to_state[ngotos_reachable] = old_to_new[to_state[i]];
+          ++ngotos_reachable;
+        }
+    }
+  while (nonterminal <= nvars)
+    {
+      aver (ngotos == goto_map[nonterminal]);
+      goto_map[nonterminal++] = ngotos_reachable;
+    }
+  ngotos = ngotos_reachable;
+}
+
+
 void
 lalr_free (void)
 {
