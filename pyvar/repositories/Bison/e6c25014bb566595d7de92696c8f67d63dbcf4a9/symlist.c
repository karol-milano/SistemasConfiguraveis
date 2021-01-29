@@ -88,7 +88,7 @@ symbol_list_syms_print (const symbol_list *l, FILE *f)
   for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
       symbol_print (l->content.sym, f);
-      fprintf (stderr, l->action_props.is_value_used ? " used" : " unused");
+      fprintf (f, l->action_props.is_value_used ? " used" : " unused");
       if (l && l->content.sym)
         fprintf (f, ", ");
     }
