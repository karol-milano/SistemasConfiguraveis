@@ -42,7 +42,7 @@
 
    Of course vector_number_t ought to be wide enough to contain
    state_number and symbol_number.  */
-typedef short int vector_number;
+typedef int vector_number;
 
 static inline vector_number
 state_number_to_vector_number (state_number s)
@@ -84,7 +84,7 @@ int nvectors;
 static base_number **froms;
 static base_number **tos;
 static unsigned int **conflict_tos;
-static short int *tally;
+static int *tally;
 static base_number *width;
 
 
@@ -94,8 +94,8 @@ static base_number *width;
    If N = MIN, stands for `raise a syntax error'.
    If N > 0, stands for `shift SYMBOL and go to n'.
    If N < 0, stands for `reduce -N'.  */
-typedef short int action_number;
-#define ACTION_NUMBER_MINIMUM SHRT_MIN
+typedef int action_number;
+#define ACTION_NUMBER_MINIMUM INT_MIN
 
 static action_number *actrow;
 
@@ -516,14 +516,14 @@ save_column (symbol_number sym, state_number default_state)
 `-------------------------------------------------------------*/
 
 static state_number
-default_goto (symbol_number sym, short int state_count[])
+default_goto (symbol_number sym, size_t state_count[])
 {
   state_number s;
   goto_number i;
   goto_number m = goto_map[sym - ntokens];
   goto_number n = goto_map[sym - ntokens + 1];
   state_number default_state = -1;
-  int max = 0;
+  size_t max = 0;
 
   if (m == n)
     return -1;
@@ -558,7 +558,7 @@ static void
 goto_actions (void)
 {
   symbol_number i;
-  short int *state_count = xnmalloc (nstates, sizeof *state_count);
+  size_t *state_count = xnmalloc (nstates, sizeof *state_count);
   yydefgoto = xnmalloc (nvars, sizeof *yydefgoto);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
