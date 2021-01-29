@@ -189,6 +189,21 @@ state_free (state *s)
 }
 
 
+void
+state_transitions_print (const state *s, FILE *out)
+{
+  const transitions *trans = s->transitions;
+  fprintf (out, "transitions of %d (%d):\n",
+           s->number, trans->num);
+  for (int i = 0; i < trans->num; ++i)
+    fprintf (out, "  %d: (%d, %s, %d)\n",
+             i,
+             s->number,
+             symbols[s->transitions->states[i]->accessing_symbol]->tag,
+             s->transitions->states[i]->number);
+}
+
+
 /*---------------------------.
 | Set the transitions of S.  |
 `---------------------------*/
@@ -199,17 +214,7 @@ state_transitions_set (state *s, int num, state **dst)
   aver (!s->transitions);
   s->transitions = transitions_new (num, dst);
   if (trace_flag & trace_automaton)
-    {
-      const transitions *trans = s->transitions;
-      fprintf (stderr, "transitions of %d (%d):\n",
-               s->number, trans->num);
-      for (int i = 0; i < trans->num; ++i)
-        fprintf (stderr, "  %d: (%d, %s, %d)\n",
-                 i,
-                 s->number,
-                 symbols[s->transitions->states[i]->accessing_symbol]->tag,
-                 s->transitions->states[i]->number);
-    }
+    state_transitions_print (s, stderr);
 }
 
 
