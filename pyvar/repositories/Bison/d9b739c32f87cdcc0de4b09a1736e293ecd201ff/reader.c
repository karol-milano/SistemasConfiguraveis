@@ -559,7 +559,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	    complain (_("symbol %s redefined"), symbol->tag);
 	  symbol->class = what_is;
 	  if (what_is == nterm_sym && oldclass != nterm_sym)
-	    symbol->value = nvars++;
+	    symbol->number = nvars++;
 
 	  if (typename)
 	    {
@@ -1202,7 +1202,7 @@ gensym (void)
   token_buffer = buf;
   sym = getsym (token_buffer);
   sym->class = nterm_sym;
-  sym->value = nvars++;
+  sym->number = nvars++;
   return sym;
 }
 
@@ -1294,7 +1294,7 @@ readgram (void)
 	if (lhs->class == unknown_sym)
 	  {
 	    lhs->class = nterm_sym;
-	    lhs->value = nvars;
+	    lhs->number = nvars;
 	    nvars++;
 	  }
 	else if (lhs->class == token_sym)
@@ -1471,7 +1471,7 @@ readgram (void)
 		  ("symbol %s is used, but is not defined as a token and has no rules"),
 		  bp->tag);
 	bp->class = nterm_sym;
-	bp->value = nvars++;
+	bp->number = nvars++;
       }
 
   /* Insert the initial rule, which line is that of the first rule
@@ -1544,7 +1544,7 @@ token_translations_init (void)
   for (bp = firstsymbol; bp; bp = bp->next)
     {
       /* Non-terminal? */
-      if (bp->value >= ntokens)
+      if (bp->number >= ntokens)
 	continue;
       /* A token string alias? */
       if (bp->user_token_number == SALIAS)
@@ -1557,7 +1557,7 @@ token_translations_init (void)
 	complain (_("tokens %s and %s both assigned number %d"),
 		  symbols[token_translations[bp->user_token_number]]->tag,
 		  bp->tag, bp->user_token_number);
-      token_translations[bp->user_token_number] = bp->value;
+      token_translations[bp->user_token_number] = bp->number;
     }
 }
 
@@ -1583,20 +1583,20 @@ packsymbols (void)
     {
       if (bp->class == nterm_sym)
 	{
-	  bp->value += ntokens;
+	  bp->number += ntokens;
 	}
       else if (bp->alias)
 	{
 	  /* This symbol and its alias are a single token defn.
 	     Allocate a tokno, and assign to both check agreement of
 	     prec and assoc fields and make both the same */
-	  if (bp->value == -1)
+	  if (bp->number == -1)
 	    {
 	      if (bp == eoftoken || bp->alias == eoftoken)
-		bp->value = bp->alias->value = 0;
+		bp->number = bp->alias->number = 0;
 	      else
 		{
-		  bp->value = bp->alias->value = tokno++;
+		  bp->number = bp->alias->number = tokno++;
 		}
 	    }
 
@@ -1632,9 +1632,9 @@ packsymbols (void)
       else /* bp->class == token_sym */
 	{
 	  if (bp == eoftoken)
-	    bp->value = 0;
+	    bp->number = 0;
 	  else
-	    bp->value = tokno++;
+	    bp->number = tokno++;
 	}
 
       if (bp->class == token_sym)
@@ -1645,25 +1645,25 @@ packsymbols (void)
 	    max_user_token_number = bp->user_token_number;
 	}
 
-      symbols[bp->value] = bp;
+      symbols[bp->number] = bp;
     }
 
   token_translations_init ();
 
-  error_token_number = errtoken->value;
+  error_token_number = errtoken->number;
 
   if (startval->class == unknown_sym)
     fatal (_("the start symbol %s is undefined"), startval->tag);
   else if (startval->class == token_sym)
     fatal (_("the start symbol %s is a token"), startval->tag);
 
-  start_symbol = startval->value;
+  start_symbol = startval->number;
 }
 
 
 /*---------------------------------------------------------------.
 | Convert the rules into the representation using RRHS, RLHS and |
-| RITEMS.                                                        |
+| RITEM.                                                         |
 `---------------------------------------------------------------*/
 
 static void
@@ -1687,7 +1687,7 @@ packgram (void)
   while (p)
     {
       bucket *ruleprec = p->ruleprec;
-      rules[ruleno].lhs = p->sym->value;
+      rules[ruleno].lhs = p->sym->number;
       rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].line = p->line;
       rules[ruleno].useful = TRUE;
@@ -1699,7 +1699,7 @@ packgram (void)
       p = p->next;
       while (p && p->sym)
 	{
-	  ritem[itemno++] = p->sym->value;
+	  ritem[itemno++] = p->sym->number;
 	  /* A rule gets by default the precedence and associativity
 	     of the last token in it.  */
 	  if (p->sym->class == token_sym)
@@ -1717,7 +1717,7 @@ packgram (void)
 	{
 	  rules[ruleno].prec = ruleprec->prec;
 	  rules[ruleno].assoc = ruleprec->assoc;
-	  rules[ruleno].precsym = ruleprec->value;
+	  rules[ruleno].precsym = ruleprec->number;
 	}
 
       ritem[itemno++] = -ruleno;
@@ -1774,7 +1774,7 @@ reader (void)
   /* Construct the axiom symbol. */
   axiom = getsym ("$axiom");
   axiom->class = nterm_sym;
-  axiom->value = nvars++;
+  axiom->number = nvars++;
 
   /* Construct the error token */
   errtoken = getsym ("error");
