@@ -176,60 +176,127 @@ output_table_data (struct obstack *oout,
 }
 
 
+/*-----------------------------------------------------------------.
+| Prepare the muscles related to the tokens: translate, tname, and |
+| toknum.                                                          |
+`-----------------------------------------------------------------*/
+
 static void
-output_token_translations (void)
+prepare_tokens (void)
 {
   output_table_data (&format_obstack, token_translations,
 		     0, 1, max_user_token_number + 1);
   muscle_insert ("translate", obstack_finish (&format_obstack));
   XFREE (token_translations);
-}
 
+  {
+    int i;
+    int j = 0;
+    for (i = 0; i < nsyms; i++)
+      {
+	/* Be sure not to use twice the same quotearg slot. */
+	const char *cp =
+	  quotearg_n_style (1, c_quoting_style,
+			    quotearg_style (escape_quoting_style,
+					    symbols[i]->tag));
+	/* Width of the next token, including the two quotes, the coma
+	   and the space.  */
+	int strsize = strlen (cp) + 2;
+
+	if (j + strsize > 75)
+	  {
+	    obstack_sgrow (&format_obstack, "\n  ");
+	    j = 2;
+	  }
+
+	obstack_sgrow (&format_obstack, cp);
+	obstack_sgrow (&format_obstack, ", ");
+	j += strsize;
+      }
+    /* Add a NULL entry to list of tokens (well, 0, as NULL might not be
+       defined).  */
+    obstack_sgrow (&format_obstack, "0");
 
-static void
-output_gram (void)
-{
+    /* Finish table and store. */
+    obstack_1grow (&format_obstack, 0);
+    muscle_insert ("tname", obstack_finish (&format_obstack));
+  }
+
+    /* Output YYTOKNUM. */
   {
     int i;
-    short *values = XCALLOC (short, nrules + 1);
-    for (i = 1; i < nrules + 1; ++i)
-      values[i] = rules[i].rhs - ritem;
+    short *values = XCALLOC (short, ntokens + 1);
+    for (i = 0; i < ntokens + 1; ++i)
+      values[i] = symbols[i]->user_token_number;
     output_table_data (&format_obstack, values,
-		       0, 1, nrules + 1);
-    XFREE (values);
+		       0, 1, ntokens + 1);
+    muscle_insert ("toknum", obstack_finish (&format_obstack));
+    free (values);
   }
+}
 
+
+/*-------------------------------------------------------------.
+| Prepare the muscles related to the rules: rhs, prhs, r1, r2, |
+| rline.                                                       |
+`-------------------------------------------------------------*/
+
+static void
+prepare_rules (void)
+{
+  short *rhsp;
+  int r;
+  int i = 0;
+  short *rhs = XMALLOC (short, nritems);
+  short *prhs = XMALLOC (short, nrules + 1);
+  short *r1 = XMALLOC (short, nrules + 1);
+  short *r2 = XMALLOC (short, nrules + 1);
+  short *rline = XMALLOC (short, nrules + 1);
+
+  for (r = 1; r < nrules + 1; ++r)
+    {
+      /* Index of rule R in RHS. */
+      prhs[r] = i;
+      /* RHS of the rule R. */
+      for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
+	rhs[i++] = *rhsp;
+      /* LHS of the rule R. */
+      r1[r] = rules[r].lhs->number;
+      /* Length of rule R's RHS. */
+      r2[r] = i - prhs[r];
+      /* Separator in RHS. */
+      rhs[i++] = -1;
+      /* Line where rule was defined. */
+      rline[r] = rules[r].line;
+    }
+  assert (i == nritems);
+
+  output_table_data (&format_obstack, rhs, ritem[0], 1, nritems);
+  muscle_insert ("rhs", obstack_finish (&format_obstack));
+
+  output_table_data (&format_obstack, prhs, 0, 1, nrules + 1);
   muscle_insert ("prhs", obstack_finish (&format_obstack));
 
-  {
-    short *rhsp;
-    int r;
-    int i = 0;
-    short *yyrhs = XMALLOC (short, nritems);
+  output_table_data (&format_obstack, rline, 0, 1, nrules + 1);
+  muscle_insert ("rline", obstack_finish (&format_obstack));
 
-    for (r = 1; r < nrules + 1; ++r)
-      {
-	for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
-	  yyrhs[i++] = *rhsp;
-	yyrhs[i++] = -1;
-      }
-    assert (i == nritems);
-    output_table_data (&format_obstack, yyrhs,
-		       ritem[0], 1, nritems);
-    muscle_insert ("rhs", obstack_finish (&format_obstack));
+  output_table_data (&format_obstack, r1, 0, 1, nrules + 1);
+  muscle_insert ("r1", obstack_finish (&format_obstack));
 
-    XFREE (yyrhs);
-  }
+  output_table_data (&format_obstack, r2, 0, 1, nrules + 1);
+  muscle_insert ("r2", obstack_finish (&format_obstack));
 
-#if 0
-  if (!semantic_parser)
-    obstack_sgrow (&table_obstack, "\n#endif\n");
-#endif
+  free (rhs);
+  free (prhs);
+  free (r2);
 }
 
