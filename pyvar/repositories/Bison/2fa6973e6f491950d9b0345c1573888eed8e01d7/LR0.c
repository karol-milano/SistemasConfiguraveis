@@ -1,22 +1,22 @@
 /* Generate the nondeterministic finite state machine for bison,
    Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
 
 
 /* See comments in state.h for the data structures that represent it.
@@ -27,7 +27,7 @@ Boston, MA 02111-1307, USA.  */
 #include "gram.h"
 #include "state.h"
 #include "complain.h"
-
+#include "closure.h"
 
 extern char *nullable;
 extern short *itemset;
@@ -40,23 +40,7 @@ core *first_state;
 shifts *first_shift;
 reductions *first_reduction;
 
-extern void generate_states PARAMS((void));
-
-static int get_state PARAMS((int));
-static core *new_state PARAMS((int));
-static void allocate_itemsets PARAMS((void));
-static void allocate_storage PARAMS((void));
-static void free_storage PARAMS((void));
-static void new_itemsets PARAMS((void));
-static void append_states PARAMS((void));
-static void initialize_states PARAMS((void));
-static void save_shifts PARAMS((void));
-static void save_reductions PARAMS((void));
-static void augment_automaton PARAMS((void));
-static void insert_start_shift PARAMS((void));
-extern void initialize_closure PARAMS((int));
-extern void closure PARAMS((short *, int));
-extern void finalize_closure PARAMS((void));
+extern void generate_states PARAMS ((void));
 
 static core *this_state;
 static core *last_state;
@@ -78,19 +62,18 @@ static short *kernel_items;
 #define	STATE_TABLE_SIZE	1009
 static core **state_table;
 
-
-
+
 static void
 allocate_itemsets (void)
 {
-  register short *itemp;
-  register int symbol;
-  register int i;
-  register int count;
-  register short *symbol_count;
+  short *itemp;
+  int symbol;
+  int i;
+  int count;
+  short *symbol_count;
 
   count = 0;
-  symbol_count = NEW2(nsyms, short);
+  symbol_count = NEW2 (nsyms, short);
 
   itemp = ritem;
   symbol = *itemp++;
@@ -104,14 +87,14 @@ allocate_itemsets (void)
       symbol = *itemp++;
     }
 
-  /* see comments before new_itemsets.  All the vectors of items
-     live inside kernel_items.  The number of active items after
+  /* See comments before new_itemsets.  All the vectors of items
+     live inside KERNEL_ITEMS.  The number of active items after
      some symbol cannot be more than the number of times that symbol
      appears as an item, which is symbol_count[symbol].
      We allocate that much space for each symbol.  */
 
-  kernel_base = NEW2(nsyms, short *);
-  kernel_items = NEW2(count, short);
+  kernel_base = NEW2 (nsyms, short *);
+  kernel_items = NEW2 (count, short);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
@@ -121,94 +104,59 @@ allocate_itemsets (void)
     }
 
   shift_symbol = symbol_count;
-  kernel_end = NEW2(nsyms, short *);
+  kernel_end = NEW2 (nsyms, short *);
 }
 
 
 static void
 allocate_storage (void)
 {
-  allocate_itemsets();
+  allocate_itemsets ();
 
-  shiftset = NEW2(nsyms, short);
-  redset = NEW2(nrules + 1, short);
-  state_table = NEW2(STATE_TABLE_SIZE, core *);
+  shiftset = NEW2 (nsyms, short);
+  redset = NEW2 (nrules + 1, short);
+  state_table = NEW2 (STATE_TABLE_SIZE, core *);
 }
 
 
 static void
 free_storage (void)
 {
-  FREE(shift_symbol);
-  FREE(redset);
-  FREE(shiftset);
-  FREE(kernel_base);
-  FREE(kernel_end);
-  FREE(kernel_items);
-  FREE(state_table);
+  FREE (shift_symbol);
+  FREE (redset);
+  FREE (shiftset);
+  FREE (kernel_base);
+  FREE (kernel_end);
+  FREE (kernel_items);
+  FREE (state_table);
 }
 
 
 
