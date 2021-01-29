@@ -84,12 +84,17 @@ symbol_list_type_new (uniqstr type_name, location loc)
 void
 symbol_list_syms_print (const symbol_list *l, FILE *f)
 {
+  char const *sep = "";
   for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
+      fputs (sep, f);
+      fputs (l->content_type == SYMLIST_SYMBOL ? "symbol: "
+             : l->content_type == SYMLIST_TYPE ? "type: "
+             : "invalid content_type: ",
+             f);
       symbol_print (l->content.sym, f);
-      fprintf (f, l->action_props.is_value_used ? " used" : " unused");
-      if (l && l->content.sym)
-        fprintf (f, ", ");
+      fputs (l->action_props.is_value_used ? " used" : " unused", f);
+      sep = ", ";
     }
 }
 
