@@ -27,7 +27,6 @@
 #include "files.h"
 #include "symtab.h"
 #include "options.h"
-#include "lex.h"
 #include "gram.h"
 #include "complain.h"
 #include "output.h"
@@ -35,28 +34,12 @@
 #include "conflicts.h"
 #include "muscle_tab.h"
 
-typedef struct symbol_list
-{
-  struct symbol_list *next;
-  symbol_t *sym;
-  int line;
-
-  /* The action is attached to the LHS of a rule. */
-  const char *action;
-  int action_line;
-
-  symbol_t *ruleprec;
-} symbol_list;
-
 int lineno;
 static symbol_list *grammar = NULL;
 static int start_flag = 0;
 
 /* Nonzero if %union has been seen.  */
-static int typed = 0;
-
-/* Incremented for each %left, %right or %nonassoc seen */
-static int lastprec = 0;
+int typed = 0;
 
 static symbol_list *
 symbol_list_new (symbol_t *sym)
@@ -71,61 +54,13 @@ symbol_list_new (symbol_t *sym)
   return res;
 }
 
-/*===================\
-| Low level lexing.  |
-\===================*/
-
-static void
-skip_to_char (int target)
-{
-  int c;
-  if (target == '\n')
-    complain (_("   Skipping to next \\n"));
-  else
-    complain (_("   Skipping to next %c"), target);
-
-  do
-    c = skip_white_space ();
-  while (c != target && c != EOF);
-  if (c != EOF)
-    ungetc (c, finput);
-}
-
-
-/*---------------------------------------------------------.
-| Read a signed integer from STREAM and return its value.  |
-`---------------------------------------------------------*/
-
-static inline int
-read_signed_integer (FILE *stream)
-{
-  int c = getc (stream);
-  int sign = 1;
-  int n = 0;
-
-  if (c == '-')
-    {
-      c = getc (stream);
-      sign = -1;
-    }
-
-  while (isdigit (c))
-    {
-      n = 10 * n + (c - '0');
-      c = getc (stream);
-    }
-
-  ungetc (c, stream);
-
-  return sign * n;
-}
 
 /*--------------------------------------------------------------.
 | Get the data type (alternative in the union) of the value for |
 | symbol N in rule RULE.                                        |
 `--------------------------------------------------------------*/
 
-static char *
+char *
 get_type_name (int n, symbol_list *rule)
 {
   int i;
@@ -153,885 +88,69 @@ get_type_name (int n, symbol_list *rule)
 
   return rp->sym->type_name;
 }
