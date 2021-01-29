@@ -1,5 +1,5 @@
-/* Type definitions for nondeterministic finite state machine for bison,
-   Copyright (C) 2001, 2002  Free Software Foundation, Inc.
+/* Type definitions for nondeterministic finite state machine for Bison.
+   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -141,7 +141,8 @@ state_new (symbol_number_t accessing_symbol,
 {
   state_t *res;
 
-  assert (nstates < STATE_NUMBER_MAX);
+  if (STATE_NUMBER_MAX <= nstates)
+    abort ();
 
   res = STATE_ALLOC (core_size);
   res->accessing_symbol = accessing_symbol;
@@ -179,7 +180,8 @@ state_free (state_t *state)
 void
 state_transitions_set (state_t *state, int num, state_t **transitions)
 {
-  assert (!state->transitions);
+  if (state->transitions)
+    abort ();
   state->transitions = transitions_new (num, transitions);
 }
 
@@ -191,7 +193,8 @@ state_transitions_set (state_t *state, int num, state_t **transitions)
 void
 state_reductions_set (state_t *state, int num, rule_t **reductions)
 {
-  assert (!state->reductions);
+  if (state->reductions)
+    abort ();
   state->reductions = reductions_new (num, reductions);
 }
 
@@ -215,7 +218,8 @@ state_reduction_find (state_t *state, rule_t *rule)
 void
 state_errs_set (state_t *state, int num, symbol_t **tokens)
 {
-  assert (!state->errs);
+  if (state->errs)
+    abort ();
   state->errs = errs_new (num, tokens);
 }
 
