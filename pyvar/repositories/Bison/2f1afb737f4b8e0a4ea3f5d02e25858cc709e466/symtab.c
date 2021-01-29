@@ -21,9 +21,20 @@
 
 #include "system.h"
 #include "hash.h"
+#include "complain.h"
 #include "symtab.h"
 #include "gram.h"
 
+/*------------------------.
+| Distinguished symbols.  |
+`------------------------*/
+
+symbol_t *errtoken = NULL;
+symbol_t *undeftoken = NULL;
+symbol_t *eoftoken = NULL;
+symbol_t *axiom = NULL;
+symbol_t *startsymbol = NULL;
+
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
 `---------------------------------*/
@@ -65,9 +76,165 @@ symbol_free (symbol_t *this)
 }
 
 
+/*-----------------------------------------------------------.
+| If THIS is not defined, report an error, and consider it a |
+| nonterminal.                                               |
+`-----------------------------------------------------------*/
+
+static bool
+symbol_check_defined (symbol_t *this)
+{
+  if (this->class == unknown_sym)
+    {
+      complain
+	(_("symbol %s is used, but is not defined as a token and has no rules"),
+	 this->tag);
+      this->class = nterm_sym;
+      this->number = nvars++;
+    }
+
+  return TRUE;
+}
+
+
+/*-------------------------------------------------------------------.
+| Declare the new SYMBOL.  Make it an alias of SYMVAL, and type them |
+| with TYPENAME.                                                     |
+`-------------------------------------------------------------------*/
+
+void
+symbol_make_alias (symbol_t *symbol, symbol_t *symval, char *typename)
+{
+  if (symval->alias)
+    warn (_("symbol `%s' used more than once as a literal string"),
+	  symval->tag);
+  else if (symbol->alias)
+    warn (_("symbol `%s' given more than one literal string"),
+	  symbol->tag);
+  else
+    {
+      symval->class = token_sym;
+      symval->type_name = typename;
+      symval->user_token_number = symbol->user_token_number;
+      symbol->user_token_number = USER_NUMBER_ALIAS;
+      symval->alias = symbol;
+      symbol->alias = symval;
+      /* symbol and symval combined are only one symbol */
+      nsyms--;
+      ntokens--;
+      assert (ntokens == symbol->number || ntokens == symval->number);
+      symbol->number = symval->number =
+	(symval->number < symbol->number) ? symval->number : symbol->number;
+    }
+}
+
+
+/*---------------------------------------------------------.
+| Check that THIS, and its alias, have same precedence and |
+| associativity.                                           |
+`---------------------------------------------------------*/
+
+static bool
+symbol_check_alias_consistence (symbol_t *this)
+{
+  /* Check only those who _are_ the aliases. */
+  if (this->alias && this->user_token_number == USER_NUMBER_ALIAS)
+    {
+      if (this->prec != this->alias->prec)
+	{
+	  if (this->prec != 0 && this->alias->prec != 0)
+	    complain (_("conflicting precedences for %s and %s"),
+		      this->tag, this->alias->tag);
+	  if (this->prec != 0)
+	    this->alias->prec = this->prec;
+	  else
+	    this->prec = this->alias->prec;
+	}
+
+      if (this->assoc != this->alias->assoc)
+	{
+	  if (this->assoc != 0 && this->alias->assoc != 0)
+	    complain (_("conflicting assoc values for %s and %s"),
+		      this->tag, this->alias->tag);
+	  if (this->assoc != 0)
+	    this->alias->assoc = this->assoc;
+	  else
+	    this->assoc = this->alias->assoc;
+	}
+    }
+  return TRUE;
+}
+
+
+/*-------------------------------------------------------------------.
+| Assign a symbol number, and write the definition of the token name |
+| into FDEFINES.  Put in SYMBOLS.                                    |
+`-------------------------------------------------------------------*/
+
+static bool
+symbol_pack (symbol_t *this)
+{
+  if (this->class == nterm_sym)
+    {
+      this->number += ntokens;
+    }
+  else if (this->alias)
+    {
+      /* This symbol and its alias are a single token defn.
+	 Allocate a tokno, and assign to both check agreement of
+	 prec and assoc fields and make both the same */
+      if (this->number == NUMBER_UNDEFINED)
+	{
+	  if (this == eoftoken || this->alias == eoftoken)
+	    this->number = this->alias->number = 0;
+	  else
+	    {
+	      assert (this->alias->number != NUMBER_UNDEFINED);
+	      this->number = this->alias->number;
+	    }
+	}
+      /* Do not do processing below for USER_NUMBER_ALIASs.  */
+      if (this->user_token_number == USER_NUMBER_ALIAS)
+	return TRUE;
+    }
+  else /* this->class == token_sym */
+    {
+      assert (this->number != NUMBER_UNDEFINED);
+    }
+
+  symbols[this->number] = this;
+  return TRUE;
+}
+
+
+
+
+/*--------------------------------------------------.
+| Put THIS in TOKEN_TRANSLATIONS if it is a token.  |
+`--------------------------------------------------*/
+
+static bool
+symbol_translation (symbol_t *this)
+{
+  /* Non-terminal? */
+  if (this->class == token_sym
+      && this->user_token_number != USER_NUMBER_ALIAS)
+    {
+      /* A token which translation has already been set? */
+      if (token_translations[this->user_token_number] != undeftoken->number)
+	complain (_("tokens %s and %s both assigned number %d"),
+		  symbols[token_translations[this->user_token_number]]->tag,
+		  this->tag, this->user_token_number);
+
+      token_translations[this->user_token_number] = this->number;
+    }
+
+  return TRUE;
+}
+
 
 /*----------------------.
-| A symbol_t hash table.  |
+| A symbol hash table.  |
 `----------------------*/
 
 /* Initial capacity of symbols hash table.  */
