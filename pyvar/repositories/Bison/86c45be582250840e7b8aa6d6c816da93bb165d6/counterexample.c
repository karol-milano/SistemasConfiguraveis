@@ -70,14 +70,14 @@ list_get_end (gl_list_t list)
 
 typedef struct
 {
-  const derivation *d1;
-  const derivation *d2;
+  derivation *d1;
+  derivation *d2;
   bool unifying;
   bool timeout;
 } counterexample;
 
 counterexample *
-new_counterexample (const derivation *d1, const derivation *d2,
+new_counterexample (derivation *d1, derivation *d2,
                     bool u, bool t)
 {
   counterexample *res = xmalloc (sizeof (counterexample));
@@ -88,6 +88,14 @@ new_counterexample (const derivation *d1, const derivation *d2,
   return res;
 }
 
+void
+free_counterexample (counterexample *cex)
+{
+  derivation_free (cex->d1);
+  derivation_free (cex->d2);
+  free (cex);
+}
+
 void
 print_counterexample (counterexample *cex)
 {
@@ -1174,7 +1182,7 @@ counterexample_report (state_item_number itm1, state_item_number itm2,
 
   gl_list_free (shortest_path);
   print_counterexample (cex);
-
+  free_counterexample (cex);
 }
 
 void
