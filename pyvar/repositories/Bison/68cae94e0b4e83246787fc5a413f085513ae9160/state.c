@@ -61,8 +61,7 @@ transitions_to (transitions *shifts, symbol_number sym)
   int j;
   for (j = 0; ; j++)
     {
-      if (shifts->num <= j)
-	abort ();
+      assert (j < shifts->num);
       if (TRANSITION_SYMBOL (shifts, j) == sym)
 	return shifts->states[j];
     }
@@ -136,8 +135,7 @@ state_new (symbol_number accessing_symbol,
   state *res;
   size_t items_size = nitems * sizeof *core;
 
-  if (STATE_NUMBER_MAXIMUM <= nstates)
-    abort ();
+  assert (nstates < STATE_NUMBER_MAXIMUM);
 
   res = xmalloc (offsetof (state, items) + items_size);
   res->number = nstates++;
@@ -214,8 +212,7 @@ state_reduction_find (state *s, rule *r)
 void
 state_errs_set (state *s, int num, symbol **tokens)
 {
-  if (s->errs)
-    abort ();
+  assert (!s->errs);
   s->errs = errs_new (num, tokens);
 }
 
