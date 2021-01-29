@@ -35,32 +35,32 @@
 | Create a new array of N shifts/gotos.  |
 `---------------------------------------*/
 
-#define SHIFTS_ALLOC(Nshifts)						\
-  (shifts_t *) xcalloc ((unsigned) (sizeof (shifts_t) 			\
+#define TRANSITIONS_ALLOC(Nshifts)						\
+  (transitions_t *) xcalloc ((unsigned) (sizeof (transitions_t) 			\
                                   + (Nshifts - 1) * sizeof (state_number_t)), 1)
 
-static shifts_t *
-shifts_new (int nshifts, state_number_t *shifts)
+static transitions_t *
+transitions_new (int num, state_number_t *the_states)
 {
-  shifts_t *res = SHIFTS_ALLOC (nshifts);
-  res->nshifts = nshifts;
-  memcpy (res->shifts, shifts, nshifts * sizeof (shifts[0]));
+  transitions_t *res = TRANSITIONS_ALLOC (num);
+  res->num = num;
+  memcpy (res->states, the_states, num * sizeof (the_states[0]));
   return res;
 }
 
 
-/*-----------------------------------------------------------------.
-| Return the state such these SHIFTS contain a shift/goto to it on |
-| SYMBOL.  Aborts if none found.                                   |
-`-----------------------------------------------------------------*/
+/*-------------------------------------------------------------------.
+| Return the state such these TRANSITIONS contain a shift/goto to it |
+| on SYMBOL.  Aborts if none found.                                  |
+`-------------------------------------------------------------------*/
 
 state_t *
-shifts_to (shifts_t *shifts, symbol_number_t s)
+transitions_to (transitions_t *shifts, symbol_number_t s)
 {
   int j;
-  for (j = 0; j < shifts->nshifts; j++)
-    if (SHIFT_SYMBOL (shifts, j) == s)
-      return states[shifts->shifts[j]];
+  for (j = 0; j < shifts->num; j++)
+    if (TRANSITION_SYMBOL (shifts, j) == s)
+      return states[shifts->states[j]];
   abort ();
 }
 
@@ -168,9 +168,9 @@ state_new (symbol_number_t accessing_symbol,
 `--------------------------*/
 
 void
-state_shifts_set (state_t *state, int nshifts, state_number_t *shifts)
+state_transitions_set (state_t *state, int nshifts, state_number_t *shifts)
 {
-  state->shifts = shifts_new (nshifts, shifts);
+  state->shifts = transitions_new (nshifts, shifts);
 }
 
 
