@@ -96,23 +96,24 @@ symbol_list_type_set (symbol_list *syms, uniqstr type_name)
 `-----------------------------------------------------------------------*/
 
 void
-symbol_list_syms_print (const symbol_list *l, FILE *f)
+symbol_list_syms_print (const symbol_list *l, FILE *out)
 {
-  fputc ('[', f);
+  fputc ('[', out);
   char const *sep = "";
   for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
-      fputs (sep, f);
-      fputs (l->content_type == SYMLIST_SYMBOL ? "symbol: "
-             : l->content_type == SYMLIST_TYPE ? "type: "
-             : "invalid content_type: ",
-             f);
+      fputs (sep, out);
+      fputs (l->content_type == SYMLIST_SYMBOL ? "symbol{"
+             : l->content_type == SYMLIST_TYPE ? "type{"
+             : "invalid content_type{",
+             out);
       if (l->content_type == SYMLIST_SYMBOL)
-        symbol_print (l->content.sym, f);
-      fputs (l->action_props.is_value_used ? " (used)" : " (unused)", f);
+        symbol_print (l->content.sym, out);
+      fputs (l->action_props.is_value_used ? " (used)" : " (unused)", out);
+      putc ('}', out);
       sep = ", ";
     }
-  fputc (']', f);
+  fputc (']', out);
 }
 
 
