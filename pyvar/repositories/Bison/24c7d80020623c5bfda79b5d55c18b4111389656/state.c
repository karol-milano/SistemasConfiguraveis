@@ -49,6 +49,20 @@ shifts_new (int nshifts, state_number_t *shifts)
 }
 
 
+/*-----------------------------------------------------------------.
+| Return the state such these SHIFTS contain a shift/goto to it on |
+| SYMBOL.  Aborts if none found.                                   |
+`-----------------------------------------------------------------*/
+
+state_t *
+shifts_to (shifts_t *shifts, symbol_number_t s)
+{
+  int j;
+  for (j = 0; j < shifts->nshifts; j++)
+    if (SHIFT_SYMBOL (shifts, j) == s)
+      return states[shifts->shifts[j]];
+  abort ();
+}
 
 
 			/*--------------------.
