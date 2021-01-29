@@ -81,11 +81,11 @@ int nvectors;
 #define BASE_MAXIMUM INT_MAX
 #define BASE_MINIMUM INT_MIN
 
-static base_number **froms = NULL;
-static base_number **tos = NULL;
-static unsigned int **conflict_tos = NULL;
-static short int *tally = NULL;
-static base_number *width = NULL;
+static base_number **froms;
+static base_number **tos;
+static unsigned int **conflict_tos;
+static short int *tally;
+static base_number *width;
 
 
 /* For a given state, N = ACTROW[SYMBOL]:
@@ -97,12 +97,12 @@ static base_number *width = NULL;
 typedef short int action_number;
 #define ACTION_NUMBER_MINIMUM SHRT_MIN
 
-static action_number *actrow = NULL;
+static action_number *actrow;
 
 /* FROMS and TOS are reordered to be compressed.  ORDER[VECTOR] is the
    new vector number of VECTOR.  We skip `empty' vectors (i.e.,
    TALLY[VECTOR] = 0), and call these `entries'.  */
-static vector_number *order = NULL;
+static vector_number *order;
 static int nentries;
 
 base_number *base = NULL;
@@ -112,9 +112,9 @@ base_number *base = NULL;
 base_number base_ninf = 0;
 static base_number *pos = NULL;
 
-static unsigned int *conflrow = NULL;
-unsigned int *conflict_table = NULL;
-unsigned int *conflict_list = NULL;
+static unsigned int *conflrow;
+unsigned int *conflict_table;
+unsigned int *conflict_list;
 int conflict_list_cnt;
 static int conflict_list_free;
 
@@ -122,8 +122,8 @@ static int conflict_list_free;
    with more or less the original hard-coded value (which was
    SHRT_MAX).  */
 static int table_size = 32768;
-base_number *table = NULL;
-base_number *check = NULL;
+base_number *table;
+base_number *check;
 /* The value used in TABLE to denote explicit syntax errors
    (%nonassoc), a negative infinite.  First defaults to ACTION_NUMBER_MININUM,
    but in order to keep small tables, renumbered as TABLE_ERROR, which
@@ -153,13 +153,15 @@ table_grow (int desired)
     fprintf (stderr, "growing table and check from: %d to %d\n",
 	     old_size, table_size);
 
-  REALLOC (table, table_size);
-  REALLOC (check, table_size);
-  REALLOC (conflict_table, table_size);
+  table = xnrealloc (table, table_size, sizeof *table);
+  conflict_table = xnrealloc (conflict_table, table_size,
+			      sizeof *conflict_table);
+  check = xnrealloc (check, table_size, sizeof *check);
 
   for (/* Nothing. */; old_size < table_size; ++old_size)
     {
       table[old_size] = 0;
+      conflict_table[old_size] = 0;
       check[old_size] = -1;
     }
 }
@@ -208,6 +210,7 @@ conflict_row (state *s)
 	/* Leave a 0 at the end.  */
 	if (conflict_list_free <= 0)
 	  abort ();
+	conflict_list[conflict_list_cnt] = 0;
 	conflict_list_cnt += 1;
 	conflict_list_free -= 1;
       }
@@ -373,7 +376,7 @@ save_row (state_number s)
   base_number *sp;
   base_number *sp1;
   base_number *sp2;
-  unsigned int *sp3 IF_LINT (= NULL);
+  unsigned int *sp3;
 
   /* Number of non default actions in S.  */
   count = 0;
@@ -385,9 +388,10 @@ save_row (state_number s)
     return;
 
   /* Allocate non defaulted actions.  */
-  froms[s] = sp = CALLOC (sp1, count);
-  tos[s] = CALLOC (sp2, count);
-  conflict_tos[s] = nondeterministic_parser ? CALLOC (sp3, count) : NULL;
+  froms[s] = sp = sp1 = xnmalloc (count, sizeof *sp1);
+  tos[s] = sp2 = xnmalloc (count, sizeof *sp2);
+  conflict_tos[s] = sp3 =
+    nondeterministic_parser ? xnmalloc (count, sizeof *sp3) : NULL;
 
   /* Store non defaulted actions.  */
   for (i = 0; i < ntokens; i++)
@@ -421,12 +425,12 @@ token_actions (void)
 
   int nconflict = nondeterministic_parser ? conflicts_total_count () : 0;
 
-  CALLOC (yydefact, nstates);
+  yydefact = xnmalloc (nstates, sizeof *yydefact);
 
-  CALLOC (actrow, ntokens);
-  CALLOC (conflrow, ntokens);
+  actrow = xnmalloc (ntokens, sizeof *actrow);
+  conflrow = xnmalloc (ntokens, sizeof *conflrow);
 
-  CALLOC (conflict_list, 1 + 2 * nconflict);
+  conflict_list = xnmalloc (1 + 2 * nconflict, sizeof *conflict_list);
   conflict_list_free = 2 * nconflict;
   conflict_list_cnt = 1;
 
@@ -491,8 +495,8 @@ save_column (symbol_number sym, state_number default_state)
     return;
 
   /* Allocate room for non defaulted gotos.  */
-  froms[symno] = sp = CALLOC (sp1, count);
-  tos[symno] = CALLOC (sp2, count);
+  froms[symno] = sp = sp1 = xnmalloc (count, sizeof *sp1);
+  tos[symno] = sp2 = xnmalloc (count, sizeof *sp2);
 
   /* Store the state numbers of the non defaulted gotos.  */
   for (i = begin; i < end; i++)
@@ -554,8 +558,8 @@ static void
 goto_actions (void)
 {
   symbol_number i;
-  short int *state_count = CALLOC (state_count, nstates);
-  MALLOC (yydefgoto, nvars);
+  short int *state_count = xnmalloc (nstates, sizeof *state_count);
+  yydefgoto = xnmalloc (nvars, sizeof *yydefgoto);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
      is a GOTO to S on I.  */
@@ -751,11 +755,11 @@ pack_table (void)
 {
   int i;
 
-  CALLOC (base, nvectors);
-  CALLOC (pos, nentries);
-  CALLOC (table, table_size);
-  CALLOC (conflict_table, table_size);
-  CALLOC (check, table_size);
+  base = xnmalloc (nvectors, sizeof *base);
+  pos = xnmalloc (nentries, sizeof *pos);
+  table = xcalloc (table_size, sizeof *table);
+  conflict_table = xcalloc (table_size, sizeof *conflict_table);
+  check = xnmalloc (table_size, sizeof *check);
 
   lowzero = 0;
   high = 0;
@@ -810,11 +814,11 @@ tables_generate (void)
 
   nvectors = state_number_as_int (nstates) + nvars;
 
-  CALLOC (froms, nvectors);
-  CALLOC (tos, nvectors);
-  CALLOC (conflict_tos, nvectors);
-  CALLOC (tally, nvectors);
-  CALLOC (width, nvectors);
+  froms = xcalloc (nvectors, sizeof *froms);
+  tos = xcalloc (nvectors, sizeof *tos);
+  conflict_tos = xcalloc (nvectors, sizeof *conflict_tos);
+  tally = xcalloc (nvectors, sizeof *tally);
+  width = xnmalloc (nvectors, sizeof *width);
 
   token_actions ();
 
@@ -823,7 +827,7 @@ tables_generate (void)
   free (from_state);
   free (to_state);
 
-  CALLOC (order, nvectors);
+  order = xcalloc (nvectors, sizeof *order);
   sort_actions ();
   pack_table ();
   free (order);
