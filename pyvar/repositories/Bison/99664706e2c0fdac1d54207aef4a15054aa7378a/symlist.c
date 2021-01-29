@@ -97,6 +97,7 @@ symbol_list_type_set (symbol_list *syms, uniqstr type_name, location loc)
 void
 symbol_list_syms_print (const symbol_list *l, FILE *f)
 {
+  fputc ('[', f);
   char const *sep = "";
   for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
@@ -105,10 +106,12 @@ symbol_list_syms_print (const symbol_list *l, FILE *f)
              : l->content_type == SYMLIST_TYPE ? "type: "
              : "invalid content_type: ",
              f);
-      symbol_print (l->content.sym, f);
-      fputs (l->action_props.is_value_used ? " used" : " unused", f);
+      if (l->content_type == SYMLIST_SYMBOL)
+        symbol_print (l->content.sym, f);
+      fputs (l->action_props.is_value_used ? " (used)" : " (unused)", f);
       sep = ", ";
     }
+  fputc (']', f);
 }
 
 
