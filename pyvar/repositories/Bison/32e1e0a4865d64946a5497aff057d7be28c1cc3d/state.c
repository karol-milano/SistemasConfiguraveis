@@ -36,14 +36,15 @@
 `---------------------------------------*/
 
 #define SHIFTS_ALLOC(Nshifts)						\
-  (shifts *) xcalloc ((unsigned) (sizeof (shifts) 			\
-                                  + (Nshifts - 1) * sizeof (short)), 1)
+  (shifts_t *) xcalloc ((unsigned) (sizeof (shifts_t) 			\
+                                  + (Nshifts - 1) * sizeof (state_number_t)), 1)
 
-shifts *
-shifts_new (int n)
+static shifts_t *
+shifts_new (int nshifts, state_number_t *shifts)
 {
-  shifts *res = SHIFTS_ALLOC (n);
-  res->nshifts = n;
+  shifts_t *res = SHIFTS_ALLOC (nshifts);
+  res->nshifts = nshifts;
+  memcpy (res->shifts, shifts, nshifts * sizeof (shifts[0]));
   return res;
 }
 
@@ -147,6 +148,18 @@ state_new (symbol_number_t accessing_symbol,
 }
 
 
+/*--------------------------.
+| Set the shifts of STATE.  |
+`--------------------------*/
+
+void
+state_shifts_set (state_t *state, int nshifts, state_number_t *shifts)
+{
+  state->shifts = shifts_new (nshifts, shifts);
+}
+
+
+
 /*--------------------------------------------------------------.
 | Print on OUT all the lookaheads such that this STATE wants to |
 | reduce this RULE.                                             |
