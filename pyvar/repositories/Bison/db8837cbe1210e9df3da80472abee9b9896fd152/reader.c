@@ -38,7 +38,7 @@
 typedef struct symbol_list
 {
   struct symbol_list *next;
-  bucket *sym;
+  symbol_t *sym;
   int line;
 
   /* The action is attached to the LHS of a rule. */
@@ -48,13 +48,13 @@ typedef struct symbol_list
   /* The guard is attached to the LHS of a rule. */
   const char *guard;
   int guard_line;
-  bucket *ruleprec;
+  symbol_t *ruleprec;
 } symbol_list;
 
 int lineno;
 static symbol_list *grammar = NULL;
 static int start_flag = 0;
-static bucket *startval = NULL;
+static symbol_t *startval = NULL;
 
 /* Nonzero if components of semantic values are used, implying
    they must be unions.  */
@@ -66,13 +66,13 @@ static int typed = 0;
 /* Incremented for each %left, %right or %nonassoc seen */
 static int lastprec = 0;
 
-bucket *errtoken = NULL;
-bucket *undeftoken = NULL;
-bucket *eoftoken = NULL;
-bucket *axiom = NULL;
+symbol_t *errtoken = NULL;
+symbol_t *undeftoken = NULL;
+symbol_t *eoftoken = NULL;
+symbol_t *axiom = NULL;
 
 static symbol_list *
-symbol_list_new (bucket *sym)
+symbol_list_new (symbol_t *sym)
 {
   symbol_list *res = XMALLOC (symbol_list, 1);
   res->next = NULL;
@@ -87,7 +87,7 @@ symbol_list_new (bucket *sym)
 }
 
 /*------------------------.
-| Operations on buckets.  |
+| Operations on symbols.  |
 `------------------------*/
 
 
@@ -97,7 +97,7 @@ symbol_list_new (bucket *sym)
 `-----------------------------------------------------------*/
 
 static bool
-bucket_check_defined (bucket *this)
+symbol_check_defined (symbol_t *this)
 {
   if (this->class == unknown_sym)
     {
@@ -118,7 +118,7 @@ bucket_check_defined (bucket *this)
 `-------------------------------------------------------------------*/
 
 static bool
