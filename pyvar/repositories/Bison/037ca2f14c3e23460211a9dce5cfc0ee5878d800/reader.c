@@ -1,5 +1,5 @@
 /* Input parser for bison
-   Copyright 1984, 1986, 1989, 1992, 1998, 2000
+   Copyright 1984, 1986, 1989, 1992, 1998, 2000, 2001
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -852,7 +852,7 @@ parse_thong_decl (void)
   token_t token;
   struct bucket *symbol;
   char *typename = 0;
-  int usrtoknum;
+  int usrtoknum = 0;
 
   token = lex ();		/* fetch typename or first token */
   if (token == tok_typename)
@@ -883,8 +883,6 @@ parse_thong_decl (void)
       usrtoknum = numval;
       token = lex ();		/* okay, did number, now get literal */
     }
-  else
-    usrtoknum = 0;
 
   /* process literal string token */
 
@@ -1699,6 +1697,43 @@ output_token_defines (struct obstack *oout)
 }
 
 
+/*------------------------------------------------------------------.
+| Set TOKEN_TRANSLATIONS.  Check that no two symbols share the same |
+| number.                                                           |
+`------------------------------------------------------------------*/
+
+static void
+token_translations_init (void)
+{
+  bucket *bp = NULL;
+  int i;
+
+  token_translations = XCALLOC (short, max_user_token_number + 1);
+
+  /* Initialize all entries for literal tokens to 2, the internal
+     token number for $undefined., which represents all invalid
+     inputs.  */
+  for (i = 0; i <= max_user_token_number; i++)
+    token_translations[i] = 2;
+
+  for (bp = firstsymbol; bp; bp = bp->next)
+    {
+      /* Non-terminal? */
+      if (bp->value >= ntokens)
+	continue;
+      /* A token string alias? */
+      if (bp->user_token_number == SALIAS)
+	continue;
+      /* A token which translation has already been set? */
+      if (token_translations[bp->user_token_number] != 2)
+	complain (_("tokens %s and %s both assigned number %d"),
+		  tags[token_translations[bp->user_token_number]],
+		  bp->tag, bp->user_token_number);
+      token_translations[bp->user_token_number] = bp->value;
+    }
+}
+
+
 /*------------------------------------------------------------------.
 | Assign symbol numbers, and write definition of token names into   |
 | FDEFINES.  Set up vectors TAGS and SPREC of names and precedences |
@@ -1710,18 +1745,19 @@ packsymbols (void)
 {
   bucket *bp = NULL;
   int tokno = 1;
-  int i, j;
   int last_user_token_number;
   static char DOLLAR[] = "$";
 
   tags = XCALLOC (char *, nsyms + 1);
-  tags[0] = DOLLAR;
   user_toknums = XCALLOC (short, nsyms + 1);
-  user_toknums[0] = 0;
 
   sprec = XCALLOC (short, nsyms);
   sassoc = XCALLOC (short, nsyms);
 
+  /* The EOF token. */
+  tags[0] = DOLLAR;
+  user_toknums[0] = 0;
+
   max_user_token_number = 256;
   last_user_token_number = 256;
 
@@ -1774,7 +1810,7 @@ packsymbols (void)
 
       if (bp->class == token_sym)
 	{
-	  if (!bp->user_token_number)
+	  if (bp->user_token_number == 0)
 	    bp->user_token_number = ++last_user_token_number;
 	  if (bp->user_token_number > max_user_token_number)
 	    max_user_token_number = bp->user_token_number;
@@ -1786,26 +1822,7 @@ packsymbols (void)
       sassoc[bp->value] = bp->assoc;
     }
 
-  token_translations = XCALLOC (short, max_user_token_number + 1);
-
-  /* initialize all entries for literal tokens to 2, the internal
-     token number for $undefined., which represents all invalid
-     inputs.  */
-  for (j = 0; j <= max_user_token_number; j++)
-    token_translations[j] = 2;
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      if (bp->value >= ntokens)
-	continue;		/* non-terminal */
-      if (bp->user_token_number == SALIAS)
-	continue;
-      if (token_translations[bp->user_token_number] != 2)
-	complain (_("tokens %s and %s both assigned number %d"),
-		  tags[token_translations[bp->user_token_number]],
-		  bp->tag, bp->user_token_number);
-      token_translations[bp->user_token_number] = bp->value;
-    }
+  token_translations_init ();
 
   error_token_number = errtoken->value;
 
@@ -1845,19 +1862,23 @@ packsymbols (void)
 	}
 
       if (semantic_parser)
-	for (i = ntokens; i < nsyms; i++)
-	  {
-	    /* don't make these for dummy nonterminals made by gensym.  */
-	    if (*tags[i] != '@')
-	       obstack_fgrow2 (&defines_obstack,
-			       "# define\tNT%s\t%d\n", tags[i], i);
-	  }
+	{
+	  int i;
+
+	  for (i = ntokens; i < nsyms; i++)
+	    {
+	      /* don't make these for dummy nonterminals made by gensym.  */
+	      if (*tags[i] != '@')
+		obstack_fgrow2 (&defines_obstack,
+				"# define\tNT%s\t%d\n", tags[i], i);
+	    }
 #if 0
-      /* `fdefines' is now a temporary file, so we need to copy its
-         contents in `done', so we can't close it here.  */
-      fclose (fdefines);
-      fdefines = NULL;
+	  /* `fdefines' is now a temporary file, so we need to copy its
+	     contents in `done', so we can't close it here.  */
+	  fclose (fdefines);
+	  fdefines = NULL;
 #endif
+	}
     }
 }
 
