@@ -26,7 +26,7 @@
 #include "system.h"
 #include "types.h"
 #include "LR0.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "gram.h"
 #include "complain.h"
 #include "lalr.h"
@@ -123,8 +123,8 @@ digraph (short **relation)
   int i;
 
   infinity = ngotos + 2;
-  INDEX = NEW2 (ngotos + 1, short);
-  VERTICES = NEW2 (ngotos + 1, short);
+  INDEX = XCALLOC (short, ngotos + 1);
+  VERTICES = XCALLOC (short, ngotos + 1);
   top = 0;
 
   R = relation;
@@ -138,8 +138,8 @@ digraph (short **relation)
 	traverse (i);
     }
 
-  FREE (INDEX);
-  FREE (VERTICES);
+  XFREE (INDEX);
+  XFREE (VERTICES);
 }
 
 static void
@@ -147,7 +147,7 @@ set_state_table (void)
 {
   core *sp;
 
-  state_table = NEW2 (nstates, core *);
+  state_table = XCALLOC (core *, nstates);
 
   for (sp = first_state; sp; sp = sp->next)
     state_table[sp->number] = sp;
@@ -159,7 +159,7 @@ set_accessing_symbol (void)
 {
   core *sp;
 
-  accessing_symbol = NEW2 (nstates, short);
+  accessing_symbol = XCALLOC (short, nstates);
 
   for (sp = first_state; sp; sp = sp->next)
     accessing_symbol[sp->number] = sp->accessing_symbol;
@@ -171,7 +171,7 @@ set_shift_table (void)
 {
   shifts *sp;
 
-  shift_table = NEW2 (nstates, shifts *);
+  shift_table = XCALLOC (shifts *, nstates);
 
   for (sp = first_shift; sp; sp = sp->next)
     shift_table[sp->number] = sp;
@@ -183,7 +183,7 @@ set_reduction_table (void)
 {
   reductions *rp;
 
-  reduction_table = NEW2 (nstates, reductions *);
+  reduction_table = XCALLOC (reductions *, nstates);
 
   for (rp = first_reduction; rp; rp = rp->next)
     reduction_table[rp->number] = rp;
@@ -227,8 +227,8 @@ initialize_LA (void)
   shifts *sp;
   short *np;
 
-  consistent = NEW2 (nstates, char);
-  lookaheads = NEW2 (nstates + 1, short);
+  consistent = XCALLOC (char, nstates);
+  lookaheads = XCALLOC (short, nstates + 1);
 
   count = 0;
   for (i = 0; i < nstates; i++)
@@ -260,15 +260,15 @@ initialize_LA (void)
 
   if (count == 0)
     {
-      LA = NEW2 (1 * tokensetsize, unsigned);
-      LAruleno = NEW2 (1, short);
-      lookback = NEW2 (1, shorts *);
+      LA = XCALLOC (unsigned, 1 * tokensetsize);
+      LAruleno = XCALLOC (short, 1);
+      lookback = XCALLOC (shorts *, 1);
     }
   else
     {
-      LA = NEW2 (count * tokensetsize, unsigned);
-      LAruleno = NEW2 (count, short);
-      lookback = NEW2 (count, shorts *);
+      LA = XCALLOC (unsigned, count * tokensetsize);
+      LAruleno = XCALLOC (short, count);
+      lookback = XCALLOC (shorts *, count);
     }
 
   np = LAruleno;
@@ -295,8 +295,8 @@ set_goto_map (void)
   int state2;
   int state1;
 
-  goto_map = NEW2 (nvars + 1, short) - ntokens;
-  temp_map = NEW2 (nvars + 1, short) - ntokens;
+  goto_map = XCALLOC (short, nvars + 1) - ntokens;
+  temp_map = XCALLOC (short, nvars + 1) - ntokens;
 
   ngotos = 0;
   for (sp = first_shift; sp; sp = sp->next)
@@ -329,8 +329,8 @@ set_goto_map (void)
   goto_map[nsyms] = ngotos;
   temp_map[nsyms] = ngotos;
 
-  from_state = NEW2 (ngotos, short);
-  to_state = NEW2 (ngotos, short);
+  from_state = XCALLOC (short, ngotos);
+  to_state = XCALLOC (short, ngotos);
 
   for (sp = first_shift; sp; sp = sp->next)
     {
@@ -349,7 +349,7 @@ set_goto_map (void)
 	}
     }
 
-  FREE (temp_map + ntokens);
+  XFREE (temp_map + ntokens);
 }
 
 
@@ -402,10 +402,10 @@ initialize_F (void)
   int nwords;
 
   nwords = ngotos * tokensetsize;
-  F = NEW2 (nwords, unsigned);
+  F = XCALLOC (unsigned, nwords);
 
-  reads = NEW2 (ngotos, short *);
-  edge = NEW2 (ngotos + 1, short);
+  reads = XCALLOC (short *, ngotos);
+  edge = XCALLOC (short, ngotos + 1);
   nedges = 0;
 
   rowp = F;
@@ -435,7 +435,7 @@ initialize_F (void)
 
 	  if (nedges)
 	    {
-	      reads[i] = rp = NEW2 (nedges + 1, short);
+	      reads[i] = rp = XCALLOC (short, nedges + 1);
 
 	      for (j = 0; j < nedges; j++)
 		rp[j] = edge[j];
@@ -453,11 +453,11 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       if (reads[i])
-	FREE (reads[i]);
+	XFREE (reads[i]);
     }
 
-  FREE (reads);
-  FREE (edge);
+  XFREE (reads);
+  XFREE (edge);
 }
 
 
@@ -482,7 +482,7 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
 
   assert (found);
 
-  sp = NEW (shorts);
+  sp = XCALLOC (shorts, 1);
   sp->next = lookback[i];
   sp->value = gotono;
   lookback[i] = sp;
@@ -499,7 +499,7 @@ transpose (short **R_arg, int n)
   int i;
   int k;
 
-  nedges = NEW2 (n, short);
+  nedges = XCALLOC (short, n);
 
   for (i = 0; i < n; i++)
     {
@@ -511,22 +511,22 @@ transpose (short **R_arg, int n)
 	}
     }
 
