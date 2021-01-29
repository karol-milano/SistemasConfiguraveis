@@ -21,7 +21,6 @@
 
 
 #include "system.h"
-#include "obstack.h"
 #include "quotearg.h"
 #include "quote.h"
 #include "getargs.h"
@@ -777,15 +776,6 @@ parse_union_decl (void)
     ungetc (c, finput);
   obstack_1grow (&union_obstack, 0);
   muscle_insert ("stype", obstack_finish (&union_obstack));
-
-  if (defines_flag)
-    obstack_fgrow1 (&defines_obstack, "\
-#ifndef YYSTYPE\n\
-typedef %s
-yystype;\n\
-# define YYSTYPE yystype\n\
-#endif\n",
-		    muscle_find ("stype"));
 }
 
 
@@ -1567,55 +1557,6 @@ read_additionnal_code (void)
 }
 
 
-/*--------------------------------------------------------------.
-| For named tokens, but not literal ones, define the name.  The |
-| value is the user token number.                               |
-`--------------------------------------------------------------*/
-
-static void
-output_token_defines (struct obstack *oout)
-{
-  bucket *bp;
-  char *cp, *symbol;
-  char c;
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    {
-      symbol = bp->tag;		/* get symbol */
-
-      if (bp->value >= ntokens)
-	continue;
-      if (bp->user_token_number == SALIAS)
-	continue;
-      if ('\'' == *symbol)
-	continue;		/* skip literal character */
-      if (bp == errtoken)
-	continue;		/* skip error token */
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
-      cp = symbol;
-      while ((c = *cp++) && c != '.');
-      if (c != '\0')
-	continue;
-
-      obstack_fgrow2 (oout, "# define\t%s\t%d\n",
-		      symbol, bp->user_token_number);
-      if (semantic_parser)
-	/* FIXME: This is certainly dead wrong, and should be just as
-	   above. --akim.  */
-	obstack_fgrow2 (oout, "# define\tT%s\t%d\n", symbol, bp->value);
-    }
-}
-
-
 /*------------------------------------------------------------------.
 | Set TOKEN_TRANSLATIONS.  Check that no two symbols share the same |
 | number.                                                           |
@@ -1757,48 +1698,57 @@ packsymbols (void)
 }
 
 
-/*-----------------------------------.
-| Output definition of token names.  |
-`-----------------------------------*/
+/*---------------------------------------------------------------.
+| Save the definition of token names in the `TOKENDEFS' muscle.  |
+`---------------------------------------------------------------*/
 
 static void
-symbols_output (void)
+symbols_save (void)
 {
-  {
-    struct obstack tokendefs;
-    obstack_init (&tokendefs);
-    output_token_defines (&tokendefs);
-    obstack_1grow (&tokendefs, 0);
-    muscle_insert ("tokendef", xstrdup (obstack_finish (&tokendefs)));
-    obstack_free (&tokendefs, NULL);
-  }
-
-  if (defines_flag)
+  struct obstack tokendefs;
+  bucket *bp;
+  char *cp, *symbol;
+  char c;
+  obstack_init (&tokendefs);
+
+  for (bp = firstsymbol; bp; bp = bp->next)
     {
-      output_token_defines (&defines_obstack);
+      symbol = bp->tag;                /* get symbol */
 
-      if (!pure_parser)
-	obstack_fgrow1 (&defines_obstack, "\nextern YYSTYPE %slval;\n",
-			spec_name_prefix);
-      if (semantic_parser)
+      if (bp->value >= ntokens)
+	continue;
+      if (bp->user_token_number == SALIAS)
+	continue;
+      if ('\'' == *symbol)
+	continue;               /* skip literal character */
+      if (bp == errtoken)
+	continue;               /* skip error token */
+      if ('\"' == *symbol)
 	{
-	  int i;
-
-	  for (i = ntokens; i < nsyms; i++)
-	    {
-	      /* don't make these for dummy nonterminals made by gensym.  */
-	      if (*tags[i] != '@')
-		obstack_fgrow2 (&defines_obstack,
-				"# define\tNT%s\t%d\n", tags[i], i);
-	    }
-#if 0
-	  /* `fdefines' is now a temporary file, so we need to copy its
-	     contents in `done', so we can't close it here.  */
-	  fclose (fdefines);
-	  fdefines = NULL;
-#endif
+	  /* use literal string only if given a symbol with an alias */
+	  if (bp->alias)
+	    symbol = bp->alias->tag;
+	  else
+	    continue;
 	}
+
+      /* Don't #define nonliteral tokens whose names contain periods.  */
+      cp = symbol;
+      while ((c = *cp++) && c != '.');
+      if (c != '\0')
+	continue;
+
+      obstack_fgrow2 (&tokendefs, "# define\t%s\t%d\n",
+		      symbol, bp->user_token_number);
+      if (semantic_parser)
+	/* FIXME: This is probably wrong, and should be just as
+	   above. --akim.  */
+	obstack_fgrow2 (&tokendefs, "# define\tT%s\t%d\n", symbol, bp->value);
     }
+
+  obstack_1grow (&tokendefs, 0);
+  muscle_insert ("tokendef", xstrdup (obstack_finish (&tokendefs)));
+  obstack_free (&tokendefs, NULL);
 }
 
 
@@ -1925,15 +1875,12 @@ reader (void)
   /* Some C code is given at the end of the grammar file. */
   read_additionnal_code ();
 
-  /* Now we know whether we need the line-number stack.  If we do,
-     write its type into the .tab.h file.
-     This is no longer need with header skeleton.  */
-
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
+  /* Save them. */
+  symbols_save ();
+
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
-  /* Output the headers. */
-  symbols_output ();
 }
