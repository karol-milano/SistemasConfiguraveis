@@ -103,11 +103,10 @@
 #include "lalr.h"
 #include "reader.h"
 #include "conflicts.h"
+#include "macrotab.h"
 
 extern void berror PARAMS((const char *));
 
-
-
 static int nvectors;
 static int nentries;
 static short **froms;
@@ -124,211 +123,54 @@ static short *check;
 static int lowzero;
 static int high;
 
+struct obstack macro_obstack;
+struct obstack output_obstack;
 
+/* FIXME. */
 
 static inline void
-output_short_or_char_table (struct obstack *oout,
-			    const char *comment,
-			    const char *type,
-			    const char *table_name,
-			    short *short_table,
-			    short first_value,
-			    short begin, short end)
+output_table_data (struct obstack* oout, 
+		   short* table, 
+		   short first, 
+		   short begin, 
+		   short end)
 {
-  int i, j;
-
-  if (comment)
-    obstack_fgrow1 (oout, "/* %s. */\n", comment);
-
-  obstack_fgrow3 (oout, "static const %s %s[] =\n{\n  %6d",
-		  type, table_name, first_value);
-
-  j = 1;
-  for (i = begin; i < end; i++)
+  int i;
+  int j = 1;
+  
+  obstack_fgrow1 (oout, "%6d", first);
+  for (i = begin; i < end; ++i)
     {
       obstack_1grow (oout, ',');
-
       if (j >= 10)
 	{
 	  obstack_sgrow (oout, "\n  ");
 	  j = 1;
 	}
       else
-	{
-	  j++;
-	}
-
-      obstack_fgrow1 (oout, "%6d", short_table[i]);
-    }
-
-  obstack_sgrow (oout, "\n};\n");
-}
-
-
-static inline void
-output_short_table (struct obstack *oout,
-		    const char *comment,
-		    const char *table_name,
-		    short *short_table,
-		    short first_value,
-		    short begin, short end)
-{
-  output_short_or_char_table (oout, comment, "short", table_name, short_table,
-			      first_value, begin, end);
-}
-
-
-/*--------------------------------------------------------------.
-| output_headers -- Output constant strings to the beginning of |
-| certain files.                                                |
-`--------------------------------------------------------------*/
-
-/* Don't put the `%s' insides quotes, since it quotearg puts them. */
-
-#define	GUARDSTR	\
-"\n\
-#include %s\n\
-extern int yyerror;\n\
-extern int yycost;\n\
-extern char * yymsg;\n\
-extern YYSTYPE yyval;\n\
-\n\
-yyguard(n, yyvsp, yylsp)\n\
-register int n;\n\
-register YYSTYPE *yyvsp;\n\
-register YYLTYPE *yylsp;\n\
-{\n\
-  yyerror = 0;\n\
-  yycost = 0;\n\
-  yymsg = 0;\n\
-  switch (n)\n\
-    {"
-
-#define	ACTSTR		\
-"\n\
-#include %s\n\
-extern YYSTYPE yyval;\n\
-extern int yychar;\n\
-\n\
-yyaction(n, yyvsp, yylsp)\n\
-register int n;\n\
-register YYSTYPE *yyvsp;\n\
-register YYLTYPE *yylsp;\n\
-{\n\
-  switch (n)\n\
-    {"
-
-#define	ACTSTR_SIMPLE	"\n  switch (yyn) {\n"
-
-void
-output_headers (void)
-{
-  char *attrsfile_quoted = 0;
-
-  if (semantic_parser)
-    {
-      /* FIXME: This is *buggy*.  ATTRSFILE is not computed yet, since
-	 we are waiting for the full input file to have been read to
-	 be sure of the output file name.  So basically, here, a SEGV
-	 is guaranteed.  OTOH, currently semantic parsers are not
-	 supported.  */
-      attrsfile_quoted = quotearg_style (c_quoting_style, attrsfile);
-      obstack_fgrow1 (&guard_obstack, GUARDSTR, attrsfile_quoted);
-    }
-
-  if (no_parser_flag)
-    return;
-
-  if (semantic_parser)
-    obstack_fgrow1 (&action_obstack, ACTSTR, attrsfile_quoted);
-  else
-    obstack_sgrow (&action_obstack, ACTSTR_SIMPLE);
-
-  /* Rename certain symbols if -p was specified.  */
-  if (spec_name_prefix)
-    {
-      obstack_fgrow1 (&table_obstack,
-		      "#define yyparse %sparse\n", spec_name_prefix);
-      obstack_fgrow1 (&table_obstack,
-		      "#define yylex %slex\n", spec_name_prefix);
-      obstack_fgrow1 (&table_obstack,
-		      "#define yyerror %serror\n", spec_name_prefix);
-      obstack_fgrow1 (&table_obstack,
-		      "#define yylval %slval\n", spec_name_prefix);
-      obstack_fgrow1 (&table_obstack,
-		      "#define yychar %schar\n", spec_name_prefix);
-      obstack_fgrow1 (&table_obstack,
-		      "#define yydebug %sdebug\n", spec_name_prefix);
-      obstack_fgrow1 (&table_obstack,
-		      "#define yynerrs %snerrs\n", spec_name_prefix);
+	++j;
+      obstack_fgrow1 (oout, "%6d", table[i]);
     }
+  obstack_1grow (oout, 0);
 }
 
 
