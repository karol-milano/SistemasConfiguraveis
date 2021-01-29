@@ -462,7 +462,13 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
       if (declaring)
         {
           if (s->status == declared)
-            complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
+            {
+              unsigned i = 0;
+              complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
+              i += SUB_INDENT;
+              complain_indent (&sym->location, Wother, &i,
+                               _("previous declaration"));
+            }
           else
             s->status = declared;
         }
