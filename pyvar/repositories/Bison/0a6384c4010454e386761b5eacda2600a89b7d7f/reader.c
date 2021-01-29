@@ -1790,8 +1790,9 @@ get_type (void)
 #endif
 
 
-/* assign symbol numbers, and write definition of token names into fdefines.
-Set up vectors tags and sprec of names and precedences of symbols.  */
+/* Assign symbol numbers, and write definition of token names into
+   fdefines.  Set up vectors tags and sprec of names and precedences
+   of symbols.  */
 
 void
 packsymbols (void)
@@ -1822,34 +1823,38 @@ packsymbols (void)
 	}
       else if (bp->alias)
 	{
-		/* this symbol and its alias are a single token defn.
-		  allocate a tokno, and assign to both
-		  check agreement of ->prec and ->assoc fields
-			and make both the same
-		*/
-		if (bp->value == 0)
-			bp->value = bp->alias->value = tokno++;
-
-		if (bp->prec != bp->alias->prec) {
-			if (bp->prec != 0 && bp->alias->prec != 0
-					&& bp->user_token_number == SALIAS)
-				warnss(_("conflicting precedences for %s and %s"),
-					bp->tag, bp->alias->tag);
-			if (bp->prec != 0) bp->alias->prec = bp->prec;
-			else bp->prec = bp->alias->prec;
-		}
+	  /* this symbol and its alias are a single token defn.
+	     allocate a tokno, and assign to both check agreement of
+	     ->prec and ->assoc fields and make both the same */
+	  if (bp->value == 0)
+	    bp->value = bp->alias->value = tokno++;
 
-		if (bp->assoc != bp->alias->assoc) {
-			if (bp->assoc != 0 && bp->alias->assoc != 0
-					&& bp->user_token_number == SALIAS)
-				warnss(_("conflicting assoc values for %s and %s"),
-					bp->tag, bp->alias->tag);
-			if (bp->assoc != 0) bp->alias->assoc = bp->assoc;
-			else bp->assoc = bp->alias->assoc;
-		}
+	  if (bp->prec != bp->alias->prec)
+	    {
+	      if (bp->prec != 0 && bp->alias->prec != 0
+		  && bp->user_token_number == SALIAS)
+		warnss(_("conflicting precedences for %s and %s"),
+		       bp->tag, bp->alias->tag);
+	      if (bp->prec != 0)
+		bp->alias->prec = bp->prec;
+	      else
+		bp->prec = bp->alias->prec;
+	    }
 
-		if (bp->user_token_number == SALIAS)
-			continue;  /* do not do processing below for SALIASs */
+	  if (bp->assoc != bp->alias->assoc)
+	    {
+	    if (bp->assoc != 0 && bp->alias->assoc != 0
+		&& bp->user_token_number == SALIAS)
+	      warnss(_("conflicting assoc values for %s and %s"),
+		     bp->tag, bp->alias->tag);
+	    if (bp->assoc != 0)
+	      bp->alias->assoc = bp->assoc;
+	    else
+	      bp->assoc = bp->alias->assoc;
+	  }
+
+	  if (bp->user_token_number == SALIAS)
+	    continue;  /* do not do processing below for SALIASs */
 
  	}
       else  /* bp->class == STOKEN */
@@ -1878,21 +1883,23 @@ packsymbols (void)
 
       token_translations = NEW2(max_user_token_number+1, short);
 
-      /* initialize all entries for literal tokens to 2,
-	 the internal token number for $undefined.,
-	 which represents all invalid inputs.  */
+      /* initialize all entries for literal tokens to 2, the internal
+	 token number for $undefined., which represents all invalid
+	 inputs.  */
       for (i = 0; i <= max_user_token_number; i++)
         token_translations[i] = 2;
 
       for (bp = firstsymbol; bp; bp = bp->next)
         {
-          if (bp->value >= ntokens) continue;		  /* non-terminal */
-          if (bp->user_token_number == SALIAS) continue;
+          if (bp->value >= ntokens)
+	    continue;		  /* non-terminal */
+          if (bp->user_token_number == SALIAS)
+	    continue;
           if (token_translations[bp->user_token_number] != 2)
 	    warnsss(_("tokens %s and %s both assigned number %s"),
-			      tags[token_translations[bp->user_token_number]],
-			      bp->tag,
-			      int_to_string(bp->user_token_number));
+		    tags[token_translations[bp->user_token_number]],
+		    bp->tag,
+		    int_to_string(bp->user_token_number));
           token_translations[bp->user_token_number] = bp->value;
         }
     }
@@ -1937,9 +1944,9 @@ packsymbols (void)
     }
 }
 
-/* For named tokens, but not literal ones, define the name.
-   The value is the user token number.
-*/
+/* For named tokens, but not literal ones, define the name.  The value
+   is the user token number.  */
+
 void
 output_token_defines (FILE *file)
 {
