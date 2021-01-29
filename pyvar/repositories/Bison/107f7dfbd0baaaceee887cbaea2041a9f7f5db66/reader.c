@@ -1327,332 +1327,246 @@ gensym (void)
   sym->value = nvars++;
   return sym;
 }
-
-#if 0
-/*------------------------------------------------------------------.
-| read in a %type declaration and record its information for        |
-| get_type_name to access.  This is unused.  It is only called from |
-| the #if 0 part of readgram                                        |
-`------------------------------------------------------------------*/
-
-static int
-get_type (void)
-{
-  int k;
-  token_t token;
-  char *name;
-
-  token = lex ();
-
-  if (token != tok_typename)
-    {
-      complain (_("invalid %s declaration"), "%type");
-      return t;
-    }
-
-  name = xstrdup (token_buffer);
-
-  for (;;)
-    {
-      token = lex ();
-
-      switch (token)
-	{
-	case tok_semicolon:
-	  return lex ();
-
-	case tok_comma:
-	  break;
-
-	case tok_identifier:
-	  if (symval->type_name == NULL)
-	    symval->type_name = name;
-	  else if (strcmp (name, symval->type_name) != 0)
-	    complain (_("type redeclaration for %s"), symval->tag);
-
-	  break;
-
-	default:
-	  return token;
-	}
-    }
-}
-
-#endif
 