@@ -89,7 +256,7 @@ hash_symbol_t (const symbol_t *m, unsigned int tablesize)
 
 
 /*-------------------------------.
-| Create the symbol_t hash table.  |
+| Create the symbol hash table.  |
 `-------------------------------*/
 
 void
@@ -150,3 +317,91 @@ symbols_do (symbol_processor processor, void *processor_data)
 		    (Hash_processor) processor,
 		    processor_data);
 }
+
+
+/*--------------------------------------------------------------.
+| Check that all the symbols are defined.  Report any undefined |
+| symbols and consider them nonterminals.                       |
+`--------------------------------------------------------------*/
+
+void
+symbols_check_defined (void)
+{
+  symbols_do (symbol_check_defined, NULL);
+}
+
+/*------------------------------------------------------------------.
+| Set TOKEN_TRANSLATIONS.  Check that no two symbols share the same |
+| number.                                                           |
+`------------------------------------------------------------------*/
+
+static void
+symbols_token_translations_init (void)
+{
+  int num_256_available_p = TRUE;
+  int i;
+
+  /* Find the highest user token number, and whether 256, the POSIX
+     preferred user token number for the error token, is used.  */
+  max_user_token_number = 0;
+  for (i = 0; i < ntokens; ++i)
+    {
+      symbol_t *this = symbols[i];
+      if (this->user_token_number != USER_NUMBER_UNDEFINED)
+	{
+	  if (this->user_token_number > max_user_token_number)
+	    max_user_token_number = this->user_token_number;
+	  if (this->user_token_number == 256)
+	    num_256_available_p = FALSE;
+	}
+    }
+
+  /* If 256 is not used, assign it to error, to follow POSIX.  */
+  if (num_256_available_p
+      && errtoken->user_token_number == USER_NUMBER_UNDEFINED)
+    errtoken->user_token_number = 256;
+
+  /* Set the missing user numbers. */
+  if (max_user_token_number < 256)
+    max_user_token_number = 256;
+
+  for (i = 0; i < ntokens; ++i)
+    {
+      symbol_t *this = symbols[i];
+      if (this->user_token_number == USER_NUMBER_UNDEFINED)
+	this->user_token_number = ++max_user_token_number;
+      if (this->user_token_number > max_user_token_number)
+	max_user_token_number = this->user_token_number;
+    }
+
+  token_translations = XCALLOC (symbol_number_t, max_user_token_number + 1);
+
+  /* Initialize all entries for literal tokens to 2, the internal
+     token number for $undefined., which represents all invalid
+     inputs.  */
+  for (i = 0; i < max_user_token_number + 1; i++)
+    token_translations[i] = undeftoken->number;
+  symbols_do (symbol_translation, NULL);
+}
+
+
+/*----------------------------------------------------------------.
+| Assign symbol numbers, and write definition of token names into |
+| FDEFINES.  Set up vectors SYMBOL_TABLE, TAGS of symbols.        |
+`----------------------------------------------------------------*/
+
+void
+symbols_pack (void)
+{
+  symbols = XCALLOC (symbol_t *, nsyms);
+
+  symbols_do (symbol_check_alias_consistence, NULL);
+  symbols_do (symbol_pack, NULL);
+
+  symbols_token_translations_init ();
+
+  if (startsymbol->class == unknown_sym)
+    fatal (_("the start symbol %s is undefined"), startsymbol->tag);
+  else if (startsymbol->class == token_sym)
+    fatal (_("the start symbol %s is a token"), startsymbol->tag);
+}
