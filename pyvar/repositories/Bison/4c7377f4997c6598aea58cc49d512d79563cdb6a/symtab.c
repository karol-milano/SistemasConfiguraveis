@@ -70,11 +70,8 @@ sym_content_new (symbol *s)
   res->symbol = s;
 
   res->type_name = NULL;
-  {
-    int i;
-    for (i = 0; i < CODE_PROPS_SIZE; ++i)
-      code_props_none_init (&res->props[i]);
-  }
+  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
+    code_props_none_init (&res->props[i]);
 
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
@@ -204,11 +201,8 @@ semantic_type_new (uniqstr tag, const location *loc)
   res->tag = tag;
   res->location = loc ? *loc : empty_location;
   res->status = undeclared;
-  {
-    int i;
-    for (i = 0; i < CODE_PROPS_SIZE; ++i)
-      code_props_none_init (&res->props[i]);
-  }
+  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
+    code_props_none_init (&res->props[i]);
 
   return res;
 }
@@ -410,9 +404,9 @@ symbol_code_props_get (symbol *sym, code_props_type kind)
 void
 symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 {
-  sym_content *s = sym->content;
   if (a != undef_assoc)
     {
+      sym_content *s = sym->content;
       if (s->prec)
         symbol_redeclaration (sym, assoc_to_string (a),
                               s->prec_location, loc);
@@ -511,11 +505,8 @@ symbol_check_defined (symbol *sym)
       s->number = nvars++;
     }
 
-  {
-    int i;
-    for (i = 0; i < 2; ++i)
-      symbol_code_props_get (sym, i)->is_used = true;
-  }
+  for (int i = 0; i < 2; ++i)
+    symbol_code_props_get (sym, i)->is_used = true;
 
   /* Set the semantic type status associated to the current symbol to
      'declared' so that we could check semantic types unnecessary uses. */
@@ -537,8 +528,7 @@ semantic_type_check_defined (semantic_type *sem_type)
       || !*sem_type->tag
       || STREQ (sem_type->tag, "*"))
     {
-      int i;
-      for (i = 0; i < 2; ++i)
+      for (int i = 0; i < 2; ++i)
         if (sem_type->props[i].kind != CODE_PROPS_NONE
             && ! sem_type->props[i].is_used)
           complain (&sem_type->location, Wother,
@@ -586,14 +576,11 @@ symbol_merge_properties (symbol *sym, symbol *str)
     }
 
 
-  {
-    int i;
-    for (i = 0; i < CODE_PROPS_SIZE; ++i)
-      if (str->content->props[i].code)
-        symbol_code_props_set (sym, i, &str->content->props[i]);
-      else if (sym->content->props[i].code)
-        symbol_code_props_set (str, i, &sym->content->props[i]);
-  }
+  for (int i = 0; i < CODE_PROPS_SIZE; ++i)
+    if (str->content->props[i].code)
+      symbol_code_props_set (sym, i, &str->content->props[i]);
+    else if (sym->content->props[i].code)
+      symbol_code_props_set (str, i, &sym->content->props[i]);
 
   if (sym->content->prec || str->content->prec)
     {
@@ -787,10 +774,9 @@ symbol *
 symbol_from_uniqstr (const uniqstr key, location loc)
 {
   symbol probe;
-  symbol *entry;
 
   probe.tag = key;
-  entry = hash_lookup (symbol_table, &probe);
+  symbol *entry = hash_lookup (symbol_table, &probe);
 
   if (!entry)
     {
@@ -813,10 +799,9 @@ semantic_type *
 semantic_type_from_uniqstr (const uniqstr key, const location *loc)
 {
   semantic_type probe;
-  semantic_type *entry;
 
   probe.tag = key;
-  entry = hash_lookup (semantic_type_table, &probe);
+  semantic_type *entry = hash_lookup (semantic_type_table, &probe);
 
   if (!entry)
     {
@@ -865,10 +850,8 @@ dummy_symbol_get (location loc)
   static int dummy_count = 0;
   static char buf[256];
 
-  symbol *sym;
-
   sprintf (buf, "$@%d", ++dummy_count);
-  sym = symbol_get (buf, loc);
+  symbol *sym = symbol_get (buf, loc);
   sym->content->class = nterm_sym;
   sym->content->number = nvars++;
   return sym;
@@ -923,11 +906,8 @@ symbols_do (Hash_processor processor, void *processor_data,
       hash_get_entries (table, (void**)*sorted, count);
       qsort (*sorted, count, sizeof **sorted, symbols_cmp_qsort);
     }
-  {
-    size_t i;
-    for (i = 0; i < count; ++i)
-      processor ((*sorted)[i], processor_data);
-  }
+  for (size_t i = 0; i < count; ++i)
+    processor ((*sorted)[i], processor_data);
 }
 
 /*--------------------------------------------------------------.
@@ -953,12 +933,11 @@ static void
 symbols_token_translations_init (void)
 {
   bool num_256_available_p = true;
-  int i;
 
   /* Find the highest user token number, and whether 256, the POSIX
      preferred user token number for the error token, is used.  */
   max_user_token_number = 0;
-  for (i = 0; i < ntokens; ++i)
+  for (int i = 0; i < ntokens; ++i)
     {
       sym_content *this = symbols[i]->content;
       if (this->user_token_number != USER_NUMBER_UNDEFINED)
@@ -979,7 +958,7 @@ symbols_token_translations_init (void)
   if (max_user_token_number < 256)
     max_user_token_number = 256;
 
-  for (i = 0; i < ntokens; ++i)
+  for (int i = 0; i < ntokens; ++i)
     {
       sym_content *this = symbols[i]->content;
       if (this->user_token_number == USER_NUMBER_UNDEFINED)
@@ -993,7 +972,7 @@ symbols_token_translations_init (void)
 
   /* Initialize all entries for literal tokens to the internal token
      number for $undefined, which represents all invalid inputs.  */
-  for (i = 0; i < max_user_token_number + 1; i++)
+  for (int i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->content->number;
   symbols_do (symbol_translation_processor, NULL,
               symbol_table, &symbols_sorted);
@@ -1013,10 +992,8 @@ symbols_pack (void)
 
   /* Aliases leave empty slots in symbols, so remove them.  */
   {
-    int writei;
-    int readi;
     int nsyms_old = nsyms;
-    for (writei = 0, readi = 0; readi < nsyms_old; readi += 1)
+    for (int writei = 0, readi = 0; readi < nsyms_old; readi += 1)
       {
         if (symbols[readi] == NULL)
           {
@@ -1052,9 +1029,8 @@ symbols_pack (void)
 static void
 init_prec_nodes (void)
 {
-  int i;
   prec_nodes = xcalloc (nsyms, sizeof *prec_nodes);
-  for (i = 0; i < nsyms; ++i)
+  for (int i = 0; i < nsyms; ++i)
     {
       prec_nodes[i] = xmalloc (sizeof *prec_nodes[i]);
       symgraph *s = prec_nodes[i];
@@ -1145,8 +1121,7 @@ linkedlist_free (symgraphlink *node)
 static void
 assoc_free (void)
 {
-  int i;
-  for (i = 0; i < nsyms; ++i)
+  for (int i = 0; i < nsyms; ++i)
     {
       linkedlist_free (prec_nodes[i]->pred);
       linkedlist_free (prec_nodes[i]->succ);
@@ -1162,9 +1137,8 @@ assoc_free (void)
 static void
 init_assoc (void)
 {
-  graphid i;
   used_assoc = xcalloc (nsyms, sizeof *used_assoc);
-  for (i = 0; i < nsyms; ++i)
+  for (graphid i = 0; i < nsyms; ++i)
     used_assoc[i] = false;
 }
 
@@ -1201,12 +1175,11 @@ register_assoc (graphid i, graphid j)
 void
 print_precedence_warnings (void)
 {
-  int i;
   if (!prec_nodes)
     init_prec_nodes ();
   if (!used_assoc)
     init_assoc ();
-  for (i = 0; i < nsyms; ++i)
+  for (int i = 0; i < nsyms; ++i)
     {
       symbol *s = symbols[i];
       if (s