-/*-------------------------------------------------------.
-| Output constant strings to the ends of certain files.  |
-`-------------------------------------------------------*/
-
-void
-output_trailers (void)
-{
-  if (semantic_parser)
-    obstack_sgrow (&guard_obstack, "\n    }\n}\n");
-
-  obstack_1grow (&action_obstack, '\n');
-
-  if (no_parser_flag)
-    return;
-
-  if (semantic_parser)
-    obstack_sgrow (&action_obstack, "    }\n");
-
-  obstack_sgrow (&action_obstack, "}\n");
-}
-
-
-
 static void
 output_token_translations (void)
 {
-  obstack_sgrow (&table_obstack, "\
-\n\
-/* YYTRANSLATE(YYLEX) -- Bison token number corresponding to YYLEX. */\n");
-
-  if (translations)
-    {
-      obstack_fgrow2 (&table_obstack,
-      "#define YYTRANSLATE(x) ((unsigned)(x) <= %d ? yytranslate[x] : %d)\
-\n\
-\n",
-	       max_user_token_number, nsyms);
-
-      output_short_or_char_table (&table_obstack,
-	     "YYTRANSLATE[YYLEX] -- Bison token number corresponding to YYLEX",
-		    ntokens < 127 ? "char" : "short",
-		    "yytranslate", token_translations,
-		    0, 1, max_user_token_number + 1);
-    }
-  else
-    {
-      obstack_sgrow (&table_obstack,
-			   "\n#define YYTRANSLATE(x) (x)\n");
-    }
+  output_table_data (&output_obstack, token_translations, 
+		     0, 1, max_user_token_number + 1);
+  macro_insert ("translate", obstack_finish (&output_obstack));
 }
 
 
 static void
 output_gram (void)
 {
-  /* With the ordinary parser,
-     yyprhs and yyrhs are needed only for yydebug. */
-  /* With the no_parser option, all tables are generated */
-  if (!semantic_parser && !no_parser_flag)
-    obstack_sgrow (&table_obstack, "\n#if YYDEBUG != 0\n");
-
-  output_short_table (&table_obstack, NULL, "yyprhs", rrhs,
-		      0, 1, nrules + 1);
-
+  output_table_data (&output_obstack, rrhs, 
+		     0, 1, nrules + 1);
+  macro_insert ("prhs", obstack_finish (&output_obstack));
+  
   {
     size_t yyrhs_size = 1;
     short *yyrhs, *sp;
@@ -341,21 +183,24 @@ output_gram (void)
     for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
       yyrhs[i] = *sp > 0 ? *sp : 0;
 
-    output_short_table (&table_obstack, NULL, "yyrhs", yyrhs,
-			ritem[0], 1, yyrhs_size);
+    output_table_data (&output_obstack, yyrhs, 
+		       ritem[0], 1, yyrhs_size);
+    macro_insert ("rhs", obstack_finish (&output_obstack));
+
     XFREE (yyrhs);
   }
 
-  if (!semantic_parser && !no_parser_flag)
-    obstack_sgrow (&table_obstack, "\n#endif\n");
+  /* if (!semantic_parser && !no_parser_flag)
+     obstack_sgrow (&table_obstack, "\n#endif\n"); */
 }
 
 
 static void
 output_stos (void)
 {
-  output_short_table (&table_obstack, NULL, "yystos", accessing_symbol,
-		      0, 1, nstates);
+  output_table_data (&output_obstack, accessing_symbol, 
+		     0, 1, nstates);
+  macro_insert ("stos", obstack_finish (&output_obstack));
 }
 
 
