@@ -86,6 +86,181 @@ symbol_list_new (bucket *sym)
   return res;
 }
 
+/*------------------------.
+| Operations on buckets.  |
+`------------------------*/
+
+
+/*-----------------------------------------------------------.
+| If THIS is not defined, report an error, and consider it a |
+| nonterminal.                                               |
+`-----------------------------------------------------------*/
+
+static bool
+bucket_check_defined (bucket *this)
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
+| Assign a symbol number, and write the definition of the token name |
+| into FDEFINES.  Put in SYMBOLS.                                    |
+`-------------------------------------------------------------------*/
+
+static bool
+bucket_make_alias (bucket *symbol, char *typename)
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
+      symbol->user_token_number = SALIAS;
+      symval->alias = symbol;
+      symbol->alias = symval;
+      /* symbol and symval combined are only one symbol */
+      nsyms--;
+      ntokens--;
+      assert (ntokens == symbol->number || ntokens == symval->number);
+      symbol->number = symval->number =
+	(symval->number < symbol->number) ? symval->number : symbol->number;
+    }
+
+  return TRUE;
+}
+
+/*---------------------------------------------------------.
+| Check that THIS, and its alias, have same precedence and |
+| associativity.                                           |
+`---------------------------------------------------------*/
+
+static bool
+bucket_check_alias_consistence (bucket *this)
+{
+  /* Check only those who _are_ the aliases. */
+  if (this->alias && this->user_token_number == SALIAS)
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
+bucket_pack (bucket *this)
+{
+  if (getenv ("DEBUG"))
+    fprintf (stderr, "Packing %s, %s, number = %d\n",
+	     this->tag,
+	     this->class == nterm_sym ? "nterm" : "TERM",
+	     this->number);
+  if (this->class == nterm_sym)
+    {
+      this->number += ntokens;
+    }
+  else if (this->alias)
+    {
+      /* This symbol and its alias are a single token defn.
+	 Allocate a tokno, and assign to both check agreement of
+	 prec and assoc fields and make both the same */
+      if (this->number == -1)
+	{
+	  if (this == eoftoken || this->alias == eoftoken)
+	    this->number = this->alias->number = 0;
+	  else
+	    {
+	      assert (this->alias->number != -1);
+	      this->number = this->alias->number;
+	    }
+	}
+      /* Do not do processing below for SALIASs.  */
+      if (this->user_token_number == SALIAS)
+	return TRUE;
+    }
+  else /* this->class == token_sym */
+    {
+      assert (this->number != -1);
+    }
+
+  if (getenv ("DEBUG"))
+    fprintf (stderr, "Setting %d = %s\n", this->number, this->tag);
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
+bucket_translation (bucket *this)
+{
+  if (getenv ("DEBUG"))
+    fprintf (stderr, "Considering Setting UserVal %s = %d (val = %d)\n",
+	     this->tag, this->user_token_number, this->number);
+
+  /* Non-terminal? */
+  if (this->class == token_sym
+      && this->user_token_number != SALIAS)
+    {
+      /* A token which translation has already been set? */
+      if (token_translations[this->user_token_number] != 2)
+	complain (_("tokens %s and %s both assigned number %d"),
+		  symbols[token_translations[this->user_token_number]]->tag,
+		  this->tag, this->user_token_number);
+
+      if (getenv ("DEBUG"))
+	fprintf (stderr, "Setting UserVal %s = %d (val = %d)\n",
+		 this->tag, this->user_token_number, this->number);
+      token_translations[this->user_token_number] = this->number;
+    }
+
+  return TRUE;
+}
 
 
 /*===================\
@@ -531,23 +706,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	}
       else if (token == tok_identifier && *symval->tag == '\"' && symbol)
 	{
-	  if (symval->alias)
-	    warn (_("symbol `%s' used more than once as a literal string"),
-		  symval->tag);
-	  else if (symbol->alias)
-	    warn (_("symbol `%s' given more than one literal string"),
-		  symbol->tag);
-	  else
-	    {
-	      symval->class = token_sym;
-	      symval->type_name = typename;
-	      symval->user_token_number = symbol->user_token_number;
-	      symbol->user_token_number = SALIAS;
-	      symval->alias = symbol;
-	      symbol->alias = symval;
-	      /* symbol and symval combined are only one symbol */
-	      nsyms--;
-	    }
+	  bucket_make_alias (symbol, typename);
  	  symbol = NULL;
 	}
       else if (token == tok_identifier)
@@ -560,6 +719,13 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	  symbol->class = what_is;
 	  if (what_is == nterm_sym && oldclass != nterm_sym)
 	    symbol->number = nvars++;