-
-/*------------------------------------------------------------------.
-| Copy the character C to OOUT, and insert quadigraphs when needed. |
-`------------------------------------------------------------------*/
-
-static inline void
-copy_character (struct obstack *oout, int c)
-{
-  switch (c)
-    {
-    case '[':
-      obstack_sgrow (oout, "@<:@");
-      break;
-
-    case ']':
-      obstack_sgrow (oout, "@:>@");
-      break;
-
-    default:
-      obstack_1grow (oout, c);
-    }
-}
-
-/*------------------------------------------------------------.
-| Dump the string from FIN to OOUT if non null.  MATCH is the |
-| delimiter of the string (either ' or ").                    |
-`------------------------------------------------------------*/
-
-static inline void
-copy_string2 (FILE *fin, struct obstack *oout, int match, int store)
-{
-  int c;
-
-  if (store)
-    obstack_1grow (oout, match);
-
-  c = getc (fin);
-
-  while (c != match)
-    {
-      if (c == EOF)
-	fatal (_("unterminated string at end of file"));
-      if (c == '\n')
-	{
-	  complain (_("unterminated string"));
-	  ungetc (c, fin);
-	  c = match;		/* invent terminator */
-	  continue;
-	}
-
-      copy_character (oout, c);
-
-      if (c == '\\')
-	{
-	  c = getc (fin);
-	  if (c == EOF)
-	    fatal (_("unterminated string at end of file"));
-	  copy_character (oout, c);
-
-	  if (c == '\n')
-	    ++lineno;
-	}
-
-      c = getc (fin);
-    }
-
-  if (store)
-    obstack_1grow (oout, c);
-}
-
-/* FIXME. */
-
-static inline void
-copy_string (FILE *fin, struct obstack *oout, int match)
-{
-  copy_string2 (fin, oout, match, 1);
-}
-
-/* FIXME. */
-
-static inline void
-copy_identifier (FILE *fin, struct obstack *oout)
-{
-  int c;
-
-  while (isalnum (c = getc (fin)) || c == '_')
-    obstack_1grow (oout, c);
-
-  ungetc (c, fin);
-}
-
-
-/*------------------------------------------------------------------.
-| Dump the wannabee comment from IN to OOUT.  In fact we just saw a |
-| `/', which might or might not be a comment.  In any case, copy    |
-| what we saw.                                                      |
-`------------------------------------------------------------------*/
-
-static inline void
-copy_comment (FILE *fin, struct obstack *oout)
-{
-  int cplus_comment;
-  int ended;
-  int c;
-
-  /* We read a `/', output it. */
-  obstack_1grow (oout, '/');
-
-  switch ((c = getc (fin)))
-    {
-    case '/':
-      cplus_comment = 1;
-      break;
-    case '*':
-      cplus_comment = 0;
-      break;
-    default:
-      ungetc (c, fin);
-      return;
-    }
-
-  obstack_1grow (oout, c);
-  c = getc (fin);
-
-  ended = 0;
-  while (!ended)
-    {
-      if (!cplus_comment && c == '*')
-	{
-	  while (c == '*')
-	    {
-	      obstack_1grow (oout, c);
-	      c = getc (fin);
-	    }
-
-	  if (c == '/')
-	    {
-	      obstack_1grow (oout, c);
-	      ended = 1;
-	    }
-	}
-      else if (c == '\n')
-	{
-	  ++lineno;
-	  obstack_1grow (oout, c);
-	  if (cplus_comment)
-	    ended = 1;
-	  else
-	    c = getc (fin);
-	}
-      else if (c == EOF)
-	fatal (_("unterminated comment"));
-      else
-	{
-	  copy_character (oout, c);
-	  c = getc (fin);
-	}
-    }
-}
-
-
-/*-------------------------------------------------------------------.
-| FIN is pointing to a location (i.e., a `@').  Output to OOUT a     |
-| reference to this location. RULE_LENGTH is the number of values in |
-| the current rule so far, which says where to find `$0' with        |
-| respect to the top of the stack.                                   |
-`-------------------------------------------------------------------*/
-
-static inline void
-copy_at (FILE *fin, struct obstack *oout, int rule_length)
-{
-  int c = getc (fin);
-  locations_flag = 1;
-
-  if (c == '$')
-    {
-      obstack_sgrow (oout, "]b4_lhs_location[");
-    }
-  else if (isdigit (c) || c == '-')
-    {
-      int n;
-
-      ungetc (c, fin);
-      n = read_signed_integer (fin);
-      if (n > rule_length)
-	complain (_("invalid value: %s%d"), "@", n);
-      else
-	obstack_fgrow2 (oout, "]b4_rhs_location([%d], [%d])[",
-			rule_length, n);
-    }
-  else
-    {
-      char buf[] = "@c";
-      buf[1] = c;
-      complain (_("%s is invalid"), quote (buf));
-    }
-}
-
-
-/*------------------------------------------------------------------.
-| FIN is pointing to a wannabee semantic value (i.e., a `$').       |
-|                                                                   |
-| Possible inputs: $[<TYPENAME>]($|integer)                         |
-|                                                                   |
-| Output to OOUT a reference to this semantic value. RULE_LENGTH is |
-| the number of values in the current rule so far, which says where |
-| to find `$0' with respect to the top of the stack.                |
-`------------------------------------------------------------------*/
-
-static inline void
-copy_dollar (FILE *fin, struct obstack *oout,
-	     symbol_list *rule, int rule_length)
-{
-  int c = getc (fin);
-  const char *type_name = NULL;
-
-  /* Get the type name if explicit. */
-  if (c == '<')
-    {
-      read_type_name (fin);
-      type_name = token_buffer;
-      c = getc (fin);
-    }
-
-  if (c == '$')
-    {
-      if (!type_name)
-	type_name = get_type_name (0, rule);
-      if (!type_name && typed)
-	complain (_("$$ of `%s' has no declared type"),
-		  rule->sym->tag);
-      if (!type_name)
-	type_name = "";
-      obstack_fgrow1 (oout,
-		      "]b4_lhs_value([%s])[", type_name);
-    }
-  else if (isdigit (c) || c == '-')
-    {
-      int n;
-      ungetc (c, fin);
-      n = read_signed_integer (fin);
-
-      if (n > rule_length)
-	complain (_("invalid value: %s%d"), "$", n);
-      else
-	{
-	  if (!type_name && n > 0)
-	    type_name = get_type_name (n, rule);
-	  if (!type_name && typed)
-	    complain (_("$%d of `%s' has no declared type"),
-		      n, rule->sym->tag);
-	  if (!type_name)
-	    type_name = "";
-	  obstack_fgrow3 (oout, "]b4_rhs_value([%d], [%d], [%s])[",
-			  rule_length, n, type_name);
-	}
-    }
-  else
-    {
-      char buf[] = "$c";
-      buf[1] = c;
-      complain (_("%s is invalid"), quote (buf));
-    }
-}
-
-/*-------------------------------------------------------------------.
-| Copy the contents of a `%{ ... %}' into the definitions file.  The |
-| `%{' has already been read.  Return after reading the `%}'.        |
-`-------------------------------------------------------------------*/
-
-static void
-copy_definition (struct obstack *oout)
-{
-  int c;
-  /* -1 while reading a character if prev char was %. */
-  int after_percent;
-
-  if (!no_lines_flag)
-    {
-      obstack_fgrow2 (oout, muscle_find ("linef"),
-		      lineno, quotearg_style (c_quoting_style,
-					      muscle_find ("filename")));
-    }
-
-  after_percent = 0;
-
-  c = getc (finput);
-
-  for (;;)
-    {
-      switch (c)
-	{
-	case '\n':
-	  obstack_1grow (oout, c);
-	  ++lineno;
-	  break;
-
-	case '%':
-	  after_percent = -1;
-	  break;
 
-	case '\'':
-	case '"':
-	  copy_string (finput, oout, c);
-	  break;
 
-	case '/':
-	  copy_comment (finput, oout);
-	  break;
+/*-----------------------.
+| Set the start symbol.  |
+`-----------------------*/
 
-	case EOF:
-	  fatal ("%s", _("unterminated `%{' definition"));
-
-	default:
-	  copy_character (oout, c);
-	}
-
-      c = getc (finput);
-
-      if (after_percent)
-	{
-	  if (c == '}')
-	    return;
-	  obstack_1grow (oout, '%');
-	}
-      after_percent = 0;
-    }
-}
-
-
-/*------------------------------------------.
-| Parse what comes after %token or %nterm.  |
-`------------------------------------------*/
-
-static void
-parse_token_decl (symbol_class class)
-{
-  token_t token = tok_undef;
-  char *typename = NULL;
-
-  /* The symbol being defined.  */
-  symbol_t *symbol = NULL;
-
-  /* After `%token' and `%nterm', any number of symbols maybe be
-     defined.  */
-  for (;;)
-    {
-      int tmp_char = ungetc (skip_white_space (), finput);
-
-      /* `%' (for instance from `%token', or from `%%' etc.) is the
-	 only valid means to end this declaration.  */
-      if (tmp_char == '%')
-	return;
-      if (tmp_char == EOF)
-	fatal (_("Premature EOF after %s"), token_buffer);
-
-      token = lex ();
-      switch (token)
-	{
-	case tok_comma:
-	  symbol = NULL;
-	  break;
-
-	case tok_typename:
-	  typename = xstrdup (token_buffer);
-	  symbol = NULL;
-	  break;
-
-	case tok_identifier:
-	  if (*symval->tag == '\"' && symbol)
-	    {
-	      symbol_make_alias (symbol, symval, typename);
-	      symbol = NULL;
-	    }
-	  else
-	    {
-	      symbol = symval;
-	      symbol_class_set (symbol, class);
-	      if (typename)
-		symbol_type_set (symbol, typename);
-	    }
-	  break;
-
-	case tok_number:
-	  symbol_user_token_number_set (symbol, numval);
-	  break;
-
-	default:
-	  complain (_("`%s' is invalid in %s"),
-		    token_buffer,
-		    (class == token_sym) ? "%token" : "%nterm");
-	  skip_to_char ('%');
-	}
-    }
-
-}
-
-
-/*------------------------------.
-| Parse what comes after %start |
-`------------------------------*/
-
-static void
-parse_start_decl (void)
+void
+grammar_start_symbol_set (symbol_t *s)
 {
   if (start_flag)
     complain (_("multiple %s declarations"), "%start");
-  if (lex () != tok_identifier)
-    complain (_("invalid %s declaration"), "%start");
   else
     {
       start_flag = 1;
-      startsymbol = symval;
+      startsymbol = s;
     }
 }
 
