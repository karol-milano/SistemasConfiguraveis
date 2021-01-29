@@ -76,8 +76,9 @@ log_resolution (rule *r, symbol_number token,
         {
         case shift_resolution:
         case right_resolution:
+          obstack_sgrow (&solved_conflicts_obstack, "    ");
           obstack_printf (&solved_conflicts_obstack,
-                          _("    Conflict between rule %d and token %s"
+                          _("Conflict between rule %d and token %s"
                             " resolved as shift"),
                           r->number,
                           symbols[token]->tag);
@@ -85,16 +86,18 @@ log_resolution (rule *r, symbol_number token,
 
         case reduce_resolution:
         case left_resolution:
+          obstack_sgrow (&solved_conflicts_obstack, "    ");
           obstack_printf (&solved_conflicts_obstack,
-                          _("    Conflict between rule %d and token %s"
+                          _("Conflict between rule %d and token %s"
                             " resolved as reduce"),
                           r->number,
                           symbols[token]->tag);
           break;
 
         case nonassoc_resolution:
+          obstack_sgrow (&solved_conflicts_obstack, "    ");
           obstack_printf (&solved_conflicts_obstack,
-                          _("    Conflict between rule %d and token %s"
+                          _("Conflict between rule %d and token %s"
                             " resolved as an error"),
                           r->number,
                           symbols[token]->tag);
