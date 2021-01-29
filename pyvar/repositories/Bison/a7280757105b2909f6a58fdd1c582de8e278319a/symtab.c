@@ -58,6 +58,35 @@ static symgraph **prec_nodes;
 
 bool *used_assoc = NULL;
 
+/*--------------------------.
+| Create a new sym_content. |
+`--------------------------*/
+
+static sym_content *
+sym_content_new (symbol *s)
+{
+  sym_content *res = xmalloc (sizeof *res);
+
+  res->symbol = s;
+
+  res->type_name = NULL;
+  {
+    int i;
+    for (i = 0; i < CODE_PROPS_SIZE; ++i)
+      code_props_none_init (&res->props[i]);
+  }
+
+  res->number = NUMBER_UNDEFINED;
+  res->prec = 0;
+  res->assoc = undef_assoc;
+  res->user_token_number = USER_NUMBER_UNDEFINED;
+
+  res->class = unknown_sym;
+  res->status = undeclared;
+
+  return res;
+}
+
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
 `---------------------------------*/
@@ -76,22 +105,9 @@ symbol_new (uniqstr tag, location loc)
 
   res->tag = tag;
   res->location = loc;
-
-  res->type_name = NULL;
-  {
-    int i;
-    for (i = 0; i < CODE_PROPS_SIZE; ++i)
-      code_props_none_init (&res->props[i]);
-  }
-
-  res->number = NUMBER_UNDEFINED;
-  res->prec = 0;
-  res->assoc = undef_assoc;
-  res->user_token_number = USER_NUMBER_UNDEFINED;
-
   res->alias = NULL;
-  res->class = unknown_sym;
-  res->status = undeclared;
+  res->content = sym_content_new (res);
+  res->is_alias = false;
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     complain (NULL, fatal, _("too many symbols in input grammar (limit is %d)"),
@@ -100,6 +116,30 @@ symbol_new (uniqstr tag, location loc)
   return res;
 }
 
+/*--------------------.
+| Free a sym_content. |
+`--------------------*/
+
+static void
+sym_content_free (sym_content *sym)
+{
+  free (sym);
+}
+
+
+/*---------------------------------------------------------.
+| Free a symbol and its associated content if appropriate. |
+`---------------------------------------------------------*/
+
+static void
+symbol_free (void *ptr)
+{
+  symbol *sym = (symbol *)ptr;
+  if (!sym->is_alias)
+    sym_content_free (sym->content);
+  free (sym);
+}
+
 char const *
 code_props_type_string (code_props_type kind)
 {
@@ -141,12 +181,12 @@ semantic_type_new (uniqstr tag, const location *loc)
 `-----------------*/
 
 #define SYMBOL_ATTR_PRINT(Attr)                         \
-  if (s->Attr)                                          \
-    fprintf (f, " %s { %s }", #Attr, s->Attr)
+  if (s->content->Attr)                                 \
+    fprintf (f, " %s { %s }", #Attr, s->content->Attr)
 
 #define SYMBOL_CODE_PRINT(Attr)                                         \
-  if (s->props[Attr].code)                                              \
-    fprintf (f, " %s { %s }", #Attr, s->props[Attr].code)
+  if (s->content->props[Attr].code)                                     \
+    fprintf (f, " %s { %s }", #Attr, s->content->props[Attr].code)
 
 void
 symbol_print (symbol const *s, FILE *f)
@@ -193,7 +233,7 @@ is_identifier (uniqstr s)
 uniqstr
 symbol_id_get (symbol const *sym)
 {
-  aver (sym->user_token_number != USER_NUMBER_HAS_STRING_ALIAS);
+  aver (sym->content->user_token_number != USER_NUMBER_HAS_STRING_ALIAS);
   if (sym->alias)
     sym = sym->alias;
   return is_identifier (sym->tag) ? sym->tag : 0;
@@ -241,13 +281,13 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
 {
   if (type_name)
     {
-      if (sym->type_name)
-        symbol_redeclaration (sym, "%type", sym->type_location, loc);
+      if (sym->content->type_name)
+        symbol_redeclaration (sym, "%type", sym->content->type_location, loc);
       else
         {
           uniqstr_assert (type_name);
-          sym->type_name = type_name;
-          sym->type_location = loc;
+          sym->content->type_name = type_name;
+          sym->content->type_location = loc;
         }
     }
 }
@@ -260,12 +300,12 @@ void
 symbol_code_props_set (symbol *sym, code_props_type kind,
                        code_props const *code)
 {
-  if (sym->props[kind].code)
+  if (sym->content->props[kind].code)
     symbol_redeclaration (sym, code_props_type_string (kind),
-                          sym->props[kind].location,
+                          sym->content->props[kind].location,
                           code->location);
   else
-    sym->props[kind] = *code;
+    sym->content->props[kind] = *code;
 }
 
 /*-----------------------------------------------------.
@@ -293,14 +333,14 @@ code_props *
 symbol_code_props_get (symbol *sym, code_props_type kind)
 {
   /* Per-symbol code props.  */
-  if (sym->props[kind].code)
-    return &sym->props[kind];
+  if (sym->content->props[kind].code)
+    return &sym->content->props[kind];
 
   /* Per-type code props.  */
-  if (sym->type_name)
+  if (sym->content->type_name)
     {
       code_props *code =
-        &semantic_type_get (sym->type_name, NULL)->props[kind];
+        &semantic_type_get (sym->content->type_name, NULL)->props[kind];
       if (code->code)
         return code;
     }
@@ -308,8 +348,8 @@ symbol_code_props_get (symbol *sym, code_props_type kind)
   /* Apply default code props's only to user-defined symbols.  */
   if (sym->tag[0] != '$' && sym != errtoken)
     {
-      code_props *code =
-        &semantic_type_get (sym->type_name ? "*" : "", NULL)->props[kind];
+      code_props *code = &semantic_type_get (sym->content->type_name ? "*" : "",
+                                             NULL)->props[kind];
       if (code->code)
         return code;
     }
@@ -324,16 +364,17 @@ symbol_code_props_get (symbol *sym, code_props_type kind)
 void
 symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 {
+  sym_content *s = sym->content;
   if (a != undef_assoc)
     {
-      if (sym->prec)
-        symbol_redeclaration (sym, assoc_to_string (a), sym->prec_location,
-                              loc);
+      if (s->prec)
+        symbol_redeclaration (sym, assoc_to_string (a),
+                              s->prec_location, loc);
       else
         {
-          sym->prec = prec;
-          sym->assoc = a;
-          sym->prec_location = loc;
+          s->prec = prec;
+          s->assoc = a;
+          s->prec_location = loc;
         }
     }
 
@@ -350,26 +391,26 @@ void
 symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 {
   bool warned = false;
-  if (sym->class != unknown_sym && sym->class != class)
+  if (sym->content->class != unknown_sym && sym->content->class != class)
     {
       complain (&loc, complaint, _("symbol %s redefined"), sym->tag);
       /* Don't report both "redefined" and "redeclared".  */
       warned = true;
     }
 
-  if (class == nterm_sym && sym->class != nterm_sym)
-    sym->number = nvars++;
-  else if (class == token_sym && sym->number == NUMBER_UNDEFINED)
-    sym->number = ntokens++;
+  if (class == nterm_sym && sym->content->class != nterm_sym)
+    sym->content->number = nvars++;
+  else if (class == token_sym && sym->content->number == NUMBER_UNDEFINED)
+    sym->content->number = ntokens++;
 
-  sym->class = class;
+  sym->content->class = class;
 
   if (declaring)
     {
-      if (sym->status == declared && !warned)
+      if (sym->content->status == declared && !warned)
         complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
       else
-        sym->status = declared;
+        sym->content->status = declared;
     }
 }
 
@@ -383,10 +424,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
   int *user_token_numberp;
 
-  if (sym->user_token_number != USER_NUMBER_HAS_STRING_ALIAS)
-    user_token_numberp = &sym->user_token_number;
-  else
-    user_token_numberp = &sym->alias->user_token_number;
+  user_token_numberp = &sym->content->user_token_number;
   if (*user_token_numberp != USER_NUMBER_UNDEFINED
       && *user_token_numberp != user_token_number)
     complain (&loc, complaint, _("redefining user token number of %s"),
@@ -396,12 +434,12 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
   /* User defined $end token? */
   if (user_token_number == 0)
     {
-      endtoken = sym;
+      endtoken = sym->content->symbol;
       /* It is always mapped to 0, so it was already counted in
          NTOKENS.  */
-      if (endtoken->number != NUMBER_UNDEFINED)
+      if (endtoken->content->number != NUMBER_UNDEFINED)
         --ntokens;
-      endtoken->number = 0;
+      endtoken->content->number = 0;
     }
 }
 
@@ -414,16 +452,17 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 static inline bool
 symbol_check_defined (symbol *sym)
 {
-  if (sym->class == unknown_sym)
+  sym_content *s = sym->content;
+  if (s->class == unknown_sym)
     {
-      assert (sym->status != declared);
+      assert (s->status != declared);
       complain (&sym->location,
-                sym->status == needed ? complaint : Wother,
+                s->status == needed ? complaint : Wother,
                 _("symbol %s is used, but is not defined as a token"
                   " and has no rules"),
                   sym->tag);
-      sym->class = nterm_sym;
-      sym->number = nvars++;
+      s->class = nterm_sym;
+      s->number = nvars++;
     }
 
   {
@@ -434,9 +473,9 @@ symbol_check_defined (symbol *sym)
 
   /* Set the semantic type status associated to the current symbol to
      'declared' so that we could check semantic types unnecessary uses. */
-  if (sym->type_name)
+  if (s->type_name)
     {
-      semantic_type *sem_type = semantic_type_get (sym->type_name, NULL);
+      semantic_type *sem_type = semantic_type_get (s->type_name, NULL);
       if (sem_type)
         sem_type->status = declared;
     }
@@ -493,71 +532,16 @@ symbol_make_alias (symbol *sym, symbol *str, location loc)
               _("symbol %s given more than one literal string"), sym->tag);
   else
     {
-      str->class = token_sym;
-      str->user_token_number = sym->user_token_number;
-      sym->user_token_number = USER_NUMBER_HAS_STRING_ALIAS;
+      sym_content_free (str->content);
+      str->content = sym->content;
+      str->content->symbol = str;
+      str->is_alias = true;
       str->alias = sym;
       sym->alias = str;
-      str->number = sym->number;
-      symbol_type_set (str, sym->type_name, loc);
     }
 }
 
 
-/*---------------------------------------------------------.
-| Check that THIS, and its alias, have same precedence and |
-| associativity.                                           |
-`---------------------------------------------------------*/
-
-static inline void
-symbol_check_alias_consistency (symbol *this)
-{
-  symbol *sym = this;
-  symbol *str = this->alias;
-
-  /* Check only the symbol in the symbol-string pair.  */
-  if (!(this->alias
-        && this->user_token_number == USER_NUMBER_HAS_STRING_ALIAS))
-    return;
-
-  if (str->type_name != sym->type_name)
-    {
-      if (str->type_name)
-        symbol_type_set (sym, str->type_name, str->type_location);
-      else
-        symbol_type_set (str, sym->type_name, sym->type_location);
-    }
-
-
-  {
-    int i;
-    for (i = 0; i < CODE_PROPS_SIZE; ++i)
-      if (str->props[i].code)
-        symbol_code_props_set (sym, i, &str->props[i]);
-      else if (sym->props[i].code)
-        symbol_code_props_set (str, i, &sym->props[i]);
-  }
-
-  if (sym->prec || str->prec)
-    {
-      if (str->prec)
-        symbol_precedence_set (sym, str->prec, str->assoc,
-                               str->prec_location);
-      else
-        symbol_precedence_set (str, sym->prec, sym->assoc,
-                               sym->prec_location);
-    }
-}
-
-static bool
-symbol_check_alias_consistency_processor (void *this,
-                                          void *null ATTRIBUTE_UNUSED)
-{
-  symbol_check_alias_consistency (this);
-  return true;
-}
-
-
 /*-------------------------------------------------------------------.
 | Assign a symbol number, and write the definition of the token name |
 | into FDEFINES.  Put in SYMBOLS.                                    |
@@ -566,13 +550,13 @@ symbol_check_alias_consistency_processor (void *this,
 static inline bool
 symbol_pack (symbol *this)
 {
-  aver (this->number != NUMBER_UNDEFINED);
-  if (this->class == nterm_sym)
-    this->number += ntokens;
-  else if (this->user_token_number == USER_NUMBER_HAS_STRING_ALIAS)
+  aver (this->content->number != NUMBER_UNDEFINED);
+  if (this->content->class == nterm_sym)
+    this->content->number += ntokens;
+  else if (this->content->user_token_number == USER_NUMBER_HAS_STRING_ALIAS)
     return true;
 
-  symbols[this->number] = this;
+  symbols[this->content->number] = this->content->symbol;
   return true;
 }
 
@@ -582,7 +566,6 @@ symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
   return symbol_pack (this);
 }
 
-
 static void
 user_token_number_redeclaration (int num, symbol *first, symbol *second)
 {
@@ -615,17 +598,18 @@ static inline bool
 symbol_translation (symbol *this)
 {
   /* Non-terminal? */
-  if (this->class == token_sym
-      && this->user_token_number != USER_NUMBER_HAS_STRING_ALIAS)
+  if (this->content->class == token_sym
+      && !this->is_alias)
     {
-      /* A token which translation has already been set? */
-      if (token_translations[this->user_token_number] != undeftoken->number)
+      /* A token which translation has already been set?*/
+      if (token_translations[this->content->user_token_number]
+          != undeftoken->content->number)
         user_token_number_redeclaration
-          (this->user_token_number,
-           symbols[token_translations[this->user_token_number]],
-           this);
+          (this->content->user_token_number,
+           symbols[token_translations[this->content->user_token_number]], this);
       else
-        token_translations[this->user_token_number] = this->number;
+        token_translations[this->content->user_token_number]
+          = this->content->number;
     }
 
   return true;
@@ -711,7 +695,7 @@ symbols_new (void)
                                   NULL,
                                   hash_symbol_hasher,
                                   hash_symbol_comparator,
-                                  free);
+                                  symbol_free);
   semantic_type_table = hash_initialize (HT_INITIAL_CAPACITY,
                                          NULL,
                                          hash_semantic_type_hasher,
@@ -811,8 +795,8 @@ dummy_symbol_get (location loc)
 
   sprintf (buf, "$@%d", ++dummy_count);
   sym = symbol_get (buf, loc);
-  sym->class = nterm_sym;
-  sym->number = nvars++;
+  sym->content->class = nterm_sym;
+  sym->content->number = nvars++;
   return sym;
 }
 
