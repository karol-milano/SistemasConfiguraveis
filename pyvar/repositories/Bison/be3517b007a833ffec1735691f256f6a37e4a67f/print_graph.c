@@ -76,7 +76,7 @@ print_core (struct obstack *oout, state *s)
     }
 
   obstack_printf (oout, _("State %d"), s->number);
-  obstack_sgrow (oout, "\\n");
+  obstack_sgrow (oout, "\\n\\l");
   for (i = 0; i < snritems; i++)
     {
       item_number *sp;
@@ -142,9 +142,6 @@ print_actions (state const *s, FILE *fgraph)
   transitions const *trans = s->transitions;
   int i;
 
-  /* Display reductions. */
-  output_red (s, s->reductions, fgraph);
-
   if (!trans->num && !s->reductions)
     return;
 
@@ -167,6 +164,8 @@ print_actions (state const *s, FILE *fgraph)
 		     TRANSITION_IS_ERROR (trans, i) ? NULL : symbols[sym]->tag,
 		     style, fgraph);
       }
+  /* Display reductions. */
+  output_red (s, s->reductions, fgraph);
 }
 
 
