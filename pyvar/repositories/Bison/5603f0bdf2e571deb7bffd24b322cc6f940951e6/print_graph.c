@@ -48,7 +48,6 @@ print_core (struct obstack *oout, state *s)
 {
   item_number const *sitems = s->items;
   sym_content *previous_lhs = NULL;
-  size_t i;
   size_t snritems = s->nitems;
 
   /* Output all the items of a state, not just its kernel.  */
@@ -61,16 +60,15 @@ print_core (struct obstack *oout, state *s)
 
   obstack_printf (oout, _("State %d"), s->number);
   obstack_sgrow (oout, "\\n\\l");
-  for (i = 0; i < snritems; i++)
+  for (size_t i = 0; i < snritems; ++i)
     {
       item_number const *sp1 = ritem + sitems[i];
       item_number const *sp = sp1;
-      rule *r;
 
       while (0 <= *sp)
         sp++;
 
-      r = &rules[item_number_as_rule_number (*sp)];
+      rule *r = &rules[item_number_as_rule_number (*sp)];
 
       obstack_printf (oout, "%3d ", r->number);
       if (previous_lhs && UNIQSTR_EQ (previous_lhs->symbol->tag,
@@ -130,16 +128,15 @@ static void
 print_actions (state const *s, FILE *fgraph)
 {
   transitions const *trans = s->transitions;
-  int i;
 
   if (!trans->num && !s->reductions)
     return;
 
-  for (i = 0; i < trans->num; i++)
+  for (int i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i))
       {
-        state *s1 = trans->states[i];
-        symbol_number sym = s1->accessing_symbol;
+        const state *s1 = trans->states[i];
+        const symbol_number sym = s1->accessing_symbol;
 
         /* Shifts are solid, gotos are dashed, and error is dotted.  */
         char const *style =
@@ -183,13 +180,12 @@ print_state (state *s, FILE *fgraph)
 void
 print_graph (void)
 {
-  state_number i;
   FILE *fgraph = xfopen (spec_graph_file, "w");
   start_graph (fgraph);
 
   /* Output nodes and edges. */
   new_closure (nritems);
-  for (i = 0; i < nstates; i++)
+  for (int i = 0; i < nstates; i++)
     print_state (states[i], fgraph);
   free_closure ();
 