@@ -902,7 +886,7 @@ symbols_token_translations_init (void)
   max_user_token_number = 0;
   for (i = 0; i < ntokens; ++i)
     {
-      symbol *this = symbols[i];
+      sym_content *this = symbols[i]->content;
       if (this->user_token_number != USER_NUMBER_UNDEFINED)
         {
           if (this->user_token_number > max_user_token_number)
@@ -914,8 +898,8 @@ symbols_token_translations_init (void)
 
   /* If 256 is not used, assign it to error, to follow POSIX.  */
   if (num_256_available_p
-      && errtoken->user_token_number == USER_NUMBER_UNDEFINED)
-    errtoken->user_token_number = 256;
+      && errtoken->content->user_token_number == USER_NUMBER_UNDEFINED)
+    errtoken->content->user_token_number = 256;
 
   /* Set the missing user numbers. */
   if (max_user_token_number < 256)
@@ -923,7 +907,7 @@ symbols_token_translations_init (void)
 
   for (i = 0; i < ntokens; ++i)
     {
-      symbol *this = symbols[i];
+      sym_content *this = symbols[i]->content;
       if (this->user_token_number == USER_NUMBER_UNDEFINED)
         this->user_token_number = ++max_user_token_number;
       if (this->user_token_number > max_user_token_number)
@@ -936,7 +920,7 @@ symbols_token_translations_init (void)
   /* Initialize all entries for literal tokens to the internal token
      number for $undefined, which represents all invalid inputs.  */
   for (i = 0; i < max_user_token_number + 1; i++)
-    token_translations[i] = undeftoken->number;
+    token_translations[i] = undeftoken->content->number;
   symbols_do (symbol_translation_processor, NULL,
               symbol_table, &symbols_sorted);
 }
@@ -950,9 +934,6 @@ symbols_token_translations_init (void)
 void
 symbols_pack (void)
 {
-  symbols_do (symbol_check_alias_consistency_processor, NULL,
-              symbol_table, &symbols_sorted);
-
   symbols = xcalloc (nsyms, sizeof *symbols);
   symbols_do (symbol_pack_processor, NULL, symbol_table, &symbols_sorted);
 
@@ -971,9 +952,7 @@ symbols_pack (void)
         else
           {
             symbols[writei] = symbols[readi];
-            symbols[writei]->number = writei;
-            if (symbols[writei]->alias)
-              symbols[writei]->alias->number = writei;
+            symbols[writei]->content->number = writei;
             writei += 1;
           }
       }
@@ -982,11 +961,11 @@ symbols_pack (void)
 
   symbols_token_translations_init ();
 
-  if (startsymbol->class == unknown_sym)
+  if (startsymbol->content->class == unknown_sym)
     complain (&startsymbol_location, fatal,
               _("the start symbol %s is undefined"),
               startsymbol->tag);
-  else if (startsymbol->class == token_sym)
+  else if (startsymbol->content->class == token_sym)
     complain (&startsymbol_location, fatal,
               _("the start symbol %s is a token"),
               startsymbol->tag);
@@ -1123,9 +1102,9 @@ static inline bool
 is_assoc_useless (symbol *s)
 {
   return s
-      && s->assoc != undef_assoc
-      && s->assoc != precedence_assoc
-      && !used_assoc[s->number];
+      && s->content->assoc != undef_assoc
+      && s->content->assoc != precedence_assoc
+      && !used_assoc[s->content->number];
 }
 
 /*-------------------------------.
@@ -1157,19 +1136,19 @@ print_precedence_warnings (void)
     {
       symbol *s = symbols[i];
       if (s
-          && s->prec != 0
+          && s->content->prec != 0
           && !prec_nodes[i]->pred
           && !prec_nodes[i]->succ)
         {
           if (is_assoc_useless (s))
-            complain (&s->prec_location, Wprecedence,
+            complain (&s->content->prec_location, Wprecedence,
                       _("useless precedence and associativity for %s"), s->tag);
-          else if (s->assoc == precedence_assoc)
-            complain (&s->prec_location, Wprecedence,
+          else if (s->content->assoc == precedence_assoc)
+            complain (&s->content->prec_location, Wprecedence,
                       _("useless precedence for %s"), s->tag);
         }
       else if (is_assoc_useless (s))
-        complain (&s->prec_location, Wprecedence,
+        complain (&s->content->prec_location, Wprecedence,
                   _("useless associativity for %s, use %%precedence"), s->tag);
     }
   free (used_assoc);