-/*-----------------------------------------------------------.
-| read in a %type declaration and record its information for |
-| get_type_name to access                                    |
-`-----------------------------------------------------------*/
-
-static void
-parse_type_decl (void)
-{
-  char *name;
-
-  if (lex () != tok_typename)
-    {
-      complain ("%s", _("%type declaration has no <typename>"));
-      skip_to_char ('%');
-      return;
-    }
-
-  name = xstrdup (token_buffer);
-
-  for (;;)
-    {
-      token_t t;
-      int tmp_char = ungetc (skip_white_space (), finput);
-
-      if (tmp_char == '%')
-	return;
-      if (tmp_char == EOF)
-	fatal (_("Premature EOF after %s"), token_buffer);
-
-      t = lex ();
-
-      switch (t)
-	{
-	case tok_comma:
-	case tok_semicolon:
-	  break;
-
-	case tok_identifier:
-	  symbol_type_set (symval, name);
-	  break;
-
-	default:
-	  complain (_("invalid %%type declaration due to item: %s"),
-		    token_buffer);
-	  skip_to_char ('%');
-	}
-    }
-}
-
-
 
 /*----------------------------------------------------------------.
-| Read in a %left, %right or %nonassoc declaration and record its |
-| information.                                                    |
+| There are two prologues: one before %union, one after.  Augment |
+| the current one.                                                |
 `----------------------------------------------------------------*/
 
