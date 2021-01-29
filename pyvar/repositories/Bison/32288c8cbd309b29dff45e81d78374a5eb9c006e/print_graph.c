@@ -58,6 +58,7 @@ print_lhs (struct obstack *oout, rule *previous_rule, rule *r)
       obstack_sgrow (oout, escape (r->lhs->tag));
       obstack_1grow (oout, ':');
     }
+  obstack_1grow (oout, ' ');
 }
 
 static void
@@ -98,7 +99,7 @@ print_core (struct obstack *oout, state *s)
       for (sp = rules[r].rhs; sp < sp1; sp++)
         obstack_printf (oout, "%s ", escape (symbols[*sp]->tag));
 
-      obstack_sgrow (oout, " .");
+      obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
         obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
