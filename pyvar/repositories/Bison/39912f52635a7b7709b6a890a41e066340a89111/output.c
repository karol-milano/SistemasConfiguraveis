@@ -107,19 +107,25 @@ GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_item_number_table, item_number_t)
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_state_number_table, state_number_t)
 
 
-/*-----------------------------------------------------------------.
-| Prepare the muscles related to the tokens: translate, tname, and |
-| toknum.                                                          |
-`-----------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Prepare the muscles related to the symbols: translate, tname, and |
+| toknum.                                                           |
+`------------------------------------------------------------------*/
 
 static void
-prepare_tokens (void)
+prepare_symbols (void)
 {
+  MUSCLE_INSERT_INT ("tokens_number", ntokens);
+  MUSCLE_INSERT_INT ("nterms_number", nvars);
+  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
+  MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
+
   muscle_insert_symbol_number_table ("translate",
 				     token_translations,
 				     token_translations[0],
 				     1, max_user_token_number + 1);
 
+  /* tname -- token names.  */
   {
     int i;
     int j = 0;
@@ -215,6 +221,8 @@ prepare_rules (void)
   muscle_insert_short_table ("dprec", dprec, 0, 0, nrules);
   muscle_insert_short_table ("merger", merger, 0, 0, nrules);
 
+  MUSCLE_INSERT_INT ("rules_number", nrules);
+
   free (rhs);
   free (prhs);
   free (rline);
@@ -238,6 +246,10 @@ prepare_states (void)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
 				     0, 1, nstates);
+
+  MUSCLE_INSERT_INT ("last", high);
+  MUSCLE_INSERT_INT ("final_state_number", final_state->number);
+  MUSCLE_INSERT_INT ("states_number", nstates);
 }
 
 
@@ -449,7 +461,7 @@ prepare_actions (void)
      that case.  Nevertheless, it seems even better to be able to use
      the GLR skeletons even without the non-deterministic tables.  */
   muscle_insert_unsigned_int_table ("conflict_list_heads", conflict_table,
-				    conflict_table[0], 1, high+1);
+				    conflict_table[0], 1, high + 1);
   muscle_insert_unsigned_int_table ("conflicting_rules", conflict_list,
 				    conflict_list[0], 1, conflict_list_cnt);
 }
@@ -566,20 +578,6 @@ prepare (void)
   MUSCLE_INSERT_STRING ("output_parser_name", parser_file_name);
   MUSCLE_INSERT_STRING ("output_header_name", spec_defines_file);
 
-  /* Symbols. */
-  MUSCLE_INSERT_INT ("tokens_number", ntokens);
-  MUSCLE_INSERT_INT ("nterms_number", nvars);
-  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
-  MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
-
-  /* Rules. */
-  MUSCLE_INSERT_INT ("rules_number", nrules);
-
-  /* States. */
-  MUSCLE_INSERT_INT ("last", high);
-  MUSCLE_INSERT_INT ("final_state_number", final_state->number);
-  MUSCLE_INSERT_INT ("states_number", nstates);
-
   /* User Code.  */
   obstack_1grow (&pre_prologue_obstack, 0);
   obstack_1grow (&post_prologue_obstack, 0);
@@ -609,7 +607,7 @@ output (void)
 {
   obstack_init (&format_obstack);
 
-  prepare_tokens ();
+  prepare_symbols ();
   prepare_rules ();
   prepare_states ();
   prepare_actions ();
