@@ -20,35 +20,37 @@
 
 
 #include "system.h"
-#include "quotearg.h"
-#include "hash.h"
+
+#include <hash.h>
+#include <quotearg.h>
+
 #include "complain.h"
-#include "symtab.h"
 #include "gram.h"
+#include "symtab.h"
 
 /*------------------------.
 | Distinguished symbols.  |
 `------------------------*/
 
-symbol_t *errtoken = NULL;
-symbol_t *undeftoken = NULL;
-symbol_t *endtoken = NULL;
-symbol_t *accept = NULL;
-symbol_t *startsymbol = NULL;
-location_t startsymbol_location;
+symbol *errtoken = NULL;
+symbol *undeftoken = NULL;
+symbol *endtoken = NULL;
+symbol *accept = NULL;
+symbol *startsymbol = NULL;
+location startsymbol_location;
 
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
 `---------------------------------*/
 
-static symbol_t *
-symbol_new (struniq_t tag, location_t location)
+static symbol *
+symbol_new (uniqstr tag, location loc)
 {
-  symbol_t *res = XMALLOC (symbol_t, 1);
+  symbol *res = XMALLOC (symbol, 1);
 
-  struniq_assert (tag);
+  uniqstr_assert (tag);
   res->tag = tag;
-  res->location = location;
+  res->location = loc;
 
   res->type_name = NULL;
   res->destructor = NULL;
@@ -67,127 +69,119 @@ symbol_new (struniq_t tag, location_t location)
 }
 
 
-/*------------------------------------------------------------------.
-| Set the TYPE_NAME associated to SYMBOL.  Does nothing if passed 0 |
-| as TYPE_NAME.                                                     |
-`------------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Set the TYPE_NAME associated with SYM.  Does nothing if passed 0 |
+| as TYPE_NAME.                                                    |
+`-----------------------------------------------------------------*/
 
 void
-symbol_type_set (symbol_t *symbol, struniq_t type_name, location_t location)
+symbol_type_set (symbol *sym, uniqstr type_name, location loc)
 {
   if (type_name)
     {
-      if (symbol->type_name)
-	complain_at (location,
-		     _("type redeclaration for %s"), symbol->tag);
-      struniq_assert (type_name);
-      symbol->type_name = type_name;
+      if (sym->type_name)
+	complain_at (loc, _("type redeclaration for %s"), sym->tag);
+      uniqstr_assert (type_name);
+      sym->type_name = type_name;
     }
 }
 
 
-/*-------------------------------------------------------------------.
-| Set the DESTRUCTOR associated to SYMBOL.  Do nothing if passed 0.  |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Set the DESTRUCTOR associated with SYM.  Do nothing if passed 0.  |
+`------------------------------------------------------------------*/
 
 void
-symbol_destructor_set (symbol_t *symbol, char *destructor, location_t location)
+symbol_destructor_set (symbol *sym, char *destructor, location loc)
 {
   if (destructor)
     {
-      if (symbol->destructor)
-	complain_at (location,
-		     _("%s redeclaration for %s"),
-		     "%destructor", symbol->tag);
-      symbol->destructor = destructor;
-      symbol->destructor_location = location;
+      if (sym->destructor)
+	complain_at (loc, _("%s redeclaration for %s"),
+		     "%destructor", sym->tag);
+      sym->destructor = destructor;
+      sym->destructor_location = loc;
     }
 }
 
 
-/*----------------------------------------------------------------.
-| Set the PRINTER associated to SYMBOL.  Do nothing if passed 0.  |
-`----------------------------------------------------------------*/
+/*---------------------------------------------------------------.
+| Set the PRINTER associated with SYM.  Do nothing if passed 0.  |
+`---------------------------------------------------------------*/
 
 void
