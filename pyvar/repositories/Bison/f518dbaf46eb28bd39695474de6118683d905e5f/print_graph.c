@@ -133,7 +133,7 @@ print_actions (state const *s, FILE *fgraph)
            : "dashed");
 
         if (TRANSITION_IS_ERROR (trans, i)
-            && strcmp (symbols[sym]->tag, "error") != 0)
+            && STRNEQ (symbols[sym]->tag, "error"))
           abort ();
         output_edge (s->number, s1->number,
                      TRANSITION_IS_ERROR (trans, i) ? NULL : symbols[sym]->tag,