@@ -366,34 +211,9 @@ output_rule_data (void)
   int j;
   short *short_tab = NULL;
 
-  obstack_sgrow (&table_obstack, "\n\
-#if YYDEBUG != 0\n");
-
-  output_short_table (&table_obstack,
-           "YYRLINE[YYN] -- source line where rule number YYN was defined",
-		      "yyrline", rline,
-		      0, 1, nrules + 1);
-
-  obstack_sgrow (&table_obstack, "#endif\n\n");
-
-  if (token_table_flag || no_parser_flag)
-    {
-      obstack_fgrow1 (&table_obstack, "#define YYNTOKENS %d\n", ntokens);
-      obstack_fgrow1 (&table_obstack, "#define YYNNTS %d\n", nvars);
-      obstack_fgrow1 (&table_obstack, "#define YYNRULES %d\n", nrules);
-      obstack_fgrow1 (&table_obstack, "#define YYNSTATES %d\n", nstates);
-      obstack_fgrow1 (&table_obstack, "#define YYMAXUTOK %d\n\n",
-		      max_user_token_number);
-    }
-
-  /* Output the table of symbol names.  */
-  if (!token_table_flag && !no_parser_flag)
-    obstack_sgrow (&table_obstack,
-			 "\n#if YYDEBUG != 0 || defined YYERROR_VERBOSE\n\n");
-  obstack_sgrow (&table_obstack, "\
-/* YYTNAME[TOKEN_NUM] -- String name of the token TOKEN_NUM. */\n");
-  obstack_sgrow (&table_obstack,
-	   "static const char *const yytname[] =\n{\n  ");
+  output_table_data (&output_obstack, rline,
+		     0, 1, nrules + 1);
+  macro_insert ("rline", obstack_finish (&output_obstack));
 
   j = 0;
   for (i = 0; i < nsyms; i++)
@@ -416,80 +236,61 @@ output_rule_data (void)
 
       if (j + strsize > 75)
 	{
-	  obstack_sgrow (&table_obstack, "\n  ");
+	  obstack_sgrow (&output_obstack, "\n  ");
 	  j = 2;
 	}
 
-      obstack_1grow (&table_obstack, '\"');
+      obstack_1grow (&output_obstack, '\"');
       for (p = tags[i]; p && *p; p++)
 	{
 	  if (*p == '"' || *p == '\\')
-	    obstack_fgrow1 (&table_obstack, "\\%c", *p);
+	    obstack_fgrow1 (&output_obstack, "\\%c", *p);
 	  else if (*p == '\n')
-	    obstack_sgrow (&table_obstack, "\\n");
+	    obstack_sgrow (&output_obstack, "\\n");
 	  else if (*p == '\t')
-	    obstack_sgrow (&table_obstack, "\\t");
+	    obstack_sgrow (&output_obstack, "\\t");
 	  else if (*p == '\b')
-	    obstack_sgrow (&table_obstack, "\\b");
+	    obstack_sgrow (&output_obstack, "\\b");
 	  else if (*p < 040 || *p >= 0177)
-	    obstack_fgrow1 (&table_obstack, "\\%03o", *p);
+	    obstack_fgrow1 (&output_obstack, "\\%03o", *p);
 	  else
-	    obstack_1grow (&table_obstack, *p);
+	    obstack_1grow (&output_obstack, *p);
 	}
 
-      obstack_sgrow (&table_obstack, "\", ");
+      obstack_sgrow (&output_obstack, "\", ");
       j += strsize;
     }
   /* add a NULL entry to list of tokens */
-  obstack_sgrow (&table_obstack, "NULL\n};\n");
+  obstack_sgrow (&output_obstack, "NULL");
 