-symbol_printer_set (symbol_t *symbol, char *printer, location_t location)
+symbol_printer_set (symbol *sym, char *printer, location loc)
 {
   if (printer)
     {
-      if (symbol->printer)
-	complain_at (location,
-		     _("%s redeclaration for %s"),
-		     "%printer", symbol->tag);
-      symbol->printer = printer;
-      symbol->printer_location = location;
+      if (sym->printer)
+	complain_at (loc, _("%s redeclaration for %s"),
+		     "%printer", sym->tag);
+      sym->printer = printer;
+      sym->printer_location = loc;
     }
 }
 
 
-/*------------------------------------------------------------------.
-| Set the PRECEDENCE associated to SYMBOL.  Does nothing if invoked |
-| with UNDEF_ASSOC as ASSOC.                                        |
-`------------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Set the PRECEDENCE associated with SYM.  Does nothing if invoked |
+| with UNDEF_ASSOC as ASSOC.                                       |
+`-----------------------------------------------------------------*/
 
 void
-symbol_precedence_set (symbol_t *symbol,
-		       int prec, assoc_t assoc, location_t location)
+symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 {
-  if (assoc != undef_assoc)
+  if (a != undef_assoc)
     {
-      if (symbol->prec != 0)
-	complain_at (location,
-		     _("redefining precedence of %s"),
-		     symbol->tag);
-      symbol->prec = prec;
-      symbol->assoc = assoc;
+      if (sym->prec != 0)
+	complain_at (loc, _("redefining precedence of %s"), sym->tag);
+      sym->prec = prec;
+      sym->assoc = a;
     }
 
   /* Only terminals have a precedence. */
-  symbol_class_set (symbol, token_sym, location);
+  symbol_class_set (sym, token_sym, loc);
 }
 
 
-/*-------------------------------------.
-| Set the CLASS associated to SYMBOL.  |
-`-------------------------------------*/
+/*------------------------------------.
+| Set the CLASS associated with SYM.  |
+`------------------------------------*/
 
 void
-symbol_class_set (symbol_t *symbol, symbol_class class, location_t location)
+symbol_class_set (symbol *sym, symbol_class class, location loc)
 {
-  if (symbol->class != unknown_sym && symbol->class != class)
-    complain_at (location, _("symbol %s redefined"), symbol->tag);
+  if (sym->class != unknown_sym && sym->class != class)
+    complain_at (loc, _("symbol %s redefined"), sym->tag);
 
-  if (class == nterm_sym && symbol->class != nterm_sym)
-    symbol->number = nvars++;
-  else if (class == token_sym && symbol->number == NUMBER_UNDEFINED)
-    symbol->number = ntokens++;
+  if (class == nterm_sym && sym->class != nterm_sym)
+    sym->number = nvars++;
+  else if (class == token_sym && sym->number == NUMBER_UNDEFINED)
+    sym->number = ntokens++;
 
-  symbol->class = class;
+  sym->class = class;
 }
 
 
-/*-------------------------------------------------.
-| Set the USER_TOKEN_NUMBER associated to SYMBOL.  |
-`-------------------------------------------------*/
+/*------------------------------------------------.
+| Set the USER_TOKEN_NUMBER associated with SYM.  |
+`------------------------------------------------*/
 
 void
-symbol_user_token_number_set (symbol_t *symbol,
-			      int user_token_number, location_t location)
+symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
-  if (symbol->class != token_sym)
+  if (sym->class != token_sym)
     abort ();
 
-  if (symbol->user_token_number != USER_NUMBER_UNDEFINED
-      && symbol->user_token_number != user_token_number)
-    complain_at (location, _("redefining user token number of %s"),
-		 symbol->tag);
+  if (sym->user_token_number != USER_NUMBER_UNDEFINED
+      && sym->user_token_number != user_token_number)
+    complain_at (loc, _("redefining user token number of %s"), sym->tag);
 
