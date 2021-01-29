@@ -115,14 +115,21 @@ static int nvectors;
 static int nentries;
 static short **froms = NULL;
 static short **tos = NULL;
+static unsigned int **conflict_tos = NULL;
 static short *tally = NULL;
 static short *width = NULL;
 static short *actrow = NULL;
+static short *conflrow = NULL;
 static short *state_count = NULL;
 static short *order = NULL;
 static short *base = NULL;
 static short *pos = NULL;
 
+static unsigned int *conflict_table = NULL;
+static unsigned int *conflict_list = NULL;
+static int conflict_list_cnt;
+static int conflict_list_free;
+
 /* TABLE_SIZE is the allocated size of both TABLE and CHECK.
    We start with the original hard-coded value: SHRT_MAX
    (yes, not USHRT_MAX). */
@@ -157,6 +164,8 @@ table_grow (size_t desired)
 
   table = XREALLOC (table, short, table_size);
   check = XREALLOC (check, short, table_size);
+  if (glr_parser)
+    conflict_table = XREALLOC (conflict_table, unsigned int, table_size);
 
   for (/* Nothing. */; old_size < table_size; ++old_size)
     {
@@ -278,7 +287,7 @@ prepare_tokens (void)
 
 /*-------------------------------------------------------------.
 | Prepare the muscles related to the rules: rhs, prhs, r1, r2, |
-| rline.                                                       |
+| rline, dprec, merger                                         |
 `-------------------------------------------------------------*/
 
 static void
@@ -291,6 +300,8 @@ prepare_rules (void)
   unsigned int *rline = XMALLOC (unsigned int, nrules + 1);
   symbol_number_t *r1 = XMALLOC (symbol_number_t, nrules + 1);
   unsigned int *r2 = XMALLOC (unsigned int, nrules + 1);
+  short *dprec = XMALLOC (short, nrules + 1);
+  short *merger = XMALLOC (short, nrules + 1);
 
   for (r = 1; r < nrules + 1; ++r)
     {
@@ -308,6 +319,10 @@ prepare_rules (void)
       rhs[i++] = -1;
       /* Line where rule was defined. */
       rline[r] = rules[r].location.first_line;
+      /* Dynamic precedence (GLR) */
+      dprec[r] = rules[r].dprec;
+      /* Merger-function index (GLR) */
+      merger[r] = rules[r].merger;
     }
   assert (i == nritems);
 
@@ -316,12 +331,16 @@ prepare_rules (void)
   muscle_insert_unsigned_int_table ("rline", rline, 0, 1, nrules + 1);
   muscle_insert_symbol_number_table ("r1", r1, 0, 1, nrules + 1);
   muscle_insert_unsigned_int_table ("r2", r2, 0, 1, nrules + 1);
+  muscle_insert_short_table ("dprec", dprec, 0, 1, nrules + 1);
+  muscle_insert_short_table ("merger", merger, 0, 1, nrules + 1);
 
   free (rhs);
   free (prhs);
   free (rline);
   free (r1);
   free (r2);
+  free (dprec);
+  free (merger);
 }
 
 /*--------------------------------------------.
@@ -341,6 +360,50 @@ prepare_states (void)
 }
 
 
+/*-------------------------------------------------------------------.
+| For GLR parsers, for each conflicted token in STATE, as indicated  |
+| by non-zero entries in conflrow, create a list of possible 	     |
+| reductions that are alternatives to the shift or reduction	     |
+| currently recorded for that token in STATE.  Store the alternative |
+| reductions followed by a 0 in conflict_list, updating		     |
+| conflict_list_cnt, and storing an index to the start of the list   |
+| back into conflrow.						     |
+`-------------------------------------------------------------------*/
+
+static void
+conflict_row (state_t *state)
+{
+  int i, j;
+
+  if (! glr_parser)
+    return;
+
+  for (j = 0; j < ntokens; j += 1) 
+    if (conflrow[j]) 
+      {
+	conflrow[j] = conflict_list_cnt;
+
+	/* find all reductions for token j, and record all that do
+	 * not match actrow[j] */
+	for (i = 0; i < state->nlookaheads; i += 1)
+	  if (bitset_test (state->lookaheads[i], j)
+	      && actrow[j] != -state->lookaheads_rule[i]->number)
+	    {	    
+	      assert (conflict_list_free > 0);
+	      conflict_list[conflict_list_cnt] 
+		= state->lookaheads_rule[i]->number;
+	      conflict_list_cnt += 1;
+	      conflict_list_free -= 1;
+	    }
+	
+	/* Leave a 0 at the end */
+	assert (conflict_list_free > 0);
+	conflict_list_cnt += 1;
+	conflict_list_free -= 1;
+      }
+}
+
+
 /*------------------------------------------------------------------.
 | Decide what to do for each type of token if seen as the lookahead |
 | token in specified state.  The value returned is used as the      |
@@ -353,6 +416,11 @@ prepare_states (void)
 | This is where conflicts are resolved.  The loop over lookahead    |
 | rules considered lower-numbered rules last, and the last rule     |
 | considered that likes a token gets to handle it.                  |
+|								    |
+| For GLR parsers, also sets conflrow[SYM] to an index into         |
+| conflict_list iff there is an unresolved conflict (s/r or r/r)    |
+| with symbol SYM. The default reduction is not used for a symbol   |
+| that has any such conflicts.					    |
 `------------------------------------------------------------------*/
 
 static int