-/* compute the nondeterministic finite state machine (see state.h for details)
-from the grammar.  */
-void
-generate_states (void)
-{
-  allocate_storage();
-  initialize_closure(nitems);
-  initialize_states();
-
-  while (this_state)
-    {
-      /* Set up ruleset and itemset for the transitions out of this state.
-         ruleset gets a 1 bit for each rule that could reduce now.
-	 itemset gets a vector of all the items that could be accepted next.  */
-      closure(this_state->items, this_state->nitems);
-      /* record the reductions allowed out of this state */
-      save_reductions();
-      /* find the itemsets of the states that shifts can reach */
-      new_itemsets();
-      /* find or create the core structures for those states */
-      append_states();
-
-      /* create the shifts structures for the shifts to those states,
-         now that the state numbers transitioning to are known */
-      if (nshifts > 0)
-        save_shifts();
-
-      /* states are queued when they are created; process them all */
-      this_state = this_state->next;
-    }
-
-  /* discard various storage */
-  finalize_closure();
-  free_storage();
-
-  /* set up initial and final states as parser wants them */
-  augment_automaton();
-}
-
 
+/*----------------------------------------------------------------.
+| Find which symbols can be shifted in the current state, and for |
+| each one record which items would be active after that shift.   |
+| Uses the contents of itemset.                                   |
+|                                                                 |
+| shift_symbol is set to a vector of the symbols that can be      |
+| shifted.  For each symbol in the grammar, kernel_base[symbol]   |
+| points to a vector of item numbers activated if that symbol is  |
+| shifted, and kernel_end[symbol] points after the end of that    |
+| vector.                                                         |
+`----------------------------------------------------------------*/
 
-/* Find which symbols can be shifted in the current state,
-   and for each one record which items would be active after that shift.
-   Uses the contents of itemset.
-   shift_symbol is set to a vector of the symbols that can be shifted.
-   For each symbol in the grammar, kernel_base[symbol] points to
-   a vector of item numbers activated if that symbol is shifted,
-   and kernel_end[symbol] points after the end of that vector.  */
 static void
 new_itemsets (void)
 {
-  register int i;
-  register int shiftcount;
-  register short *isp;
-  register short *ksp;
-  register int symbol;
-
-#ifdef	TRACE
-  fprintf(stderr, "Entering new_itemsets\n");
+  int i;
+  int shiftcount;
+  short *isp;
+  short *ksp;
+  int symbol;
+
+#if TRACE
+  fprintf (stderr, "Entering new_itemsets\n");
 #endif
 
   for (i = 0; i < nsyms; i++)
@@ -224,16 +172,16 @@ new_itemsets (void)
       symbol = ritem[i];
       if (symbol > 0)
 	{
-          ksp = kernel_end[symbol];
+	  ksp = kernel_end[symbol];
 
-          if (!ksp)
+	  if (!ksp)
 	    {
 	      shift_symbol[shiftcount++] = symbol;
 	      ksp = kernel_base[symbol];
 	    }
 
-          *ksp++ = i + 1;
-          kernel_end[symbol] = ksp;
+	  *ksp++ = i + 1;
+	  kernel_end[symbol] = ksp;
 	}
     }
 
@@ -242,63 +190,70 @@ new_itemsets (void)
 
 
 
-/* Use the information computed by new_itemsets to find the state numbers
-   reached by each shift transition from the current state.
+/*-----------------------------------------------------------------.
+| Subroutine of get_state.  Create a new state for those items, if |
+| necessary.                                                       |
+`-----------------------------------------------------------------*/
 
-   shiftset is set up as a vector of state numbers of those states.  */
-static void
-append_states (void)
+static core *
+new_state (int symbol)
 {
-  register int i;
-  register int j;
-  register int symbol;
+  int n;
+  core *p;
+  short *isp1;
+  short *isp2;
+  short *iend;
 
-#ifdef	TRACE
-  fprintf(stderr, "Entering append_states\n");
+#if TRACE
+  fprintf (stderr, "Entering new_state, symbol = %d\n", symbol);
 #endif
 
-  /* first sort shift_symbol into increasing order */
+  if (nstates >= MAXSHORT)
+    fatal (_("too many states (max %d)"), MAXSHORT);
 
-  for (i = 1; i < nshifts; i++)
-    {
-      symbol = shift_symbol[i];
-      j = i;
-      while (j > 0 && shift_symbol[j - 1] > symbol)
-	{
-	  shift_symbol[j] = shift_symbol[j - 1];
-	  j--;
-	}
-      shift_symbol[j] = symbol;
-    }
+  isp1 = kernel_base[symbol];
+  iend = kernel_end[symbol];
+  n = iend - isp1;
 
-  for (i = 0; i < nshifts; i++)
-    {
-      symbol = shift_symbol[i];
-      shiftset[i] = get_state(symbol);
-    }
-}
+  p =
+    (core *) xmalloc ((unsigned) (sizeof (core) + (n - 1) * sizeof (short)));
+  p->accessing_symbol = symbol;
+  p->number = nstates;
+  p->nitems = n;
+
+  isp2 = p->items;
+  while (isp1 < iend)
+    *isp2++ = *isp1++;
+
+  last_state->next = p;
+  last_state = p;
 
