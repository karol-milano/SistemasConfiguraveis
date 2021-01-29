@@ -74,25 +74,26 @@ short *goto_map;
 short *from_state;
 short *to_state;
 
-void lalr PARAMS((void));
-short **transpose PARAMS((short **, int));
-void set_state_table PARAMS((void));
-void set_accessing_symbol PARAMS((void));
-void set_shift_table PARAMS((void));
-void set_reduction_table PARAMS((void));
-void set_maxrhs PARAMS((void));
-void initialize_LA PARAMS((void));
-void set_goto_map PARAMS((void));
-int map_goto PARAMS((int, int));
-void initialize_F PARAMS((void));
-void build_relations PARAMS((void));
-void add_lookback_edge PARAMS((int, int, int));
-void compute_FOLLOWS PARAMS((void));
-void compute_lookaheads PARAMS((void));
-void digraph PARAMS((short **));
-void traverse PARAMS((register int));
-
-extern void berror PARAMS((char *));
+extern void lalr PARAMS((void));
+
+static short **transpose PARAMS((short **, int));
+static void set_state_table PARAMS((void));
+static void set_accessing_symbol PARAMS((void));
+static void set_shift_table PARAMS((void));
+static void set_reduction_table PARAMS((void));
+static void set_maxrhs PARAMS((void));
+static void initialize_LA PARAMS((void));
+static void set_goto_map PARAMS((void));
+static int map_goto PARAMS((int, int));
+static void initialize_F PARAMS((void));
+static void build_relations PARAMS((void));
+static void add_lookback_edge PARAMS((int, int, int));
+static void compute_FOLLOWS PARAMS((void));
+static void compute_lookaheads PARAMS((void));
+static void digraph PARAMS((short **));
+static void traverse PARAMS((register int));
+
+extern void berror PARAMS((const char *));
 
 static int infinity;
 static int maxrhs;
@@ -125,7 +126,7 @@ lalr (void)
 }
 
 
-void
+static void
 set_state_table (void)
 {
   register core *sp;
@@ -137,7 +138,7 @@ set_state_table (void)
 }
 
 
-void
+static void
 set_accessing_symbol (void)
 {
   register core *sp;
@@ -149,7 +150,7 @@ set_accessing_symbol (void)
 }
 
 
-void
+static void
 set_shift_table (void)
 {
   register shifts *sp;
@@ -161,7 +162,7 @@ set_shift_table (void)
 }
 
 
-void
+static void
 set_reduction_table (void)
 {
   register reductions *rp;
@@ -173,7 +174,7 @@ set_reduction_table (void)
 }
 
 
-void
+static void
 set_maxrhs (void)
 {
   register short *itemp;
@@ -199,7 +200,7 @@ set_maxrhs (void)
 }
 
 
-void
+static void
 initialize_LA (void)
 {
   register int i;
@@ -266,7 +267,7 @@ initialize_LA (void)
 }
 
 
-void
+static void
 set_goto_map (void)
 {
   register shifts *sp;
@@ -336,7 +337,7 @@ set_goto_map (void)
 
 /*  Map_goto maps a state/symbol pair into its numeric representation.	*/
 
-int
+static int
 map_goto (int state, int symbol)
 {
   register int high;
@@ -365,7 +366,7 @@ map_goto (int state, int symbol)
 }
 
 
-void
+static void
 initialize_F (void)
 {
   register int i;
@@ -441,7 +442,7 @@ initialize_F (void)
 }
 
 
-void
+static void
 build_relations (void)
 {
   register int i;
@@ -536,7 +537,7 @@ build_relations (void)
 }
 
 
-void
+static void
 add_lookback_edge (int stateno, int ruleno, int gotono)
 {
   register int i;
@@ -566,7 +567,7 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
 
 
 
-short **
+static short **
 transpose (short **R_arg, int n)
 {
   register short **new_R;
@@ -621,7 +622,7 @@ transpose (short **R_arg, int n)
 }
 
 
-void
+static void
 compute_FOLLOWS (void)
 {
   register int i;
@@ -637,7 +638,7 @@ compute_FOLLOWS (void)
 }
 
 
-void
+static void
 compute_lookaheads (void)
 {
   register int i;
@@ -680,7 +681,7 @@ compute_lookaheads (void)
 }
 
 
-void
+static void
 digraph (short **relation)
 {
   register int i;
@@ -706,7 +707,7 @@ digraph (short **relation)
 }
 
 
-void
+static void
 traverse (register int i)
 {
   register unsigned *fp1;
