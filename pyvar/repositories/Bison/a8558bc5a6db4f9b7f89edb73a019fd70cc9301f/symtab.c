@@ -309,9 +309,12 @@ complain_class_redeclared (symbol *sym, symbol_class class, location second)
                    class == token_sym
                    ? _("symbol %s redeclared as a token")
                    : _("symbol %s redeclared as a nonterminal"), sym->tag);
-  i += SUB_INDENT;
-  complain_indent (&sym->location, complaint, &i,
-                   _("previous definition"));
+  if (!location_empty (sym->location))
+    {
+      i += SUB_INDENT;
+      complain_indent (&sym->location, complaint, &i,
+                       _("previous definition"));
+    }
 }
 
 
