@@ -46,7 +46,7 @@ static void
 print_core (struct obstack *oout, state *s)
 {
   item_number const *sitems = s->items;
-  symbol *previous_lhs = NULL;
+  sym_content *previous_lhs = NULL;
   size_t i;
   size_t snritems = s->nitems;
 
@@ -72,11 +72,12 @@ print_core (struct obstack *oout, state *s)
       r = &rules[item_number_as_rule_number (*sp)];
 
       obstack_printf (oout, "%3d ", r->number);
-      if (previous_lhs && UNIQSTR_EQ (previous_lhs->tag, r->lhs->tag))
+      if (previous_lhs && UNIQSTR_EQ (previous_lhs->symbol->tag,
+                                      r->lhs->symbol->tag))
         obstack_printf (oout, "%*s| ",
-                        (int) strlen (previous_lhs->tag), "");
+                        (int) strlen (previous_lhs->symbol->tag), "");
       else
-        obstack_printf (oout, "%s: ", escape (r->lhs->tag));
+        obstack_printf (oout, "%s: ", escape (r->lhs->symbol->tag));
       previous_lhs = r->lhs;
 
       for (sp = r->rhs; sp < sp1; sp++)