@@ -365,9 +433,10 @@ action_row (state_t *state)
   errs *errp = state->errs;
   /* set nonzero to inhibit having any default reduction */
   int nodefault = 0;
+  int conflicted = 0;
 
   for (i = 0; i < ntokens; i++)
-    actrow[i] = 0;
+    actrow[i] = conflrow[i] = 0;
 
   if (redp->nreds >= 1)
     {
@@ -381,7 +450,11 @@ action_row (state_t *state)
 	  /* and record this rule as the rule to use if that
 	     token follows.  */
 	  if (bitset_test (state->lookaheads[i], j))
-	    actrow[j] = -state->lookaheads_rule[i]->number;
+	    {
+	      if (actrow[j] != 0)
+		conflicted = conflrow[j] = 1;
+	      actrow[j] = -state->lookaheads_rule[i]->number;
+	    }
     }
 
   /* Now see which tokens are allowed for shifts in this state.  For
@@ -399,6 +472,8 @@ action_row (state_t *state)
       if (ISVAR (symbol))
 	break;
 
+      if (actrow[symbol] != 0)
+	conflicted = conflrow[symbol] = 1;
       actrow[symbol] = shift_state;
 
       /* Do not use any default reduction if there is a shift for
@@ -442,18 +517,20 @@ action_row (state_t *state)
 		}
 	    }
 
-	  /* actions which match the default are replaced with zero,
-	     which means "use the default" */
+	  /* GLR parsers need space for conflict lists, so we can't
+	     default conflicted entries.  For non-conflicted entries
+	     or as long as we are not building a GLR parser, 
+	     actions that match the default are replaced with zero,
+	     which means "use the default". */
 
 	  if (max > 0)
 	    {
 	      int j;
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == default_rule)
+		if (actrow[j] == default_rule && ! (glr_parser && conflrow[j]))
 		  actrow[j] = 0;
-
-	      default_rule = -default_rule;
 	    }
+	  default_rule = -default_rule;
 	}
     }
 
@@ -465,6 +542,9 @@ action_row (state_t *state)
       if (actrow[i] == SHRT_MIN)
 	actrow[i] = 0;
 
+  if (conflicted)
+    conflict_row (state);
+
   return default_rule;
 }
 
@@ -477,6 +557,7 @@ save_row (int state)
   short *sp;
   short *sp1;
   short *sp2;
+  unsigned int *sp3;
 
   count = 0;
   for (i = 0; i < ntokens; i++)
@@ -488,12 +569,18 @@ save_row (int state)
 
   froms[state] = sp1 = sp = XCALLOC (short, count);
   tos[state] = sp2 = XCALLOC (short, count);
+  if (glr_parser)
+    conflict_tos[state] = sp3 = XCALLOC (unsigned int, count);  
+  else 
+    conflict_tos[state] = NULL;
 
   for (i = 0; i < ntokens; i++)
     if (actrow[i] != 0)
       {
 	*sp1++ = i;
 	*sp2++ = actrow[i];
+	if (glr_parser)
+	  *sp3++ = conflrow[i];
       }
 
   tally[state] = count;
@@ -513,9 +600,22 @@ static void
 token_actions (void)
 {
   size_t i;
+  int nconflict = conflicts_total_count ();
+
   short *yydefact = XCALLOC (short, nstates);
 
   actrow = XCALLOC (short, ntokens);
+
+  conflrow = XCALLOC (short, ntokens);
+  if (glr_parser)
+    {
+      conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
+      conflict_list_free = 2 * nconflict;
+      conflict_list_cnt = 1;
+    } 
+  else 
+    conflict_list_free = conflict_list_cnt = 0;
+
   for (i = 0; i < nstates; ++i)
     {
       yydefact[i] = action_row (states[i]);
@@ -525,6 +625,7 @@ token_actions (void)
   muscle_insert_short_table ("defact", yydefact,
 			     yydefact[0], 1, nstates);
   XFREE (actrow);
+  XFREE (conflrow);
   XFREE (yydefact);
 }
 
@@ -555,6 +656,28 @@ actions_output (FILE *out)
   fputs ("]])\n\n", out);
 }
 
