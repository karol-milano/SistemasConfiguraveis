@@ -19,34 +19,9 @@ the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 Boston, MA 02111-1307, USA.  */
 
 
-/* Compute how to make the finite state machine deterministic;
- find which rules need lookahead in each state, and which lookahead tokens they accept.
-
-lalr(), the entry point, builds these data structures:
-
-goto_map, from_state and to_state
- record each shift transition which accepts a variable (a nonterminal).
-ngotos is the number of such transitions.
-from_state[t] is the state number which a transition leads from
-and to_state[t] is the state number it leads to.
-All the transitions that accept a particular variable are grouped together and
-goto_map[i - ntokens] is the index in from_state and to_state of the first of them.
-
-consistent[s] is nonzero if no lookahead is needed to decide what to do in state s.
-
-LAruleno is a vector which records the rules that need lookahead in various states.
-The elements of LAruleno that apply to state s are those from
- lookaheads[s] through lookaheads[s+1]-1.
-Each element of LAruleno is a rule number.
-
-If lr is the length of LAruleno, then a number from 0 to lr-1
-can specify both a rule and a state where the rule might be applied.
-
-LA is a lr by ntokens matrix of bits.
-LA[l, i] is 1 if the rule LAruleno[l] is applicable in the appropriate state
- when the next token is symbol i.
-If LA[l, i] and LA[l, j] are both 1 for i != j, it is a conflict.
-*/
+/* Compute how to make the finite state machine deterministic; find
+   which rules need lookahead in each state, and which lookahead
+   tokens they accept. */
 
 #include "system.h"
 #include "types.h"
@@ -54,6 +29,7 @@ If LA[l, i] and LA[l, j] are both 1 for i != j, it is a conflict.
 #include "alloc.h"
 #include "gram.h"
 #include "complain.h"
+#include "lalr.h"
 
 extern short **derives;
 extern char *nullable;
@@ -72,26 +48,7 @@ short *goto_map;
 short *from_state;
 short *to_state;
 
-extern void lalr PARAMS((void));
-
-static short **transpose PARAMS((short **, int));
-static void set_state_table PARAMS((void));
-static void set_accessing_symbol PARAMS((void));
-static void set_shift_table PARAMS((void));
-static void set_reduction_table PARAMS((void));
-static void set_maxrhs PARAMS((void));
-static void initialize_LA PARAMS((void));
-static void set_goto_map PARAMS((void));
-static int map_goto PARAMS((int, int));
-static void initialize_F PARAMS((void));
-static void build_relations PARAMS((void));
-static void add_lookback_edge PARAMS((int, int, int));
-static void compute_FOLLOWS PARAMS((void));
-static void compute_lookaheads PARAMS((void));
-static void digraph PARAMS((short **));
-static void traverse PARAMS((register int));
-
-extern void berror PARAMS((const char *));
+extern void berror PARAMS ((const char *));
 
 static int infinity;
 static int maxrhs;
@@ -105,31 +62,94 @@ static short *VERTICES;
 static int top;
 
 
-void
-lalr (void)
+static void
+traverse (int i)
 {
-  tokensetsize = WORDSIZE(ntokens);
-
-  set_state_table();
-  set_accessing_symbol();
-  set_shift_table();
-  set_reduction_table();
-  set_maxrhs();
-  initialize_LA();
-  set_goto_map();
-  initialize_F();
-  build_relations();
-  compute_FOLLOWS();
-  compute_lookaheads();
+  unsigned *fp1;
+  unsigned *fp2;
+  unsigned *fp3;
+  int j;
+  short *rp;
+
+  int height;
+  unsigned *base;
+
+  VERTICES[++top] = i;
+  INDEX[i] = height = top;
+
+  base = F + i * tokensetsize;
+  fp3 = base + tokensetsize;
+
+  rp = R[i];
+  if (rp)
+    {
+      while ((j = *rp++) >= 0)
+	{
+	  if (INDEX[j] == 0)
+	    traverse (j);
+
+	  if (INDEX[i] > INDEX[j])
+	    INDEX[i] = INDEX[j];
+
+	  fp1 = base;
+	  fp2 = F + j * tokensetsize;
+
+	  while (fp1 < fp3)
+	    *fp1++ |= *fp2++;
+	}
+    }
+
+  if (INDEX[i] == height)
+    {
+      for (;;)
+	{
+	  j = VERTICES[top--];
+	  INDEX[j] = infinity;
+
+	  if (i == j)
+	    break;
+
+	  fp1 = base;
+	  fp2 = F + j * tokensetsize;
+
+	  while (fp1 < fp3)
+	    *fp2++ = *fp1++;
+	}
+    }
 }
 
 
