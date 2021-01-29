@@ -189,7 +189,7 @@ initialize_F (void)
 
 
 static void
-add_lookback_edge (state *s, rule *r, goto_number gotono)
+add_lookback_edge (state *s, rule const *r, goto_number gotono)
 {
   int ri = state_reduction_find (s, r);
   goto_list *sp = xmalloc (sizeof *sp);
@@ -204,48 +204,50 @@ static void
 build_relations (void)
 {
   goto_number *edge = xnmalloc (ngotos + 1, sizeof *edge);
-  state_number *states1 = xnmalloc (ritem_longest_rhs () + 1, sizeof *states1);
+  state_number *path = xnmalloc (ritem_longest_rhs () + 1, sizeof *path);
 
   includes = xnmalloc (ngotos, sizeof *includes);
 
+  /* For each goto (from SRC to DST labeled by nterm VAR), iterate
+     over each rule with VAR as LHS, and find the path PATH from SRC
+     labeled with the RHS of the rule. */
   for (goto_number i = 0; i < ngotos; ++i)
     {
-      int nedges = 0;
-      symbol_number symbol1 = states[to_state[i]]->accessing_symbol;
+      const state_number src = from_state[i];
+      const state_number dst = to_state[i];
+      symbol_number var = states[dst]->accessing_symbol;
 
-      for (rule **rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
+      /* Size of EDGE.  */
+      int nedges = 0;
+      for (rule **rulep = derives[var - ntokens]; *rulep; ++rulep)
         {
-          state *s = states[from_state[i]];
-          states1[0] = s->number;
+          rule const* r = *rulep;
+          state *s = states[src];
+          path[0] = s->number;
 
+          /* Length of PATH.  */
           int length = 1;
-          item_number const *rp;
-          for (rp = (*rulep)->rhs; 0 <= *rp; rp++)
+          for (item_number const *rp = r->rhs; 0 <= *rp; rp++)
             {
               symbol_number sym = item_number_as_symbol_number (*rp);
               s = transitions_to (s, sym);
-              states1[length++] = s->number;
+              path[length++] = s->number;
             }
 
           if (!s->consistent)
-            add_lookback_edge (s, *rulep, i);
+            add_lookback_edge (s, r, i);
+
+          /* Walk back PATH from penultimate to beginning.
 
-          length--;
-          bool done = false;
-          while (!done)
+             The "0 <= p" part is actually useless: each rhs ends in a
+             rule number (for which ISVAR(...) is false), and there is
+             a sentinel (ritem[-1]=0) before the first rhs.  */
+          for (int p = length - 2; 0 <= p && ISVAR (r->rhs[p]); --p)
             {
-              done = true;
-              /* Each rhs ends in a rule number, and there is a
-                 sentinel (ritem[-1]=0) before the first rhs, so it is safe to
-                 decrement RP here.  */
-              rp--;
-              if (ISVAR (*rp))
-                {
-                  edge[nedges++] = map_goto (states1[--length],
-                                             item_number_as_symbol_number (*rp));
-                  if (nullable[*rp - ntokens])
-                    done = false;
-                }
+              symbol_number sym = item_number_as_symbol_number (r->rhs[p]);
+              edge[nedges++] = map_goto (path[p], sym);
+              if (!nullable[sym - ntokens])
+                break;
             }
         }
 
@@ -261,7 +263,7 @@ build_relations (void)
     }
 
   free (edge);
-  free (states1);
+  free (path);
 
   relation_transpose (&includes, ngotos);
 }
