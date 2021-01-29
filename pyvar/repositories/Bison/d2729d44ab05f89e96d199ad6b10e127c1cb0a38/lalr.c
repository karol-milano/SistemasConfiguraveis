@@ -73,24 +73,26 @@ short *goto_map;
 short *from_state;
 short *to_state;
 
-short **transpose();
-void set_state_table();
-void set_accessing_symbol();
-void set_shift_table();
-void set_reduction_table();
-void set_maxrhs();
-void initialize_LA();
-void set_goto_map();
-void initialize_F();
-void build_relations();
-void add_lookback_edge();
-void compute_FOLLOWS();
-void compute_lookaheads();
-void digraph();
-void traverse();
-
-extern void toomany();
-extern void berror();
+void lalr PARAMS((void));
+short **transpose PARAMS((short **, int));
+void set_state_table PARAMS((void));
+void set_accessing_symbol PARAMS((void));
+void set_shift_table PARAMS((void));
+void set_reduction_table PARAMS((void));
+void set_maxrhs PARAMS((void));
+void initialize_LA PARAMS((void));
+void set_goto_map PARAMS((void));
+int map_goto PARAMS((int, int));
+void initialize_F PARAMS((void));
+void build_relations PARAMS((void));
+void add_lookback_edge PARAMS((int, int, int));
+void compute_FOLLOWS PARAMS((void));
+void compute_lookaheads PARAMS((void));
+void digraph PARAMS((short **));
+void traverse PARAMS((register int));
+
+extern void toomany PARAMS((char *));
+extern void berror PARAMS((char *));
 
 static int infinity;
 static int maxrhs;
@@ -105,7 +107,7 @@ static int top;
 
 
 void
-lalr()
+lalr (void)
 {
   tokensetsize = WORDSIZE(ntokens);
 
@@ -124,7 +126,7 @@ lalr()
 
 
 void
-set_state_table()
+set_state_table (void)
 {
   register core *sp;
 
@@ -136,7 +138,7 @@ set_state_table()
 
 
 void
-set_accessing_symbol()
+set_accessing_symbol (void)
 {
   register core *sp;
 
@@ -148,7 +150,7 @@ set_accessing_symbol()
 
 
 void
-set_shift_table()
+set_shift_table (void)
 {
   register shifts *sp;
 
@@ -160,7 +162,7 @@ set_shift_table()
 
 
 void
-set_reduction_table()
+set_reduction_table (void)
 {
   register reductions *rp;
 
@@ -172,7 +174,7 @@ set_reduction_table()
 
 
 void
-set_maxrhs()
+set_maxrhs (void)
 {
   register short *itemp;
   register int length;
@@ -198,7 +200,7 @@ set_maxrhs()
 
 
 void
-initialize_LA()
+initialize_LA (void)
 {
   register int i;
   register int j;
@@ -256,7 +258,7 @@ initialize_LA()
     {
       if (!consistent[i])
 	{
-	  if (rp = reduction_table[i])
+	  if ((rp = reduction_table[i]))
 	    for (j = 0; j < rp->nreds; j++)
 	      *np++ = rp->rules[j];
 	}
@@ -265,7 +267,7 @@ initialize_LA()
 
 
 void
-set_goto_map()
+set_goto_map (void)
 {
   register shifts *sp;
   register int i;
@@ -335,9 +337,7 @@ set_goto_map()
 /*  Map_goto maps a state/symbol pair into its numeric representation.	*/
 
 int
-map_goto(state, symbol)
-int state;
-int symbol;
+map_goto (int state, int symbol)
 {
   register int high;
   register int low;
@@ -366,7 +366,7 @@ int symbol;
 
 
 void
-initialize_F()
+initialize_F (void)
 {
   register int i;
   register int j;
@@ -442,7 +442,7 @@ initialize_F()
 
 
 void
-build_relations()
+build_relations (void)
 {
   register int i;
   register int j;
@@ -537,10 +537,7 @@ build_relations()
 
 
 void
-add_lookback_edge(stateno, ruleno, gotono)
-int stateno;
-int ruleno;
-int gotono;
+add_lookback_edge (int stateno, int ruleno, int gotono)
 {
   register int i;
   register int k;
@@ -570,9 +567,7 @@ int gotono;
 
 
 short **
-transpose(R_arg, n)
-short **R_arg;
-int n;
+transpose (short **R_arg, int n)
 {
   register short **new_R;
   register short **temp_R;
@@ -627,7 +622,7 @@ int n;
 
 
 void
-compute_FOLLOWS()
+compute_FOLLOWS (void)
 {
   register int i;
 
@@ -643,7 +638,7 @@ compute_FOLLOWS()
 
 
 void
-compute_lookaheads()
+compute_lookaheads (void)
 {
   register int i;
   register int n;
@@ -686,8 +681,7 @@ compute_lookaheads()
 
 
 void
-digraph(relation)
-short **relation;
+digraph (short **relation)
 {
   register int i;
 
@@ -713,8 +707,7 @@ short **relation;
 
 
 void
-traverse(i)
-register int i;
+traverse (register int i)
 {
   register unsigned *fp1;
   register unsigned *fp2;