-  symbol->user_token_number = user_token_number;
+  sym->user_token_number = user_token_number;
   /* User defined $end token? */
   if (user_token_number == 0)
     {
-      endtoken = symbol;
+      endtoken = sym;
       endtoken->number = 0;
       /* It is always mapped to 0, so it was already counted in
 	 NTOKENS.  */
@@ -196,67 +190,67 @@ symbol_user_token_number_set (symbol_t *symbol,
 }
 
 
-/*------------.
-| Free THIS.  |
-`------------*/
+/*-----------.
+| Free SYM.  |
+`-----------*/
 
 static void
-symbol_free (symbol_t *this)
+symbol_free (symbol *sym)
 {
-  free (this);
+  free (sym);
 }
 
 
-/*-----------------------------------------------------------.
-| If THIS is not defined, report an error, and consider it a |
-| nonterminal.                                               |
-`-----------------------------------------------------------*/
+/*----------------------------------------------------------.
+| If SYM is not defined, report an error, and consider it a |
+| nonterminal.                                              |
+`----------------------------------------------------------*/
 
 static bool
-symbol_check_defined (symbol_t *this)
+symbol_check_defined (symbol *sym)
 {
-  if (this->class == unknown_sym)
+  if (sym->class == unknown_sym)
     {
       complain_at
-	(this->location,
+	(sym->location,
 	 _("symbol %s is used, but is not defined as a token and has no rules"),
-	 this->tag);
-      this->class = nterm_sym;
-      this->number = nvars++;
+	 sym->tag);
+      sym->class = nterm_sym;
+      sym->number = nvars++;
     }
 
   return true;
 }
 
 
-/*-------------------------------------------------------------------.
-| Declare the new SYMBOL.  Make it an alias of SYMVAL, and type them |
-| with TYPENAME.                                                     |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Declare the new symbol SYM.  Make it an alias of SYMVAL, and type |
+| them with TYPENAME.                                               |
+`------------------------------------------------------------------*/
 
 void
-symbol_make_alias (symbol_t *symbol, symbol_t *symval, location_t loc)
+symbol_make_alias (symbol *sym, symbol *symval, location loc)
 {
   if (symval->alias)
     warn_at (loc, _("symbol `%s' used more than once as a literal string"),
 	  symval->tag);
-  else if (symbol->alias)
+  else if (sym->alias)
     warn_at (loc, _("symbol `%s' given more than one literal string"),
-	  symbol->tag);
+	  sym->tag);
   else
     {
       symval->class = token_sym;
-      symval->user_token_number = symbol->user_token_number;
-      symbol->user_token_number = USER_NUMBER_ALIAS;
-      symval->alias = symbol;
-      symbol->alias = symval;
-      /* symbol and symval combined are only one symbol */
+      symval->user_token_number = sym->user_token_number;
+      sym->user_token_number = USER_NUMBER_ALIAS;
+      symval->alias = sym;
+      sym->alias = symval;
+      /* sym and symval combined are only one symbol.  */
       nsyms--;
       ntokens--;
-      if (ntokens != symbol->number && ntokens != symval->number)
+      if (ntokens != sym->number && ntokens != symval->number)
 	abort ();
-      symbol->number = symval->number =
-	(symval->number < symbol->number) ? symval->number : symbol->number;
+      sym->number = symval->number =
+	(symval->number < sym->number) ? symval->number : sym->number;
     }
 }
 
@@ -267,7 +261,7 @@ symbol_make_alias (symbol_t *symbol, symbol_t *symval, location_t loc)
 `---------------------------------------------------------*/
 
 static bool
-symbol_check_alias_consistence (symbol_t *this)
+symbol_check_alias_consistence (symbol *this)
 {
   /* Check only those who _are_ the aliases. */
   if (this->alias && this->user_token_number == USER_NUMBER_ALIAS)
@@ -307,7 +301,7 @@ symbol_check_alias_consistence (symbol_t *this)
 `-------------------------------------------------------------------*/
 
 static bool