-  if (!token_table_flag && !no_parser_flag)
-    obstack_sgrow (&table_obstack, "#endif\n\n");
+  /* Finish table and store. */
+  obstack_1grow (&output_obstack, 0);
+  macro_insert ("tname", obstack_finish (&output_obstack));
 
   /* Output YYTOKNUM. */
-  if (token_table_flag)
-    {
-      output_short_table (&table_obstack,
-		  "YYTOKNUM[YYLEX] -- Index in YYTNAME corresponding to YYLEX",
-			  "yytoknum", user_toknums,
-			  0, 1, ntokens + 1);
-    }
+  output_table_data (&output_obstack, user_toknums,
+		     0, 1, ntokens + 1);
+  macro_insert ("toknum", obstack_finish (&output_obstack));
 
   /* Output YYR1. */
-  output_short_table (&table_obstack,
-	      "YYR1[YYN] -- Symbol number of symbol that rule YYN derives",
-		      "yyr1", rlhs,
-		      0, 1, nrules + 1);
+  output_table_data (&output_obstack, rlhs, 
+		     0, 1, nrules + 1);
+  macro_insert ("r1", obstack_finish (&output_obstack));
   XFREE (rlhs + 1);
 
-  obstack_1grow (&table_obstack, '\n');
-
   /* Output YYR2. */
   short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
     short_tab[i] = rrhs[i + 1] - rrhs[i] - 1;
   short_tab[nrules] = nitems - rrhs[nrules] - 1;
-  output_short_table (&table_obstack,
-        "YYR2[YYN] -- Number of symbols composing right hand side of rule YYN",
-		      "yyr2", short_tab,
-		      0, 1, nrules + 1);
-  obstack_1grow (&table_obstack, '\n');
-
+  output_table_data (&output_obstack, short_tab, 
+		     0, 1, nrules + 1);
+  macro_insert ("r2", obstack_finish (&output_obstack));
   XFREE (short_tab);
 
   XFREE (rrhs + 1);
 }
 
-
-static void
-output_defines (void)
-{
-  obstack_fgrow1 (&table_obstack, "\n\n#define\tYYFINAL\t\t%d\n", final_state);
-  obstack_fgrow1 (&table_obstack, "#define\tYYFLAG\t\t%d\n", MINSHORT);
-  obstack_fgrow1 (&table_obstack, "#define\tYYNTBASE\t%d\n", ntokens);
-}
-
-
 /*------------------------------------------------------------------.
 | Decide what to do for each type of token if seen as the lookahead |
 | token in specified state.  The value returned is used as the      |
@@ -730,15 +531,12 @@ token_actions (void)
       yydefact[i] = action_row (i);
       save_row (i);
     }
-  XFREE (actrow);
 
-  output_short_table (&table_obstack,
-  "YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE\n\
-   doesn't specify something else to do.  Zero means the default is an\n\
-   error",
-		      "yydefact", yydefact,
-		      yydefact[0], 1, nstates);
-  obstack_1grow (&table_obstack, '\n');
+  output_table_data (&output_obstack, yydefact, 
+		     yydefact[0], 1, nstates);
+  macro_insert ("defact", obstack_finish (&output_obstack));
+  
+  XFREE (actrow);
   XFREE (yydefact);
 }
 
@@ -865,10 +663,9 @@ static void
 goto_actions (void)
 {
   int i;
-
   short *yydefgoto = XMALLOC (short, nsyms - ntokens);
-  state_count = XCALLOC (short, nstates);
 
+  state_count = XCALLOC (short, nstates);
   for (i = ntokens; i < nsyms; ++i)
     {
       int default_state = default_goto (i);
@@ -876,8 +673,9 @@ goto_actions (void)
       yydefgoto[i - ntokens] = default_state;
     }
 
-  output_short_table (&table_obstack, NULL, "yydefgoto", yydefgoto,
-		      yydefgoto[0], 1, nsyms - ntokens);
+  output_table_data (&output_obstack, yydefgoto, 
+		     yydefgoto[0], 1, nsyms - ntokens);
+  macro_insert ("defgoto", obstack_finish (&output_obstack));
 
   XFREE (state_count);
   XFREE (yydefgoto);
@@ -1079,13 +877,15 @@ pack_table (void)
 static void
 output_base (void)
 {
-  output_short_table (&table_obstack, NULL, "yypact", base,
-		      base[0], 1, nstates);
-
-  obstack_1grow (&table_obstack, '\n');
+  /* Output pact. */
+  output_table_data (&output_obstack, base, 
+		     base[0], 1, nstates);
+  macro_insert ("pact", obstack_finish (&output_obstack));
 