+  nstates++;
 
+  return p;
+}
 
-/* find the state number for the state we would get to
-(from the current state) by shifting symbol.
-Create a new state if no equivalent one exists already.
-Used by append_states  */
+
+/*--------------------------------------------------------------.
+| Find the state number for the state we would get to (from the |
+| current state) by shifting symbol.  Create a new state if no  |
+| equivalent one exists already.  Used by append_states.         |
+`--------------------------------------------------------------*/
 
 static int
 get_state (int symbol)
 {
-  register int key;
-  register short *isp1;
-  register short *isp2;
-  register short *iend;
-  register core *sp;
-  register int found;
+  int key;
+  short *isp1;
+  short *isp2;
+  short *iend;
+  core *sp;
+  int found;
 
   int n;
 
-#ifdef	TRACE
-  fprintf(stderr, "Entering get_state, symbol = %d\n", symbol);
+#if TRACE
+  fprintf (stderr, "Entering get_state, symbol = %d\n", symbol);
 #endif
 
   isp1 = kernel_base[symbol];
@@ -338,73 +293,68 @@ get_state (int symbol)
 		{
 		  sp = sp->link;
 		}
-	      else   /* bucket exhausted and no match */
+	      else		/* bucket exhausted and no match */
 		{
-		  sp = sp->link = new_state(symbol);
+		  sp = sp->link = new_state (symbol);
 		  found = 1;
 		}
 	    }
 	}
     }
-  else      /* bucket is empty */
+  else				/* bucket is empty */
     {
-      state_table[key] = sp = new_state(symbol);
+      state_table[key] = sp = new_state (symbol);
     }
 
   return sp->number;
 }
 
+/*------------------------------------------------------------------.
+| Use the information computed by new_itemsets to find the state    |
+| numbers reached by each shift transition from the current state.  |
+|                                                                   |
+| shiftset is set up as a vector of state numbers of those states.  |
+`------------------------------------------------------------------*/
 
-
-/* subroutine of get_state.  create a new state for those items, if necessary.  */
-
-static core *
-new_state (int symbol)
+static void
+append_states (void)
 {
-  register int n;
-  register core *p;
-  register short *isp1;
-  register short *isp2;
-  register short *iend;
-
-#ifdef	TRACE
-  fprintf(stderr, "Entering new_state, symbol = %d\n", symbol);
-#endif
-
-  if (nstates >= MAXSHORT)
-    fatal (_("too many states (max %d)"), MAXSHORT);
+  int i;
+  int j;
+  int symbol;
 
-  isp1 = kernel_base[symbol];
-  iend = kernel_end[symbol];
-  n = iend - isp1;
-
-  p = (core *) xmalloc((unsigned) (sizeof(core) + (n - 1) * sizeof(short)));
-  p->accessing_symbol = symbol;
-  p->number = nstates;
-  p->nitems = n;
-
-  isp2 = p->items;
-  while (isp1 < iend)
-    *isp2++ = *isp1++;
+#if TRACE
+  fprintf (stderr, "Entering append_states\n");
+#endif
 
-  last_state->next = p;
-  last_state = p;
+  /* first sort shift_symbol into increasing order */
 
-  nstates++;
+  for (i = 1; i < nshifts; i++)
+    {
+      symbol = shift_symbol[i];
+      j = i;
+      while (j > 0 && shift_symbol[j - 1] > symbol)
+	{
+	  shift_symbol[j] = shift_symbol[j - 1];
+	  j--;
+	}
+      shift_symbol[j] = symbol;
+    }
 
-  return p;
+  for (i = 0; i < nshifts; i++)
+    {
+      symbol = shift_symbol[i];
+      shiftset[i] = get_state (symbol);
+    }
 }
 
 
 static void