-symbol_pack (symbol_t *this)
+symbol_pack (symbol *this)
 {
   if (this->class == nterm_sym)
     {
@@ -351,7 +345,7 @@ symbol_pack (symbol_t *this)
 `--------------------------------------------------*/
 
 static bool
-symbol_translation (symbol_t *this)
+symbol_translation (symbol *this)
 {
   /* Non-terminal? */
   if (this->class == token_sym
@@ -381,14 +375,14 @@ symbol_translation (symbol_t *this)
 static struct hash_table *symbol_table = NULL;
 
 static bool
-hash_compare_symbol (const symbol_t *m1, const symbol_t *m2)
+hash_compare_symbol (const symbol *m1, const symbol *m2)
 {
   /* Since tags are unique, we can compare the pointers themselves.  */
-  return STRUNIQ_EQ (m1->tag, m2->tag);
+  return UNIQSTR_EQ (m1->tag, m2->tag);
 }
 
 static unsigned int
-hash_symbol (const symbol_t *m, unsigned int tablesize)
+hash_symbol (const symbol *m, unsigned int tablesize)
 {
   /* Since tags are unique, we can hash the pointer itself.  */
   return ((size_t) m->tag) % tablesize;
@@ -415,21 +409,21 @@ symbols_new (void)
 | yet, create it.                                                 |
 `----------------------------------------------------------------*/
 
-symbol_t *
-symbol_get (const char *key, location_t location)
+symbol *
+symbol_get (const char *key, location loc)
 {
-  symbol_t probe;
-  symbol_t *entry;
+  symbol probe;
+  symbol *entry;
 
   /* Keep the symbol in a printable form.  */
-  key = struniq_new (quotearg_style (escape_quoting_style, key));
+  key = uniqstr_new (quotearg_style (escape_quoting_style, key));
   *(char const **) &probe.tag = key;
   entry = hash_lookup (symbol_table, &probe);
 
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = symbol_new (key, location);
+      entry = symbol_new (key, loc);
       hash_insert (symbol_table, entry);
     }
   return entry;
@@ -441,17 +435,17 @@ symbol_get (const char *key, location_t location)
 | user's names.                                                     |
 `------------------------------------------------------------------*/
 
-symbol_t *
-dummy_symbol_get (location_t location)
+symbol *
+dummy_symbol_get (location loc)
 {
   /* Incremented for each generated symbol.  */
   static int dummy_count = 0;
   static char buf[256];
 
-  symbol_t *sym;
+  symbol *sym;
 
   sprintf (buf, "@%d", ++dummy_count);
-  sym = symbol_get (buf, location);
+  sym = symbol_get (buf, loc);
   sym->class = nterm_sym;
   sym->number = nvars++;
   return sym;
@@ -511,7 +505,7 @@ symbols_token_translations_init (void)
   max_user_token_number = 0;
   for (i = 0; i < ntokens; ++i)
     {
-      symbol_t *this = symbols[i];
+      symbol *this = symbols[i];
       if (this->user_token_number != USER_NUMBER_UNDEFINED)
 	{
 	  if (this->user_token_number > max_user_token_number)
@@ -532,14 +526,14 @@ symbols_token_translations_init (void)
 
   for (i = 0; i < ntokens; ++i)
     {
-      symbol_t *this = symbols[i];
+      symbol *this = symbols[i];
       if (this->user_token_number == USER_NUMBER_UNDEFINED)
 	this->user_token_number = ++max_user_token_number;
       if (this->user_token_number > max_user_token_number)
 	max_user_token_number = this->user_token_number;
     }
 
-  token_translations = XCALLOC (symbol_number_t, max_user_token_number + 1);
+  token_translations = XCALLOC (symbol_number, max_user_token_number + 1);
 
   /* Initialize all entries for literal tokens to 2, the internal
      token number for $undefined, which represents all invalid inputs.
@@ -558,7 +552,7 @@ symbols_token_translations_init (void)
 void
 symbols_pack (void)
 {
-  symbols = XCALLOC (symbol_t *, nsyms);
+  symbols = XCALLOC (symbol *, nsyms);
 
   symbols_do (symbol_check_alias_consistence, NULL);
   symbols_do (symbol_pack, NULL);
