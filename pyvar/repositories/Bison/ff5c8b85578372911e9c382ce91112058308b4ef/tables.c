@@ -1,4 +1,5 @@
 /* Output the generated parsing program for Bison.
+
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -42,10 +43,18 @@
    Of course vector_number_t ought to be wide enough to contain
    state_number and symbol_number.  */
 typedef short vector_number;
-#define state_number_to_vector_number(State) \
-   ((vector_number) State)
-#define symbol_number_to_vector_number(Symbol) \
-   ((vector_number) (state_number_as_int (nstates) + Symbol - ntokens))
+
+static inline vector_number
+state_number_to_vector_number (state_number s)
+{
+  return s;
+}
+
+static inline vector_number
+symbol_number_to_vector_number (symbol_number s)
+{
+  return state_number_as_int (nstates) + s - ntokens;
+}
 
 int nvectors;
 
@@ -112,7 +121,7 @@ static int conflict_list_free;
 /* TABLE_SIZE is the allocated size of both TABLE and CHECK.  We start
    with more or less the original hard-coded value (which was
    SHRT_MAX).  */
-static size_t table_size = 32768;
+static int table_size = 32768;
 base_number *table = NULL;
 base_number *check = NULL;
 /* The value used in TABLE to denote explicit syntax errors
@@ -133,9 +142,9 @@ rule_number *yydefact;
 `----------------------------------------------------------------*/
 
 static void
