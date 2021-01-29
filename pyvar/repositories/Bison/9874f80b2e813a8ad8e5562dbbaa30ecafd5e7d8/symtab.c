@@ -409,11 +409,11 @@ void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
 {
   if (str->alias)
-    warn_at (loc, _("symbol `%s' used more than once as a literal string"),
-	     str->tag);
+    warn_at (loc, _("symbol '%s' used more than once as a literal string"),
+             str->tag);
   else if (sym->alias)
-    warn_at (loc, _("symbol `%s' given more than one literal string"),
-	     sym->tag);
+    warn_at (loc, _("symbol '%s' given more than one literal string"),
+             sym->tag);
   else
     {
       str->class = token_sym;