-  new_R = NEW2 (n, short *);
-  temp_R = NEW2 (n, short *);
+  new_R = XCALLOC (short *, n);
+  temp_R = XCALLOC (short *, n);
 
   for (i = 0; i < n; i++)
     {
       k = nedges[i];
       if (k > 0)
 	{
-	  sp = NEW2 (k + 1, short);
+	  sp = XCALLOC (short, k + 1);
 	  new_R[i] = sp;
 	  temp_R[i] = sp;
 	  sp[k] = -1;
 	}
     }
 
-  FREE (nedges);
+  XFREE (nedges);
 
   for (i = 0; i < n; i++)
     {
@@ -538,7 +538,7 @@ transpose (short **R_arg, int n)
 	}
     }
 
-  FREE (temp_R);
+  XFREE (temp_R);
 
   return new_R;
 }
@@ -565,9 +565,9 @@ build_relations (void)
   short *states;
   short **new_includes;
 
-  includes = NEW2 (ngotos, short *);
-  edge = NEW2 (ngotos + 1, short);
-  states = NEW2 (maxrhs + 1, short);
+  includes = XCALLOC (short *, ngotos);
+  edge = XCALLOC (short, ngotos + 1);
+  states = XCALLOC (short, maxrhs + 1);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -619,7 +619,7 @@ build_relations (void)
 
       if (nedges)
 	{
-	  includes[i] = shortp = NEW2 (nedges + 1, short);
+	  includes[i] = shortp = XCALLOC (short, nedges + 1);
 	  for (j = 0; j < nedges; j++)
 	    shortp[j] = edge[j];
 	  shortp[nedges] = -1;
@@ -630,14 +630,14 @@ build_relations (void)
 
   for (i = 0; i < ngotos; i++)
     if (includes[i])
-      FREE (includes[i]);
+      XFREE (includes[i]);
 
-  FREE (includes);
+  XFREE (includes);
 
   includes = new_includes;
 
-  FREE (edge);
-  FREE (states);
+  XFREE (edge);
+  XFREE (states);
 }
 
 
@@ -652,10 +652,10 @@ compute_FOLLOWS (void)
   for (i = 0; i < ngotos; i++)
     {
       if (includes[i])
-	FREE (includes[i]);
+	XFREE (includes[i]);
     }
 
-  FREE (includes);
+  XFREE (includes);
 }
 
 
@@ -693,12 +693,12 @@ compute_lookaheads (void)
       for (sp = lookback[i]; sp; sp = sptmp)
 	{
 	  sptmp = sp->next;
-	  FREE (sp);
+	  XFREE (sp);
 	}
     }
 
-  FREE (lookback);
-  FREE (F);
+  XFREE (lookback);
+  XFREE (F);
 }
 
 
