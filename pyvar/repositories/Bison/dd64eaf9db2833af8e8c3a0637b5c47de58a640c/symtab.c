@@ -29,13 +29,13 @@
 #include "complain.h"
 #include "gram.h"
 
-/*-------------------------------------------------------------------.
-| Symbols sorted by tag.  Allocated by the first invocation of       |
-| symbols_do, after which no more symbols should be created.         |
-`-------------------------------------------------------------------*/
+/*----------------------------------------------------------------.
+| Symbols sorted by tag.  Allocated by table_sort, after which no |
+| more symbols should be created.                                 |
+`----------------------------------------------------------------*/
 
 static symbol **symbols_sorted = NULL;
-static symbol **semantic_types_sorted = NULL;
+static semantic_type **semantic_types_sorted = NULL;
 
 /*------------------------.
 | Distinguished symbols.  |
@@ -149,8 +149,8 @@ symbol_free (void *ptr)
    declaration first.
 */
 
-static
-void symbols_sort (symbol **first, symbol **second)
+static void
+symbols_sort (symbol **first, symbol **second)
 {
   if (0 < location_cmp ((*first)->location, (*second)->location))
     {
@@ -162,8 +162,8 @@ void symbols_sort (symbol **first, symbol **second)
 
 /* Likewise, for locations.  */
 
-static
-void locations_sort (location *first, location *second)
+static void
+locations_sort (location *first, location *second)
 {
   if (0 < location_cmp (*first, *second))
     {
@@ -514,7 +514,7 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 | nonterminal.                                              |
 `----------------------------------------------------------*/
 
-static inline bool
+static void
 symbol_check_defined (symbol *sym)
 {
   sym_content *s = sym->content;
@@ -541,11 +541,9 @@ symbol_check_defined (symbol *sym)
       if (sem_type)
         sem_type->status = declared;
     }
-
-  return true;
 }
 
-static inline bool
+static void
 semantic_type_check_defined (semantic_type *sem_type)
 {
   /* <*> and <> do not have to be "declared".  */
@@ -564,24 +562,8 @@ semantic_type_check_defined (semantic_type *sem_type)
     complain (&sem_type->location, Wother,
               _("type <%s> is used, but is not associated to any symbol"),
               sem_type->tag);
-
-  return true;
-}
-
-static bool
-symbol_check_defined_processor (void *sym, void *null ATTRIBUTE_UNUSED)
-{
-  return symbol_check_defined (sym);
 }
 
-static bool
-semantic_type_check_defined_processor (void *sem_type,
-                                       void *null ATTRIBUTE_UNUSED)
-{
-  return semantic_type_check_defined (sem_type);
-}
-
-
 /*-------------------------------------------------------------------.
 | Merge the properties (precedence, associativity, etc.) of SYM, and |
 | its string-named alias STR; check consistency.                     |
@@ -648,7 +630,7 @@ symbol_make_alias (symbol *sym, symbol *str, location loc)
 | into FDEFINES.  Put in SYMBOLS.                                    |
 `-------------------------------------------------------------------*/
 
-static inline bool
+static void
 symbol_pack (symbol *this)
 {
   aver (this->content->number != NUMBER_UNDEFINED);
@@ -656,13 +638,6 @@ symbol_pack (symbol *this)
     this->content->number += ntokens;
 
   symbols[this->content->number] = this->content->symbol;
-  return true;
-}
-
-static bool
-symbol_pack_processor (void *this, void *null ATTRIBUTE_UNUSED)
-{
-  return symbol_pack (this);
 }
 
 static void
@@ -683,7 +658,7 @@ complain_user_token_number_redeclared (int num, symbol *first, symbol *second)
 | Put THIS in TOKEN_TRANSLATIONS if it is a token.  |
 `--------------------------------------------------*/
 
-static inline bool
+static void
 symbol_translation (symbol *this)
 {
   /* Nonterminal? */
@@ -700,14 +675,6 @@ symbol_translation (symbol *this)
         token_translations[this->content->user_token_number]
           = this->content->number;
     }
-
-  return true;
-}
-
-static bool
-symbol_translation_processor (void *this, void *null ATTRIBUTE_UNUSED)
-{
-  return symbol_translation (this);
 }
 
 
@@ -906,36 +873,25 @@ symbols_free (void)
 }
 
 
-/*---------------------------------------------------------------.
-| Look for undefined symbols, report an error, and consider them |
-| terminals.                                                     |
-`---------------------------------------------------------------*/
-
 static int
-symbols_cmp (symbol const *a, symbol const *b)
+symbol_cmp (void const *a, void const *b)
 {
-  return strcmp (a->tag, b->tag);
+  return strcmp ((*(symbol * const *)a)->tag,
+                 (*(symbol * const *)b)->tag);
 }
 
-static int
-symbols_cmp_qsort (void const *a, void const *b)
-{
-  return symbols_cmp (*(symbol * const *)a, *(symbol * const *)b);
-}
+/* Store in *SORTED an array of pointers to the symbols contained in
+   TABLE, sorted (alphabetically) by tag. */
 
 static void
-symbols_do (Hash_processor processor, void *processor_data,
-            struct hash_table *table, symbol ***sorted)
+table_sort (struct hash_table *table, symbol ***sorted)
 {
+  aver (!*sorted);
   size_t count = hash_get_n_entries (table);
-  if (!*sorted)
-    {
-      *sorted = xnmalloc (count, sizeof **sorted);
-      hash_get_entries (table, (void**)*sorted, count);
-      qsort (*sorted, count, sizeof **sorted, symbols_cmp_qsort);
-    }
-  for (size_t i = 0; i < count; ++i)
-    processor ((*sorted)[i], processor_data);
+  *sorted = xnmalloc (count + 1, sizeof **sorted);
+  hash_get_entries (table, (void**)*sorted, count);
+  qsort (*sorted, count, sizeof **sorted, symbol_cmp);
+  (*sorted)[count] = NULL;
 }
 
 /*--------------------------------------------------------------.
@@ -946,10 +902,21 @@ symbols_do (Hash_processor processor, void *processor_data,
 void
 symbols_check_defined (void)
 {
-  symbols_do (symbol_check_defined_processor, NULL,
-              symbol_table, &symbols_sorted);
-  symbols_do (semantic_type_check_defined_processor, NULL,
-              semantic_type_table, &semantic_types_sorted);
+  table_sort (symbol_table, &symbols_sorted);
+  /* semantic_type, like symbol, starts with a 'tag' field.  And here
+     we only deal with arrays/hashes of pointers, sizeof is not an
+     issue.
+
+     So instead of implementing table_sort (and symbol_cmp) once for
+     each type, let's lie a bit to the typing system, and treat
+     'semantic_type' as if it were 'symbol'.  Anyway this is only
+     about arrays of pointers.  */
+  table_sort (semantic_type_table, (symbol ***) &semantic_types_sorted);
+
+  for (int i = 0; symbols_sorted[i]; ++i)
+    symbol_check_defined (symbols_sorted[i]);
+  for (int i = 0; semantic_types_sorted[i]; ++i)
+    semantic_type_check_defined (semantic_types_sorted[i]);
 }
 
 /*------------------------------------------------------------------.
@@ -1000,10 +967,10 @@ symbols_token_translations_init (void)
 
   /* Initialize all entries for literal tokens to the internal token
      number for $undefined, which represents all invalid inputs.  */
-  for (int i = 0; i < max_user_token_number + 1; i++)
+  for (int i = 0; i < max_user_token_number + 1; ++i)
     token_translations[i] = undeftoken->content->number;
-  symbols_do (symbol_translation_processor, NULL,
-              symbol_table, &symbols_sorted);
+  for (int i = 0; symbols_sorted[i]; ++i)
+    symbol_translation(symbols_sorted[i]);
 }
 
 
@@ -1016,7 +983,8 @@ void
 symbols_pack (void)
 {
   symbols = xcalloc (nsyms, sizeof *symbols);
-  symbols_do (symbol_pack_processor, NULL, symbol_table, &symbols_sorted);
+  for (int i = 0; symbols_sorted[i]; ++i)
+    symbol_pack(symbols_sorted[i]);
 
   /* Aliases leave empty slots in symbols, so remove them.  */
   {
