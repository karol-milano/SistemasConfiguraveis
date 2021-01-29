@@ -61,23 +61,23 @@ shifts_new (int nshifts, state_number_t *shifts)
 `-------------------------------*/
 
 #define ERRS_ALLOC(Nerrs)						\
-  (errs *) xcalloc ((unsigned) (sizeof (errs) 				\
+  (errs_t *) xcalloc ((unsigned) (sizeof (errs_t)			\
                                   + (Nerrs - 1) * sizeof (short)), 1)
 
 
-errs *
+errs_t *
 errs_new (int n)
 {
-  errs *res = ERRS_ALLOC (n);
+  errs_t *res = ERRS_ALLOC (n);
   res->nerrs = n;
   return res;
 }
 
 
-errs *
-errs_dup (errs *src)
+errs_t *
+errs_dup (errs_t *src)
 {
-  errs *res = errs_new (src->nerrs);
+  errs_t *res = errs_new (src->nerrs);
   memcpy (res->errs, src->errs, src->nerrs * sizeof (src->errs[0]));
   return res;
 }
@@ -95,14 +95,15 @@ errs_dup (errs *src)
 `-------------------------------------*/
 
 #define REDUCTIONS_ALLOC(Nreductions)					\
-  (reductions *) xcalloc ((unsigned) (sizeof (reductions)		\
+  (reductions_t *) xcalloc ((unsigned) (sizeof (reductions_t)		\
                                   + (Nreductions - 1) * sizeof (short)), 1)
 
-reductions *
-reductions_new (int n)
+static reductions_t *
+reductions_new (int nreductions, short *reductions)
 {
-  reductions *res = REDUCTIONS_ALLOC (n);
-  res->nreds = n;
+  reductions_t *res = REDUCTIONS_ALLOC (nreductions);
+  res->nreds = nreductions;
+  memcpy (res->rules, reductions, nreductions * sizeof (reductions[0]));
   return res;
 }
 
@@ -159,6 +160,17 @@ state_shifts_set (state_t *state, int nshifts, state_number_t *shifts)
 }
 
 
+/*------------------------------.
+| Set the reductions of STATE.  |
+`------------------------------*/
+
+void
+state_reductions_set (state_t *state, int nreductions, short *reductions)
+{
+  state->reductions = reductions_new (nreductions, reductions);
+}
+
+
 
 /*--------------------------------------------------------------.
 | Print on OUT all the lookaheads such that this STATE wants to |