+/*--------------------------------------.
+| Output the merge functions to OUT.   |
+`--------------------------------------*/
+
+void
+merger_output (FILE *out)
+{
+  int n;
+  merger_list* p;
+
+  fputs ("m4_define([b4_mergers], \n[[", out);
+  for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next) 
+    {
+      if (p->type[0] == '\0') 
+	fprintf (out, "  case %d: yyval = %s (*yy0, *yy1); break;\n",
+		 n, p->name);
+      else
+	fprintf (out, "  case %d: yyval.%s = %s (*yy0, *yy1); break;\n",
+		 n, p->type, p->name);
+    }
+  fputs ("]])\n\n", out);
+}
 
 /*---------------------------------------.
 | Output the tokens definition to OOUT.  |
@@ -844,6 +967,7 @@ pack_vector (int vector)
   int loc = 0;
   short *from = froms[i];
   short *to = tos[i];
+  unsigned int *conflict_to = conflict_tos[i];
 
   assert (t);
 
@@ -872,6 +996,8 @@ pack_vector (int vector)
 	    {
 	      loc = j + from[k];
 	      table[loc] = to[k];
+	      if (glr_parser && conflict_to != NULL)
+		conflict_table[loc] = conflict_to[k];
 	      check[loc] = from[k];
 	    }
 
@@ -900,6 +1026,8 @@ pack_table (void)
   base = XCALLOC (short, nvectors);
   pos = XCALLOC (short, nentries);
   table = XCALLOC (short, table_size);
+  if (glr_parser)
+    conflict_table = XCALLOC (unsigned int, table_size);
   check = XCALLOC (short, table_size);
 
   lowzero = 0;
@@ -928,14 +1056,16 @@ pack_table (void)
     {
       XFREE (froms[i]);
       XFREE (tos[i]);
+      XFREE (conflict_tos[i]);
     }
 
   XFREE (froms);
   XFREE (tos);
+  XFREE (conflict_tos);
   XFREE (pos);
 }
 
-/* the following functions output yytable, yycheck
+/* the following functions output yytable, yycheck, yyconflp, yyconfl,
    and the vectors whose elements index the portion starts */
 
 static void
@@ -961,6 +1091,28 @@ output_table (void)
 }
 
 
+static void
+output_conflicts (void)
+{
+  /* GLR parsing slightly modifies yytable and yycheck
+     (and thus yypact) so that in states with unresolved conflicts,
+     the default reduction is not used in the conflicted entries, so
+     that there is a place to put a conflict pointer.  This means that
+     yyconflp and yyconfl are nonsense for a non-GLR parser, so we
+     avoid accidents by not writing them out in that case. */
+  if (! glr_parser)
+    return;
+
+  muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table, 
+				    conflict_table[0], 1, high+1);
+  muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list, 
+			     conflict_list[0], 1, conflict_list_cnt);
+
+  XFREE (conflict_table);
+  XFREE (conflict_list);
+}
+
+
 static void
 output_check (void)
 {
@@ -982,6 +1134,7 @@ output_actions (void)
 
   froms = XCALLOC (short *, nvectors);
   tos = XCALLOC (short *, nvectors);
+  conflict_tos = XCALLOC (unsigned int *, nvectors);
   tally = XCALLOC (short, nvectors);
   width = XCALLOC (short, nvectors);
 
@@ -999,6 +1152,7 @@ output_actions (void)
 
   output_base ();
   output_table ();
+  output_conflicts ();
 
   output_check ();
 
@@ -1084,6 +1238,7 @@ output_skeleton (void)
   fputs ("m4_init()\n", out);
 
   actions_output (out);
+  merger_output (out);
   token_definitions_output (out);
   symbol_destructors_output (out);
   symbol_printers_output (out);
@@ -1140,7 +1295,12 @@ prepare (void)
 
   /* Find the right skeleton file.  */
   if (!skeleton)
-    skeleton = "yacc.c";
+    {
+      if (glr_parser)
+	skeleton = "glr.c";
+      else
+	skeleton = "yacc.c";
+    }
 
   /* Parse the skeleton file and output the needed parsers.  */
   muscle_insert ("skeleton", skeleton);
