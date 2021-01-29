@@ -1,4 +1,5 @@
-/* Symbol table manager for Bison,
+/* Symbol table manager for Bison.
+
    Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -46,7 +47,7 @@ location startsymbol_location;
 static symbol *
 symbol_new (uniqstr tag, location loc)
 {
-  symbol *res = XMALLOC (symbol, 1);
+  symbol *res = MALLOC (res, 1);
 
   uniqstr_assert (tag);
   res->tag = tag;
@@ -190,23 +191,12 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 }
 
 
-/*-----------.
-| Free SYM.  |
-`-----------*/
-
-static void
-symbol_free (symbol *sym)
-{
-  free (sym);
-}
-
-
 /*----------------------------------------------------------.
 | If SYM is not defined, report an error, and consider it a |
 | nonterminal.                                              |
 `----------------------------------------------------------*/
 
-static bool
+static inline bool
 symbol_check_defined (symbol *sym)
 {
   if (sym->class == unknown_sym)
@@ -222,6 +212,12 @@ symbol_check_defined (symbol *sym)
   return true;
 }
 
+static bool
+symbol_check_defined_processor (void *sym, void *null ATTRIBUTE_UNUSED)
+{
+  return symbol_check_defined (sym);
+}
+
 
 /*------------------------------------------------------------------.
 | Declare the new symbol SYM.  Make it an alias of SYMVAL, and type |
@@ -260,8 +256,8 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 | associativity.                                           |
 `---------------------------------------------------------*/
 
-static bool
-symbol_check_alias_consistence (symbol *this)
+static inline bool
+symbol_check_alias_consistency (symbol *this)
 {
   /* Check only those who _are_ the aliases. */
   if (this->alias && this->user_token_number == USER_NUMBER_ALIAS)
@@ -294,13 +290,20 @@ symbol_check_alias_consistence (symbol *this)
   return true;
 }
 
+static bool
+symbol_check_alias_consistency_processor (void *this,
+					  void *null ATTRIBUTE_UNUSED)
+{
+  return symbol_check_alias_consistency (this);
+}
+
 
 /*-------------------------------------------------------------------.
 | Assign a symbol number, and write the definition of the token name |
 | into FDEFINES.  Put in SYMBOLS.                                    |
 `-------------------------------------------------------------------*/
 
-static bool
+static inline bool
 symbol_pack (symbol *this)
 {
   if (this->class == nterm_sym)
@@ -337,6 +340,12 @@ symbol_pack (symbol *this)
   return true;
 }
 
+static bool
+symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
+{
+  return symbol_pack (this);
+}
+
 
 
 
@@ -344,7 +353,7 @@ symbol_pack (symbol *this)
 | Put THIS in TOKEN_TRANSLATIONS if it is a token.  |
 `--------------------------------------------------*/
 
-static bool
+static inline bool
 symbol_translation (symbol *this)
 {
   /* Non-terminal? */
@@ -364,6 +373,12 @@ symbol_translation (symbol *this)
   return true;
 }
 
+static bool
+symbol_translation_processor (void *this, void *null ATTRIBUTE_UNUSED)
+{
+  return symbol_translation (this);
+}
+
 
 /*----------------------.
 | A symbol hash table.  |
@@ -374,18 +389,30 @@ symbol_translation (symbol *this)
 
 static struct hash_table *symbol_table = NULL;
 
-static bool
+static inline bool
 hash_compare_symbol (const symbol *m1, const symbol *m2)
 {
   /* Since tags are unique, we can compare the pointers themselves.  */
   return UNIQSTR_EQ (m1->tag, m2->tag);
 }
 
-static unsigned int
+static bool
+hash_symbol_comparator (void const *m1, void const *m2)
+{
+  return hash_compare_symbol (m1, m2);
+}
+
+static inline unsigned int
 hash_symbol (const symbol *m, unsigned int tablesize)
 {
   /* Since tags are unique, we can hash the pointer itself.  */
-  return ((size_t) m->tag) % tablesize;
+  return ((uintptr_t) m->tag) % tablesize;
+}
+
+static unsigned int
+hash_symbol_hasher (void const *m, unsigned int tablesize)
+{
+  return hash_symbol (m, tablesize);
 }
 
 
@@ -398,9 +425,9 @@ symbols_new (void)
 {
   symbol_table = hash_initialize (HT_INITIAL_CAPACITY,
 				  NULL,
-				  (Hash_hasher) hash_symbol,
-				  (Hash_comparator) hash_compare_symbol,
-				  (Hash_data_freer) symbol_free);
+				  hash_symbol_hasher,
+				  hash_symbol_comparator,
+				  free);
 }
 
 
@@ -417,7 +444,7 @@ symbol_get (const char *key, location loc)
 
   /* Keep the symbol in a printable form.  */
   key = uniqstr_new (quotearg_style (escape_quoting_style, key));
-  *(char const **) &probe.tag = key;
+  probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
   if (!entry)
@@ -469,12 +496,10 @@ symbols_free (void)
 | terminals.                                                     |
 `---------------------------------------------------------------*/
 
-void
-symbols_do (symbol_processor processor, void *processor_data)
+static void
+symbols_do (Hash_processor processor, void *processor_data)
 {
-  hash_do_for_each (symbol_table,
-		    (Hash_processor) processor,
-		    processor_data);
+  hash_do_for_each (symbol_table, processor, processor_data);
 }
 
 
@@ -486,7 +511,7 @@ symbols_do (symbol_processor processor, void *processor_data)
 void
 symbols_check_defined (void)
 {
-  symbols_do (symbol_check_defined, NULL);
+  symbols_do (symbol_check_defined_processor, NULL);
 }
 
 /*------------------------------------------------------------------.
@@ -533,14 +558,14 @@ symbols_token_translations_init (void)
 	max_user_token_number = this->user_token_number;
     }
 
-  token_translations = XCALLOC (symbol_number, max_user_token_number + 1);
+  CALLOC (token_translations, max_user_token_number + 1);
 
   /* Initialize all entries for literal tokens to 2, the internal
      token number for $undefined, which represents all invalid inputs.
      */
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = undeftoken->number;
-  symbols_do (symbol_translation, NULL);
+  symbols_do (symbol_translation_processor, NULL);
 }
 
 
@@ -552,10 +577,10 @@ symbols_token_translations_init (void)
 void
 symbols_pack (void)
 {
-  symbols = XCALLOC (symbol *, nsyms);
+  CALLOC (symbols, nsyms);
 
-  symbols_do (symbol_check_alias_consistence, NULL);
-  symbols_do (symbol_pack, NULL);
+  symbols_do (symbol_check_alias_consistency_processor, NULL);
+  symbols_do (symbol_pack_processor, NULL);
 
   symbols_token_translations_init ();
 
