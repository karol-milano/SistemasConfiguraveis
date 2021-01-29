@@ -42,20 +42,20 @@ core *first_state;
 shifts *first_shift;
 reductions *first_reduction;
 
-int get_state PARAMS((int));
-core *new_state PARAMS((int));
-
-void allocate_itemsets PARAMS((void));
-void allocate_storage PARAMS((void));
-void free_storage PARAMS((void));
-void generate_states PARAMS((void));
-void new_itemsets PARAMS((void));
-void append_states PARAMS((void));
-void initialize_states PARAMS((void));
-void save_shifts PARAMS((void));
-void save_reductions PARAMS((void));
-void augment_automaton PARAMS((void));
-void insert_start_shift PARAMS((void));
+extern void generate_states PARAMS((void));
+
+static int get_state PARAMS((int));
+static core *new_state PARAMS((int));
+static void allocate_itemsets PARAMS((void));
+static void allocate_storage PARAMS((void));
+static void free_storage PARAMS((void));
+static void new_itemsets PARAMS((void));
+static void append_states PARAMS((void));
+static void initialize_states PARAMS((void));
+static void save_shifts PARAMS((void));
+static void save_reductions PARAMS((void));
+static void augment_automaton PARAMS((void));
+static void insert_start_shift PARAMS((void));
 extern void initialize_closure PARAMS((int));
 extern void closure PARAMS((short *, int));
 extern void finalize_closure PARAMS((void));
@@ -82,7 +82,7 @@ static core **state_table;
 
 
 
-void
+static void
 allocate_itemsets (void)
 {
   register short *itemp;
@@ -127,7 +127,7 @@ allocate_itemsets (void)
 }
 
 
-void
+static void
 allocate_storage (void)
 {
   allocate_itemsets();
@@ -138,7 +138,7 @@ allocate_storage (void)
 }
 
 
-void
+static void
 free_storage (void)
 {
   FREE(shift_symbol);
@@ -200,7 +200,7 @@ generate_states (void)
    For each symbol in the grammar, kernel_base[symbol] points to
    a vector of item numbers activated if that symbol is shifted,
    and kernel_end[symbol] points after the end of that vector.  */
-void
+static void
 new_itemsets (void)
 {
   register int i;
@@ -248,7 +248,7 @@ new_itemsets (void)
    reached by each shift transition from the current state.
 
    shiftset is set up as a vector of state numbers of those states.  */
-void
+static void
 append_states (void)
 {
   register int i;
@@ -287,7 +287,7 @@ append_states (void)
 Create a new state if no equivalent one exists already.
 Used by append_states  */
 
-int
+static int
 get_state (int symbol)
 {
   register int key;
@@ -360,7 +360,7 @@ get_state (int symbol)
 
 /* subroutine of get_state.  create a new state for those items, if necessary.  */
 
-core *
+static core *
 new_state (int symbol)
 {
   register int n;
@@ -398,7 +398,7 @@ new_state (int symbol)
 }
 
 
-void
+static void
 initialize_states (void)
 {
   register core *p;
@@ -412,7 +412,7 @@ initialize_states (void)
 }
 
 
-void
+static void
 save_shifts (void)
 {
   register shifts *p;
@@ -449,7 +449,7 @@ save_shifts (void)
 
 /* find which rules can be used for reduction transitions from the current state
    and make a reductions structure for the state to record their rule numbers.  */
-void
+static void
 save_reductions (void)
 {
   register short *isp;
@@ -510,7 +510,7 @@ grammar's start symbol and goes to the next-to-final state,
 which has a shift going to the final state, which has a shift
 to the termination state.
 Create such states and shifts if they don't happen to exist already.  */
-void
+static void
 augment_automaton (void)
 {
   register int i;
@@ -683,7 +683,7 @@ augment_automaton (void)
 /* subroutine of augment_automaton.
    Create the next-to-final state, to which a shift has already been made in
    the initial state.  */
-void
+static void
 insert_start_shift (void)
 {
   register core *statep;