+static void
+digraph (short **relation)
+{
+  int i;
+
+  infinity = ngotos + 2;
+  INDEX = NEW2 (ngotos + 1, short);
+  VERTICES = NEW2 (ngotos + 1, short);
+  top = 0;
+
+  R = relation;
+
+  for (i = 0; i < ngotos; i++)
+    INDEX[i] = 0;
+
+  for (i = 0; i < ngotos; i++)
+    {
+      if (INDEX[i] == 0 && R[i])
+	traverse (i);
+    }
+
+  FREE (INDEX);
+  FREE (VERTICES);
+}
+
 static void
 set_state_table (void)
 {
-  register core *sp;
+  core *sp;
 
-  state_table = NEW2(nstates, core *);
+  state_table = NEW2 (nstates, core *);
 
   for (sp = first_state; sp; sp = sp->next)
     state_table[sp->number] = sp;
@@ -139,9 +159,9 @@ set_state_table (void)
 static void
 set_accessing_symbol (void)
 {
-  register core *sp;
+  core *sp;
 
-  accessing_symbol = NEW2(nstates, short);
+  accessing_symbol = NEW2 (nstates, short);
 
   for (sp = first_state; sp; sp = sp->next)
     accessing_symbol[sp->number] = sp->accessing_symbol;
@@ -151,9 +171,9 @@ set_accessing_symbol (void)
 static void
 set_shift_table (void)
 {
-  register shifts *sp;
+  shifts *sp;
 
-  shift_table = NEW2(nstates, shifts *);
+  shift_table = NEW2 (nstates, shifts *);
 
   for (sp = first_shift; sp; sp = sp->next)
     shift_table[sp->number] = sp;
@@ -163,9 +183,9 @@ set_shift_table (void)
 static void
 set_reduction_table (void)
 {
-  register reductions *rp;
+  reductions *rp;
 
-  reduction_table = NEW2(nstates, reductions *);
+  reduction_table = NEW2 (nstates, reductions *);
 
   for (rp = first_reduction; rp; rp = rp->next)
     reduction_table[rp->number] = rp;
@@ -175,9 +195,9 @@ set_reduction_table (void)
 static void
 set_maxrhs (void)
 {
-  register short *itemp;
-  register int length;
-  register int max;
+  short *itemp;
+  int length;
+  int max;
 
   length = 0;
   max = 0;
@@ -189,7 +209,8 @@ set_maxrhs (void)
 	}
       else
 	{
-	  if (length > max) max = length;
+	  if (length > max)
+	    max = length;
 	  length = 0;
 	}
     }
@@ -201,27 +222,27 @@ set_maxrhs (void)
 static void
 initialize_LA (void)
 {
-  register int i;
-  register int j;
-  register int count;
-  register reductions *rp;
-  register shifts *sp;
-  register short *np;
+  int i;
+  int j;
+  int count;
+  reductions *rp;
+  shifts *sp;
+  short *np;
 
-  consistent = NEW2(nstates, char);
-  lookaheads = NEW2(nstates + 1, short);
+  consistent = NEW2 (nstates, char);
+  lookaheads = NEW2 (nstates + 1, short);
 
   count = 0;
   for (i = 0; i < nstates; i++)
     {
-      register int k;
+      int k;
 
       lookaheads[i] = count;
 
       rp = reduction_table[i];
       sp = shift_table[i];
       if (rp && (rp->nreds > 1
-          || (sp && ! ISVAR(accessing_symbol[sp->shifts[0]]))))
+		 || (sp && !ISVAR (accessing_symbol[sp->shifts[0]]))))
 	count += rp->nreds;
       else
 	consistent[i] = 1;
@@ -241,15 +262,15 @@ initialize_LA (void)
 
   if (count == 0)
     {
-      LA = NEW2(1 * tokensetsize, unsigned);
-      LAruleno = NEW2(1, short);
-      lookback = NEW2(1, shorts *);
+      LA = NEW2 (1 * tokensetsize, unsigned);
+      LAruleno = NEW2 (1, short);
+      lookback = NEW2 (1, shorts *);
     }
   else
     {
-      LA = NEW2(count * tokensetsize, unsigned);
-      LAruleno = NEW2(count, short);
-      lookback = NEW2(count, shorts *);
+      LA = NEW2 (count * tokensetsize, unsigned);
+      LAruleno = NEW2 (count, short);
+      lookback = NEW2 (count, shorts *);
     }
 
   np = LAruleno;
@@ -268,16 +289,16 @@ initialize_LA (void)
 static void
 set_goto_map (void)
 {
-  register shifts *sp;
-  register int i;
-  register int symbol;
-  register int k;
-  register short *temp_map;
-  register int state2;
-  register int state1;
+  shifts *sp;
+  int i;
+  int symbol;
+  int k;
+  short *temp_map;
+  int state2;
+  int state1;
 
-  goto_map = NEW2(nvars + 1, short) - ntokens;
-  temp_map = NEW2(nvars + 1, short) - ntokens;
+  goto_map = NEW2 (nvars + 1, short) - ntokens;
+  temp_map = NEW2 (nvars + 1, short) - ntokens;
 
   ngotos = 0;
   for (sp = first_shift; sp; sp = sp->next)
@@ -286,14 +307,15 @@ set_goto_map (void)
 	{
 	  symbol = accessing_symbol[sp->shifts[i]];
 
-	  if (ISTOKEN(symbol)) break;
+	  if (ISTOKEN (symbol))
+	    break;
 
 	  if (ngotos == MAXSHORT)
 	    fatal (_("too many gotos (max %d)"), MAXSHORT);
 
 	  ngotos++;
 	  goto_map[symbol]++;
-        }
+	}
     }
 
   k = 0;
@@ -309,8 +331,8 @@ set_goto_map (void)
   goto_map[nsyms] = ngotos;
   temp_map[nsyms] = ngotos;
 
-  from_state = NEW2(ngotos, short);
-  to_state = NEW2(ngotos, short);
+  from_state = NEW2 (ngotos, short);
+  to_state = NEW2 (ngotos, short);
 
   for (sp = first_shift; sp; sp = sp->next)
     {
@@ -320,7 +342,8 @@ set_goto_map (void)
 	  state2 = sp->shifts[i];
 	  symbol = accessing_symbol[state2];
 
-	  if (ISTOKEN(symbol)) break;
+	  if (ISTOKEN (symbol))
+	    break;
 
 	  k = temp_map[symbol]++;
 	  from_state[k] = state1;
@@ -328,7 +351,7 @@ set_goto_map (void)
 	}
     }
 
-  FREE(temp_map + ntokens);
+  FREE (temp_map + ntokens);
 }
 
 
