@@ -43,8 +43,6 @@ short *LAruleno;
 unsigned *LA;
 
 char *consistent;
-shifts **shift_table;
-reductions **reduction_table;
 short *goto_map;
 short *from_state;
 short *to_state;
@@ -148,39 +146,28 @@ digraph (short **relation)
 static void
 set_state_table (void)
 {
-  core *sp;
-
   state_table = XCALLOC (state_t, nstates);
 
-  for (sp = first_state; sp; sp = sp->next)
-    {
-      state_table[sp->number].state = sp;
-      state_table[sp->number].accessing_symbol = sp->accessing_symbol;
-    }
-}
-
-
-static void
-set_shift_table (void)
-{
-  shifts *sp;
-
-  shift_table = XCALLOC (shifts *, nstates);
-
-  for (sp = first_shift; sp; sp = sp->next)
-    shift_table[sp->number] = sp;
-}
-
-
-static void
-set_reduction_table (void)
-{
-  reductions *rp;
-
-  reduction_table = XCALLOC (reductions *, nstates);
-
-  for (rp = first_reduction; rp; rp = rp->next)
-    reduction_table[rp->number] = rp;
+  {
+    core *sp;
+    for (sp = first_state; sp; sp = sp->next)
+      {
+	state_table[sp->number].state = sp;
+	state_table[sp->number].accessing_symbol = sp->accessing_symbol;
+      }
+  }
+
+  {
+    shifts *sp;
+    for (sp = first_shift; sp; sp = sp->next)
+      state_table[sp->number].shift_table = sp;
+  }
+
+  {
+    reductions *rp;
+    for (rp = first_reduction; rp; rp = rp->next)
+      state_table[rp->number].reduction_table = rp;
+  }
 }
 
 
@@ -231,8 +218,8 @@ initialize_LA (void)
 
       lookaheads[i] = count;
 
-      rp = reduction_table[i];
-      sp = shift_table[i];
+      rp = state_table[i].reduction_table;
+      sp = state_table[i].shift_table;
       if (rp
 	  && (rp->nreds > 1
 	      || (sp && !ISVAR (state_table[sp->shifts[0]].accessing_symbol))))
@@ -270,7 +257,7 @@ initialize_LA (void)
     {
       if (!consistent[i])
 	{
-	  if ((rp = reduction_table[i]))
+	  if ((rp = state_table[i].reduction_table))
 	    for (j = 0; j < rp->nreds; j++)
 	      *np++ = rp->rules[j];
 	}
@@ -408,7 +395,7 @@ initialize_F (void)
   for (i = 0; i < ngotos; i++)
     {
       stateno = to_state[i];
-      sp = shift_table[stateno];
+      sp = state_table[stateno].shift_table;
 
       if (sp)
 	{
@@ -580,7 +567,7 @@ build_relations (void)
 	  for (rp = ritem + rrhs[*rulep]; *rp > 0; rp++)
 	    {
 	      symbol2 = *rp;
-	      sp = shift_table[stateno];
+	      sp = state_table[stateno].shift_table;
 	      k = sp->nshifts;
 
 	      for (j = 0; j < k; j++)
@@ -704,8 +691,6 @@ lalr (void)
   tokensetsize = WORDSIZE (ntokens);
 
   set_state_table ();
-  set_shift_table ();
-  set_reduction_table ();
   set_maxrhs ();
   initialize_LA ();
   set_goto_map ();
