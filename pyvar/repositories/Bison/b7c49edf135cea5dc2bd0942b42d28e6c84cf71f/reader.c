@@ -68,9 +68,9 @@ static int typed;
 /* Incremented for each %left, %right or %nonassoc seen */
 static int lastprec;
 
-static bucket *errtoken;
-static bucket *undeftoken;
-
+static bucket *errtoken = NULL;
+static bucket *undeftoken = NULL;
+static bucket *eoftoken = NULL;
 
 static symbol_list *
 symbol_list_new (bucket *sym)
@@ -441,7 +441,7 @@ copy_definition (void)
     {
       obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
 		      lineno, quotearg_style (c_quoting_style,
-					      muscle_find("filename")));
+					      muscle_find ("filename")));
     }
 
   after_percent = 0;
@@ -573,6 +573,9 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
       else if (symbol && token == tok_number)
 	{
 	  symbol->user_token_number = numval;
+	  /* User defined EOF token? */
+	  if (numval == 0)
+	    eoftoken = symbol;
 	}
       else
 	{
@@ -902,8 +905,8 @@ static void
 parse_muscle_decl (void)
 {
   int ch = ungetc (skip_white_space (), finput);
-  char* muscle_key;
-  char* muscle_value;
+  char *muscle_key;
+  char *muscle_value;
 
   /* Read key. */
   if (!isalpha (ch) && ch != '_')
@@ -1486,7 +1489,7 @@ read_additionnal_code (void)
     {
       obstack_fgrow2 (&el_obstack, muscle_find ("linef"),
 		      lineno, quotearg_style (c_quoting_style,
-					      muscle_find("filename")));
+					      muscle_find ("filename")));
     }
 
   while ((c = getc (finput)) != EOF)
@@ -1549,7 +1552,6 @@ packsymbols (void)
   bucket *bp = NULL;
   int tokno = 1;
   int last_user_token_number;
-  static char DOLLAR[] = "$";
 
   tags = XCALLOC (char *, nsyms + 1);
   user_toknums = XCALLOC (short, nsyms + 1);
@@ -1557,10 +1559,6 @@ packsymbols (void)
   sprec = XCALLOC (short, nsyms);
   sassoc = XCALLOC (short, nsyms);
 
-  /* The EOF token. */
-  tags[0] = DOLLAR;
-  user_toknums[0] = 0;
-
   max_user_token_number = 256;
   last_user_token_number = 256;
 
@@ -1572,11 +1570,18 @@ packsymbols (void)
 	}
       else if (bp->alias)
 	{
-	  /* this symbol and its alias are a single token defn.
-	     allocate a tokno, and assign to both check agreement of
-	     ->prec and ->assoc fields and make both the same */
-	  if (bp->value == 0)
-	    bp->value = bp->alias->value = tokno++;
+	  /* This symbol and its alias are a single token defn.
+	     Allocate a tokno, and assign to both check agreement of
+	     prec and assoc fields and make both the same */
+	  if (bp->value == -1)
+	    {
+	      if (bp == eoftoken || bp->alias == eoftoken)
+		bp->value = bp->alias->value = 0;
+	      else
+		{
+		  bp->value = bp->alias->value = tokno++;
+		}
+	    }
 
 	  if (bp->prec != bp->alias->prec)
 	    {
@@ -1602,13 +1607,17 @@ packsymbols (void)
 		bp->assoc = bp->alias->assoc;
 	    }
 
+	  /* Do not do processing below for SALIASs.  */
 	  if (bp->user_token_number == SALIAS)
-	    continue;		/* do not do processing below for SALIASs */
+	    continue;
 
 	}
-      else			/* bp->class == token_sym */
+      else /* bp->class == token_sym */
 	{
-	  bp->value = tokno++;
+	  if (bp == eoftoken)
+	    bp->value = 0;
+	  else
+	    bp->value = tokno++;
 	}
 
       if (bp->class == token_sym)
@@ -1774,7 +1783,7 @@ reader (void)
   start_flag = 0;
   startval = NULL;		/* start symbol not specified yet. */
 
-  nsyms = 1;
+  nsyms = 0;
   nvars = 0;
   nrules = 0;
   nitems = 0;
@@ -1818,6 +1827,16 @@ reader (void)
      TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
      etc. found there.  */
   read_declarations ();
+
+  /* If the user did not define her EOFTOKEN, do it now. */
+  if (!eoftoken)
+    {
+      eoftoken = getsym ("$");
+      eoftoken->class = token_sym;
+      /* Value specified by POSIX.  */
+      eoftoken->user_token_number = 0;
+    }
+
   /* Read in the grammar, build grammar in list form.  Write out
      guards and actions.  */
   readgram ();
