@@ -396,7 +396,7 @@ symbol_check_defined (symbol *sym)
           complain_at (sym->location, complaint,
                        _("symbol %s is used, but is not defined as a token"
                          " and has no rules"),
-                    sym->tag);
+                       sym->tag);
           break;
         case declared:
           /* If declared, then sym->class != unknown_sym. */
