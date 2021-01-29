@@ -40,20 +40,24 @@ core *first_state;
 shifts *first_shift;
 reductions *first_reduction;
 
-int get_state();
-core *new_state();
-
-void new_itemsets();
-void append_states();
-void initialize_states();
-void save_shifts();
-void save_reductions();
-void augment_automaton();
-void insert_start_shift();
-extern void initialize_closure();
-extern void closure();
-extern void finalize_closure();
-extern void toomany();
+int get_state PARAMS((int));
+core *new_state PARAMS((int));
+
+void allocate_itemsets PARAMS((void));
+void allocate_storage PARAMS((void));
+void free_storage PARAMS((void));
+void generate_states PARAMS((void));
+void new_itemsets PARAMS((void));
+void append_states PARAMS((void));
+void initialize_states PARAMS((void));
+void save_shifts PARAMS((void));
+void save_reductions PARAMS((void));
+void augment_automaton PARAMS((void));
+void insert_start_shift PARAMS((void));
+extern void initialize_closure PARAMS((int));
+extern void closure PARAMS((short *, int));
+extern void finalize_closure PARAMS((void));
+extern void toomany PARAMS((char *));
 
 static core *this_state;
 static core *last_state;
@@ -78,7 +82,7 @@ static core **state_table;
 
 
 void
-allocate_itemsets()
+allocate_itemsets (void)
 {
   register short *itemp;
   register int symbol;
@@ -123,7 +127,7 @@ allocate_itemsets()
 
 
 void
-allocate_storage()
+allocate_storage (void)
 {
   allocate_itemsets();
 
@@ -134,7 +138,7 @@ allocate_storage()
 
 
 void
-free_storage()
+free_storage (void)
 {
   FREE(shift_symbol);
   FREE(redset);
@@ -150,7 +154,7 @@ free_storage()
 /* compute the nondeterministic finite state machine (see state.h for details)
 from the grammar.  */
 void
-generate_states()
+generate_states (void)
 {
   allocate_storage();
   initialize_closure(nitems);
@@ -196,7 +200,7 @@ generate_states()
    a vector of item numbers activated if that symbol is shifted,
    and kernel_end[symbol] points after the end of that vector.  */
 void
-new_itemsets()
+new_itemsets (void)
 {
   register int i;
   register int shiftcount;
@@ -244,7 +248,7 @@ new_itemsets()
 
    shiftset is set up as a vector of state numbers of those states.  */
 void
-append_states()
+append_states (void)
 {
   register int i;
   register int j;
@@ -283,8 +287,7 @@ Create a new state if no equivalent one exists already.
 Used by append_states  */
 
 int
-get_state(symbol)
-int symbol;
+get_state (int symbol)
 {
   register int key;
   register short *isp1;
@@ -357,8 +360,7 @@ int symbol;
 /* subroutine of get_state.  create a new state for those items, if necessary.  */
 
 core *
-new_state(symbol)
-int symbol;
+new_state (int symbol)
 {
   register int n;
   register core *p;
@@ -396,7 +398,7 @@ int symbol;
 
 
 void
-initialize_states()
+initialize_states (void)
 {
   register core *p;
 /*  register unsigned *rp1; JF unused */
@@ -410,7 +412,7 @@ initialize_states()
 
 
 void
-save_shifts()
+save_shifts (void)
 {
   register shifts *p;
   register short *sp1;
@@ -418,7 +420,7 @@ save_shifts()
   register short *send;
 
   p = (shifts *) xmalloc((unsigned) (sizeof(shifts) +
-				       (nshifts - 1) * sizeof(short)));
+				     (nshifts - 1) * sizeof(short)));
 
   p->number = this_state->number;
   p->nshifts = nshifts;
@@ -447,7 +449,7 @@ save_shifts()
 /* find which rules can be used for reduction transitions from the current state
    and make a reductions structure for the state to record their rule numbers.  */
 void
-save_reductions()
+save_reductions (void)
 {
   register short *isp;
   register short *rp1;
@@ -475,7 +477,7 @@ save_reductions()
   if (count)
     {
       p = (reductions *) xmalloc((unsigned) (sizeof(reductions) +
-					       (count - 1) * sizeof(short)));
+					     (count - 1) * sizeof(short)));
 
       p->number = this_state->number;
       p->nreds = count;
@@ -508,7 +510,7 @@ which has a shift going to the final state, which has a shift
 to the termination state.
 Create such states and shifts if they don't happen to exist already.  */
 void
-augment_automaton()
+augment_automaton (void)
 {
   register int i;
   register int k;
@@ -548,7 +550,7 @@ augment_automaton()
 	      if (sp && sp->number == k)
 		{
 		  sp2 = (shifts *) xmalloc((unsigned) (sizeof(shifts)
-							 + sp->nshifts * sizeof(short)));
+						       + sp->nshifts * sizeof(short)));
 		  sp2->number = k;
 		  sp2->nshifts = sp->nshifts + 1;
 		  sp2->shifts[0] = nstates;
@@ -681,7 +683,7 @@ augment_automaton()
    Create the next-to-final state, to which a shift has already been made in
    the initial state.  */
 void
-insert_start_shift()
+insert_start_shift (void)
 {
   register core *statep;
   register shifts *sp;
