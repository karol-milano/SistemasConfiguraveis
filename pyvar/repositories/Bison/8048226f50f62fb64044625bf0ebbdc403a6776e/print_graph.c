@@ -55,7 +55,8 @@ print_core (struct obstack *oout, state *s)
       snritems = nitemset;
     }
 
-  obstack_printf (oout, "state %d\\n", s->number);
+  obstack_printf (oout, _("State %d"), s->number);
+  obstack_sgrow (oout, "\\n");
   for (i = 0; i < snritems; i++)
     {
       item_number *sp;
@@ -69,12 +70,12 @@ print_core (struct obstack *oout, state *s)
 
       r = item_number_as_rule_number (*sp);
 
-      obstack_printf (oout, "%d: %s -> ", r, escape (rules[r].lhs->tag));
+      obstack_printf (oout, "%d: %s ->", r, escape (rules[r].lhs->tag));
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
-        obstack_printf (oout, "%s ", escape (symbols[*sp]->tag));
+        obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
 
-      obstack_1grow (oout, '.');
+      obstack_sgrow (oout, " .");
 
       for (/* Nothing */; *sp >= 0; ++sp)
         obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
@@ -93,7 +94,7 @@ print_core (struct obstack *oout, state *s)
               bitset_iterator biter;
               int k;
               char const *sep = "";
-              obstack_1grow (oout, '[');
+              obstack_sgrow (oout, "  [");
               BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
                 {
                   obstack_sgrow (oout, sep);
@@ -116,9 +117,8 @@ print_core (struct obstack *oout, state *s)
 static void
 print_actions (state const *s, FILE *fgraph)
 {
-  int i;
-
   transitions const *trans = s->transitions;
+  int i;
 
   /* Display reductions. */
   output_red (s, s->reductions, fgraph);
