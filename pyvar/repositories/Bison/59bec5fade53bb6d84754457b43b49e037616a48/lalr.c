@@ -67,6 +67,15 @@ size_t nLA;
 static goto_number **includes;
 static goto_list **lookback;
 
+static void
+goto_print (goto_number i, FILE* out)
+{
+  const state_number src = from_state[i];
+  const state_number dst = to_state[i];
+  symbol_number var = states[dst]->accessing_symbol;
+  fprintf (out,
+           "goto[%ld] = (%d, %s, %d)", i, src, symbols[var]->tag, dst);
+}
 
 void
 set_goto_map (void)
@@ -117,6 +126,13 @@ set_goto_map (void)
     }
 
   free (temp_map);
+
+  if (trace_flag & trace_automaton)
+    for (int i = 0; i < ngotos; ++i)
+      {
+        goto_print (i, stderr);
+        fputc ('\n', stderr);
+      }
 }
 
 
@@ -140,7 +156,7 @@ map_goto (state_number src, symbol_number sym)
     }
 }
 
-
+/* Build goto_follows. */
 static void
 initialize_F (void)
 {
@@ -181,7 +197,6 @@ initialize_F (void)
 
   for (goto_number i = 0; i < ngotos; ++i)
     free (reads[i]);
-
   free (reads);
   free (edge);
 }
@@ -198,7 +213,8 @@ add_lookback_edge (state *s, rule const *r, goto_number gotono)
 }
 
 
-
+/* Compute INCLUDES and LOOKBACK.  Corresponds to step E in Sec. 6 of
+   [DeRemer 1982].  */
 static void
 build_relations (void)
 {
@@ -265,18 +281,42 @@ build_relations (void)
   free (path);
 
   relation_transpose (&includes, ngotos);
+  if (trace_flag & trace_automaton)
+    {
+      fprintf (stderr, "includes:\n");
+      relation_print (includes, ngotos, goto_print, stderr);
+    }
 }
 
+/* Print FOLLOWS for debugging.  */
+static void
+follows_print (FILE* out)
+{
+  for (goto_number i = 0; i < ngotos; ++i)
+    {
+      fputs ("FOLLOWS[", out);
+      goto_print (i, out);
+      fputs ("] =", out);
+      bitset_iterator iter;
+      symbol_number sym;
+      BITSET_FOR_EACH (iter, goto_follows[i], sym, 0)
+        {
+          fputc (' ', out);
+          symbol_print (symbols[sym], out);
+        }
+      fputc ('\n', out);
+    }
+}
 
-
+/* Compute FOLLOWS from INCLUDES, and free INCLUDES.  */
 static void
-compute_FOLLOWS (void)
+compute_follows (void)
 {
   relation_digraph (includes, ngotos, &goto_follows);
-
+  if (trace_flag & trace_sets)
+    follows_print (stderr);
   for (goto_number i = 0; i < ngotos; ++i)
     free (includes[i]);
-
   free (includes);
 }
 
@@ -291,7 +331,6 @@ compute_lookahead_tokens (void)
   /* Free LOOKBACK. */
   for (size_t i = 0; i < nLA; ++i)
     LIST_FREE (goto_list, lookback[i]);
-
   free (lookback);
 }
 
@@ -421,7 +460,7 @@ lalr (void)
   initialize_F ();
   lookback = xcalloc (nLA, sizeof *lookback);
   build_relations ();
-  compute_FOLLOWS ();
+  compute_follows ();
   compute_lookahead_tokens ();
 
   if (trace_flag & trace_sets)