@@ -338,10 +361,10 @@ set_goto_map (void)
 static int
 map_goto (int state, int symbol)
 {
-  register int high;
-  register int low;
-  register int middle;
-  register int s;
+  int high;
+  int low;
+  int middle;
+  int s;
 
   low = goto_map[symbol];
   high = goto_map[symbol + 1] - 1;
@@ -358,7 +381,7 @@ map_goto (int state, int symbol)
 	high = middle - 1;
     }
 
-  berror("map_goto");
+  berror ("map_goto");
 /* NOTREACHED */
   return 0;
 }
@@ -367,24 +390,24 @@ map_goto (int state, int symbol)
 static void
 initialize_F (void)
 {
-  register int i;
-  register int j;
-  register int k;
-  register shifts *sp;
-  register short *edge;
-  register unsigned *rowp;
-  register short *rp;
-  register short **reads;
-  register int nedges;
-  register int stateno;
-  register int symbol;
-  register int nwords;
+  int i;
+  int j;
+  int k;
+  shifts *sp;
+  short *edge;
+  unsigned *rowp;
+  short *rp;
+  short **reads;
+  int nedges;
+  int stateno;
+  int symbol;
+  int nwords;
 
   nwords = ngotos * tokensetsize;
-  F = NEW2(nwords, unsigned);
+  F = NEW2 (nwords, unsigned);
 
-  reads = NEW2(ngotos, short *);
-  edge = NEW2(ngotos + 1, short);
+  reads = NEW2 (ngotos, short *);
+  edge = NEW2 (ngotos + 1, short);
   nedges = 0;
 
   rowp = F;
@@ -400,21 +423,21 @@ initialize_F (void)
 	  for (j = 0; j < k; j++)
 	    {
 	      symbol = accessing_symbol[sp->shifts[j]];
-	      if (ISVAR(symbol))
+	      if (ISVAR (symbol))
 		break;
-	      SETBIT(rowp, symbol);
+	      SETBIT (rowp, symbol);
 	    }
 
 	  for (; j < k; j++)
 	    {
 	      symbol = accessing_symbol[sp->shifts[j]];
 	      if (nullable[symbol])
-		edge[nedges++] = map_goto(stateno, symbol);
+		edge[nedges++] = map_goto (stateno, symbol);
 	    }
 
 	  if (nedges)
 	    {
-	      reads[i] = rp = NEW2(nedges + 1, short);
+	      reads[i] = rp = NEW2 (nedges + 1, short);
 
 	      for (j = 0; j < nedges; j++)
 		rp[j] = edge[j];
@@ -427,121 +450,26 @@ initialize_F (void)
       rowp += tokensetsize;
     }
 
-  digraph(reads);
+  digraph (reads);
 
   for (i = 0; i < ngotos; i++)
     {
       if (reads[i])
-	FREE(reads[i]);
+	FREE (reads[i]);
     }
 
-  FREE(reads);
-  FREE(edge);
-}
-
-
-static void
-build_relations (void)
-{
-  register int i;
-  register int j;
-  register int k;
-  register short *rulep;
-  register short *rp;
-  register shifts *sp;
-  register int length;
-  register int nedges;
-  register int done;
-  register int state1;
-  register int stateno;
-  register int symbol1;
-  register int symbol2;
-  register short *shortp;
-  register short *edge;
-  register short *states;
-  register short **new_includes;
-
-  includes = NEW2(ngotos, short *);
-  edge = NEW2(ngotos + 1, short);
-  states = NEW2(maxrhs + 1, short);
-
-  for (i = 0; i < ngotos; i++)
-    {
-      nedges = 0;
-      state1 = from_state[i];
-      symbol1 = accessing_symbol[to_state[i]];
-
-      for (rulep = derives[symbol1]; *rulep > 0; rulep++)
-	{
-	  length = 1;
-	  states[0] = state1;
-	  stateno = state1;
-
-	  for (rp = ritem + rrhs[*rulep]; *rp > 0; rp++)
-	    {
-	      symbol2 = *rp;
-	      sp = shift_table[stateno];
-	      k = sp->nshifts;
-
-	      for (j = 0; j < k; j++)
-		{
-		  stateno = sp->shifts[j];
-		  if (accessing_symbol[stateno] == symbol2) break;
-		}
-
-	      states[length++] = stateno;
-	    }
-
-	  if (!consistent[stateno])
-	    add_lookback_edge(stateno, *rulep, i);
-
-	  length--;
-	  done = 0;
-	  while (!done)
-	    {
-	      done = 1;
-	      rp--;
-			/* JF added rp>=ritem &&   I hope to god its right! */
-	      if (rp>=ritem && ISVAR(*rp))
-		{
-		  stateno = states[--length];
-		  edge[nedges++] = map_goto(stateno, *rp);
-		  if (nullable[*rp]) done = 0;
-		}
-	    }
-	}
-
-      if (nedges)
-	{
-	  includes[i] = shortp = NEW2(nedges + 1, short);
-	  for (j = 0; j < nedges; j++)
-	    shortp[j] = edge[j];
-	  shortp[nedges] = -1;
-	}
-    }
-
-  new_includes = transpose(includes, ngotos);
-
-  for (i = 0; i < ngotos; i++)
-    if (includes[i])
-      FREE(includes[i]);
-
-  FREE(includes);
-
-  includes = new_includes;
-
-  FREE(edge);
-  FREE(states);
+  FREE (reads);
+  FREE (edge);
 }
 
 
 static void
 add_lookback_edge (int stateno, int ruleno, int gotono)
 {
-  register int i;
-  register int k;
-  register int found;
-  register shorts *sp;
+  int i;
+  int k;
+  int found;
+  shorts *sp;
 
   i = lookaheads[stateno];
   k = lookaheads[stateno + 1];
@@ -555,27 +483,26 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
     }
 
   if (found == 0)
