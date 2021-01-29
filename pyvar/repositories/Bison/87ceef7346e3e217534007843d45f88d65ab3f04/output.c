@@ -1,4 +1,5 @@
 /* Output the generated parsing program for Bison.
+
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -67,6 +68,8 @@ Name (const char *name,							\
 {									\
   Type min = first;							\
   Type max = first;							\
+  long int lmin;							\
+  long int lmax;							\
   int i;								\
   int j = 1;								\
 									\
@@ -90,15 +93,15 @@ Name (const char *name,							\
   obstack_1grow (&format_obstack, 0);					\
   muscle_insert (name, obstack_finish (&format_obstack));		\
 									\
+  lmin = min;								\
+  lmax = max;								\
   /* Build `NAME_min' and `NAME_max' in the obstack. */			\
   obstack_fgrow1 (&format_obstack, "%s_min", name);			\
   obstack_1grow (&format_obstack, 0);					\
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack),		\
-			  (long int) min);				\
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmin);	\
   obstack_fgrow1 (&format_obstack, "%s_max", name);			\
   obstack_1grow (&format_obstack, 0);					\
-  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack),		\
-			  (long int) max);				\
+  MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmax);	\
 }
 
 GENERATE_MUSCLE_INSERT_TABLE(muscle_insert_unsigned_int_table, unsigned int)
@@ -190,7 +193,7 @@ prepare_symbols (void)
   /* Output YYTOKNUM. */
   {
     int i;
-    int *values = XCALLOC (int, ntokens);
+    int *values = MALLOC (values, ntokens);
     for (i = 0; i < ntokens; ++i)
       values[i] = symbols[i]->user_token_number;
     muscle_insert_int_table ("toknum", values,
@@ -210,13 +213,13 @@ prepare_rules (void)
 {
   rule_number r;
   unsigned int i = 0;
-  item_number *rhs = XMALLOC (item_number, nritems);
-  unsigned int *prhs = XMALLOC (unsigned int, nrules);
-  unsigned int *rline = XMALLOC (unsigned int, nrules);
-  symbol_number *r1 = XMALLOC (symbol_number, nrules);
-  unsigned int *r2 = XMALLOC (unsigned int, nrules);
-  short *dprec = XMALLOC (short, nrules);
-  short *merger = XMALLOC (short, nrules);
+  item_number *rhs = MALLOC (rhs, nritems);
+  unsigned int *prhs = MALLOC (prhs, nrules);
+  unsigned int *rline = MALLOC (rline, nrules);
+  symbol_number *r1 = MALLOC (r1, nrules);
+  unsigned int *r2 = MALLOC (r2, nrules);
+  short *dprec = MALLOC (dprec, nrules);
+  short *merger = MALLOC (merger, nrules);
 
   for (r = 0; r < nrules; ++r)
     {
@@ -269,12 +272,12 @@ static void
 prepare_states (void)
 {
   state_number i;
-  symbol_number *values =
-    (symbol_number *) alloca (sizeof (symbol_number) * nstates);
+  symbol_number *values = MALLOC (values, nstates);
   for (i = 0; i < nstates; ++i)
     values[i] = states[i]->accessing_symbol;
   muscle_insert_symbol_number_table ("stos", values,
 				     0, 1, nstates);
+  free (values);
 
   MUSCLE_INSERT_INT ("last", high);
   MUSCLE_INSERT_INT ("final_state_number", final_state->number);
