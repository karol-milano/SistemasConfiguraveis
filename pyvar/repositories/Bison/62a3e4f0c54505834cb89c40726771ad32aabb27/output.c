@@ -153,11 +153,47 @@ get_lines_number (const char *s)
 `----------------------------------------------------------------*/
 
 static inline long int
-output_table_data (struct obstack *oout,
-		   short *table_data,
-		   short first,
-		   int begin,
-		   int end)
+output_short_table (struct obstack *oout,
+		    short *table_data,
+		    short first,
+		    int begin,
+		    int end)
+{
+  long int max = first;
+  int i;
+  int j = 1;
+
+  obstack_fgrow1 (oout, "%6d", first);
+  for (i = begin; i < end; ++i)
+    {
+      obstack_1grow (oout, ',');
+      if (j >= 10)
+	{
+	  obstack_sgrow (oout, "\n  ");
+	  j = 1;
+	}
+      else
+	++j;
+      obstack_fgrow1 (oout, "%6d", table_data[i]);
+      if (table_data[i] > max)
+	max = table_data[i];
+    }
+  obstack_1grow (oout, 0);
+
+  return max;
+}
+
+
+/*--------------------.
+| Similar, for ints.  |
+`--------------------*/
+
+static inline long int
+output_int_table (struct obstack *oout,
+		  int *table_data,
+		  int first,
+		  int begin,
+		  int end)
 {
   long int max = first;
   int i;
@@ -192,7 +228,7 @@ output_table_data (struct obstack *oout,
 static void
 prepare_tokens (void)
 {
-  long int max = output_table_data (&format_obstack, token_translations,
+  long int max = output_short_table (&format_obstack, token_translations,
 				    0, 1, max_user_token_number + 1);
   muscle_insert ("translate", obstack_finish (&format_obstack));
   MUSCLE_INSERT_LONG_INT ("token_number_max", max);
@@ -237,7 +273,7 @@ prepare_tokens (void)
     short *values = XCALLOC (short, ntokens + 1);
     for (i = 0; i < ntokens + 1; ++i)
       values[i] = symbols[i]->user_token_number;
-    output_table_data (&format_obstack, values,
+    output_short_table (&format_obstack, values,
 		       0, 1, ntokens + 1);
     muscle_insert ("toknum", obstack_finish (&format_obstack));
     free (values);
@@ -253,10 +289,11 @@ prepare_tokens (void)
 static void
 prepare_rules (void)
 {
-  short *rhsp;
+  long int max;
+  item_number_t *rhsp;
   int r;
   int i = 0;
-  short *rhs = XMALLOC (short, nritems);
+  item_number_t *rhs = XMALLOC (item_number_t, nritems);
   short *prhs = XMALLOC (short, nrules + 1);
   short *r1 = XMALLOC (short, nrules + 1);
   short *r2 = XMALLOC (short, nrules + 1);
@@ -280,19 +317,20 @@ prepare_rules (void)
     }
   assert (i == nritems);
 
-  output_table_data (&format_obstack, rhs, ritem[0], 1, nritems);
+  max = output_int_table (&format_obstack, rhs, ritem[0], 1, nritems);
   muscle_insert ("rhs", obstack_finish (&format_obstack));
+  MUSCLE_INSERT_LONG_INT ("rhs_number_max", max);
 
-  output_table_data (&format_obstack, prhs, 0, 1, nrules + 1);
+  output_short_table (&format_obstack, prhs, 0, 1, nrules + 1);
   muscle_insert ("prhs", obstack_finish (&format_obstack));
 
-  output_table_data (&format_obstack, rline, 0, 1, nrules + 1);
+  output_short_table (&format_obstack, rline, 0, 1, nrules + 1);
   muscle_insert ("rline", obstack_finish (&format_obstack));
 
-  output_table_data (&format_obstack, r1, 0, 1, nrules + 1);
+  output_short_table (&format_obstack, r1, 0, 1, nrules + 1);
   muscle_insert ("r1", obstack_finish (&format_obstack));
 
-  output_table_data (&format_obstack, r2, 0, 1, nrules + 1);
+  output_short_table (&format_obstack, r2, 0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&format_obstack));
 
   free (rhs);
@@ -311,7 +349,7 @@ prepare_states (void)
   short *values = (short *) alloca (sizeof (short) * nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
-  output_table_data (&format_obstack, values,
+  output_short_table (&format_obstack, values,
 		     0, 1, nstates);
   muscle_insert ("stos", obstack_finish (&format_obstack));
 }
@@ -323,7 +361,7 @@ prepare_states (void)
 | default action (yydefact) for the state.  In addition, actrow is  |
 | filled with what to do for each kind of token, index by symbol    |
 | number, with zero meaning do the default action.  The value       |
-| MINSHORT, a very negative number, means this situation is an      |
+| SHRT_MIN, a very negative number, means this situation is an      |
 | error.  The parser recognizes this value specially.               |
 |                                                                   |
 | This is where conflicts are resolved.  The loop over lookahead    |
@@ -384,11 +422,11 @@ action_row (state_t *state)
     }
 
   /* See which tokens are an explicit error in this state (due to
-     %nonassoc).  For them, record MINSHORT as the action.  */
+     %nonassoc).  For them, record SHRT_MIN as the action.  */
   for (i = 0; i < errp->nerrs; i++)
     {
       int symbol = errp->errs[i];
-      actrow[symbol] = MINSHORT;
+      actrow[symbol] = SHRT_MIN;
     }
 
   /* Now find the most common reduction and make it the default action
@@ -438,7 +476,7 @@ action_row (state_t *state)
 
   if (default_rule == 0)
     for (i = 0; i < ntokens; i++)
-      if (actrow[i] == MINSHORT)
+      if (actrow[i] == SHRT_MIN)
 	actrow[i] = 0;
 
   return default_rule;
@@ -498,7 +536,7 @@ token_actions (void)
       save_row (i);
     }
 
-  output_table_data (&format_obstack, yydefact,
+  output_short_table (&format_obstack, yydefact,
 		     yydefact[0], 1, nstates);
   muscle_insert ("defact", obstack_finish (&format_obstack));
 
@@ -692,7 +730,7 @@ goto_actions (void)
       yydefgoto[i - ntokens] = default_state;
     }
 
-  output_table_data (&format_obstack, yydefgoto,
+  output_short_table (&format_obstack, yydefgoto,
 		     yydefgoto[0], 1, nsyms - ntokens);
   muscle_insert ("defgoto", obstack_finish (&format_obstack));
 
@@ -769,6 +807,8 @@ matching_state (int vector)
   return -1;
 }
 
+/* FIXME: For the time being, best approximation... */
+#define MAXTABLE SHRT_MAX
 
 static int
 pack_vector (int vector)
@@ -841,7 +881,7 @@ pack_table (void)
   high = 0;
 
   for (i = 0; i < nvectors; i++)
-    base[i] = MINSHORT;
+    base[i] = SHRT_MIN;
 
   for (i = 0; i < MAXTABLE; i++)
     check[i] = -1;
@@ -877,12 +917,12 @@ static void
 output_base (void)
 {
   /* Output pact. */
-  output_table_data (&format_obstack, base,
+  output_short_table (&format_obstack, base,
 		     base[0], 1, nstates);
   muscle_insert ("pact", obstack_finish (&format_obstack));
 
   /* Output pgoto. */
-  output_table_data (&format_obstack, base,
+  output_short_table (&format_obstack, base,
 		     base[nstates], nstates + 1, nvectors);
   muscle_insert ("pgoto", obstack_finish (&format_obstack));
 
@@ -893,7 +933,7 @@ output_base (void)
 static void
 output_table (void)
 {
-  output_table_data (&format_obstack, table,
+  output_short_table (&format_obstack, table,
 		     table[0], 1, high + 1);
   muscle_insert ("table", obstack_finish (&format_obstack));
   XFREE (table);
@@ -903,7 +943,7 @@ output_table (void)
 static void
 output_check (void)
 {
-  output_table_data (&format_obstack, check,
+  output_short_table (&format_obstack, check,
 		     check[0], 1, high + 1);
   muscle_insert ("check", obstack_finish (&format_obstack));
   XFREE (check);
@@ -1033,7 +1073,7 @@ static void
 prepare (void)
 {
   MUSCLE_INSERT_INT ("last", high);
-  MUSCLE_INSERT_INT ("flag", MINSHORT);
+  MUSCLE_INSERT_INT ("flag", SHRT_MIN);
   MUSCLE_INSERT_INT ("pure", pure_parser);
   MUSCLE_INSERT_INT ("nsym", nsyms);
   MUSCLE_INSERT_INT ("debug", debug_flag);