-    berror("add_lookback_edge");
+    berror ("add_lookback_edge");
 
-  sp = NEW(shorts);
+  sp = NEW (shorts);
   sp->next = lookback[i];
   sp->value = gotono;
   lookback[i] = sp;
 }
 
 
-
 static short **
 transpose (short **R_arg, int n)
 {
-  register short **new_R;
-  register short **temp_R;
-  register short *nedges;
-  register short *sp;
-  register int i;
-  register int k;
+  short **new_R;
+  short **temp_R;
+  short *nedges;
+  short *sp;
+  int i;
+  int k;
 
-  nedges = NEW2(n, short);
+  nedges = NEW2 (n, short);
 
   for (i = 0; i < n; i++)
     {
@@ -587,22 +514,22 @@ transpose (short **R_arg, int n)
 	}
     }
 
-  new_R = NEW2(n, short *);
-  temp_R = NEW2(n, short *);
+  new_R = NEW2 (n, short *);
+  temp_R = NEW2 (n, short *);
 
   for (i = 0; i < n; i++)
     {
       k = nedges[i];
       if (k > 0)
 	{
-	  sp = NEW2(k + 1, short);
+	  sp = NEW2 (k + 1, short);
 	  new_R[i] = sp;
 	  temp_R[i] = sp;
 	  sp[k] = -1;
 	}
     }
 