+	  if (what_is == token_sym && symbol->number == -1)
+	    {
+	      symbol->number = ntokens++;
+	      if (getenv ("DEBUG"))
+		fprintf (stderr, "Set %s to %d\n",
+			 symbol->tag, symbol->number);
+	    }
 
 	  if (typename)
 	    {
@@ -574,7 +740,13 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	  symbol->user_token_number = numval;
 	  /* User defined EOF token? */
 	  if (numval == 0)
-	    eoftoken = symbol;
+	    {
+	      eoftoken = symbol;
+	      eoftoken->number = 0;
+	      /* It is always mapped to 0, so it was already counted in
+		 NTOKENS.  */
+	      --ntokens;
+	    }
 	}
       else
 	{
@@ -703,7 +875,11 @@ parse_assoc_decl (associativity assoc)
 	  symval->assoc = assoc;
 	  if (symval->class == nterm_sym)
 	    complain (_("symbol %s redefined"), symval->tag);
-	  symval->class = token_sym;
+	  if (symval->number == -1)
+	    {
+	      symval->number = ntokens++;
+	      symval->class = token_sym;
+	    }
 	  if (name)
 	    {			/* record the type, if one is specified */
 	      if (symval->type_name == NULL)
@@ -720,9 +896,9 @@ parse_assoc_decl (associativity assoc)
 	    }
 	  else
 	    {
-	      complain (_
-			("invalid text (%s) - number should be after identifier"),
-token_buffer);
+	      complain
+		(_("invalid text (%s) - number should be after identifier"),
+		 token_buffer);
 	      skip_to_char ('%');
 	    }
 	  break;
@@ -1073,7 +1249,7 @@ read_declarations (void)
 	    case tok_stropt:
 	    case tok_intopt:
 	    case tok_obsolete:
-	      abort ();
+	      assert (0);
 	      break;
 
 	    case tok_illegal:
@@ -1231,7 +1407,6 @@ readgram (void)
   bucket *lhs = NULL;
   symbol_list *p = NULL;
   symbol_list *p1 = NULL;
-  bucket *bp;
 
   /* Points to first symbol_list of current rule. its symbol is the
      lhs of the rule.  */
@@ -1463,16 +1638,7 @@ readgram (void)
     fatal (_("no rules in the input grammar"));
 
   /* Report any undefined symbols and consider them nonterminals.  */
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    if (bp->class == unknown_sym)
-      {
-	complain (_
-		  ("symbol %s is used, but is not defined as a token and has no rules"),
-		  bp->tag);
-	bp->class = nterm_sym;
-	bp->number = nvars++;
-      }
+  buckets_do (bucket_check_defined, NULL);
 
   /* Insert the initial rule, which line is that of the first rule
      (not that of the start symbol):
@@ -1493,7 +1659,10 @@ readgram (void)
     fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
 	   MAXSHORT);
 
-  ntokens = nsyms - nvars;
+  if (getenv ("DEBUG"))
+    fprintf (stderr, "nsyms == ntokens + nvars: %d == %d + %d\n",
+	     nsyms, ntokens, nvars);
+  assert (nsyms == ntokens + nvars);
 }
 
 /* At the end of the grammar file, some C source code must
@@ -1530,9 +1699,25 @@ read_additionnal_code (void)
 static void
 token_translations_init (void)
 {
-  bucket *bp = NULL;
+  int last_user_token_number = 256;
   int i;
 
+  /* Set the user numbers. */
+  for (i = 0; i < ntokens; ++i)
+    {
+      bucket *this = symbols[i];
+      if (getenv ("DEBUG"))
+	fprintf (stderr, "UserVal %s = %d (val = %d)\n",
+		 this->tag, this->user_token_number, this->number);
+      if (this->user_token_number == SUNDEF)
+	this->user_token_number = ++last_user_token_number;
+      if (this->user_token_number > max_user_token_number)
+	max_user_token_number = this->user_token_number;
+      if (getenv ("DEBUG"))
+	fprintf (stderr, "Now: UserVal %s = %d (val = %d)\n",
+		 this->tag, this->user_token_number, this->number);
+    }
+
   token_translations = XCALLOC (short, max_user_token_number + 1);
 
   /* Initialize all entries for literal tokens to 2, the internal
@@ -1541,24 +1726,7 @@ token_translations_init (void)
   for (i = 0; i < max_user_token_number + 1; i++)
     token_translations[i] = 2;
 
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      /* Non-terminal? */
-      if (bp->number >= ntokens)
-	continue;
-      /* A token string alias? */
-      if (bp->user_token_number == SALIAS)
-	continue;
-
-      assert (bp->user_token_number != SUNDEF);
-
-      /* A token which translation has already been set? */
-      if (token_translations[bp->user_token_number] != 2)
-	complain (_("tokens %s and %s both assigned number %d"),
-		  symbols[token_translations[bp->user_token_number]]->tag,
-		  bp->tag, bp->user_token_number);
-      token_translations[bp->user_token_number] = bp->number;
-    }
+  buckets_do (bucket_translation, NULL);
 }
 
 