-static void
-parse_assoc_decl (associativity assoc)
-{
-  char *name = NULL;
-  int prev = 0;
-
-  /* Assign a new precedence level, never 0.  */
-  ++lastprec;
-
-  for (;;)
-    {
-      token_t t;
-      int tmp_char = ungetc (skip_white_space (), finput);
-
-      if (tmp_char == '%')
-	return;
-      if (tmp_char == EOF)
-	fatal (_("Premature EOF after %s"), token_buffer);
-
-      t = lex ();
-
-      switch (t)
-	{
-	case tok_typename:
-	  name = xstrdup (token_buffer);
-	  break;
-
-	case tok_comma:
-	  break;
-
-	case tok_identifier:
-	  symbol_class_set (symval, token_sym);
-	  symbol_precedence_set (symval, lastprec, assoc);
-	  if (name)
-	    symbol_type_set (symval, name);
-	  break;
-
-	case tok_number:
-	  if (prev == tok_identifier)
-	    {
-	      symbol_user_token_number_set (symval, numval);
-	    }
-	  else
-	    {
-	      complain
-		(_("invalid text (%s) - number should be after identifier"),
-		 token_buffer);
-	      skip_to_char ('%');
-	    }
-	  break;
-
-	case tok_semicolon:
-	  return;
-
-	default:
-	  complain (_("unexpected item: %s"), token_buffer);
-	  skip_to_char ('%');
-	}
-
-      prev = t;
-    }
-}
-
-
-
-/*--------------------------------------------------------------.
-| Copy the union declaration into the stype muscle		|
-| (and fdefines),  where it is made into the definition of	|
-| YYSTYPE, the type of elements of the parser value stack.	|
-`--------------------------------------------------------------*/
-
-static void
-parse_union_decl (void)
-{
-  int c;
-  int count = 0;
-  bool done = FALSE;
-  struct obstack union_obstack;
-  if (typed)
-    complain (_("multiple %s declarations"), "%union");
-
-  typed = 1;
-
-  MUSCLE_INSERT_INT ("stype_line", lineno);
-  obstack_init (&union_obstack);
-  obstack_sgrow (&union_obstack, "union");
-
-  while (!done)
-    {
-      c = xgetc (finput);
-
-      /* If C contains '/', it is output by copy_comment ().  */
-      if (c != '/')
-	obstack_1grow (&union_obstack, c);
-
-      switch (c)
-	{
-	case '\n':
-	  ++lineno;
-	  break;
-
-	case '/':
-	  copy_comment (finput, &union_obstack);
-	  break;
-
-	case '{':
-	  ++count;
-	  break;
-
-	case '}':
-	  /* FIXME: Errr.  How could this happen???. --akim */
-	  if (count == 0)
-	    complain (_("unmatched %s"), "`}'");
-	  count--;
-	  if (!count)
-	    done = TRUE;
-	  break;
-	}
-    }
-
-  /* JF don't choke on trailing semi */
-  c = skip_white_space ();
-  if (c != ';')
-    ungetc (c, finput);
-  obstack_1grow (&union_obstack, 0);
-  muscle_insert ("stype", obstack_finish (&union_obstack));
-}
-
-
-/*-------------------------------------------------------.
-| Parse the declaration %expect N which says to expect N |
-| shift-reduce conflicts.                                |
-`-------------------------------------------------------*/
-
-static void
-parse_expect_decl (void)
-{
-  int c = skip_white_space ();
-  ungetc (c, finput);
-
-  if (!isdigit (c))
-    complain (_("argument of %%expect is not an integer"));
-  else
-    expected_conflicts = read_signed_integer (finput);
-}
-
-
-static void
-parse_muscle_decl (void)
+void
+prologue_augment (const char *prologue, int location)
 {
-  int ch = ungetc (skip_white_space (), finput);
-  char *muscle_key;
-  char *muscle_value;
+  struct obstack *oout =
+    !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
-  /* Read key. */
-  if (!isalpha (ch) && ch != '_')
-    {
-      complain (_("invalid %s declaration"), "%define");
-      skip_to_char ('%');
-      return;
-    }
-  copy_identifier (finput, &muscle_obstack);
-  obstack_1grow (&muscle_obstack, 0);
-  muscle_key = obstack_finish (&muscle_obstack);
-
-  /* Read value. */
-  ch = skip_white_space ();
-  if (ch != '"')
+  if (!no_lines_flag)
     {
-      ungetc (ch, finput);
-      if (ch != EOF)
-	{
-	  complain (_("invalid %s declaration"), "%define");
-	  skip_to_char ('%');
-	  return;
-	}
-      else
-	fatal (_("Premature EOF after %s"), "\"");
+      obstack_fgrow2 (oout, muscle_find ("linef"),
+		      location, quotearg_style (c_quoting_style,
+						muscle_find ("filename")));
     }
-  copy_string2 (finput, &muscle_obstack, '"', 0);
-  obstack_1grow (&muscle_obstack, 0);
-  muscle_value = obstack_finish (&muscle_obstack);
-
-  /* Store the (key, value) pair in the environment. */
-  muscle_insert (muscle_key, muscle_value);
+  obstack_sgrow (oout, prologue);
 }
 
 
 