-bucket_make_alias (bucket *symbol, char *typename)
+symbol_make_alias (symbol_t *symbol, char *typename)
 {
   if (symval->alias)
     warn (_("symbol `%s' used more than once as a literal string"),
@@ -151,7 +151,7 @@ bucket_make_alias (bucket *symbol, char *typename)
 `---------------------------------------------------------*/
 
 static bool
-bucket_check_alias_consistence (bucket *this)
+symbol_check_alias_consistence (symbol_t *this)
 {
   /* Check only those who _are_ the aliases. */
   if (this->alias && this->user_token_number == SALIAS)
@@ -188,7 +188,7 @@ bucket_check_alias_consistence (bucket *this)
 `-------------------------------------------------------------------*/
 
 static bool
-bucket_pack (bucket *this)
+symbol_pack (symbol_t *this)
 {
   if (getenv ("DEBUG"))
     fprintf (stderr, "Packing %s, %s, number = %d\n",
@@ -237,7 +237,7 @@ bucket_pack (bucket *this)
 `--------------------------------------------------*/
 
 static bool
-bucket_translation (bucket *this)
+symbol_translation (symbol_t *this)
 {
   if (getenv ("DEBUG"))
     fprintf (stderr, "Considering Setting UserVal %s = %d (val = %d)\n",
@@ -677,7 +677,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
   char *typename = NULL;
 
   /* The symbol being defined.  */
-  struct bucket *symbol = NULL;
+  symbol_t *symbol = NULL;
 
   /* After `%token' and `%nterm', any number of symbols maybe be
      defined.  */
@@ -706,7 +706,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	}
       else if (token == tok_identifier && *symval->tag == '\"' && symbol)
 	{
-	  bucket_make_alias (symbol, typename);
+	  symbol_make_alias (symbol, typename);
  	  symbol = NULL;
 	}
       else if (token == tok_identifier)
@@ -1023,7 +1023,7 @@ static void
 parse_thong_decl (void)
 {
   token_t token;
-  struct bucket *symbol;
+  symbol_t *symbol;
   char *typename = 0;
   int usrtoknum = SUNDEF;
 
@@ -1365,14 +1365,14 @@ parse_guard (symbol_list *rule, int stack_offset)
 | with the user's names.                                             |
 `-------------------------------------------------------------------*/
 
-static bucket *
+static symbol_t *
 gensym (void)
 {
   /* Incremented for each generated symbol */
   static int gensym_count = 0;
   static char buf[256];
 
-  bucket *sym;
+  symbol_t *sym;
 
   sprintf (buf, "@%d", ++gensym_count);
   token_buffer = buf;
@@ -1404,7 +1404,7 @@ static void
 readgram (void)
 {
   token_t t;
-  bucket *lhs = NULL;
+  symbol_t *lhs = NULL;
   symbol_list *p = NULL;
   symbol_list *p1 = NULL;
 
@@ -1423,7 +1423,7 @@ readgram (void)
 	/* Number of symbols in rhs of this rule so far */
 	int rulelength = 0;
 	int xactions = 0;	/* JF for error checking */
-	bucket *first_rhs = 0;
+	symbol_t *first_rhs = 0;
 
 	if (t == tok_identifier)
 	  {
@@ -1494,7 +1494,7 @@ readgram (void)
 	       If one does, exit this rule now.  */
 	    if (t == tok_identifier)
 	      {
-		bucket *ssave;
+		symbol_t *ssave;
 		token_t t1;
 
 		ssave = symval;
@@ -1523,7 +1523,7 @@ readgram (void)
 		   inserting the new rule before it.  */
 
 		/* Make a dummy nonterminal, a gensym.  */
-		bucket *sdummy = gensym ();
+		symbol_t *sdummy = gensym ();
 
 		/* Make a new rule, whose body is empty, before the
 		   current one, so that the action just read can
@@ -1638,7 +1638,7 @@ readgram (void)
     fatal (_("no rules in the input grammar"));
 
   /* Report any undefined symbols and consider them nonterminals.  */
-  buckets_do (bucket_check_defined, NULL);
+  symbols_do (symbol_check_defined, NULL);
 
   /* Insert the initial rule, which line is that of the first rule
      (not that of the start symbol):
@@ -1705,7 +1705,7 @@ token_translations_init (void)
   /* Set the user numbers. */
   for (i = 0; i < ntokens; ++i)
     {
-      bucket *this = symbols[i];
+      symbol_t *this = symbols[i];
       if (getenv ("DEBUG"))
 	fprintf (stderr, "UserVal %s = %d (val = %d)\n",
 		 this->tag, this->user_token_number, this->number);
@@ -1726,7 +1726,7 @@ token_translations_init (void)
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = 2;
 
-  buckets_do (bucket_translation, NULL);
+  symbols_do (symbol_translation, NULL);
 }
 
 
@@ -1738,10 +1738,10 @@ token_translations_init (void)
 static void
 packsymbols (void)
 {
-  symbols = XCALLOC (bucket *, nsyms);
+  symbols = XCALLOC (symbol_t *, nsyms);
 
-  buckets_do (bucket_check_alias_consistence, NULL);
-  buckets_do (bucket_pack, NULL);
+  symbols_do (symbol_check_alias_consistence, NULL);
+  symbols_do (symbol_pack, NULL);
 
   token_translations_init ();
 
@@ -1781,7 +1781,7 @@ packgram (void)
   p = grammar;
   while (p)
     {
-      bucket *ruleprec = p->ruleprec;
+      symbol_t *ruleprec = p->ruleprec;
       rules[ruleno].user_number = ruleno;
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym;
@@ -1845,7 +1845,7 @@ reader (void)
   obstack_init (&muscle_obstack);
 
   /* Initialize the symbol table.  */
-  buckets_new ();
+  symbols_new ();
 
   /* Construct the axiom symbol. */
   axiom = getsym ("$axiom");
@@ -1913,5 +1913,5 @@ grammar_free (void)
   XFREE (ritem);
   free (rules + 1);
   /* Free the symbol table data structure.  */
-  buckets_free ();
+  symbols_free ();
 }
