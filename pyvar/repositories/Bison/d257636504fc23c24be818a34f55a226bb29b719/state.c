@@ -76,14 +76,14 @@ transitions_to (transitions_t *shifts, symbol_number_t s)
 
 #define ERRS_ALLOC(Nerrs)						\
   (errs_t *) xcalloc ((unsigned) (sizeof (errs_t)			\
-                                  + (Nerrs - 1) * sizeof (short)), 1)
+                                  + (Nerrs - 1) * sizeof (symbol_number_t)), 1)
 
 
 errs_t *
 errs_new (int n)
 {
   errs_t *res = ERRS_ALLOC (n);
-  res->nerrs = n;
+  res->num = n;
   return res;
 }
 
@@ -91,8 +91,8 @@ errs_new (int n)
 errs_t *
 errs_dup (errs_t *src)
 {
-  errs_t *res = errs_new (src->nerrs);
-  memcpy (res->errs, src->errs, src->nerrs * sizeof (src->errs[0]));
+  errs_t *res = errs_new (src->num);
+  memcpy (res->symbols, src->symbols, src->num * sizeof (src->symbols[0]));
   return res;
 }
 
@@ -110,13 +110,13 @@ errs_dup (errs_t *src)
 
 #define REDUCTIONS_ALLOC(Nreductions)					\
   (reductions_t *) xcalloc ((unsigned) (sizeof (reductions_t)		\
-                                  + (Nreductions - 1) * sizeof (short)), 1)
+                                  + (Nreductions - 1) * sizeof (rule_number_t)), 1)
 
 static reductions_t *
 reductions_new (int nreductions, short *reductions)
 {
   reductions_t *res = REDUCTIONS_ALLOC (nreductions);
-  res->nreds = nreductions;
+  res->num = nreductions;
   memcpy (res->rules, reductions, nreductions * sizeof (reductions[0]));
   return res;
 }
