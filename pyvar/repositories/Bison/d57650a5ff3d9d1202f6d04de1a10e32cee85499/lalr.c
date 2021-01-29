@@ -48,8 +48,8 @@ size_t nLA;
 
 static int ngotos;
 short *goto_map = NULL;
-short *from_state = NULL;
-short *to_state = NULL;
+state_number_t *from_state = NULL;
+state_number_t *to_state = NULL;
 
 /* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
@@ -134,7 +134,7 @@ digraph (short **relation)
 static void
 initialize_LA (void)
 {
-  size_t i;
+  state_number_t i;
   int j;
   rule_t **np;
 
@@ -157,8 +157,7 @@ initialize_LA (void)
 static void
 set_goto_map (void)
 {
-  size_t state;
-  int i;
+  state_number_t state;
   short *temp_map;
 
   goto_map = XCALLOC (short, nvars + 1) - ntokens;
@@ -168,6 +167,7 @@ set_goto_map (void)
   for (state = 0; state < nstates; ++state)
     {
       shifts *sp = states[state]->shifts;
+      int i;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  if (ngotos == SHRT_MAX)
@@ -180,6 +180,7 @@ set_goto_map (void)
 
   {
     int k = 0;
+    int i;
     for (i = ntokens; i < nsyms; i++)
       {
 	temp_map[i] = k;
@@ -193,12 +194,13 @@ set_goto_map (void)
     temp_map[nsyms] = ngotos;
   }
 
-  from_state = XCALLOC (short, ngotos);
-  to_state = XCALLOC (short, ngotos);
+  from_state = XCALLOC (state_number_t, ngotos);
+  to_state = XCALLOC (state_number_t, ngotos);
 
   for (state = 0; state < nstates; ++state)
     {
       shifts *sp = states[state]->shifts;
+      int i;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  int k = temp_map[SHIFT_SYMBOL (sp, i)]++;
@@ -217,12 +219,12 @@ set_goto_map (void)
 `----------------------------------------------------------*/
 
 static int
-map_goto (int state, symbol_number_t symbol)
+map_goto (state_number_t state, symbol_number_t symbol)
 {
   int high;
   int low;
   int middle;
-  int s;
+  state_number_t s;
 
   low = goto_map[symbol];
   high = goto_map[symbol + 1] - 1;
@@ -258,7 +260,7 @@ initialize_F (void)
 
   for (i = 0; i < ngotos; i++)
     {
-      int stateno = to_state[i];
+      state_number_t stateno = to_state[i];
       shifts *sp = states[stateno]->shifts;
 
       int j;
@@ -400,7 +402,7 @@ static void
 build_relations (void)
 {
   short *edge = XCALLOC (short, ngotos + 1);
-  short *states1 = XCALLOC (short, ritem_longest_rhs () + 1);
+  state_number_t *states1 = XCALLOC (state_number_t, ritem_longest_rhs () + 1);
   int i;
 
   includes = XCALLOC (short *, ngotos);
@@ -514,7 +516,7 @@ compute_lookaheads (void)
 static void
 states_lookaheads_count (void)
 {
-  size_t i;
+  state_number_t i;
   nLA = 0;
 
   /* Count   */
@@ -555,7 +557,7 @@ states_lookaheads_count (void)
 static void
 states_lookaheads_initialize (void)
 {
-  size_t i;
+  state_number_t i;
   bitsetv pLA = LA;
   rule_t **pLArule = LArule;
 
@@ -578,7 +580,7 @@ states_lookaheads_initialize (void)
 static void
 lookaheads_print (FILE *out)
 {
-  size_t i;
+  state_number_t i;
   int j, k;
   fprintf (out, "Lookaheads: BEGIN\n");
   for (i = 0; i < nstates; ++i)