-/*------------------------------------------------------------------.
-| Parse the input grammar into a one symbol_list structure.  Each   |
-| rule is represented by a sequence of symbols: the left hand side  |
-| followed by the contents of the right hand side, followed by a    |
-| null pointer instead of a symbol to terminate the rule.  The next |
-| symbol is the lhs of the following rule.                          |
-|                                                                   |
-| All guards and actions are copied out to the appropriate files,   |
-| labelled by the rule number they apply to.                        |
-`------------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Parse the input grammar into a one symbol_list structure.  Each    |
+| rule is represented by a sequence of symbols: the left hand side   |
+| followed by the contents of the right hand side, followed by a     |
+| null pointer instead of a symbol to terminate the rule.  The next  |
+| symbol is the lhs of the following rule.                           |
+|                                                                    |
+| All guards and actions are copied out to the appropriate files,    |
+| labelled by the rule number they apply to.                         |
+|                                                                    |
+| Bison used to allow some %directives in the rules sections, but    |
+| this is no longer consider appropriate: (i) the documented grammar |
+| doesn't claim it, (ii), it would promote bad style, (iii), error   |
+| recovery for %directives consists in skipping the junk until a `%' |
+| is seen and helrp synchronizing.  This scheme is definitely wrong  |
+| in the rules section.                                              |
+`-------------------------------------------------------------------*/
 
 static void
 readgram (void)
 {
   token_t t;
   bucket *lhs = NULL;
-  symbol_list *p;
-  symbol_list *p1;
+  symbol_list *p = NULL;
+  symbol_list *p1 = NULL;
   bucket *bp;
 
   /* Points to first symbol_list of current rule. its symbol is the
      lhs of the rule.  */
-  symbol_list *crule;
+  symbol_list *crule = NULL;
   /* Points to the symbol_list preceding crule.  */
-  symbol_list *crule1;
-
-  p1 = NULL;
+  symbol_list *crule1 = NULL;
 
   t = lex ();
 
   while (t != tok_two_percents && t != tok_eof)
-    {
-      if (t == tok_identifier || t == tok_bar)
-	{
-	  int action_flag = 0;
-	  /* Number of symbols in rhs of this rule so far */
-	  int rulelength = 0;
-	  int xactions = 0;	/* JF for error checking */
-	  bucket *first_rhs = 0;
-
-	  if (t == tok_identifier)
-	    {
-	      lhs = symval;
-
-	      if (!start_flag)
-		{
-		  startval = lhs;
-		  start_flag = 1;
-		}
-
-	      t = lex ();
-	      if (t != tok_colon)
-		{
-		  complain (_("ill-formed rule: initial symbol not followed by colon"));
-		  unlex (t);
-		}
-	    }
-
-	  if (nrules == 0 && t == tok_bar)
-	    {
-	      complain (_("grammar starts with vertical bar"));
-	      lhs = symval;	/* BOGUS: use a random symval */
-	    }
-	  /* start a new rule and record its lhs.  */
-
-	  nrules++;
-	  nitems++;
-
-	  p = symbol_list_new (lhs);
+    if (t == tok_identifier || t == tok_bar)
+      {
+	int action_flag = 0;
+	/* Number of symbols in rhs of this rule so far */
+	int rulelength = 0;
+	int xactions = 0;	/* JF for error checking */
+	bucket *first_rhs = 0;
+
+	if (t == tok_identifier)
+	  {
+	    lhs = symval;
+
+	    if (!start_flag)
+	      {
+		startval = lhs;
+		start_flag = 1;
+	      }
 
-	  crule1 = p1;
-	  if (p1)
-	    p1->next = p;
-	  else
-	    grammar = p;
+	    t = lex ();
+	    if (t != tok_colon)
+	      {
+		complain (_("ill-formed rule: initial symbol not followed by colon"));
+		unlex (t);
+	      }
+	  }
+
+	if (nrules == 0 && t == tok_bar)
+	  {
+	    complain (_("grammar starts with vertical bar"));
+	    lhs = symval;	/* BOGUS: use a random symval */
+	  }
+	/* start a new rule and record its lhs.  */
+
+	nrules++;
+	nitems++;
+
+	p = symbol_list_new (lhs);
+
+	crule1 = p1;
+	if (p1)
+	  p1->next = p;
+	else
+	  grammar = p;
 
-	  p1 = p;
-	  crule = p;
+	p1 = p;
+	crule = p;
 
-	  /* mark the rule's lhs as a nonterminal if not already so.  */
+	/* mark the rule's lhs as a nonterminal if not already so.  */
 
-	  if (lhs->class == unknown_sym)
-	    {
-	      lhs->class = nterm_sym;
-	      lhs->value = nvars;
-	      nvars++;
-	    }
-	  else if (lhs->class == token_sym)
-	    complain (_("rule given for %s, which is a token"), lhs->tag);
+	if (lhs->class == unknown_sym)
+	  {
+	    lhs->class = nterm_sym;
+	    lhs->value = nvars;
+	    nvars++;
+	  }
+	else if (lhs->class == token_sym)
+	  complain (_("rule given for %s, which is a token"), lhs->tag);
 
-	  /* read the rhs of the rule.  */
+	/* read the rhs of the rule.  */
 
-	  for (;;)
-	    {
-	      t = lex ();
-	      if (t == tok_prec)
-		{
-		  t = lex ();
-		  crule->ruleprec = symval;
-		  t = lex ();
-		}
-
-	      if (!(t == tok_identifier || t == tok_left_curly))
-		break;
-
-	      /* If next token is an identifier, see if a colon follows it.
-	         If one does, exit this rule now.  */
-	      if (t == tok_identifier)
-		{
-		  bucket *ssave;
-		  token_t t1;
-
-		  ssave = symval;
-		  t1 = lex ();
-		  unlex (t1);
-		  symval = ssave;
-		  if (t1 == tok_colon)
-		    break;
-
-		  if (!first_rhs)	/* JF */
-		    first_rhs = symval;
-		  /* Not followed by colon =>
-		     process as part of this rule's rhs.  */
-		}
-
-	      /* If we just passed an action, that action was in the middle
-	         of a rule, so make a dummy rule to reduce it to a
-	         non-terminal.  */
-	      if (action_flag)
-		{
-		  /* Since the action was written out with this rule's
-		     number, we must give the new rule this number by
-		     inserting the new rule before it.  */
-
-		  /* Make a dummy nonterminal, a gensym.  */
-		  bucket *sdummy = gensym ();
-
-		  /* Make a new rule, whose body is empty, before the
-		     current one, so that the action just read can
-		     belong to it.  */
-		  nrules++;
-		  nitems++;
-		  p = symbol_list_new (sdummy);
-		  /* Attach its lineno to that of the host rule. */
-		  p->line = crule->line;
-		  if (crule1)
-		    crule1->next = p;
-		  else
-		    grammar = p;
-		  /* End of the rule. */
-		  crule1 = symbol_list_new (NULL);
-		  crule1->next = crule;
-
-		  p->next = crule1;
-
-		  /* Insert the dummy generated by that rule into this
-		     rule.  */
-		  nitems++;
-		  p = symbol_list_new (sdummy);
-		  p1->next = p;
-		  p1 = p;
-
-		  action_flag = 0;
-		}
-
-	      if (t == tok_identifier)
-		{
-		  nitems++;
-		  p = symbol_list_new (symval);
-		  p1->next = p;
-		  p1 = p;
-		}
-	      else		/* handle an action.  */
-		{
-		  copy_action (crule, rulelength);
-		  action_flag = 1;
-		  xactions++;	/* JF */
-		}
-	      rulelength++;
-	    }			/* end of  read rhs of rule */
-
-	  /* Put an empty link in the list to mark the end of this rule  */
-	  p = symbol_list_new (NULL);
-	  p1->next = p;
-	  p1 = p;
+	for (;;)
+	  {
+	    t = lex ();
+	    if (t == tok_prec)
+	      {
+		t = lex ();
+		crule->ruleprec = symval;
+		t = lex ();
+	      }
+
+	    if (!(t == tok_identifier || t == tok_left_curly))
+	      break;
 
-	  if (t == tok_prec)
-	    {
-	      complain (_("two @prec's in a row"));
-	      t = lex ();
-	      crule->ruleprec = symval;
-	      t = lex ();
-	    }
-	  if (t == tok_guard)
-	    {
-	      if (!semantic_parser)
-		complain (_("%%guard present but %%semantic_parser not specified"));
+	    /* If next token is an identifier, see if a colon follows it.
+	       If one does, exit this rule now.  */
+	    if (t == tok_identifier)
+	      {
+		bucket *ssave;
+		token_t t1;
+
+		ssave = symval;
+		t1 = lex ();
+		unlex (t1);
+		symval = ssave;
+		if (t1 == tok_colon)
+		  break;
+
+		if (!first_rhs)	/* JF */
+		  first_rhs = symval;
+		/* Not followed by colon =>
+		   process as part of this rule's rhs.  */
+	      }
+
+	    /* If we just passed an action, that action was in the middle
+	       of a rule, so make a dummy rule to reduce it to a
+	       non-terminal.  */
+	    if (action_flag)
+	      {
+		/* Since the action was written out with this rule's
+		   number, we must give the new rule this number by
+		   inserting the new rule before it.  */
+
+		/* Make a dummy nonterminal, a gensym.  */
+		bucket *sdummy = gensym ();
+
+		/* Make a new rule, whose body is empty, before the
+		   current one, so that the action just read can
+		   belong to it.  */
+		nrules++;
+		nitems++;
+		p = symbol_list_new (sdummy);
+		/* Attach its lineno to that of the host rule. */
+		p->line = crule->line;
+		if (crule1)
+		  crule1->next = p;
+		else
+		  grammar = p;
+		/* End of the rule. */
+		crule1 = symbol_list_new (NULL);
+		crule1->next = crule;
+
+		p->next = crule1;
+
+		/* Insert the dummy generated by that rule into this
+		   rule.  */
+		nitems++;
+		p = symbol_list_new (sdummy);
+		p1->next = p;
+		p1 = p;
+
+		action_flag = 0;
+	      }
+
+	    if (t == tok_identifier)
+	      {
+		nitems++;
+		p = symbol_list_new (symval);
+		p1->next = p;
+		p1 = p;
+	      }
+	    else		/* handle an action.  */
+	      {
+		copy_action (crule, rulelength);
+		action_flag = 1;
+		xactions++;	/* JF */
+	      }
+	    rulelength++;
+	  }			/* end of  read rhs of rule */
+
+	/* Put an empty link in the list to mark the end of this rule  */
+	p = symbol_list_new (NULL);
+	p1->next = p;
+	p1 = p;
+
+	if (t == tok_prec)
+	  {
+	    complain (_("two @prec's in a row"));
+	    t = lex ();
+	    crule->ruleprec = symval;
+	    t = lex ();
+	  }
+	if (t == tok_guard)
+	  {
+	    if (!semantic_parser)
+	      complain (_("%%guard present but %%semantic_parser not specified"));
 
-	      copy_guard (crule, rulelength);
-	      t = lex ();
-	    }
-	  else if (t == tok_left_curly)
-	    {
-	      /* This case never occurs -wjh */
-	      if (action_flag)
-		complain (_("two actions at end of one rule"));
-	      copy_action (crule, rulelength);
-	      action_flag = 1;
-	      xactions++;	/* -wjh */
-	      t = lex ();
-	    }
-	  /* If $$ is being set in default way, report if any type
-	     mismatch.  */
-	  else if (!xactions
-		   && first_rhs && lhs->type_name != first_rhs->type_name)
-	    {
-	      if (lhs->type_name == 0
-		  || first_rhs->type_name == 0
-		  || strcmp (lhs->type_name, first_rhs->type_name))
-		complain (_("type clash (`%s' `%s') on default action"),
-			  lhs->type_name ? lhs->type_name : "",
-			  first_rhs->type_name ? first_rhs->type_name : "");
-	    }
-	  /* Warn if there is no default for $$ but we need one.  */
-	  else if (!xactions && !first_rhs && lhs->type_name != 0)
-	    complain (_("empty rule for typed nonterminal, and no action"));
-	  if (t == tok_semicolon)
+	    copy_guard (crule, rulelength);
 	    t = lex ();
-	}
-#if 0
-      /* these things can appear as alternatives to rules.  */
-/* NO, they cannot.
-	a) none of the documentation allows them
-	b) most of them scan forward until finding a next %
-		thus they may swallow lots of intervening rules
-*/
-      else if (t == tok_token)
-	{
-	  parse_token_decl (token_sym, nterm_sym);
-	  t = lex ();
-	}
-      else if (t == tok_nterm)
-	{
-	  parse_token_decl (nterm_sym, token_sym);
-	  t = lex ();
-	}
-      else if (t == tok_type)
-	{
-	  t = get_type ();
-	}
-      else if (t == tok_union)
-	{
-	  parse_union_decl ();
-	  t = lex ();
-	}
-      else if (t == tok_expect)
-	{
-	  parse_expect_decl ();
-	  t = lex ();
-	}
-      else if (t == tok_start)
-	{
-	  parse_start_decl ();
+	  }
+	else if (t == tok_left_curly)
+	  {
+	    /* This case never occurs -wjh */
+	    if (action_flag)
+	      complain (_("two actions at end of one rule"));
+	    copy_action (crule, rulelength);
+	    action_flag = 1;
+	    xactions++;	/* -wjh */
+	    t = lex ();
+	  }
+	/* If $$ is being set in default way, report if any type
+	   mismatch.  */
+	else if (!xactions
+		 && first_rhs && lhs->type_name != first_rhs->type_name)
+	  {
+	    if (lhs->type_name == 0
+		|| first_rhs->type_name == 0
+		|| strcmp (lhs->type_name, first_rhs->type_name))
+	      complain (_("type clash (`%s' `%s') on default action"),
+			lhs->type_name ? lhs->type_name : "",
+			first_rhs->type_name ? first_rhs->type_name : "");
+	  }
+	/* Warn if there is no default for $$ but we need one.  */
+	else if (!xactions && !first_rhs && lhs->type_name != 0)
+	  complain (_("empty rule for typed nonterminal, and no action"));
+	if (t == tok_semicolon)
 	  t = lex ();
-	}
-#endif
+      }
+    else
+      {
+	complain (_("invalid input: %s"), quote (token_buffer));
+	t = lex ();
+      }
 
-      else
-	{
-	  complain (_("invalid input: %s"), quote (token_buffer));
-	  t = lex ();
-	}
-    }
 
   /* grammar has been read.  Do some checking */
 
