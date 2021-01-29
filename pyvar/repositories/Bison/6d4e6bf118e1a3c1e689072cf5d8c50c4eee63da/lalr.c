@@ -73,6 +73,10 @@ size_t nLA;
 
 
 static goto_number **includes;
+
+/* "(q, A → ω) lookback (p, A)" iff state p reaches state q on label ω.
+
+   Definition p.621 [DeRemer 1982]. */
 static goto_list **lookback;
 
 static void
@@ -239,6 +243,58 @@ initialize_goto_follows (void)
 }
 
 
+/* Find the state which LOOKBACK[LOOKBACK_INDEX] is about.  */
+static const state *
+lookback_find_state (int lookback_index)
+{
+  state *res = NULL;
+  for (int j = 0; j < nstates; ++j)
+    if (states[j]->reductions
+        && states[j]->reductions->lookahead_tokens)
+      {
+        if (states[j]->reductions->lookahead_tokens - LA > lookback_index)
+          /* Went too far. */
+          break;
+        else
+          res = states[j];
+      }
+  /* Pacify "potential null pointer dereference" warning.  */
+  if (!res)
+    abort ();
+  return res;
+}
+
+/* Print LOOKBACK for debugging.  */
+static void
+lookback_print (FILE *out)
+{
+  fputs ("lookback:\n", out);
+  for (int i = 0; i < nLA; ++i)
+    if (lookback[i])
+    {
+      fprintf (out, "   %3d = ", i);
+      const state *s = lookback_find_state (i);
+      int rnum = i - (s->reductions->lookahead_tokens - LA);
+      const rule *r = s->reductions->rules[rnum];
+      fprintf (out, "(%3d, ", s->number);
+      rule_print (r, NULL, out);
+      fputs (") ->", out);
+      for (goto_list *sp = lookback[i]; sp; sp = sp->next)
+        {
+          fputc (' ', out);
+          goto_print (sp->value, out);
+        }
+      fputc ('\n', out);
+    }
+  fputc ('\n', out);
+}
+
+/* Add (S, R) -> GOTONO to LOOKBACK.
+
+   "(q, A → ω) lookback (p, A)" iff state p reaches state q on label ω.
+
+   The goto number GOTONO, whose source is S (which is
+   inconsistent), */
 static void
 add_lookback_edge (state *s, rule const *r, goto_number gotono)
 {
@@ -284,6 +340,7 @@ build_relations (void)
               path[length++] = s->number;
             }
 
+          /* S is the end of PATH.  */
           if (!s->consistent)
             add_lookback_edge (s, r, i);
 
@@ -313,6 +370,18 @@ build_relations (void)
             }
         }
 
+      if (trace_flag & trace_automaton)
+        {
+          goto_print (i, stderr);
+          fputs (" edges = ", stderr);
+          for (int j = 0; j < nedges; ++j)
+            {
+              fputc (' ', stderr);
+              goto_print (edge[j], stderr);
+            }
+          fputc ('\n', stderr);
+        }
+
       if (nedges == 0)
         includes[i] = NULL;
       else
@@ -329,7 +398,10 @@ build_relations (void)
 
   relation_transpose (&includes, ngotos);
   if (trace_flag & trace_automaton)
-    relation_print ("includes", includes, ngotos, goto_print, stderr);
+    {
+      lookback_print (stderr);
+      relation_print ("includes", includes, ngotos, goto_print, stderr);
+    }
 }
 
 /* Compute FOLLOWS from INCLUDES, and free INCLUDES.  */