-  output_short_table (&table_obstack, NULL, "yypgoto", base,
-		      base[nstates], nstates + 1, nvectors);
+  /* Output pgoto. */
+  output_table_data (&output_obstack, base, 
+		     base[nstates], nstates + 1, nvectors);
+  macro_insert ("pgoto", obstack_finish (&output_obstack));
 
   XFREE (base);
 }
@@ -1094,9 +894,9 @@ output_base (void)
 static void
 output_table (void)
 {
-  obstack_fgrow1 (&table_obstack, "\n\n#define\tYYLAST\t\t%d\n\n\n", high);
-  output_short_table (&table_obstack, NULL, "yytable", table,
-		      table[0], 1, high + 1);
+  output_table_data (&output_obstack, table, 
+		     table[0], 1, high + 1);
+  macro_insert ("table", obstack_finish (&output_obstack));
   XFREE (table);
 }
 
@@ -1104,8 +904,9 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_short_table (&table_obstack, NULL, "yycheck", check,
-		      check[0], 1, high + 1);
+  output_table_data (&output_obstack, check, 
+		     check[0], 1, high + 1);
+  macro_insert ("check", obstack_finish (&output_obstack));
   XFREE (check);
 }
 
@@ -1137,10 +938,12 @@ output_actions (void)
 
   sort_actions ();
   pack_table ();
-  obstack_1grow (&table_obstack, '\n');
+  /* FIXME: See if this is useful. */
+  /* obstack_1grow (&table_obstack, '\n'); */
   output_base ();
   output_table ();
-  obstack_1grow (&table_obstack, '\n');
+  /* FIXME: See if this is useful. */
+  /* obstack_1grow (&table_obstack, '\n'); */
   output_check ();
 }
 
@@ -1156,9 +959,6 @@ output_parser (void)
   size_t line;
   int actions_dumped = 0;
 
-  if (pure_parser)
-    obstack_sgrow (&table_obstack, "#define YYPURE 1\n\n");
-
   /* Loop over lines in the standard parser file.  */
   if (!skeleton)
     {
@@ -1169,114 +969,49 @@ output_parser (void)
     }
   fskel = xfopen (skeleton, "r");
 
