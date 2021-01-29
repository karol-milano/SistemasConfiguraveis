@@ -23,7 +23,7 @@
    The entry point is generate_states.  */
 
 #include "system.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "gram.h"
 #include "state.h"
 #include "complain.h"
@@ -68,7 +68,7 @@ allocate_itemsets (void)
   short *symbol_count;
 
   count = 0;
-  symbol_count = NEW2 (nsyms, short);
+  symbol_count = XCALLOC (short, nsyms);
 
   itemp = ritem;
   symbol = *itemp++;
@@ -88,8 +88,8 @@ allocate_itemsets (void)
      appears as an item, which is symbol_count[symbol].
      We allocate that much space for each symbol.  */
 
-  kernel_base = NEW2 (nsyms, short *);
-  kernel_items = NEW2 (count, short);
+  kernel_base = XCALLOC (short *, nsyms);
+  kernel_items = XCALLOC (short, count);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
@@ -99,7 +99,7 @@ allocate_itemsets (void)
     }
 
   shift_symbol = symbol_count;
-  kernel_end = NEW2 (nsyms, short *);
+  kernel_end = XCALLOC (short *, nsyms);
 }
 
 
@@ -108,22 +108,22 @@ allocate_storage (void)
 {
   allocate_itemsets ();
 
-  shiftset = NEW2 (nsyms, short);
-  redset = NEW2 (nrules + 1, short);
-  state_table = NEW2 (STATE_TABLE_SIZE, core *);
+  shiftset = XCALLOC (short, nsyms);
+  redset = XCALLOC (short, nrules + 1);
+  state_table = XCALLOC (core *, STATE_TABLE_SIZE);
 }
 
 
 static void
 free_storage (void)
 {
-  FREE (shift_symbol);
-  FREE (redset);
-  FREE (shiftset);
-  FREE (kernel_base);
-  FREE (kernel_end);
-  FREE (kernel_items);
-  FREE (state_table);
+  XFREE (shift_symbol);
+  XFREE (redset);
+  XFREE (shiftset);
+  XFREE (kernel_base);
+  XFREE (kernel_end);
+  XFREE (kernel_items);
+  XFREE (state_table);
 }
 
 
@@ -211,7 +211,7 @@ new_state (int symbol)
   n = iend - isp1;
 
   p =
-    (core *) xmalloc ((unsigned) (sizeof (core) + (n - 1) * sizeof (short)));
+    (core *) xcalloc ((unsigned) (sizeof (core) + (n - 1) * sizeof (short)), 1);
   p->accessing_symbol = symbol;
   p->number = nstates;
   p->nitems = n;
@@ -349,7 +349,7 @@ new_states (void)
 {
   core *p;
 
-  p = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
+  p = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
   first_state = last_state = this_state = p;
   nstates = 1;
 }
@@ -363,8 +363,8 @@ save_shifts (void)
   short *sp2;
   short *send;
 
-  p = (shifts *) xmalloc ((unsigned) (sizeof (shifts) +
-				      (nshifts - 1) * sizeof (short)));
+  p = (shifts *) xcalloc ((unsigned) (sizeof (shifts) +
+				      (nshifts - 1) * sizeof (short)), 1);
 
   p->number = this_state->number;
   p->nshifts = nshifts;
@@ -400,7 +400,7 @@ insert_start_shift (void)
   core *statep;
   shifts *sp;
 
-  statep = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
+  statep = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
   statep->number = nstates;
   statep->accessing_symbol = start_symbol;
 
@@ -408,7 +408,7 @@ insert_start_shift (void)
   last_state = statep;
 
   /* Make a shift from this state to (what will be) the final state.  */
-  sp = NEW (shifts);
+  sp = XCALLOC (shifts, 1);
   sp->number = nstates++;
   sp->nshifts = 1;
   sp->shifts[0] = nstates;
@@ -465,10 +465,10 @@ augment_automaton (void)
 
 	      if (sp && sp->number == k)
 		{
-		  sp2 = (shifts *) xmalloc ((unsigned) (sizeof (shifts)
+		  sp2 = (shifts *) xcalloc ((unsigned) (sizeof (shifts)
 							+
 							sp->nshifts *
-							sizeof (short)));
+							sizeof (short)), 1);
 		  sp2->number = k;
 		  sp2->nshifts = sp->nshifts + 1;
 		  sp2->shifts[0] = nstates;
@@ -481,11 +481,11 @@ augment_automaton (void)
 		  sp1->next = sp2;
 		  if (sp == last_shift)
 		    last_shift = sp2;
-		  FREE (sp);
+		  XFREE (sp);
 		}
 	      else
 		{
-		  sp2 = NEW (shifts);
+		  sp2 = XCALLOC (shifts, 1);
 		  sp2->number = k;
 		  sp2->nshifts = 1;
 		  sp2->shifts[0] = nstates;
@@ -504,8 +504,8 @@ augment_automaton (void)
 	         going to the next-to-final state (yet to be made).  */
 	      sp = first_shift;
 
-	      sp2 = (shifts *) xmalloc (sizeof (shifts)
-					+ sp->nshifts * sizeof (short));
+	      sp2 = (shifts *) xcalloc (sizeof (shifts)
+					+ sp->nshifts * sizeof (short), 1);
 	      sp2->nshifts = sp->nshifts + 1;
 
 	      /* Stick this shift into the vector at the proper place.  */
@@ -527,7 +527,7 @@ augment_automaton (void)
 	      if (last_shift == sp)
 		last_shift = sp2;
 
-	      FREE (sp);
+	      XFREE (sp);
 
 	      /* Create the next-to-final state, with shift to
 	         what will be the final state.  */
@@ -538,7 +538,7 @@ augment_automaton (void)
 	{
 	  /* The initial state didn't even have any shifts.
 	     Give it one shift, to the next-to-final state.  */
-	  sp = NEW (shifts);
+	  sp = XCALLOC (shifts, 1);
 	  sp->nshifts = 1;
 	  sp->shifts[0] = nstates;
 
@@ -556,7 +556,7 @@ augment_automaton (void)
       /* There are no shifts for any state.
          Make one shift, from the initial state to the next-to-final state.  */
 
-      sp = NEW (shifts);
+      sp = XCALLOC (shifts, 1);
       sp->nshifts = 1;
       sp->shifts[0] = nstates;
 
@@ -572,13 +572,13 @@ augment_automaton (void)
   /* Make the final state--the one that follows a shift from the
      next-to-final state.
      The symbol for that shift is 0 (end-of-file).  */
-  statep = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
+  statep = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
   statep->number = nstates;
   last_state->next = statep;
   last_state = statep;
 
   /* Make the shift from the final state to the termination state.  */
-  sp = NEW (shifts);
+  sp = XCALLOC (shifts, 1);
   sp->number = nstates++;
   sp->nshifts = 1;
   sp->shifts[0] = nstates;
@@ -590,7 +590,7 @@ augment_automaton (void)
   final_state = nstates;
 
   /* Make the termination state.  */
-  statep = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
+  statep = (core *) xcalloc ((unsigned) (sizeof (core) - sizeof (short)), 1);
   statep->number = nstates++;
   last_state->next = statep;
   last_state = statep;
@@ -629,8 +629,8 @@ save_reductions (void)
 
   if (count)
     {
-      p = (reductions *) xmalloc ((unsigned) (sizeof (reductions) +
-					      (count - 1) * sizeof (short)));
+      p = (reductions *) xcalloc ((unsigned) (sizeof (reductions) +
+					      (count - 1) * sizeof (short)), 1);
 
       p->number = this_state->number;
       p->nreds = count;
