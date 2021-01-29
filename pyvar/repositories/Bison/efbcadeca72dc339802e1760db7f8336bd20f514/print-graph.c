@@ -72,19 +72,28 @@ print_core (struct obstack *oout, state *s)
         obstack_printf (oout, "%*s| ",
                         (int) strlen (previous_lhs->symbol->tag), "");
       else
-        obstack_printf (oout, "%s: ", escape (r->lhs->symbol->tag));
+        {
+          obstack_backslash (oout, r->lhs->symbol->tag);
+          obstack_printf (oout, ": ");
+        }
       previous_lhs = r->lhs;
 
       for (item_number const *sp = r->rhs; sp < sp1; sp++)
-        obstack_printf (oout, "%s ", escape (symbols[*sp]->tag));
+        {
+          obstack_backslash (oout, symbols[*sp]->tag);
+          obstack_1grow (oout, ' ');
+        }
 
       obstack_1grow (oout, '.');
 
       if (0 <= *r->rhs)
         for (item_number const *sp = sp1; 0 <= *sp; ++sp)
-          obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
+          {
+            obstack_1grow (oout, ' ');
+            obstack_backslash (oout, symbols[*sp]->tag);
+          }
       else
-        obstack_printf (oout, " %%empty");
+        obstack_sgrow (oout, " %empty");
 
       /* Experimental feature: display the lookahead tokens. */
       if (report_flag & report_lookahead_tokens
@@ -104,7 +113,7 @@ print_core (struct obstack *oout, state *s)
               BITSET_FOR_EACH (biter, reds->lookahead_tokens[redno], k, 0)
                 {
                   obstack_sgrow (oout, sep);
-                  obstack_sgrow (oout, escape (symbols[k]->tag));
+                  obstack_backslash (oout, symbols[k]->tag);
                   sep = ", ";
                 }
               obstack_1grow (oout, ']');
