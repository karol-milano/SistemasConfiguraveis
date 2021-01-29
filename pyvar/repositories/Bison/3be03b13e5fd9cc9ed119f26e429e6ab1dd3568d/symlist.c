@@ -31,11 +31,12 @@
 `--------------------------------------*/
 
 symbol_list *
-symbol_list_new (symbol *sym, location loc)
+symbol_list_sym_new (symbol *sym, location loc)
 {
   symbol_list *res = xmalloc (sizeof *res);
 
-  res->sym = sym;
+  res->content_type = SYMLIST_SYMBOL;
+  res->content.sym = sym;
   res->location = loc;
 
   res->midrule = NULL;
@@ -55,39 +56,73 @@ symbol_list_new (symbol *sym, location loc)
 }
 
 
-/*------------------.
-| Print this list.  |
-`------------------*/
+/*--------------------------------------------.
+| Create a list containing TYPE_NAME at LOC.  |
+`--------------------------------------------*/
+
+symbol_list *
+symbol_list_type_new (uniqstr type_name, location loc)
+{
+  symbol_list *res = xmalloc (sizeof *res);
+
+  res->content_type = SYMLIST_TYPE;
+  res->content.type_name = type_name;
+  res->location = loc;
+  res->next = NULL;
+
+  return res;
+}
+
+
+/*----------------------------------------------------.
+| Create a list containing a %symbol-default at LOC.  |
+`----------------------------------------------------*/
+
+symbol_list *
+symbol_list_default_new (location loc)
+{
+  symbol_list *res = xmalloc (sizeof *res);
+
+  res->content_type = SYMLIST_DEFAULT;
+  res->location = loc;
+  res->next = NULL;
+
+  return res;
+}
+
+
+/*-----------------------------------------------------------------------.
+| Print this list, for which every content_type must be SYMLIST_SYMBOL.  |
+`-----------------------------------------------------------------------*/
 
 void
-symbol_list_print (const symbol_list *l, FILE *f)
+symbol_list_syms_print (const symbol_list *l, FILE *f)
 {
-  for (/* Nothing. */; l && l->sym; l = l->next)
+  for (/* Nothing. */; l && l->content.sym; l = l->next)
     {
-      symbol_print (l->sym, f);
+      symbol_print (l->content.sym, f);
       fprintf (stderr, l->used ? " used" : " unused");
-      if (l && l->sym)
+      if (l && l->content.sym)
 	fprintf (f, ", ");
     }
 }
 
 
-/*---------------------------------.
-| Prepend SYM at LOC to the LIST.  |
-`---------------------------------*/
+/*---------------------------.
+| Prepend NODE to the LIST.  |
+`---------------------------*/
 
 symbol_list *
-symbol_list_prepend (symbol_list *list, symbol *sym, location loc)
+symbol_list_prepend (symbol_list *list, symbol_list *node)
 {
-  symbol_list *res = symbol_list_new (sym, loc);
-  res->next = list;
-  return res;
+  node->next = list;
+  return node;
 }
 
 
-/*-------------------------------------------------.
-| Free the LIST, but not the symbols it contains.  |
-`-------------------------------------------------*/
+/*-----------------------------------------------.
+| Free the LIST, but not the items it contains.  |
+`-----------------------------------------------*/
 
 void
 symbol_list_free (symbol_list *list)
@@ -104,15 +139,17 @@ int
 symbol_list_length (symbol_list const *l)
 {
   int res = 0;
-  for (/* Nothing. */; l && l->sym; l = l->next)
+  for (/* Nothing. */;
+       l && !(l->content_type == SYMLIST_SYMBOL && l->content.sym == NULL);
+       l = l->next)
     ++res;
   return res;
 }
 
 
-/*--------------------------------.
-| Get symbol N in symbol list L.  |
-`--------------------------------*/
+/*------------------------------.
+| Get item N in symbol list L.  |
+`------------------------------*/
 
 symbol_list *
 symbol_list_n_get (symbol_list *l, int n)
@@ -125,7 +162,8 @@ symbol_list_n_get (symbol_list *l, int n)
   for (i = 0; i < n; ++i)
     {
       l = l->next;
-      if (l == NULL || l->sym == NULL)
+      if (l == NULL
+          || (l->content_type == SYMLIST_SYMBOL && l->content.sym == NULL))
 	return NULL;
     }
 
@@ -147,13 +185,14 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
       complain_at (loc, _("invalid $ value: $%d"), n);
       return NULL;
     }
-  return l->sym->type_name;
+  assert (l->content_type == SYMLIST_SYMBOL);
+  return l->content.sym->type_name;
 }
 
 
-/*----------------------------------------.
-| The symbol N in symbol list L is USED.  |
-`----------------------------------------*/
+/*--------------------------------------.
+| The item N in symbol list L is USED.  |
+`--------------------------------------*/
 
 void
 symbol_list_n_used_set (symbol_list *l, int n, bool used)
@@ -162,3 +201,38 @@ symbol_list_n_used_set (symbol_list *l, int n, bool used)
   if (l)
     l->used = used;
 }
+
+void
+symbol_list_destructor_set (symbol_list *node, const char *destructor,
+                            location loc)
+{
+  switch (node->content_type)
+    {
+      case SYMLIST_SYMBOL:
+        symbol_destructor_set (node->content.sym, destructor, loc);
+        break;
+      case SYMLIST_TYPE:
+        /* FIXME: */
+        break;
+      case SYMLIST_DEFAULT:
+        default_destructor_set (destructor, loc);
+        break;
+    }
+}
+
+void
+symbol_list_printer_set (symbol_list *node, const char *printer, location loc)
+{
+  switch (node->content_type)
+    {
+      case SYMLIST_SYMBOL:
+        symbol_printer_set (node->content.sym, printer, loc);
+        break;
+      case SYMLIST_TYPE:
+        /* FIXME: */
+        break;
+      case SYMLIST_DEFAULT:
+        default_printer_set (printer, loc);
+        break;
+    }
+}
