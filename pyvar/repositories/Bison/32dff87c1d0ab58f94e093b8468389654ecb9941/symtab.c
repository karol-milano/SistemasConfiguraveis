@@ -464,7 +464,8 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
           if (s->status == declared)
             {
               unsigned i = 0;
-              complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
+              complain_indent (&loc, Wother, &i,
+                               _("symbol %s redeclared"), sym->tag);
               i += SUB_INDENT;
               complain_indent (&sym->location, Wother, &i,
                                _("previous declaration"));