-/*---------------------------------.
-| Parse a double quoted parameter. |
-`---------------------------------*/
-
-static const char *
-parse_dquoted_param (const char *from)
-{
-  struct obstack param_obstack;
-  const char *param = NULL;
-  int c;
-
-  obstack_init (&param_obstack);
-  c = skip_white_space ();
-
-  if (c != '"')
-    {
-      complain (_("invalid %s declaration"), from);
-      ungetc (c, finput);
-      skip_to_char ('%');
-      return NULL;
-    }
-
-  while ((c = literalchar ()) != '"')
-    obstack_1grow (&param_obstack, c);
 
-  obstack_1grow (&param_obstack, '\0');
-  param = obstack_finish (&param_obstack);
+/*----------------------.
+| Handle the epilogue.  |
+`----------------------*/
 
-  if (c != '"' || strlen (param) == 0)
-    {
-      complain (_("invalid %s declaration"), from);
-      if (c != '"')
-	ungetc (c, finput);
-      skip_to_char ('%');
-      return NULL;
-    }
-
-  return param;
-}
-
-/*----------------------------------.
-| Parse what comes after %skeleton. |
-`----------------------------------*/
-
-static void
-parse_skel_decl (void)
+void
+epilogue_set (const char *epilogue, int location)
 {
-  skeleton = parse_dquoted_param ("%skeleton");
-}
-
-/*----------------------------------------------------------------.
-| Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
-| any `%' declarations, and copy the contents of any `%{ ... %}'  |
-| groups to PRE_PROLOGUE_OBSTACK or POST_PROLOGUE_OBSTACK.        |
-`----------------------------------------------------------------*/
+  struct obstack el_obstack;
+  obstack_init (&el_obstack);
 
-static void
-read_declarations (void)
-{
-  for (;;)
+  if (!no_lines_flag)
     {
-      int c = skip_white_space ();
-
-      if (c == '%')
-	{
-	  token_t tok = parse_percent_token ();
-
-	  switch (tok)
-	    {
-	    case tok_two_percents:
-	      return;
-
-	    case tok_percent_left_curly:
-              if (!typed)
-		copy_definition (&pre_prologue_obstack);
-	      else
-		copy_definition (&post_prologue_obstack);
-	      break;
-
-	    case tok_token:
-	      parse_token_decl (token_sym);
-	      break;
-
-	    case tok_nterm:
-	      parse_token_decl (nterm_sym);
-	      break;
-
-	    case tok_type:
-	      parse_type_decl ();
-	      break;
-
-	    case tok_start:
-	      parse_start_decl ();
-	      break;
-
-	    case tok_union:
-	      parse_union_decl ();
-	      break;
-
-	    case tok_expect:
-	      parse_expect_decl ();
-	      break;
-
-	    case tok_left:
-	      parse_assoc_decl (left_assoc);
-	      break;
-
-	    case tok_right:
-	      parse_assoc_decl (right_assoc);
-	      break;
-
-	    case tok_nonassoc:
-	      parse_assoc_decl (non_assoc);
-	      break;
-
-	    case tok_define:
-	      parse_muscle_decl ();
-	      break;
-
-	    case tok_skel:
-	      parse_skel_decl ();
-	      break;
-
-	    case tok_noop:
-	      break;
-
-	    case tok_stropt:
-	    case tok_intopt:
-	    case tok_obsolete:
-	      assert (0);
-	      break;
-
-	    case tok_illegal:
-	    default:
-	      complain (_("unrecognized: %s"), token_buffer);
-	      skip_to_char ('%');
-	    }
-	}
-      else if (c == EOF)
-	fatal (_("no input grammar"));
-      else
-	{
-	  char buf[] = "c";
-	  buf[0] = c;
-	  complain (_("unknown character: %s"), quote (buf));
-	  skip_to_char ('%');
-	}
+      obstack_fgrow2 (&el_obstack, muscle_find ("linef"),
+		      location, quotearg_style (c_quoting_style,
+						muscle_find ("filename")));
     }
+  obstack_sgrow (&el_obstack, epilogue);
+  obstack_1grow (&el_obstack, 0);
+  muscle_insert ("epilogue", obstack_finish (&el_obstack));
 }