-  /* Set LINE to 2, not 1: `#line LINENUM' -- Here LINENUM is a
-     decimal integer constant.  This specifies that the line number of
-     the *following* line of input, in its original source file, was
-     LINENUM.  */
-  line = 2;
-
-  while (1)
+  /* New output code. */
+  line = 1;
+  c = getc (fskel);
+  while (c != EOF)
     {
-      enum line_type_e
+      if (c != '%')
 	{
-	  regular_line,
-	  sync_line,	/* #line. */
-	  actions_line	/* %% actions. */
-	};
-      enum line_type_e line_type = regular_line;
-
-      c = getc (fskel);
-
-      /* Is this line special? */
-      if (c == '#')
-	{
-	  /* See if it's a `#line' line. */
-	  if ((c = getc (fskel)) == 'l')
-	    if ((c = getc (fskel)) == 'i')
-	      if ((c = getc (fskel)) == 'n')
-		if ((c = getc (fskel)) == 'e')
-		  line_type = sync_line;
-		else
-		  obstack_sgrow (&table_obstack, "#lin");
-	      else
-		obstack_sgrow (&table_obstack, "#li");
-	    else
-	      obstack_sgrow (&table_obstack, "#l");
-	  else
-	    obstack_sgrow (&table_obstack, "#");
+	  if (c == '\n')
+	    ++line;
+	  obstack_1grow (&table_obstack, c);
+	  c = getc (fskel);
 	}
-      else if (c == '%')
+      else if ((c = getc (fskel)) == '%')
 	{
-	  /* See if it's a `%% actions' line. */
-	  if ((c = getc (fskel)) == '%')
-	    if ((c = getc (fskel)) == ' ')
-	      if ((c = getc (fskel)) == 'a')
-		if ((c = getc (fskel)) == 'c')
-		  if ((c = getc (fskel)) == 't')
-		    if ((c = getc (fskel)) == 'i')
-		      if ((c = getc (fskel)) == 'o')
-			if ((c = getc (fskel)) == 'n')
-			  if ((c = getc (fskel)) == 's')
-			    line_type = actions_line;
-			  else
-			    obstack_sgrow (&table_obstack, "%% action");
-			else
-			  obstack_sgrow (&table_obstack, "%% actio");
-		      else
-			obstack_sgrow (&table_obstack, "%% acti");
-		    else
-		      obstack_sgrow (&table_obstack, "%% act");
-		  else
-		    obstack_sgrow (&table_obstack, "%% ac");
-		else
-		  obstack_sgrow (&table_obstack, "%% a");
-	      else
-		obstack_sgrow (&table_obstack, "%% ");
-	    else
-	      obstack_sgrow (&table_obstack, "%%");
+	  /* Read the macro. */
+	  char* macro_key = 0;
+	  char* macro_value = 0;
+	  while (isalnum (c = getc (fskel)) || c == '_')
+	    obstack_1grow (&macro_obstack, c);
+	  obstack_1grow (&macro_obstack, 0);
+
+	  /* Output the right value, or see if it's something special. */
+	  macro_key = obstack_finish (&macro_obstack);
+	  macro_value = macro_find (macro_key);
+	  if (macro_value)
+	    obstack_sgrow (&table_obstack, macro_value);
+	  else if (!strcmp (macro_key, "line"))
+	    obstack_fgrow1 (&table_obstack, "%d", line + 1);
+	  else if (!strcmp (macro_key, "action"))
+	    {
+	      size_t size = obstack_object_size (&action_obstack);
+	      obstack_grow (&table_obstack, 
+			    obstack_finish (&action_obstack), size);
+	    }
 	  else
-	    obstack_sgrow (&table_obstack, "%");
-	}
-
-      switch (line_type)
-	{
-	case sync_line:
-	  if (!no_lines_flag)
-	    obstack_fgrow2 (&table_obstack, "#line %d %s\n",
-			    line, quotearg_style (c_quoting_style, skeleton));
-
-	  /* Skip the end of line. */
-	  for (; c != '\n' && c != EOF; c = getc (fskel))
-	    /* nothing */;
-	  break;
-
-	case actions_line:
-	  {
-	    size_t size = obstack_object_size (&action_obstack);
-
-	    actions_dumped++;
-	    assert (actions_dumped == 1);
-	    obstack_grow (&table_obstack,
-			  obstack_finish (&action_obstack),
-			  size);
-	  }
-
-	  /* Skip the end of line. */
-	  for (; c != '\n' && c != EOF; c = getc (fskel))
-	    /* nothing */;
-	  break;
-
-	case regular_line:
-	  for (; c != '\n' && c != EOF; c = getc (fskel))
-	    obstack_1grow (&table_obstack, c);
+	    {
+	      obstack_sgrow (&table_obstack, "%%");
+	      obstack_sgrow (&table_obstack, macro_key);
+	    }
 	}
-
-      if (c == EOF)
-	break;
-      obstack_1grow (&table_obstack, c);
-      line++;
     }
-  assert (actions_dumped == 1);
+
+  /* End. */
   xfclose (fskel);
 }
 
@@ -1285,10 +1020,6 @@ output_program (void)
 {
   int c;
 
-  if (!no_lines_flag)
-    obstack_fgrow2 (&table_obstack, "#line %d %s\n",
-		    lineno, quotearg_style (c_quoting_style, infile));
-
   while ((c = getc (finput)) != EOF)
     obstack_1grow (&table_obstack, c);
 }
@@ -1308,6 +1039,60 @@ free_itemsets (void)
     }
 }
 
