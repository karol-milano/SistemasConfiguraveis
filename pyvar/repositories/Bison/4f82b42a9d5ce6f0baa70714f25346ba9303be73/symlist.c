@@ -185,7 +185,7 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
       complain_at (loc, _("invalid $ value: $%d"), n);
       return NULL;
     }
-  assert (l->content_type == SYMLIST_SYMBOL);
+  aver (l->content_type == SYMLIST_SYMBOL);
   return l->content.sym->type_name;
 }
 
