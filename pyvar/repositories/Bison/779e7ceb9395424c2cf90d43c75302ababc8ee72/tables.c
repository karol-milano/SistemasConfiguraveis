@@ -1,6 +1,6 @@
 /* Output the generated parsing program for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -42,7 +42,7 @@
 
    Of course vector_number_t ought to be wide enough to contain
    state_number and symbol_number.  */
-typedef short vector_number;
+typedef short int vector_number;
 
 static inline vector_number
 state_number_to_vector_number (state_number s)
@@ -84,7 +84,7 @@ int nvectors;
 static base_number **froms = NULL;
 static base_number **tos = NULL;
 static unsigned int **conflict_tos = NULL;
-static short *tally = NULL;
+static short int *tally = NULL;
 static base_number *width = NULL;
 
 
@@ -94,7 +94,7 @@ static base_number *width = NULL;
    If N = MIN, stands for `raise a syntax error'.
    If N > 0, stands for `shift SYMBOL and go to n'.
    If N < 0, stands for `reduce -N'.  */
-typedef short action_number;
+typedef short int action_number;
 #define ACTION_NUMBER_MINIMUM SHRT_MIN
 
 static action_number *actrow = NULL;
@@ -512,7 +512,7 @@ save_column (symbol_number sym, state_number default_state)
 `-------------------------------------------------------------*/
 
 static state_number
-default_goto (symbol_number sym, short state_count[])
+default_goto (symbol_number sym, short int state_count[])
 {
   state_number s;
   int i;
@@ -554,7 +554,7 @@ static void
 goto_actions (void)
 {
   symbol_number i;
-  short *state_count = CALLOC (state_count, nstates);
+  short int *state_count = CALLOC (state_count, nstates);
   MALLOC (yydefgoto, nvars);
 
   /* For a given nterm I, STATE_COUNT[S] is the number of times there