+/* FIXME. */
+
+#define MACRO_INSERT_INT(Key, Value)			\
+{							\
+  obstack_fgrow1 (&macro_obstack, "%d", Value);		\
+  obstack_1grow (&macro_obstack, 0);			\
+  macro_insert (Key, obstack_finish (&macro_obstack));	\
+}
+
+#define MACRO_INSERT_STRING(Key, Value)			\
+{							\
+  obstack_sgrow (&macro_obstack, Value);		\
+  obstack_1grow (&macro_obstack, 0);			\
+  macro_insert (Key, obstack_finish (&macro_obstack));	\
+}
+
+#define MACRO_INSERT_PREFIX(Key, Value)					\
+{									\
+  obstack_fgrow2 (&macro_obstack, "%s%s", spec_name_prefix, Value);	\
+  obstack_1grow (&macro_obstack, 0);					\
+  macro_insert (Key, obstack_finish (&macro_obstack));			\
+}
+
+static void
+prepare (void)
+{
+  MACRO_INSERT_INT ("last", high);
+  MACRO_INSERT_INT ("flag", MINSHORT);
+  MACRO_INSERT_INT ("pure", pure_parser);
+  MACRO_INSERT_INT ("nsym", nsyms);
+  MACRO_INSERT_INT ("debug", debug_flag);
+  MACRO_INSERT_INT ("final", final_state);
+  MACRO_INSERT_INT ("maxtok", max_user_token_number);
+  MACRO_INSERT_INT ("ntbase", ntokens);
+  MACRO_INSERT_INT ("verbose", 0);
+
+  MACRO_INSERT_STRING ("filename", infile);
+
+  MACRO_INSERT_INT ("nnts", nvars);
+  MACRO_INSERT_INT ("nrules", nrules);
+  MACRO_INSERT_INT ("nstates", nstates);
+  MACRO_INSERT_INT ("ntokens", ntokens);
+
+  if (spec_name_prefix)
+    {
+      MACRO_INSERT_PREFIX ("yylex", "lex");
+      MACRO_INSERT_PREFIX ("yychar", "char");
+      MACRO_INSERT_PREFIX ("yylval", "lval");
+      MACRO_INSERT_PREFIX ("yydebug", "debug");
+      MACRO_INSERT_PREFIX ("yyerror", "error");
+      MACRO_INSERT_PREFIX ("yynerrs", "nerrs");
+      MACRO_INSERT_PREFIX ("yyparse", "parse");
+    }
+}
 
 /*----------------------------------------------------------.
 | Output the parsing tables and the parser code to ftable.  |
@@ -1316,8 +1101,10 @@ free_itemsets (void)
 void
 output (void)
 {
-  /* output_token_defines(ftable);      / * JF put out token defines FIRST */
+  obstack_init (&macro_obstack);
+  obstack_init (&output_obstack);
 
+#if 0
   /* If using a simple parser the definition of YYSTYPE are put into
      TABLE_OBSTACK.  */
   if (!semantic_parser)
@@ -1325,42 +1112,25 @@ output (void)
       size_t size = obstack_object_size (&attrs_obstack);
       obstack_grow (&table_obstack, obstack_finish (&attrs_obstack), size);
     }
-  reader_output_yylsp (&table_obstack);
-  if (debug_flag)
-    obstack_sgrow (&table_obstack, "\
-#ifndef YYDEBUG\n\
-# define YYDEBUG 1\n\
-#endif\n\
-\n");
-
-  if (semantic_parser)
-    obstack_fgrow1 (&table_obstack, "#include %s\n",
-		    quotearg_style (c_quoting_style, attrsfile));
-
-  if (!no_parser_flag)
-    obstack_sgrow (&table_obstack, "#include <stdio.h>\n\n");
-
-  /* Make "const" do nothing if not in ANSI C.  */
-  obstack_sgrow (&table_obstack, "\
-#ifndef __cplusplus\n\
-# ifndef __STDC__\n\
-#  define const\n\
-# endif\n\
-#endif\n\
-\n");
+#endif
 
+  /* reader_output_yylsp (&table_obstack); */
   free_itemsets ();
-  output_defines ();
+
   output_token_translations ();
-/*   if (semantic_parser) */
-  /* This is now unconditional because debugging printouts can use it.  */
   output_gram ();
+
   XFREE (ritem);
   if (semantic_parser)
     output_stos ();
   output_rule_data ();
   output_actions ();
-  if (!no_parser_flag)
-    output_parser ();
+
+  /* if (!no_parser_flag) */
+  prepare ();
+  output_parser ();
   output_program ();
+
+  obstack_free (&macro_obstack, 0);
+  obstack_free (&output_obstack, 0);
 }
