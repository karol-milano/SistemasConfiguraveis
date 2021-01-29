@@ -64,3 +64,19 @@ errs_dup (errs *src)
   memcpy (res->errs, src->errs, src->nerrs);
   return res;
 }
+
+/*-------------------------------------.
+| Create a new array of N reductions.  |
+`-------------------------------------*/
+
+#define REDUCTIONS_ALLOC(Nreductions)					\
+  (reductions *) xcalloc ((unsigned) (sizeof (reductions)		\
+                                  + (Nreductions - 1) * sizeof (short)), 1)
+
+reductions *
+reductions_new (int n)
+{
+  reductions *res = REDUCTIONS_ALLOC (n);
+  res->nreds = n;
+  return res;
+}
