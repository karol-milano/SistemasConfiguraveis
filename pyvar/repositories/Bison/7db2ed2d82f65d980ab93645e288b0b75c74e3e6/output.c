@@ -20,17 +20,15 @@
    02111-1307, USA.  */
 
 
-/* The parser tables consist of these tables.  Marked ones needed only
-   for the semantic parser.  Double marked are output only if switches
-   are set.
+/* The parser tables consist of these tables.
 
    YYTRANSLATE = vector mapping yylex's token numbers into bison's
    token numbers.
 
-   ++ YYTNAME = vector of string-names indexed by bison token number.
+   YYTNAME = vector of string-names indexed by bison token number.
 
-   ++ YYTOKNUM = vector of yylex token numbers corresponding to
-   entries in YYTNAME.
+   YYTOKNUM = vector of yylex token numbers corresponding to entries
+   in YYTNAME.
 
    YYRLINE = vector of line-numbers of all rules.  For yydebug
    printouts.
@@ -44,8 +42,7 @@
 
    YYR2[R] = number of symbols composing right hand side of rule R.
 
-   + YYSTOS[S] = the symbol number of the symbol that leads to state
-   S.
+   YYSTOS[S] = the symbol number of the symbol that leads to state S.
 
    YYDEFACT[S] = default rule to reduce with in state s, when YYTABLE
    doesn't specify something else to do.  Zero means the default is an
@@ -109,8 +106,8 @@ void m4_invoke PARAMS ((const char *definitions));
 
 static int nvectors;
 static int nentries;
-static short **froms = NULL;
-static short **tos = NULL;
+static state_number_t **froms = NULL;
+static state_number_t **tos = NULL;
 static unsigned int **conflict_tos = NULL;
 static short *tally = NULL;
 static short *width = NULL;
@@ -790,14 +787,14 @@ static void
 save_column (symbol_number_t symbol, state_number_t default_state)
 {
   int i;
-  short *sp;
-  short *sp1;
-  short *sp2;
+  state_number_t *sp;
+  state_number_t *sp1;
+  state_number_t *sp2;
   int count;
   int symno = symbol - ntokens + state_number_as_int (nstates);
 
-  int begin = goto_map[symbol];
-  int end = goto_map[symbol + 1];
+  goto_number_t begin = goto_map[symbol];
+  goto_number_t end = goto_map[symbol + 1];
 
   count = 0;
   for (i = begin; i < end; i++)
@@ -827,8 +824,8 @@ default_goto (symbol_number_t symbol)
 {
   state_number_t s;
   int i;
-  int m = goto_map[symbol];
-  int n = goto_map[symbol + 1];
+  goto_number_t m = goto_map[symbol];
+  goto_number_t n = goto_map[symbol + 1];
   state_number_t default_state = (state_number_t) -1;
   int max = 0;
 
@@ -1214,33 +1211,37 @@ output_skeleton (void)
 static void
 prepare (void)
 {
-  MUSCLE_INSERT_INT ("last", high);
-  MUSCLE_INSERT_INT ("flag", SHRT_MIN);
+  /* Flags. */
+  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
+  MUSCLE_INSERT_INT ("defines_flag", defines_flag);
+  MUSCLE_INSERT_INT ("error_verbose", error_verbose);
   MUSCLE_INSERT_INT ("pure", pure_parser);
-  MUSCLE_INSERT_INT ("nsym", nsyms);
   MUSCLE_INSERT_INT ("debug", debug_flag);
-  MUSCLE_INSERT_INT ("final", final_state->number);
-  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
-  MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
-  MUSCLE_INSERT_INT ("error_verbose", error_verbose);
-  MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
 
   /* FIXME: This is wrong: the muscles should decide whether they hold
      a copy or not, but the situation is too obscure currently.  */
+  MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
   MUSCLE_INSERT_STRING ("output_infix", output_infix ? output_infix : "");
   MUSCLE_INSERT_STRING ("output_prefix", short_base_name);
   MUSCLE_INSERT_STRING ("output_parser_name", parser_file_name);
   MUSCLE_INSERT_STRING ("output_header_name", spec_defines_file);
 
-  MUSCLE_INSERT_INT ("nnts", nvars);
-  MUSCLE_INSERT_INT ("nrules", nrules);
-  MUSCLE_INSERT_INT ("nstates", nstates);
-  MUSCLE_INSERT_INT ("ntokens", ntokens);
+  /* Symbols. */
+  MUSCLE_INSERT_INT ("tokens_number", ntokens);
+  MUSCLE_INSERT_INT ("nterms_number", nvars);
+  MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
+  MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
 
-  MUSCLE_INSERT_INT ("locations_flag", locations_flag);
-  MUSCLE_INSERT_INT ("defines_flag", defines_flag);
+  /* Rules. */
+  MUSCLE_INSERT_INT ("rules_number", nrules);
+
+  /* States. */
+  MUSCLE_INSERT_INT ("last", high);
+  MUSCLE_INSERT_INT ("flag", SHRT_MIN);
+  MUSCLE_INSERT_INT ("final_state_number", final_state->number);
+  MUSCLE_INSERT_INT ("states_number", nstates);
 
-  /* Copy definitions in directive.  */
+  /* User Code.  */
   obstack_1grow (&pre_prologue_obstack, 0);
   obstack_1grow (&post_prologue_obstack, 0);
   muscle_insert ("pre_prologue", obstack_finish (&pre_prologue_obstack));
