@@ -83,6 +83,23 @@ symbol_new (uniqstr tag, location loc)
   return res;
 }
 
+/*----------------------------------------.
+| Create a new semantic type, named TAG.  |
+`----------------------------------------*/
+
+static semantic_type *
+semantic_type_new (uniqstr tag)
+{
+  semantic_type *res = xmalloc (sizeof *res);
+
+  uniqstr_assert (tag);
+  res->tag = tag;
+  res->destructor = NULL;
+  res->printer = NULL;
+
+  return res;
+}
+
 
 /*-----------------.
 | Print a symbol.  |
@@ -114,12 +131,21 @@ symbol_print (symbol *s, FILE *f)
 `------------------------------------------------------------------*/
 
 static void
-redeclaration (symbol* s, const char *what, location first, location second)
+symbol_redeclaration (symbol *s, const char *what, location first,
+                      location second)
 {
   complain_at (second, _("%s redeclaration for %s"), what, s->tag);
   complain_at (first, _("previous declaration"));
 }
 
+static void
+semantic_type_redeclaration (semantic_type *s, const char *what, location first,
+                             location second)
+{
+  complain_at (second, _("%s redeclaration for <%s>"), what, s->tag);
+  complain_at (first, _("previous declaration"));
+}
+
 
 /*-----------------------------------------------------------------.
 | Set the TYPE_NAME associated with SYM.  Does nothing if passed 0 |
@@ -132,7 +158,7 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
   if (type_name)
     {
       if (sym->type_name)
-	redeclaration (sym, "%type", sym->type_location, loc);
+	symbol_redeclaration (sym, "%type", sym->type_location, loc);
       uniqstr_assert (type_name);
       sym->type_name = type_name;
       sym->type_location = loc;
@@ -150,12 +176,31 @@ symbol_destructor_set (symbol *sym, const char *destructor, location loc)
   if (destructor)
     {
       if (sym->destructor)
-	redeclaration (sym, "%destructor", sym->destructor_location, loc);
+	symbol_redeclaration (sym, "%destructor", sym->destructor_location,
+                              loc);
       sym->destructor = destructor;
       sym->destructor_location = loc;
     }
 }
 
+/*-------------------------------------------------------------------.
+| Set the DESTRUCTOR associated with TYPE.  Do nothing if passed 0.  |
+`-------------------------------------------------------------------*/
+
+void
+semantic_type_destructor_set (semantic_type *type, const char *destructor,
+                              location loc)
+{
+  if (destructor)
+    {
+      if (type->destructor)
+	semantic_type_redeclaration (type, "%destructor",
+                                     type->destructor_location, loc);
+      type->destructor = destructor;
+      type->destructor_location = loc;
+    }
+}
+
 /*---------------------------------------.
 | Get the computed %destructor for SYM.  |
 `---------------------------------------*/
@@ -167,6 +212,14 @@ symbol_destructor_get (symbol *sym)
   if (sym->destructor != NULL)
     return sym->destructor;
 
+  /* Per-type %destructor.  */
+  if (sym->type_name)
+    {
+      semantic_type *type = semantic_type_get (sym->type_name);
+      if (type->destructor)
+        return type->destructor;
+    }
+
   /* Apply the default %destructor only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
     return NULL;
@@ -182,6 +235,12 @@ symbol_destructor_location_get (symbol *sym)
 {
   if (sym->destructor != NULL)
     return sym->destructor_location;
+  if (sym->type_name)
+    {
+      semantic_type *type = semantic_type_get (sym->type_name);
+      if (type->destructor)
+        return type->destructor_location;
+    }
   return default_destructor_location;
 }
 
@@ -195,12 +254,30 @@ symbol_printer_set (symbol *sym, const char *printer, location loc)
   if (printer)
     {
       if (sym->printer)
-	redeclaration (sym, "%printer", sym->printer_location, loc);
+	symbol_redeclaration (sym, "%printer", sym->printer_location, loc);
       sym->printer = printer;
       sym->printer_location = loc;
     }
 }
 
+/*----------------------------------------------------------------.
+| Set the PRINTER associated with TYPE.  Do nothing if passed 0.  |
+`----------------------------------------------------------------*/
+
+void
+semantic_type_printer_set (semantic_type *type, const char *printer,
+                           location loc)
+{
+  if (printer)
+    {
+      if (type->printer)
+	semantic_type_redeclaration (type, "%printer", type->printer_location,
+                                     loc);
+      type->printer = printer;
+      type->printer_location = loc;
+    }
+}
+
 /*------------------------------------.
 | Get the computed %printer for SYM.  |
 `------------------------------------*/
@@ -212,6 +289,14 @@ symbol_printer_get (symbol *sym)
   if (sym->printer != NULL)
     return sym->printer;
 
+  /* Per-type %printer.  */
+  if (sym->type_name)
+    {
+      semantic_type *type = semantic_type_get (sym->type_name);
+      if (type->printer)
+        return type->printer;
+    }
+
   /* Apply the default %printer only to user-defined symbols.  */
   if (sym->tag[0] == '$' || sym == errtoken)
     return NULL;