-
-/*------------------------------------------------------------------.
-| Assuming that a `{' has just been seen, copy everything up to the |
-| matching `}' into ACTION_OBSTACK, and return a pointer to this    |
-| action.                                                           |
-`------------------------------------------------------------------*/
 
-static char *
-parse_action (symbol_list *rule)
-{
-  int count = 1;
-
-  /* RULE_LENGTH is the number of values in the current rule so far,
-     which says where to find `$0' with respect to the top of the
-     stack.  It is not the same as the rule->length in the case of mid
-     rule actions.  */
-  int rule_length = 0;
-  symbol_list *rhs;
-  for (rhs = rule->next; rhs; rhs = rhs->next)
-    ++rule_length;
-
-  while (count > 0)
-    {
-      int c;
-      while ((c = getc (finput)) != '}')
-	switch (c)
-	  {
-	  case '\n':
-	    copy_character (&action_obstack, c);
-	    ++lineno;
-	    break;
-
-	  case '{':
-	    copy_character (&action_obstack, c);
-	    ++count;
-	    break;
-
-	  case '\'':
-	  case '"':
-	    copy_string (finput, &action_obstack, c);
-	    break;
-
-	  case '/':
-	    copy_comment (finput, &action_obstack);
-	    break;
-
-	  case '$':
-	    copy_dollar (finput, &action_obstack, rule, rule_length);
-	    break;
-
-	  case '@':
-	    copy_at (finput, &action_obstack, rule_length);
-	    break;
-
-	  case EOF:
-	    fatal (_("unmatched %s"), "`{'");
-
-	  default:
-	    copy_character (&action_obstack, c);
-	  }
-
-      /* Above loop exits when C is '}'.  */
-      if (--count)
-	copy_character (&action_obstack, c);
-    }
-
-  obstack_1grow (&action_obstack, '\0');
-  return obstack_finish (&action_obstack);
-}
 
 
 
@@ -1050,8 +169,7 @@ gensym (void)
   symbol_t *sym;
 
   sprintf (buf, "@%d", ++gensym_count);
-  token_buffer = buf;
-  sym = getsym (token_buffer);
+  sym = getsym (buf);
   sym->class = nterm_sym;
   sym->number = nvars++;
   return sym;
@@ -1079,7 +197,7 @@ gensym (void)
 symbol_list *grammar_end = NULL;
 
 /* Append S to the GRAMMAR. */