-initialize_states (void)
+new_states (void)
 {
-  register core *p;
-/*  register unsigned *rp1; JF unused */
-/*  register unsigned *rp2; JF unused */
-/*  register unsigned *rend; JF unused */
+  core *p;
 
-  p = (core *) xmalloc((unsigned) (sizeof(core) - sizeof(short)));
+  p = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
   first_state = last_state = this_state = p;
   nstates = 1;
 }
@@ -413,13 +363,13 @@ initialize_states (void)
 static void
 save_shifts (void)
 {
-  register shifts *p;
-  register short *sp1;
-  register short *sp2;
-  register short *send;
+  shifts *p;
+  short *sp1;
+  short *sp2;
+  short *send;
 
-  p = (shifts *) xmalloc((unsigned) (sizeof(shifts) +
-				     (nshifts - 1) * sizeof(short)));
+  p = (shifts *) xmalloc ((unsigned) (sizeof (shifts) +
+				      (nshifts - 1) * sizeof (short)));
 
   p->number = this_state->number;
   p->nshifts = nshifts;
@@ -444,80 +394,52 @@ save_shifts (void)
 }
 
 
+/*------------------------------------------------------------------.
+| Subroutine of augment_automaton.  Create the next-to-final state, |
+| to which a shift has already been made in the initial state.      |
+`------------------------------------------------------------------*/
 
-/* find which rules can be used for reduction transitions from the current state
-   and make a reductions structure for the state to record their rule numbers.  */
 static void
-save_reductions (void)
+insert_start_shift (void)
 {
-  register short *isp;
-  register short *rp1;
-  register short *rp2;
-  register int item;
-  register int count;
-  register reductions *p;
-
-  short *rend;
-
-  /* find and count the active items that represent ends of rules */
-
-  count = 0;
-  for (isp = itemset; isp < itemsetend; isp++)
-    {
-      item = ritem[*isp];
-      if (item < 0)
-	{
-	  redset[count++] = -item;
-	}
-    }
-
-  /* make a reductions structure and copy the data into it.  */
+  core *statep;
+  shifts *sp;
 
-  if (count)
-    {
-      p = (reductions *) xmalloc((unsigned) (sizeof(reductions) +
-					     (count - 1) * sizeof(short)));
-
-      p->number = this_state->number;
-      p->nreds = count;
+  statep = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
+  statep->number = nstates;
+  statep->accessing_symbol = start_symbol;
 
-      rp1 = redset;
-      rp2 = p->rules;
-      rend = rp1 + count;
+  last_state->next = statep;
+  last_state = statep;
 
-      while (rp1 < rend)
-	*rp2++ = *rp1++;
+  /* Make a shift from this state to (what will be) the final state.  */
+  sp = NEW (shifts);
+  sp->number = nstates++;
+  sp->nshifts = 1;
+  sp->shifts[0] = nstates;
 
-      if (last_reduction)
-	{
-	  last_reduction->next = p;
-	  last_reduction = p;
-	}
-      else
-	{
-	  first_reduction = p;
-	  last_reduction = p;
-	}
-    }
+  last_shift->next = sp;
+  last_shift = sp;
 }
 
 
+/*------------------------------------------------------------------.
+| Make sure that the initial state has a shift that accepts the     |
+| grammar's start symbol and goes to the next-to-final state, which |
+| has a shift going to the final state, which has a shift to the    |
+| termination state.  Create such states and shifts if they don't   |
+| happen to exist already.                                          |
+`------------------------------------------------------------------*/
 