@@ -227,6 +312,12 @@ symbol_printer_location_get (symbol *sym)
 {
   if (sym->printer != NULL)
     return sym->printer_location;
+  if (sym->type_name)
+    {
+      semantic_type *type = semantic_type_get (sym->type_name);
+      if (type->printer)
+        return type->printer_location;
+    }
   return default_printer_location;
 }
 
@@ -242,7 +333,8 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
   if (a != undef_assoc)
     {
       if (sym->prec != 0)
-	redeclaration (sym, assoc_to_string (a), sym->prec_location, loc);
+	symbol_redeclaration (sym, assoc_to_string (a), sym->prec_location,
+                              loc);
       sym->prec = prec;
       sym->assoc = a;
       sym->prec_location = loc;
@@ -509,14 +601,15 @@ symbol_translation_processor (void *this, void *null ATTRIBUTE_UNUSED)
 }
 
 
-/*----------------------.
-| A symbol hash table.  |
-`----------------------*/
+/*---------------------------------------.
+| Symbol and semantic type hash tables.  |
+`---------------------------------------*/
 
-/* Initial capacity of symbols hash table.  */
+/* Initial capacity of symbol and semantic type hash table.  */
 #define HT_INITIAL_CAPACITY 257
 
 static struct hash_table *symbol_table = NULL;
+static struct hash_table *semantic_type_table = NULL;
 
 static inline bool
 hash_compare_symbol (const symbol *m1, const symbol *m2)
@@ -525,12 +618,25 @@ hash_compare_symbol (const symbol *m1, const symbol *m2)
   return UNIQSTR_EQ (m1->tag, m2->tag);
 }
 
+static inline bool
+hash_compare_semantic_type (const semantic_type *m1, const semantic_type *m2)
+{
+  /* Since names are unique, we can compare the pointers themselves.  */
+  return UNIQSTR_EQ (m1->tag, m2->tag);
+}
+
 static bool
 hash_symbol_comparator (void const *m1, void const *m2)
 {
   return hash_compare_symbol (m1, m2);
 }
 
+static bool
+hash_semantic_type_comparator (void const *m1, void const *m2)
+{
+  return hash_compare_semantic_type (m1, m2);
+}
+
 static inline size_t
 hash_symbol (const symbol *m, size_t tablesize)
 {
@@ -538,12 +644,24 @@ hash_symbol (const symbol *m, size_t tablesize)
   return ((uintptr_t) m->tag) % tablesize;
 }
 
+static inline size_t
+hash_semantic_type (const semantic_type *m, size_t tablesize)
+{
+  /* Since names are unique, we can hash the pointer itself.  */
+  return ((uintptr_t) m->tag) % tablesize;
+}
+
 static size_t
 hash_symbol_hasher (void const *m, size_t tablesize)
 {
   return hash_symbol (m, tablesize);
 }
 
+static size_t
+hash_semantic_type_hasher (void const *m, size_t tablesize)
+{
+  return hash_semantic_type (m, tablesize);
+}
 
 /*-------------------------------.
 | Create the symbol hash table.  |
@@ -557,6 +675,11 @@ symbols_new (void)
 				  hash_symbol_hasher,
 				  hash_symbol_comparator,
 				  free);
+  semantic_type_table = hash_initialize (HT_INITIAL_CAPACITY,
+				         NULL,
+				         hash_semantic_type_hasher,
+				         hash_semantic_type_comparator,
+				         free);
 }
 
 
@@ -584,6 +707,30 @@ symbol_from_uniqstr (const uniqstr key, location loc)
 }
 
 
+/*-----------------------------------------------------------------------.
+| Find the semantic type named KEY, and return it.  If it does not exist |
+| yet, create it.                                                        |
+`-----------------------------------------------------------------------*/
+
+semantic_type *
+semantic_type_from_uniqstr (const uniqstr key)
+{
+  semantic_type probe;
+  semantic_type *entry;
+
+  probe.tag = key;
+  entry = hash_lookup (semantic_type_table, &probe);
+
+  if (!entry)
+    {
+      /* First insertion in the hash. */
+      entry = semantic_type_new (key);
+      hash_insert (semantic_type_table, entry);
+    }
+  return entry;
+}
+
+
 /*----------------------------------------------------------------.
 | Find the symbol named KEY, and return it.  If it does not exist |
 | yet, create it.                                                 |
@@ -596,6 +743,18 @@ symbol_get (const char *key, location loc)
 }
 
 
+/*-----------------------------------------------------------------------.
+| Find the semantic type named KEY, and return it.  If it does not exist |
+| yet, create it.                                                        |
+`-----------------------------------------------------------------------*/
+
+semantic_type *
+semantic_type_get (const char *key)
+{
+  return semantic_type_from_uniqstr (uniqstr_new (key));
+}
+
+
 /*------------------------------------------------------------------.
 | Generate a dummy nonterminal, whose name cannot conflict with the |
 | user's names.                                                     |
@@ -631,6 +790,7 @@ void
 symbols_free (void)
 {
   hash_free (symbol_table);
+  hash_free (semantic_type_table);
   free (symbols);
 }
 
