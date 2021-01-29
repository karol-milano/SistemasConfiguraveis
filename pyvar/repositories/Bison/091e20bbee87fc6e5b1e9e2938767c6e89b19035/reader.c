@@ -1658,56 +1658,6 @@ packsymbols (void)
 }
 
 
-/*---------------------------------------------------------------.
-| Save the definition of token names in the `TOKENDEFS' muscle.  |
-`---------------------------------------------------------------*/
-
-static void
-symbols_save (void)
-{
-  struct obstack tokendefs;
-  bucket *bp;
-  obstack_init (&tokendefs);
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      char *symbol = bp->tag;                /* get symbol */
-
-      if (bp->value >= ntokens)
-	continue;
-      if (bp->user_token_number == SALIAS)
-	continue;
-      if ('\'' == *symbol)
-	continue;               /* skip literal character */
-      if (bp == errtoken)
-	continue;               /* skip error token */
-      if ('\"' == *symbol)
-	{
-	  /* use literal string only if given a symbol with an alias */
-	  if (bp->alias)
-	    symbol = bp->alias->tag;
-	  else
-	    continue;
-	}
-
-      /* Don't #define nonliteral tokens whose names contain periods.  */
-      if (strchr (symbol, '.'))
-	continue;
-
-      obstack_fgrow2 (&tokendefs, "# define %s\t%d\n",
-		      symbol, bp->user_token_number);
-      if (semantic_parser)
-	/* FIXME: This is probably wrong, and should be just as
-	   above. --akim.  */
-	obstack_fgrow2 (&tokendefs, "# define T%s\t%d\n", symbol, bp->value);
-    }
-
-  obstack_1grow (&tokendefs, 0);
-  muscle_insert ("tokendef", xstrdup (obstack_finish (&tokendefs)));
-  obstack_free (&tokendefs, NULL);
-}
-
-
 /*---------------------------------------------------------------.
 | Convert the rules into the representation using RRHS, RLHS and |
 | RITEMS.                                                        |
@@ -1867,8 +1817,6 @@ reader (void)
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
-  /* Save them. */
-  symbols_save ();
 
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