-/* Make sure that the initial state has a shift that accepts the
-grammar's start symbol and goes to the next-to-final state,
-which has a shift going to the final state, which has a shift
-to the termination state.
-Create such states and shifts if they don't happen to exist already.  */
 static void
 augment_automaton (void)
 {
-  register int i;
-  register int k;
-/*  register int found; JF unused */
-  register core *statep;
-  register shifts *sp;
-  register shifts *sp2;
-  register shifts *sp1 = NULL;
+  int i;
+  int k;
+  core *statep;
+  shifts *sp;
+  shifts *sp2;
+  shifts *sp1 = NULL;
 
   sp = first_shift;
 
@@ -531,13 +453,13 @@ augment_automaton (void)
 	  /* The states reached by shifts from first_state are numbered 1...K.
 	     Look for one reached by start_symbol.  */
 	  while (statep->accessing_symbol < start_symbol
-		  && statep->number < k)
+		 && statep->number < k)
 	    statep = statep->next;
 
 	  if (statep->accessing_symbol == start_symbol)
 	    {
 	      /* We already have a next-to-final state.
-		 Make sure it has a shift to what will be the final state.  */
+	         Make sure it has a shift to what will be the final state.  */
 	      k = statep->number;
 
 	      while (sp && sp->number < k)
@@ -548,8 +470,10 @@ augment_automaton (void)
 
 	      if (sp && sp->number == k)
 		{
-		  sp2 = (shifts *) xmalloc((unsigned) (sizeof(shifts)
-						       + sp->nshifts * sizeof(short)));
+		  sp2 = (shifts *) xmalloc ((unsigned) (sizeof (shifts)
+							+
+							sp->nshifts *
+							sizeof (short)));
 		  sp2->number = k;
 		  sp2->nshifts = sp->nshifts + 1;
 		  sp2->shifts[0] = nstates;
@@ -562,11 +486,11 @@ augment_automaton (void)
 		  sp1->next = sp2;
 		  if (sp == last_shift)
 		    last_shift = sp2;
-		  FREE(sp);
+		  FREE (sp);
 		}
 	      else
 		{
-		  sp2 = NEW(shifts);
+		  sp2 = NEW (shifts);
 		  sp2->number = k;
 		  sp2->nshifts = 1;
 		  sp2->shifts[0] = nstates;
@@ -582,11 +506,11 @@ augment_automaton (void)
 	    {
 	      /* There is no next-to-final state as yet.  */
 	      /* Add one more shift in first_shift,
-		 going to the next-to-final state (yet to be made).  */
+	         going to the next-to-final state (yet to be made).  */
 	      sp = first_shift;
 
-	      sp2 = (shifts *) xmalloc(sizeof(shifts)
-					 + sp->nshifts * sizeof(short));
+	      sp2 = (shifts *) xmalloc (sizeof (shifts)
+					+ sp->nshifts * sizeof (short));
 	      sp2->nshifts = sp->nshifts + 1;
 
 	      /* Stick this shift into the vector at the proper place.  */
@@ -602,24 +526,24 @@ augment_automaton (void)
 		sp2->shifts[k++] = nstates;
 
 	      /* Patch sp2 into the chain of shifts
-		 in place of sp, at the beginning.  */
+	         in place of sp, at the beginning.  */
 	      sp2->next = sp->next;
 	      first_shift = sp2;
 	      if (last_shift == sp)
 		last_shift = sp2;
 
-	      FREE(sp);
+	      FREE (sp);
 
 	      /* Create the next-to-final state, with shift to
-		 what will be the final state.  */
-	      insert_start_shift();
+	         what will be the final state.  */
+	      insert_start_shift ();
 	    }
 	}
       else
 	{
 	  /* The initial state didn't even have any shifts.
 	     Give it one shift, to the next-to-final state.  */
-	  sp = NEW(shifts);
+	  sp = NEW (shifts);
 	  sp->nshifts = 1;
 	  sp->shifts[0] = nstates;
 
@@ -629,15 +553,15 @@ augment_automaton (void)
 
 	  /* Create the next-to-final state, with shift to
 	     what will be the final state.  */
-	  insert_start_shift();
+	  insert_start_shift ();
 	}
     }
   else
     {
       /* There are no shifts for any state.
-	 Make one shift, from the initial state to the next-to-final state.  */
+         Make one shift, from the initial state to the next-to-final state.  */
 
-      sp = NEW(shifts);
+      sp = NEW (shifts);
       sp->nshifts = 1;
       sp->shifts[0] = nstates;
 
@@ -646,20 +570,20 @@ augment_automaton (void)
       last_shift = sp;
 
       /* Create the next-to-final state, with shift to
-	 what will be the final state.  */
-      insert_start_shift();
+         what will be the final state.  */
+      insert_start_shift ();
     }
 
   /* Make the final state--the one that follows a shift from the
      next-to-final state.
      The symbol for that shift is 0 (end-of-file).  */
