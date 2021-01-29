@@ -34,13 +34,19 @@ symbol_list *
 symbol_list_new (symbol *sym, location loc)
 {
   symbol_list *res = xmalloc (sizeof *res);
-  res->next = NULL;
+
   res->sym = sym;
   res->location = loc;
+
   res->action = NULL;
+  res->used = false;
+
   res->ruleprec = NULL;
   res->dprec = 0;
   res->merger = 0;
+
+  res->next = NULL;
+
   return res;
 }
 
@@ -56,7 +62,7 @@ symbol_list_print (symbol_list *l, FILE *f)
     {
       symbol_print (l->sym, f);
       if (l && l->sym)
-	fputc (' ', f);
+	fprintf (f, ", ");
     }
 }
 
@@ -90,43 +96,64 @@ symbol_list_free (symbol_list *list)
 `--------------------*/
 
 unsigned int
-symbol_list_length (symbol_list *list)
+symbol_list_length (symbol_list *l)
 {
   int res = 0;
-  for (/* Nothing. */; list; list = list->next)
+  for (/* Nothing. */; l; l = l->next)
     ++res;
   return res;
 }
 
 
+/*--------------------------------.
+| Get symbol N in symbol list L.  |
+`--------------------------------*/
+
+symbol_list *
+symbol_list_n_get (symbol_list *l, int n)
+{
+  int i;
+
+  if (n < 0)
+    return NULL;
+
+  for (i = 0; i < n; ++i)
+    {
+      l = l->next;
+      if (l == NULL || l->sym == NULL)
+	return NULL;
+    }
+
+  return l;
+}
+
+
 /*--------------------------------------------------------------.
 | Get the data type (alternative in the union) of the value for |
-| symbol N in symbol list RP.                                   |
+| symbol N in symbol list L.                                    |
 `--------------------------------------------------------------*/
 
 uniqstr
-symbol_list_n_type_name_get (symbol_list *rp, location loc, int n)
+symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
 {
-  int i;
-
-  if (n < 0)
+  l = symbol_list_n_get (l, n);
+  if (!l)
     {
       complain_at (loc, _("invalid $ value: $%d"), n);
       return NULL;
     }
+  return l->sym->type_name;
+}
 
-  i = 0;
 
-  while (i < n)
-    {
-      rp = rp->next;
-      if (rp == NULL || rp->sym == NULL)
-	{
-	  complain_at (loc, _("invalid $ value: $%d"), n);
-	  return NULL;
-	}
-      ++i;
-    }
+/*----------------------------------------.
+| The symbol N in symbol list L is USED.  |
+`----------------------------------------*/
 
-  return rp->sym->type_name;
+void
+symbol_list_n_used_set (symbol_list *l, int n, bool used)
+{
+  l = symbol_list_n_get (l, n);
+  if (l)
+    l->used = used;
 }
