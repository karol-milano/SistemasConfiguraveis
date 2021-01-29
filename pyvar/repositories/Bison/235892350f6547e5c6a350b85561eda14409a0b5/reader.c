@@ -325,9 +325,9 @@ grammar_rule_check (const symbol_list *r)
             void (*warn_at_ptr)(location, char const*, ...) =
               midrule_warning ? midrule_value_at : warn_at;
             if (n)
-              warn_at_ptr (r->location, _("unused value: $%d"), n);
+              warn_at_ptr (l->location, _("unused value: $%d"), n);
             else
-              warn_at_ptr (r->location, _("unset value: $$"));
+              warn_at_ptr (l->location, _("unset value: $$"));
           }
       }
   }
