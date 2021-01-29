@@ -32,7 +32,6 @@
 #include "symtab.h"
 #include "gram.h"
 #include "reader.h"
-#include "types.h"
 #include "LR0.h"
 #include "complain.h"
 #include "lalr.h"
@@ -40,21 +39,30 @@
 #include "derives.h"
 #include "getargs.h"
 
+goto_number_t *goto_map = NULL;
+static goto_number_t ngotos = 0;
+state_number_t *from_state = NULL;
+state_number_t *to_state = NULL;
+
+/* Linked list of goto numbers.  */
+typedef struct goto_list_s
+{
+  struct goto_list_s *next;
+  goto_number_t value;
+} goto_list_t;
+
+
 rule_t **LArule = NULL;
 bitsetv LA = NULL;
 size_t nLA;
 
-static int ngotos;
-short *goto_map = NULL;
-state_number_t *from_state = NULL;
-state_number_t *to_state = NULL;
 
 /* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
 static bitsetv F = NULL;
 
-static short **includes;
-static shorts **lookback;
+static goto_number_t **includes;
+static goto_list_t **lookback;
 
 
 
@@ -72,7 +80,7 @@ initialize_LA (void)
 
   LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
   LArule = XCALLOC (rule_t *, nLA);
-  lookback = XCALLOC (shorts *, nLA);
+  lookback = XCALLOC (goto_list_t *, nLA);
 
   np = LArule;
   for (i = 0; i < nstates; i++)
@@ -86,10 +94,10 @@ static void
 set_goto_map (void)
 {
   state_number_t state;
-  short *temp_map;
+  goto_number_t *temp_map;
 
-  goto_map = XCALLOC (short, nvars + 1) - ntokens;
-  temp_map = XCALLOC (short, nvars + 1) - ntokens;
+  goto_map = XCALLOC (goto_number_t, nvars + 1) - ntokens;
+  temp_map = XCALLOC (goto_number_t, nvars + 1) - ntokens;
 
   ngotos = 0;
   for (state = 0; state < nstates; ++state)
@@ -98,8 +106,8 @@ set_goto_map (void)
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  if (ngotos == SHRT_MAX)
-	    fatal (_("too many gotos (max %d)"), SHRT_MAX);
+	  if (ngotos == GOTO_NUMBER_MAX)
+	    fatal (_("too many gotos (max %d)"), GOTO_NUMBER_MAX);
 
 	  ngotos++;
 	  goto_map[TRANSITION_SYMBOL (sp, i)]++;
@@ -178,8 +186,8 @@ map_goto (state_number_t state, symbol_number_t symbol)
 static void
 initialize_F (void)
 {
-  short **reads = XCALLOC (short *, ngotos);
-  short *edge = XCALLOC (short, ngotos + 1);
+  goto_number_t **reads = XCALLOC (goto_number_t *, ngotos);
+  goto_number_t *edge = XCALLOC (goto_number_t, ngotos + 1);
   int nedges = 0;
 
   int i;
@@ -204,7 +212,7 @@ initialize_F (void)
 
       if (nedges)
 	{
-	  reads[i] = XCALLOC (short, nedges + 1);
+	  reads[i] = XCALLOC (goto_number_t, nedges + 1);
 	  memcpy (reads[i], edge, nedges * sizeof (edge[0]));
 	  reads[i][nedges] = -1;
 	  nedges = 0;
@@ -225,7 +233,7 @@ static void
 add_lookback_edge (state_t *state, rule_number_t ruleno, int gotono)
 {
   int i;
-  shorts *sp;
+  goto_list_t *sp;
 
   for (i = 0; i < state->nlookaheads; ++i)
     if (state->lookaheads_rule[i]->number == ruleno)
@@ -233,7 +241,7 @@ add_lookback_edge (state_t *state, rule_number_t ruleno, int gotono)
 
   assert (state->lookaheads_rule[i]->number == ruleno);
 
-  sp = XCALLOC (shorts, 1);
+  sp = XCALLOC (goto_list_t, 1);
   sp->next = lookback[(state->lookaheads - LA) + i];
   sp->value = gotono;
   lookback[(state->lookaheads - LA) + i] = sp;
@@ -244,11 +252,11 @@ add_lookback_edge (state_t *state, rule_number_t ruleno, int gotono)
 static void
 build_relations (void)
 {
-  short *edge = XCALLOC (short, ngotos + 1);
+  goto_number_t *edge = XCALLOC (goto_number_t, ngotos + 1);
   state_number_t *states1 = XCALLOC (state_number_t, ritem_longest_rhs () + 1);
   int i;
 
-  includes = XCALLOC (short *, ngotos);
+  includes = XCALLOC (goto_number_t *, ngotos);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -295,7 +303,7 @@ build_relations (void)
       if (nedges)
 	{
 	  int j;
-	  includes[i] = XCALLOC (short, nedges + 1);
+	  includes[i] = XCALLOC (goto_number_t, nedges + 1);
 	  for (j = 0; j < nedges; j++)
 	    includes[i][j] = edge[j];
 	  includes[i][nedges] = -1;
@@ -328,7 +336,7 @@ static void
 compute_lookaheads (void)
 {
   size_t i;
-  shorts *sp;
+  goto_list_t *sp;
 
   for (i = 0; i < nLA; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
@@ -336,7 +344,7 @@ compute_lookaheads (void)
 
   /* Free LOOKBACK. */
   for (i = 0; i < nLA; i++)
-    LIST_FREE (shorts, lookback[i]);
+    LIST_FREE (goto_list_t, lookback[i]);
 
   XFREE (lookback);
   bitsetv_free (F);
