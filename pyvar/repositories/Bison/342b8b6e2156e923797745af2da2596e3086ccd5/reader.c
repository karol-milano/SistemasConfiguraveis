@@ -26,7 +26,6 @@
 #include "quote.h"
 #include "getargs.h"
 #include "files.h"
-#include "xalloc.h"
 #include "symtab.h"
 #include "options.h"
 #include "lex.h"
@@ -431,7 +430,7 @@ copy_definition (void)
   if (!no_lines_flag)
     {
       obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
-		      lineno, quotearg_style (c_quoting_style, 
+		      lineno, quotearg_style (c_quoting_style,
 					      muscle_find("filename")));
     }
 #endif
@@ -491,8 +490,8 @@ copy_definition (void)
 static void
 parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 {
-  token_t token = 0;
-  char *typename = 0;
+  token_t token = tok_undef;
+  char *typename = NULL;
 
   /* The symbol being defined.  */
   struct bucket *symbol = NULL;
@@ -541,7 +540,6 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	      /* symbol and symval combined are only one symbol */
 	      nsyms--;
 	    }
-	  translations = 1;
  	  symbol = NULL;
 	}
       else if (token == tok_identifier)
@@ -566,7 +564,6 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
       else if (symbol && token == tok_number)
 	{
 	  symbol->user_token_number = numval;
-	  translations = 1;
 	}
       else
 	{
@@ -708,7 +705,6 @@ parse_assoc_decl (associativity assoc)
 	  if (prev == tok_identifier)
 	    {
 	      symval->user_token_number = numval;
-	      translations = 1;
 	    }
 	  else
 	    {
@@ -754,7 +750,7 @@ parse_union_decl (void)
 
   if (no_lines_flag)
     obstack_1grow (&attrs_obstack, '\n');
-  
+
   obstack_init (&union_obstack);
   obstack_sgrow (&union_obstack, "union");
   if (defines_flag)
@@ -764,9 +760,13 @@ parse_union_decl (void)
 
   while (c != EOF)
     {
-      obstack_1grow (&union_obstack, c);
-      if (defines_flag)
-	obstack_1grow (&defines_obstack, c);
+      /* If C contains '/', it is output by copy_comment ().  */
+      if (c != '/')
+	{
+	  obstack_1grow (&attrs_obstack, c);
+	  if (defines_flag)
+	    obstack_1grow (&defines_obstack, c);
+	}
 
       switch (c)
 	{
@@ -852,7 +852,6 @@ parse_thong_decl (void)
   char *typename = 0;
   int usrtoknum;
 
-  translations = 1;
   token = lex ();		/* fetch typename or first token */
   if (token == tok_typename)
     {
@@ -904,8 +903,6 @@ parse_thong_decl (void)
   nsyms--;
 }
 
-/* FIXME. */
-
 static void
 parse_muscle_decl (void)
 {
@@ -923,7 +920,7 @@ parse_muscle_decl (void)
   copy_identifier (finput, &muscle_obstack);
   obstack_1grow (&muscle_obstack, 0);
   muscle_key = obstack_finish (&muscle_obstack);
-  
+
   /* Read value. */
   ch = skip_white_space ();
   if (ch != '"')
@@ -957,36 +954,6 @@ parse_skel_decl (void)
   /* Complete with parse_dquoted_param () on the CVS branch 1.29.  */
 }
 
-/*------------------------------------------.
-| Parse what comes after %header_extension. |
-`------------------------------------------*/
-
-static void
-parse_header_extension_decl (void)
-{
-  char buff[32];
-
-  if (header_extension)
-    complain (_("multiple %%header_extension declarations"));
-  fscanf (finput, "%s", buff);
-  header_extension = xstrdup (buff);
-}
-
-/*------------------------------------------.
-| Parse what comes after %source_extension. |
-`------------------------------------------*/
-
-static void
-parse_source_extension_decl (void)
-{
-  char buff[32];
-
-  if (src_extension)
-    complain (_("multiple %%source_extension declarations"));
-  fscanf (finput, "%s", buff);
-  src_extension = xstrdup (buff);
-}
-
 /*----------------------------------------------------------------.
 | Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
 | any `%' declarations, and copy the contents of any `%{ ... %}'  |
@@ -1056,18 +1023,10 @@ read_declarations (void)
 	      parse_assoc_decl (non_assoc);
 	      break;
 
-	    case tok_hdrext:
-	      parse_header_extension_decl ();
-	      break;
-
-	    case tok_srcext:
-	      parse_source_extension_decl ();
-	      break;
-
 	    case tok_define:
 	      parse_muscle_decl ();
 	      break;
-	      
+
 	    case tok_skel:
 	      parse_skel_decl ();
 	      break;
@@ -1115,7 +1074,7 @@ copy_action (symbol_list *rule, int stack_offset)
   if (!no_lines_flag)
     {
       obstack_fgrow2 (&action_obstack, muscle_find ("linef"),
-		      lineno, quotearg_style (c_quoting_style, 
+		      lineno, quotearg_style (c_quoting_style,
 					      muscle_find ("filename")));
     }
   obstack_1grow (&action_obstack, '{');
@@ -1678,12 +1637,12 @@ read_additionnal_code (void)
 {
   char c;
   struct obstack el_obstack;
-  
+
   obstack_init (&el_obstack);
 
   while ((c = getc (finput)) != EOF)
     obstack_1grow (&el_obstack, c);
-  
+
   obstack_1grow (&el_obstack, 0);
   muscle_insert ("epilogue", obstack_finish (&el_obstack));
 }
@@ -1729,9 +1688,10 @@ output_token_defines (struct obstack *oout)
 	continue;
 
       obstack_fgrow2 (oout, "# define\t%s\t%d\n",
-		      symbol,
-		      (translations ? bp->user_token_number : bp->value));
+		      symbol, bp->user_token_number);
       if (semantic_parser)
+	/* FIXME: This is certainly dead wrong, and should be just as
+	   above. --akim.  */
 	obstack_fgrow2 (oout, "# define\tT%s\t%d\n", symbol, bp->value);
     }
 }
@@ -1746,9 +1706,9 @@ output_token_defines (struct obstack *oout)
 static void
 packsymbols (void)
 {
-  bucket *bp;
+  bucket *bp = NULL;
   int tokno = 1;
-  int i;
+  int i, j;
   int last_user_token_number;
   static char DOLLAR[] = "$";
 
@@ -1812,7 +1772,7 @@ packsymbols (void)
 
       if (bp->class == token_sym)
 	{
-	  if (translations && !(bp->user_token_number))
+	  if (!bp->user_token_number)
 	    bp->user_token_number = ++last_user_token_number;
 	  if (bp->user_token_number > max_user_token_number)
 	    max_user_token_number = bp->user_token_number;
@@ -1822,40 +1782,39 @@ packsymbols (void)
       user_toknums[bp->value] = bp->user_token_number;
       sprec[bp->value] = bp->prec;
       sassoc[bp->value] = bp->assoc;
-
     }
 
-  if (translations)
-    {
-      int j;
+  token_translations = XCALLOC (short, max_user_token_number + 1);
 
-      token_translations = XCALLOC (short, max_user_token_number + 1);
+  /* initialize all entries for literal tokens to 2, the internal
+     token number for $undefined., which represents all invalid
+     inputs.  */
+  for (j = 0; j <= max_user_token_number; j++)
+    token_translations[j] = 2;
 
-      /* initialize all entries for literal tokens to 2, the internal
-         token number for $undefined., which represents all invalid
-         inputs.  */
-      for (j = 0; j <= max_user_token_number; j++)
-	token_translations[j] = 2;
-
-      for (bp = firstsymbol; bp; bp = bp->next)
-	{
-	  if (bp->value >= ntokens)
-	    continue;		/* non-terminal */
-	  if (bp->user_token_number == SALIAS)
-	    continue;
-	  if (token_translations[bp->user_token_number] != 2)
-	    complain (_("tokens %s and %s both assigned number %d"),
-		      tags[token_translations[bp->user_token_number]],
-		      bp->tag, bp->user_token_number);
-	  token_translations[bp->user_token_number] = bp->value;
-	}
+  for (bp = firstsymbol; bp; bp = bp->next)
+    {
+      if (bp->value >= ntokens)
+	continue;		/* non-terminal */
+      if (bp->user_token_number == SALIAS)
+	continue;
+      if (token_translations[bp->user_token_number] != 2)
+	complain (_("tokens %s and %s both assigned number %d"),
+		  tags[token_translations[bp->user_token_number]],
+		  bp->tag, bp->user_token_number);
+      token_translations[bp->user_token_number] = bp->value;
     }
 
   error_token_number = errtoken->value;
 
-  output_token_defines (&output_obstack);
-  obstack_1grow (&output_obstack, 0);
-  muscle_insert ("tokendef", obstack_finish (&output_obstack));
+  {
+    struct obstack tokendefs;
+    obstack_init (&tokendefs);
+    output_token_defines (&tokendefs);
+    obstack_1grow (&tokendefs, 0);
+    muscle_insert ("tokendef", xstrdup (obstack_finish (&tokendefs)));
+    obstack_free (&tokendefs, NULL);
+  }
 
 #if 0
   if (!no_parser_flag)
@@ -1980,15 +1939,6 @@ reader (void)
   start_flag = 0;
   startval = NULL;		/* start symbol not specified yet. */
 
-#if 0
-  /* initially assume token number translation not needed.  */
-  translations = 0;
-#endif
-  /* Nowadays translations is always set to 1, since we give `error' a
-     user-token-number to satisfy the Posix demand for YYERRCODE==256.
-   */
-  translations = 1;
-
   nsyms = 1;
   nvars = 0;
   nrules = 0;
@@ -2004,7 +1954,7 @@ reader (void)
 
   grammar = NULL;
 
-  init_lex ();
+  lex_init ();
   lineno = 1;
 
   /* Initialize the muscle obstack.  */
@@ -2043,7 +1993,4 @@ reader (void)
   packsymbols ();
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
-  /* Free the symbol table data structure since symbols are now all
-     referred to by symbol number.  */
-  free_symtab ();
 }
