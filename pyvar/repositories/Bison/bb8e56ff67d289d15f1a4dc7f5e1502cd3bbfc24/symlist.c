@@ -175,7 +175,7 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
   l = symbol_list_n_get (l, n);
   if (!l)
     {
-      complain_at (loc, complaint, _("invalid $ value: $%d"), n);
+      complain (&loc, complaint, _("invalid $ value: $%d"), n);
       return NULL;
     }
   aver (l->content_type == SYMLIST_SYMBOL);
