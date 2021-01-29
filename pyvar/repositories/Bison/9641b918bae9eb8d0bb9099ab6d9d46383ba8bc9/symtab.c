@@ -33,6 +33,7 @@
 `-------------------------------------------------------------------*/
 
 static symbol **symbols_sorted = NULL;
+static symbol **semantic_types_sorted = NULL;
 
 /*------------------------.
 | Distinguished symbols.  |
@@ -118,12 +119,14 @@ code_props_type_string (code_props_type kind)
 `----------------------------------------*/
 
 static semantic_type *
-semantic_type_new (uniqstr tag)
+semantic_type_new (uniqstr tag, const location *loc)
 {
   semantic_type *res = xmalloc (sizeof *res);
 
   uniqstr_assert (tag);
   res->tag = tag;
+  if (loc)
+    res->location = *loc;
   for (int i = 0; i < CODE_PROPS_SIZE; ++i)
     code_props_none_init (&res->props[i]);
 
@@ -283,7 +286,7 @@ symbol_code_props_get (symbol const *sym,
   if (sym->type_name)
     {
       code_props const *code =
-        &semantic_type_get (sym->type_name)->props[kind];
+        &semantic_type_get (sym->type_name, NULL)->props[kind];
       if (code->code)
         return code;
     }
@@ -416,6 +419,26 @@ symbol_check_defined (symbol *sym)
       sym->number = nvars++;
     }
 
+  /* Set the semantic type status associated to the current symbol to
+     'declared' so that we could check semantic types unnecessary uses. */
+  if (sym->type_name)
+    {
+      semantic_type *sem_type = semantic_type_get (sym->type_name, NULL);
+      if (sem_type)
+        sem_type->status = declared;
+    }
+
+  return true;
+}
+
+static inline bool
+semantic_type_check_defined (semantic_type *sem_type)
+{
+  if (sem_type->status != declared)
+    warn_at (sem_type->location,
+             _("type <%s> is used, but is not associated to any symbol"),
+             sem_type->tag);
+
   return true;
 }
 
@@ -425,6 +448,13 @@ symbol_check_defined_processor (void *sym, void *null ATTRIBUTE_UNUSED)
   return symbol_check_defined (sym);
 }
 
+static bool
+semantic_type_check_defined_processor (void *sem_type,
+                                       void *null ATTRIBUTE_UNUSED)
+{
+  return semantic_type_check_defined (sem_type);
+}
+
 
 void
 symbol_make_alias (symbol *sym, symbol *str, location loc)
@@ -690,7 +720,7 @@ symbol_from_uniqstr (const uniqstr key, location loc)
 `-----------------------------------------------------------------------*/
 
 semantic_type *
-semantic_type_from_uniqstr (const uniqstr key)
+semantic_type_from_uniqstr (const uniqstr key, const location *loc)
 {
   semantic_type probe;
   semantic_type *entry;
@@ -701,7 +731,7 @@ semantic_type_from_uniqstr (const uniqstr key)
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = semantic_type_new (key);
+      entry = semantic_type_new (key, loc);
       if (!hash_insert (semantic_type_table, entry))
         xalloc_die ();
     }
@@ -727,9 +757,9 @@ symbol_get (const char *key, location loc)
 `-----------------------------------------------------------------------*/
 
 semantic_type *
-semantic_type_get (const char *key)
+semantic_type_get (const char *key, const location *loc)
 {
-  return semantic_type_from_uniqstr (uniqstr_new (key));
+  return semantic_type_from_uniqstr (uniqstr_new (key), loc);
 }
 
 
@@ -819,6 +849,8 @@ symbols_check_defined (void)
 {
   symbols_do (symbol_check_defined_processor, NULL,
               symbol_table, symbols_sorted);
+  symbols_do (semantic_type_check_defined_processor, NULL,
+              semantic_type_table, semantic_types_sorted);
 }
 
 /*------------------------------------------------------------------.
