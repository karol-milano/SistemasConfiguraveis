@@ -26,6 +26,10 @@
 | Create a new array of N shitfs.  |
 `---------------------------------*/
 
+#define SHIFTS_ALLOC(Nshifts)						\
+  (shifts *) xcalloc ((unsigned) (sizeof (shifts) 			\
+                                  + (Nshifts - 1) * sizeof (short)), 1)
+
 shifts *
 shifts_new (int n)
 {
@@ -33,3 +37,30 @@ shifts_new (int n)
   res->nshifts = n;
   return res;
 }
+
+
+/*-------------------------------.
+| Create a new array of N errs.  |
+`-------------------------------*/
+
+#define ERRS_ALLOC(Nerrs)						\
+  (errs *) xcalloc ((unsigned) (sizeof (errs) 				\
+                                  + (Nerrs - 1) * sizeof (short)), 1)
+
+
+errs *
+errs_new (int n)
+{
+  errs *res = ERRS_ALLOC (n);
+  res->nerrs = n;
+  return res;
+}
+
+
+errs *
+errs_dup (errs *src)
+{
+  errs *res = errs_new (src->nerrs);
+  memcpy (res->errs, src->errs, src->nerrs);
+  return res;
+}
