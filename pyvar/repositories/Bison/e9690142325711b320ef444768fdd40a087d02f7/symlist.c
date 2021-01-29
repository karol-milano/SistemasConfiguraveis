@@ -123,7 +123,7 @@ symbol_list_syms_print (const symbol_list *l, FILE *f)
       symbol_print (l->content.sym, f);
       fprintf (stderr, l->action_props.is_value_used ? " used" : " unused");
       if (l && l->content.sym)
-	fprintf (f, ", ");
+        fprintf (f, ", ");
     }
 }
 
@@ -190,7 +190,7 @@ symbol_list_n_get (symbol_list *l, int n)
       l = l->next;
       if (l == NULL
           || (l->content_type == SYMLIST_SYMBOL && l->content.sym == NULL))
-	return NULL;
+        return NULL;
     }
 
   return l;