-  FREE(nedges);
+  FREE (nedges);
 
   for (i = 0; i < n; i++)
     {
@@ -614,149 +541,184 @@ transpose (short **R_arg, int n)
 	}
     }
 
-  FREE(temp_R);
+  FREE (temp_R);
 
   return new_R;
 }
 
 
 static void
-compute_FOLLOWS (void)
+build_relations (void)
 {
-  register int i;
-
-  digraph(includes);
+  int i;
+  int j;
+  int k;
+  short *rulep;
+  short *rp;
+  shifts *sp;
+  int length;
+  int nedges;
+  int done;
+  int state1;
+  int stateno;
+  int symbol1;
+  int symbol2;
+  short *shortp;
+  short *edge;
+  short *states;
+  short **new_includes;
+
+  includes = NEW2 (ngotos, short *);
+  edge = NEW2 (ngotos + 1, short);
+  states = NEW2 (maxrhs + 1, short);
 
   for (i = 0; i < ngotos; i++)
     {
-      if (includes[i]) FREE(includes[i]);
-    }
+      nedges = 0;
+      state1 = from_state[i];
+      symbol1 = accessing_symbol[to_state[i]];
 
-  FREE(includes);
-}
+      for (rulep = derives[symbol1]; *rulep > 0; rulep++)
+	{
+	  length = 1;
+	  states[0] = state1;
+	  stateno = state1;
 
+	  for (rp = ritem + rrhs[*rulep]; *rp > 0; rp++)
+	    {
+	      symbol2 = *rp;
+	      sp = shift_table[stateno];
+	      k = sp->nshifts;
 
-static void
-compute_lookaheads (void)
-{
-  register int i;
-  register int n;
-  register unsigned *fp1;
-  register unsigned *fp2;
-  register unsigned *fp3;
-  register shorts *sp;
-  register unsigned *rowp;
-/*   register short *rulep; JF unused */
-/*  register int count; JF unused */
-  register shorts *sptmp;/* JF */
+	      for (j = 0; j < k; j++)
+		{
+		  stateno = sp->shifts[j];
+		  if (accessing_symbol[stateno] == symbol2)
+		    break;
+		}
 
-  rowp = LA;
-  n = lookaheads[nstates];
-  for (i = 0; i < n; i++)
-    {
-      fp3 = rowp + tokensetsize;
-      for (sp = lookback[i]; sp; sp = sp->next)
-	{
-	  fp1 = rowp;
-	  fp2 = F + tokensetsize * sp->value;
-	  while (fp1 < fp3)
-	    *fp1++ |= *fp2++;
+	      states[length++] = stateno;
+	    }
+
+	  if (!consistent[stateno])
+	    add_lookback_edge (stateno, *rulep, i);
+
+	  length--;
+	  done = 0;
+	  while (!done)
+	    {
+	      done = 1;
+	      rp--;
+	      /* JF added rp>=ritem &&   I hope to god its right! */
+	      if (rp >= ritem && ISVAR (*rp))
+		{
+		  stateno = states[--length];
+		  edge[nedges++] = map_goto (stateno, *rp);
+		  if (nullable[*rp])
+		    done = 0;
+		}
+	    }
 	}
 
-      rowp = fp3;
+      if (nedges)
+	{
+	  includes[i] = shortp = NEW2 (nedges + 1, short);
+	  for (j = 0; j < nedges; j++)
+	    shortp[j] = edge[j];
+	  shortp[nedges] = -1;
+	}
     }
 
-  for (i = 0; i < n; i++)
-    {/* JF removed ref to freed storage */
-      for (sp = lookback[i]; sp; sp = sptmp) {
-	sptmp=sp->next;
-	FREE(sp);
-      }
-    }
+  new_includes = transpose (includes, ngotos);
 
-  FREE(lookback);
-  FREE(F);
+  for (i = 0; i < ngotos; i++)
+    if (includes[i])
+      FREE (includes[i]);
+
+  FREE (includes);
+
+  includes = new_includes;
+
+  FREE (edge);
+  FREE (states);
 }
 
 
+
 static void
-digraph (short **relation)
+compute_FOLLOWS (void)
 {
-  register int i;
+  int i;
 
-  infinity = ngotos + 2;
-  INDEX = NEW2(ngotos + 1, short);
-  VERTICES = NEW2(ngotos + 1, short);
-  top = 0;
-
-  R = relation;
-
-  for (i = 0; i < ngotos; i++)
-    INDEX[i] = 0;
+  digraph (includes);
 
   for (i = 0; i < ngotos; i++)
     {
-      if (INDEX[i] == 0 && R[i])
-	traverse(i);
+      if (includes[i])
+	FREE (includes[i]);
     }
 
-  FREE(INDEX);
-  FREE(VERTICES);
+  FREE (includes);
 }
 
 
 static void
-traverse (register int i)
+compute_lookaheads (void)
 {
-  register unsigned *fp1;
-  register unsigned *fp2;
-  register unsigned *fp3;
-  register int j;
-  register short *rp;
-
-  int height;
-  unsigned *base;
-
-  VERTICES[++top] = i;
-  INDEX[i] = height = top;
-
-  base = F + i * tokensetsize;
-  fp3 = base + tokensetsize;
+  int i;
+  int n;
+  unsigned *fp1;
+  unsigned *fp2;
+  unsigned *fp3;
+  shorts *sp;
+  unsigned *rowp;
+  shorts *sptmp;		/* JF */
 
-  rp = R[i];
-  if (rp)
+  rowp = LA;
+  n = lookaheads[nstates];
+  for (i = 0; i < n; i++)
     {
-      while ((j = *rp++) >= 0)
+      fp3 = rowp + tokensetsize;
+      for (sp = lookback[i]; sp; sp = sp->next)
 	{
-	  if (INDEX[j] == 0)
-	    traverse(j);
-
-	  if (INDEX[i] > INDEX[j])
-	    INDEX[i] = INDEX[j];
-
-	  fp1 = base;
-	  fp2 = F + j * tokensetsize;
-
+	  fp1 = rowp;
+	  fp2 = F + tokensetsize * sp->value;
 	  while (fp1 < fp3)
 	    *fp1++ |= *fp2++;
 	}
+
+      rowp = fp3;
     }
 
-  if (INDEX[i] == height)
+  for (i = 0; i < n; i++)
     {
-      for (;;)
+      /* JF removed ref to freed storage */
+      for (sp = lookback[i]; sp; sp = sptmp)
 	{
-	  j = VERTICES[top--];
-	  INDEX[j] = infinity;
+	  sptmp = sp->next;
+	  FREE (sp);
+	}
+    }
 
-	  if (i == j)
-	    break;
+  FREE (lookback);
+  FREE (F);
+}
 
-	  fp1 = base;
-	  fp2 = F + j * tokensetsize;
 
-	  while (fp1 < fp3)
-	    *fp2++ = *fp1++;
-	}
-    }
+void
+lalr (void)
+{
+  tokensetsize = WORDSIZE (ntokens);
+
+  set_state_table ();
+  set_accessing_symbol ();
+  set_shift_table ();
+  set_reduction_table ();
+  set_maxrhs ();
+  initialize_LA ();
+  set_goto_map ();
+  initialize_F ();
+  build_relations ();
+  compute_FOLLOWS ();
+  compute_lookaheads ();
 }