-static void
+void
 grammar_symbol_append (symbol_t *s)
 {
   symbol_list *p = symbol_list_new (s);
@@ -1100,7 +218,7 @@ symbol_list *previous_rule = NULL;
 
 /* Create a new rule for LHS in to the GRAMMAR. */
 
-static void
+void
 grammar_rule_begin (symbol_t *lhs)
 {
   if (!start_flag)
@@ -1129,12 +247,56 @@ grammar_rule_begin (symbol_t *lhs)
     complain (_("rule given for %s, which is a token"), lhs->tag);
 }
 
+/* Check that the last rule (CURRENT_RULE) is properly defined.  For
+   instance, there should be no type clash on the default action.  */
+
+static void
+grammar_current_rule_check (void)
+{
+  symbol_t *lhs = current_rule->sym;
+  symbol_t *first_rhs = current_rule->next->sym;
+
+  /* If there is an action, then there is nothing we can do: the user
+     is allowed to shoot in her foot.  */
+  if (current_rule->action)
+    return;
+
+  /* If $$ is being set in default way, report if any type mismatch.
+     */
+  if (first_rhs)
+    {
+      const char *lhs_type = lhs->type_name       ? lhs->type_name       : "";
+      const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
+      if (strcmp (lhs_type, rhs_type))
+	complain (_("type clash (`%s' `%s') on default action"),
+		  lhs_type, rhs_type);
+    }
+  /* Warn if there is no default for $$ but we need one.  */
+  else
+    {
+      if (lhs->type_name)
+	complain (_("empty rule for typed nonterminal, and no action"));
+    }
+}
+
+
+/* End the currently being grown rule. */
+
+void
+grammar_rule_end (void)
+{
+  /* Put an empty link in the list to mark the end of this rule  */
+  grammar_symbol_append (NULL);
+  grammar_current_rule_check ();
+}
+
+
 /* The previous action turns out the be a mid-rule action.  Attach it
    to the current rule, i.e., create a dummy symbol, attach it this
    mid-rule action, and append this dummy nonterminal to the current
    rule.  */
 
-static void
+void
 grammar_midrule_action (void)
 {
   /* Since the action was written out with this rule's number, we must
@@ -1174,7 +336,7 @@ grammar_midrule_action (void)
 
 /* Set the precedence symbol of the current rule to PRECSYM. */
 
-static void
+void
 grammar_current_rule_prec_set (symbol_t *precsym)
 {
   if (current_rule->ruleprec)
@@ -1182,43 +344,10 @@ grammar_current_rule_prec_set (symbol_t *precsym)
   current_rule->ruleprec = precsym;
 }
 
-/* Check that the last rule (CURRENT_RULE) is properly defined.  For
-   instance, there should be no type clash on the default action.  */
-
-static void
-grammar_current_rule_check (void)
-{
-  symbol_t *lhs = current_rule->sym;
-  symbol_t *first_rhs = current_rule->next->sym;
-
-  /* If there is an action, then there is nothing we can do: the user
-     is allowed to shoot in her foot.  */
-  if (current_rule->action)
-    return;
-
-  /* If $$ is being set in default way, report if any type mismatch.
-     */
-  if (first_rhs)
-    {
-      const char *lhs_type = lhs->type_name       ? lhs->type_name       : "";
-      const char *rhs_type = first_rhs->type_name ? first_rhs->type_name : "";
-      if (strcmp (lhs_type, rhs_type))
-	complain (_("type clash (`%s' `%s') on default action"),
-		  lhs_type, rhs_type);
-    }
-  /* Warn if there is no default for $$ but we need one.  */
-  else
-    {
-      if (lhs->type_name)
-	complain (_("empty rule for typed nonterminal, and no action"));
-    }
-}
-
-
 /* Attach a SYMBOL to the current rule.  If needed, move the previous
    action as a mid-rule action.  */
 
-static void
+void
 grammar_current_rule_symbol_append (symbol_t *symbol)
 {
   if (current_rule->action)
@@ -1231,8 +360,8 @@ grammar_current_rule_symbol_append (symbol_t *symbol)
 /* Attach an ACTION to the current rule.  If needed, move the previous
    action as a mid-rule action.  */
 
-static void
-grammar_current_rule_action_append (char *action, int action_line)
+void
+grammar_current_rule_action_append (const char *action, int action_line)
 {
   if (current_rule->action)
     grammar_midrule_action ();
@@ -1240,171 +369,6 @@ grammar_current_rule_action_append (char *action, int action_line)
   current_rule->action_line = action_line;
 }
 
-
-
-static void
-readgram (void)
-{
-  token_t t;
-  symbol_t *lhs = NULL;
-
-  t = lex ();
-
-  while (t != tok_two_percents && t != tok_eof)
-    if (t == tok_identifier || t == tok_bar)
-      {
-	if (t == tok_identifier)
-	  {
-	    lhs = symval;
-
-	    t = lex ();
-	    if (t != tok_colon)
-	      {
-		complain (_("ill-formed rule: initial symbol not followed by colon"));
-		unlex (t);
-	      }
-	  }
-	if (nrules == 0 && t == tok_bar)
-	  {
-	    complain (_("grammar starts with vertical bar"));
-	    lhs = symval;	/* BOGUS: use a random symval */
-	  }
-
-	grammar_rule_begin (lhs);
-	/* read the rhs of the rule.  */
-
-	for (;;)
-	  {
-	    t = lex ();
-	    if (t == tok_prec)
-	      {
-		t = lex ();
-		grammar_current_rule_prec_set (symval);
-		t = lex ();
-	      }
-
-	    if (!(t == tok_identifier || t == tok_left_curly))
-	      break;
-
-	    /* If next token is an identifier, see if a colon follows it.
-	       If one does, exit this rule now.  */
-	    if (t == tok_identifier)
-	      {
-		symbol_t *ssave;
-		token_t t1;
-
-		ssave = symval;
-		t1 = lex ();
-		unlex (t1);
-		symval = ssave;
-		if (t1 == tok_colon)
-		  {
-		    warn (_("previous rule lacks an ending `;'"));
-		    break;
-		  }
-		/* Not followed by colon => process as part of this
-		   rule's rhs.  */
-	      }
-
-	    if (t == tok_identifier)
-	      {
-		grammar_current_rule_symbol_append (symval);
-	      }
-	    else		/* handle an action.  */
-	      {
-		int action_line = lineno;
-		char *action = parse_action (current_rule);
-		grammar_current_rule_action_append (action, action_line);
-	      }
-	  }			/* end of  read rhs of rule */
-
-	/* Put an empty link in the list to mark the end of this rule  */
-	grammar_symbol_append (NULL);
-
-	if (t == tok_prec)
-	  {
-	    t = lex ();
-	    grammar_current_rule_prec_set (symval);
-	    t = lex ();
-	  }
-
-	if (t == tok_left_curly)
-	  {
-	    int action_line = lineno;
-	    char *action = parse_action (current_rule);
-	    grammar_current_rule_action_append (action, action_line);
-	    t = lex ();
-	  }
-
-	grammar_current_rule_check ();
-
-	if (t == tok_two_percents || t == tok_eof)
-	  warn (_("previous rule lacks an ending `;'"));
-	if (t == tok_semicolon)
-	  t = lex ();
-      }
-    else
-      {
-	complain (_("invalid input: %s"), quote (token_buffer));
-	t = lex ();
-      }
-
-  /* grammar has been read.  Do some checking */
-
-  if (nrules == 0)
-    fatal (_("no rules in the input grammar"));
-
-  /* Report any undefined symbols and consider them nonterminals.  */
-  symbols_check_defined ();
-
-  /* Insert the initial rule, which line is that of the first rule
-     (not that of the start symbol):
-
-     axiom: %start EOF.  */
-  {
-    symbol_list *p = symbol_list_new (axiom);
-    p->line = grammar->line;
-    p->next = symbol_list_new (startsymbol);
-    p->next->next = symbol_list_new (eoftoken);
-    p->next->next->next = symbol_list_new (NULL);
-    p->next->next->next->next = grammar;
-    nrules += 1;
-    nritems += 3;
-    grammar = p;
-  }
-
-  if (nsyms > SHRT_MAX)
-    fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
-	   SHRT_MAX);
-
-  assert (nsyms == ntokens + nvars);
-}
-
-/* At the end of the grammar file, some C source code must
-   be stored. It is going to be associated to the epilogue
-   directive.  */
-static void
-read_additionnal_code (void)
-{
-  int c;
-  struct obstack el_obstack;
-
-  obstack_init (&el_obstack);
-
-  if (!no_lines_flag)
-    {
-      obstack_fgrow2 (&el_obstack, muscle_find ("linef"),
-		      lineno, quotearg_style (c_quoting_style,
-					      muscle_find ("filename")));
-    }
-
-  while ((c = getc (finput)) != EOF)
-    copy_character (&el_obstack, c);
-
-  obstack_1grow (&el_obstack, 0);
-  muscle_insert ("epilogue", obstack_finish (&el_obstack));
-}
-
 
 /*---------------------------------------------------------------.
 | Convert the rules into the representation using RRHS, RLHS and |
@@ -1481,7 +445,7 @@ packgram (void)
 void
 reader (void)
 {
-  lex_init ();
+  gram_control_t gram_control;
   lineno = 1;
 
   /* Initialize the muscle obstack.  */
@@ -1513,11 +477,18 @@ reader (void)
   obstack_init (&post_prologue_obstack);
 
   finput = xfopen (infile, "r");
+  gram_in = finput;
+
+  gram_debug = !!getenv ("parse");
+  gram__flex_debug = !!getenv ("scan");
+  gram_parse (&gram_control);
 
-  /* Read the declaration section.  Copy %{ ... %} groups to
-     TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
-     etc. found there.  */
-  read_declarations ();
+  /* Grammar has been read.  Do some checking */
+  if (nrules == 0)
+    fatal (_("no rules in the input grammar"));
+
+  /* Report any undefined symbols and consider them nonterminals.  */
+  symbols_check_defined ();
 
   /* If the user did not define her EOFTOKEN, do it now. */
   if (!eoftoken)
@@ -1529,13 +500,28 @@ reader (void)
       eoftoken->user_token_number = 0;
     }
 
-  /* Read in the grammar, build grammar in list form.  Write out
-     actions.  */
-  readgram ();
-  /* Some C code is given at the end of the grammar file. */
-  read_additionnal_code ();
+  /* Insert the initial rule, which line is that of the first rule
+     (not that of the start symbol):
+
+     axiom: %start EOF.  */
+  {
+    symbol_list *p = symbol_list_new (axiom);
+    p->line = grammar->line;
+    p->next = symbol_list_new (startsymbol);
+    p->next->next = symbol_list_new (eoftoken);
+    p->next->next->next = symbol_list_new (NULL);
+    p->next->next->next->next = grammar;
+    nrules += 1;
+    nritems += 3;
+    grammar = p;
+  }
+
+  if (nsyms > SHRT_MAX)
+    fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
+          SHRT_MAX);
+
+  assert (nsyms == ntokens + nvars);
 
-  lex_free ();
   xfclose (finput);
 
   /* Assign the symbols their symbol numbers.  Write #defines for the