-table_grow (size_t desired)
+table_grow (int desired)
 {
-  size_t old_size = table_size;
+  int old_size = table_size;
 
   while (table_size <= desired)
     table_size *= 2;
@@ -144,9 +153,9 @@ table_grow (size_t desired)
     fprintf (stderr, "growing table and check from: %d to %d\n",
 	     old_size, table_size);
 
-  table = XREALLOC (table, base_number, table_size);
-  check = XREALLOC (check, base_number, table_size);
-  conflict_table = XREALLOC (conflict_table, unsigned int, table_size);
+  REALLOC (table, table_size);
+  REALLOC (check, table_size);
+  REALLOC (conflict_table, table_size);
 
   for (/* Nothing. */; old_size < table_size; ++old_size)
     {
@@ -355,10 +364,10 @@ save_row (state_number s)
 {
   symbol_number i;
   int count;
-  base_number *sp = NULL;
-  base_number *sp1 = NULL;
-  base_number *sp2 = NULL;
-  unsigned int *sp3 = NULL;
+  base_number *sp;
+  base_number *sp1;
+  base_number *sp2;
+  unsigned int *sp3 IF_LINT (= NULL);
 
   /* Number of non default actions in S.  */
   count = 0;
@@ -370,12 +379,9 @@ save_row (state_number s)
     return;
 
   /* Allocate non defaulted actions.  */
-  froms[s] = sp1 = sp = XCALLOC (base_number, count);
-  tos[s] = sp2 = XCALLOC (base_number, count);
-  if (glr_parser)
-    conflict_tos[s] = sp3 = XCALLOC (unsigned int, count);
-  else
-    conflict_tos[s] = NULL;
+  froms[s] = sp = CALLOC (sp1, count);
+  tos[s] = CALLOC (sp2, count);
+  conflict_tos[s] = glr_parser ? CALLOC (sp3, count) : NULL;
 
   /* Store non defaulted actions.  */
   for (i = 0; i < ntokens; i++)
@@ -409,12 +415,12 @@ token_actions (void)
 
   int nconflict = glr_parser ? conflicts_total_count () : 0;
 
-  yydefact = XCALLOC (rule_number, nstates);
+  CALLOC (yydefact, nstates);
 
-  actrow = XCALLOC (action_number, ntokens);
-  conflrow = XCALLOC (unsigned int, ntokens);
+  CALLOC (actrow, ntokens);
+  CALLOC (conflrow, ntokens);
 
-  conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
+  CALLOC (conflict_list, 1 + 2 * nconflict);
   conflict_list_free = 2 * nconflict;
   conflict_list_cnt = 1;
 
@@ -466,8 +472,8 @@ save_column (symbol_number sym, state_number default_state)
   int count;
   vector_number symno = symbol_number_to_vector_number (sym);
 
-  goto_number begin = goto_map[sym];
-  goto_number end = goto_map[sym + 1];
+  goto_number begin = goto_map[sym - ntokens];
+  goto_number end = goto_map[sym - ntokens + 1];
 
   /* Number of non default GOTO.  */
   count = 0;
@@ -479,8 +485,8 @@ save_column (symbol_number sym, state_number default_state)
     return;
 
   /* Allocate room for non defaulted gotos.  */
-  froms[symno] = sp1 = sp = XCALLOC (base_number, count);
-  tos[symno] = sp2 = XCALLOC (base_number, count);
+  froms[symno] = sp = CALLOC (sp1, count);
+  tos[symno] = CALLOC (sp2, count);
 
   /* Store the state numbers of the non defaulted gotos.  */
   for (i = begin; i < end; i++)
@@ -504,13 +510,13 @@ default_goto (symbol_number sym, short state_count[])
 {
   state_number s;
   int i;
-  goto_number m = goto_map[sym];
-  goto_number n = goto_map[sym + 1];
-  state_number default_state = (state_number) -1;
+  goto_number m = goto_map[sym - ntokens];
+  goto_number n = goto_map[sym - ntokens + 1];
+  state_number default_state = -1;
   int max = 0;
 
   if (m == n)
-    return (state_number) -1;
+    return -1;
 
   for (s = 0; s < nstates; s++)
     state_count[s] = 0;
@@ -542,8 +548,8 @@ static void
 goto_actions (void)
 {
   symbol_number i;
-  short *state_count = XCALLOC (short, nstates);
-  yydefgoto = XMALLOC (state_number, nvars);
+  short *state_count = CALLOC (state_count, nstates);
+  MALLOC (yydefgoto, nvars);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
      is a GOTO to S on I.  */
@@ -607,7 +613,7 @@ matching_state (vector_number vector)
   int prev;
 
   /* If VECTOR is a nterm, return -1.  */
-  if (i >= (int) nstates)
+  if (nstates <= i)
     return -1;
 
   t = tally[i];
@@ -665,13 +671,13 @@ pack_vector (vector_number vector)
       int k;
       int ok = 1;
 
-      if ((int) table_size <= j)
+      if (table_size <= j)
 	abort ();
 
       for (k = 0; ok && k < t; k++)
 	{
 	  loc = j + state_number_as_int (from[k]);
-	  if (loc >= (int) table_size)
+	  if (table_size <= loc)
 	    table_grow (loc);
 
 	  if (table[loc] != 0)
@@ -716,10 +722,10 @@ pack_vector (vector_number vector)
 `-------------------------------------------------------------*/
 
 static base_number
-table_ninf_remap (base_number tab[], size_t size, base_number ninf)
+table_ninf_remap (base_number tab[], int size, base_number ninf)
 {
   base_number res = 0;
-  size_t i;
+  int i;
 
   for (i = 0; i < size; i++)
     if (tab[i] < res && tab[i] != ninf)
@@ -739,11 +745,11 @@ pack_table (void)
 {
   int i;
 
-  base = XCALLOC (base_number, nvectors);
-  pos = XCALLOC (base_number, nentries);
-  table = XCALLOC (base_number, table_size);
-  conflict_table = XCALLOC (unsigned int, table_size);
-  check = XCALLOC (base_number, table_size);
+  CALLOC (base, nvectors);
+  CALLOC (pos, nentries);
+  CALLOC (table, table_size);
+  CALLOC (conflict_table, table_size);
+  CALLOC (check, table_size);
 
   lowzero = 0;
   high = 0;
@@ -751,7 +757,7 @@ pack_table (void)
   for (i = 0; i < nvectors; i++)
     base[i] = BASE_MINIMUM;
 
-  for (i = 0; i < (int) table_size; i++)
+  for (i = 0; i < table_size; i++)
     check[i] = -1;
 
   for (i = 0; i < nentries; i++)
@@ -798,20 +804,20 @@ tables_generate (void)
 
   nvectors = state_number_as_int (nstates) + nvars;
 
-  froms = XCALLOC (base_number *, nvectors);
-  tos = XCALLOC (base_number *, nvectors);
-  conflict_tos = XCALLOC (unsigned int *, nvectors);
-  tally = XCALLOC (short, nvectors);
-  width = XCALLOC (base_number, nvectors);
+  CALLOC (froms, nvectors);
+  CALLOC (tos, nvectors);
+  CALLOC (conflict_tos, nvectors);
+  CALLOC (tally, nvectors);
+  CALLOC (width, nvectors);
 
   token_actions ();
 
   goto_actions ();
-  free (goto_map + ntokens);
+  free (goto_map);
   free (from_state);
   free (to_state);
 
-  order = XCALLOC (vector_number, nvectors);
+  CALLOC (order, nvectors);
   sort_actions ();
   pack_table ();
   free (order);