-  statep = (core *) xmalloc((unsigned) (sizeof(core) - sizeof(short)));
+  statep = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
   statep->number = nstates;
   last_state->next = statep;
   last_state = statep;
 
   /* Make the shift from the final state to the termination state.  */
-  sp = NEW(shifts);
+  sp = NEW (shifts);
   sp->number = nstates++;
   sp->nshifts = 1;
   sp->shifts[0] = nstates;
@@ -671,35 +595,111 @@ augment_automaton (void)
   final_state = nstates;
 
   /* Make the termination state.  */
-  statep = (core *) xmalloc((unsigned) (sizeof(core) - sizeof(short)));
+  statep = (core *) xmalloc ((unsigned) (sizeof (core) - sizeof (short)));
   statep->number = nstates++;
   last_state->next = statep;
   last_state = statep;
 }
 
 
-/* subroutine of augment_automaton.
-   Create the next-to-final state, to which a shift has already been made in
-   the initial state.  */
+/*----------------------------------------------------------------.
+| Find which rules can be used for reduction transitions from the |
+| current state and make a reductions structure for the state to  |
+| record their rule numbers.                                      |
+`----------------------------------------------------------------*/
+
 static void
-insert_start_shift (void)
+save_reductions (void)
 {
-  register core *statep;
-  register shifts *sp;
+  short *isp;
+  short *rp1;
+  short *rp2;
+  int item;
+  int count;
+  reductions *p;
 
-  statep = (core *) xmalloc((unsigned) (sizeof(core) - sizeof(short)));
-  statep->number = nstates;
-  statep->accessing_symbol = start_symbol;
+  short *rend;
 
-  last_state->next = statep;
-  last_state = statep;
+  /* Find and count the active items that represent ends of rules. */
 
-  /* Make a shift from this state to (what will be) the final state.  */
-  sp = NEW(shifts);
-  sp->number = nstates++;
-  sp->nshifts = 1;
-  sp->shifts[0] = nstates;
+  count = 0;
+  for (isp = itemset; isp < itemsetend; isp++)
+    {
+      item = ritem[*isp];
+      if (item < 0)
+	redset[count++] = -item;
+    }
 
-  last_shift->next = sp;
-  last_shift = sp;
+  /* Make a reductions structure and copy the data into it.  */
+
+  if (count)
+    {
+      p = (reductions *) xmalloc ((unsigned) (sizeof (reductions) +
+					      (count - 1) * sizeof (short)));
+
+      p->number = this_state->number;
+      p->nreds = count;
+
+      rp1 = redset;
+      rp2 = p->rules;
+      rend = rp1 + count;
+
+      for (/* nothing */; rp1 < rend; ++rp1, ++rp2)
+	*rp2 = *rp1;
+
+      if (last_reduction)
+	{
+	  last_reduction->next = p;
+	  last_reduction = p;
+	}
+      else
+	{
+	  first_reduction = p;
+	  last_reduction = p;
+	}
+    }
+}
+
+
+/*-------------------------------------------------------------------.
+| Compute the nondeterministic finite state machine (see state.h for |
+| details) from the grammar.                                         |
+`-------------------------------------------------------------------*/
+
+void
+generate_states (void)
+{
+  allocate_storage ();
+  new_closure (nitems);
+  new_states ();
+
+  while (this_state)
+    {
+      /* Set up ruleset and itemset for the transitions out of this
+         state.  ruleset gets a 1 bit for each rule that could reduce
+         now.  itemset gets a vector of all the items that could be
+         accepted next.  */
+      closure (this_state->items, this_state->nitems);
+      /* record the reductions allowed out of this state */
+      save_reductions ();
+      /* find the itemsets of the states that shifts can reach */
+      new_itemsets ();
+      /* find or create the core structures for those states */
+      append_states ();
+
+      /* create the shifts structures for the shifts to those states,
+         now that the state numbers transitioning to are known */
+      if (nshifts > 0)
+	save_shifts ();
+
+      /* states are queued when they are created; process them all */
+      this_state = this_state->next;
+    }
+
+  /* discard various storage */
+  free_closure ();
+  free_storage ();
+
+  /* set up initial and final states as parser wants them */
+  augment_automaton ();
 }