@@ -1570,83 +1738,10 @@ token_translations_init (void)
 static void
 packsymbols (void)
 {
-  bucket *bp = NULL;
-  int tokno = 1;
-  int last_user_token_number;
-
   symbols = XCALLOC (bucket *, nsyms);
 
-  max_user_token_number = 256;
-  last_user_token_number = 256;
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      if (bp->class == nterm_sym)
-	{
-	  bp->number += ntokens;
-	}
-      else if (bp->alias)
-	{
-	  /* This symbol and its alias are a single token defn.
-	     Allocate a tokno, and assign to both check agreement of
-	     prec and assoc fields and make both the same */
-	  if (bp->number == -1)
-	    {
-	      if (bp == eoftoken || bp->alias == eoftoken)
-		bp->number = bp->alias->number = 0;
-	      else
-		{
-		  bp->number = bp->alias->number = tokno++;
-		}
-	    }
-
-	  if (bp->prec != bp->alias->prec)
-	    {
-	      if (bp->prec != 0 && bp->alias->prec != 0
-		  && bp->user_token_number == SALIAS)
-		complain (_("conflicting precedences for %s and %s"),
-			  bp->tag, bp->alias->tag);
-	      if (bp->prec != 0)
-		bp->alias->prec = bp->prec;
-	      else
-		bp->prec = bp->alias->prec;
-	    }
-
-	  if (bp->assoc != bp->alias->assoc)
-	    {
-	      if (bp->assoc != 0 && bp->alias->assoc != 0
-		  && bp->user_token_number == SALIAS)
-		complain (_("conflicting assoc values for %s and %s"),
-			  bp->tag, bp->alias->tag);
-	      if (bp->assoc != 0)
-		bp->alias->assoc = bp->assoc;
-	      else
-		bp->assoc = bp->alias->assoc;
-	    }
-
-	  /* Do not do processing below for SALIASs.  */
-	  if (bp->user_token_number == SALIAS)
-	    continue;
-
-	}
-      else /* bp->class == token_sym */
-	{
-	  if (bp == eoftoken)
-	    bp->number = 0;
-	  else
-	    bp->number = tokno++;
-	}
-
-      if (bp->class == token_sym)
-	{
-	  if (bp->user_token_number == SUNDEF)
-	    bp->user_token_number = ++last_user_token_number;
-	  if (bp->user_token_number > max_user_token_number)
-	    max_user_token_number = bp->user_token_number;
-	}
-
-      symbols[bp->number] = bp;
-    }
+  buckets_do (bucket_check_alias_consistence, NULL);
+  buckets_do (bucket_pack, NULL);
 
   token_translations_init ();
 
@@ -1750,7 +1845,7 @@ reader (void)
   obstack_init (&muscle_obstack);
 
   /* Initialize the symbol table.  */
-  tabinit ();
+  buckets_new ();
 
   /* Construct the axiom symbol. */
   axiom = getsym ("$axiom");
@@ -1760,12 +1855,14 @@ reader (void)
   /* Construct the error token */
   errtoken = getsym ("error");
   errtoken->class = token_sym;
+  errtoken->number = ntokens++;
   errtoken->user_token_number = 256;	/* Value specified by POSIX.  */
 
   /* Construct a token that represents all undefined literal tokens.
      It is always token number 2.  */
   undeftoken = getsym ("$undefined.");
   undeftoken->class = token_sym;
+  undeftoken->number = ntokens++;
   undeftoken->user_token_number = 2;
 
   /* Initialize the obstacks. */
@@ -1785,6 +1882,7 @@ reader (void)
     {
       eoftoken = getsym ("$");
       eoftoken->class = token_sym;
+      eoftoken->number = 0;
       /* Value specified by POSIX.  */
       eoftoken->user_token_number = 0;
     }
@@ -1815,5 +1913,5 @@ grammar_free (void)
   XFREE (ritem);
   free (rules + 1);
   /* Free the symbol table data structure.  */
-  free_symtab ();
+  buckets_free ();
 }