+/*--------------------------------------------.
+| Prepare the muscles related to the states.  |
+`--------------------------------------------*/
 
 static void
-output_stos (void)
+prepare_states (void)
 {
   size_t i;
   short *values = (short *) alloca (sizeof (short) * nstates);
@@ -241,87 +308,6 @@ output_stos (void)
 }
 
 
-static void
-output_rule_data (void)
-{
-  int i;
-  int j;
-  short *short_tab = NULL;
-
-  {
-    short *values = XCALLOC (short, nrules + 1);
-    for (i = 1; i < nrules + 1; ++i)
-      values[i] = rules[i].line;
-    output_table_data (&format_obstack, values,
-		       0, 1, nrules + 1);
-    muscle_insert ("rline", obstack_finish (&format_obstack));
-    XFREE (values);
-  }
-
-
-  j = 0;
-  for (i = 0; i < nsyms; i++)
-    {
-      /* Be sure not to use twice the same quotearg slot. */
-      const char *cp =
-	quotearg_n_style (1, c_quoting_style,
-			  quotearg_style (escape_quoting_style, symbols[i]->tag));
-      /* Width of the next token, including the two quotes, the coma
-	 and the space.  */
-      int strsize = strlen (cp) + 2;
-
-      if (j + strsize > 75)
-	{
-	  obstack_sgrow (&format_obstack, "\n  ");
-	  j = 2;
-	}
-
-      obstack_sgrow (&format_obstack, cp);
-      obstack_sgrow (&format_obstack, ", ");
-      j += strsize;
-    }
-  /* Add a NULL entry to list of tokens (well, 0, as NULL might not be
-     defined).  */
-  obstack_sgrow (&format_obstack, "0");
-
-  /* Finish table and store. */
-  obstack_1grow (&format_obstack, 0);
-  muscle_insert ("tname", obstack_finish (&format_obstack));
-
-  /* Output YYTOKNUM. */
-  {
-    short *values = XCALLOC (short, ntokens + 1);
-    for (i = 0; i < ntokens + 1; ++i)
-      values[i] = symbols[i]->user_token_number;
-    output_table_data (&format_obstack, values,
-		       0, 1, ntokens + 1);
-    muscle_insert ("toknum", obstack_finish (&format_obstack));
-    XFREE (values);
-  }
-
-
-  /* Output YYR1. */
-  {
-    short *values = XCALLOC (short, nrules + 1);
-    for (i = 1; i < nrules + 1; ++i)
-      values[i] = rules[i].lhs->number;
-    output_table_data (&format_obstack, values,
-		       0, 1, nrules + 1);
-    muscle_insert ("r1", obstack_finish (&format_obstack));
-    XFREE (values);
-  }
-
-  /* Output YYR2. */
-  short_tab = XMALLOC (short, nrules + 1);
-  for (i = 1; i < nrules; i++)
-    short_tab[i] = rules[i + 1].rhs - rules[i].rhs - 1;
-  short_tab[nrules] =  nritems - (rules[nrules].rhs - ritem) - 1;
-  output_table_data (&format_obstack, short_tab,
-		     0, 1, nrules + 1);
-  muscle_insert ("r2", obstack_finish (&format_obstack));
-  XFREE (short_tab);
-}
-
 /*------------------------------------------------------------------.
 | Decide what to do for each type of token if seen as the lookahead |
 | token in specified state.  The value returned is used as the      |
@@ -914,8 +900,10 @@ output_check (void)
   XFREE (check);
 }
 
-/* compute and output yydefact, yydefgoto, yypact, yypgoto, yytable
-   and yycheck.  */
+/*-----------------------------------------------------------------.
+| Compute and output yydefact, yydefgoto, yypact, yypgoto, yytable |
+| and yycheck.                                                     |
+`-----------------------------------------------------------------*/
 
 static void
 output_actions (void)
@@ -1087,12 +1075,9 @@ output (void)
 {
   obstack_init (&format_obstack);
 
-  output_token_translations ();
-  output_gram ();
-
-  if (semantic_parser)
-    output_stos ();
-  output_rule_data ();
+  prepare_tokens ();
+  prepare_rules ();
+  prepare_states ();
   output_actions ();
 
   prepare ();
