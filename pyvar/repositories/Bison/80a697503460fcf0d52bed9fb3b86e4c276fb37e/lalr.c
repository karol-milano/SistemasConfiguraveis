@@ -358,14 +358,11 @@ initialize_F (void)
 {
   int i;
   int j;
-  int k;
-  shifts *sp;
   short *edge;
   unsigned *rowp;
   short *rp;
   short **reads;
   int nedges;
-  int stateno;
   int symbol;
   int nwords;
 
@@ -379,14 +376,12 @@ initialize_F (void)
   rowp = F;
   for (i = 0; i < ngotos; i++)
     {
-      stateno = to_state[i];
-      sp = state_table[stateno].shift_table;
+      int stateno = to_state[i];
+      shifts *sp = state_table[stateno].shift_table;
 
       if (sp)
 	{
-	  k = sp->nshifts;
-
-	  for (j = 0; j < k; j++)
+	  for (j = 0; j < sp->nshifts; j++)
 	    {
 	      symbol = state_table[sp->shifts[j]].accessing_symbol;
 	      if (ISVAR (symbol))
@@ -394,7 +389,7 @@ initialize_F (void)
 	      SETBIT (rowp, symbol);
 	    }
 
-	  for (; j < k; j++)
+	  for (; j < sp->nshifts; j++)
 	    {
 	      symbol = state_table[sp->shifts[j]].accessing_symbol;
 	      if (nullable[symbol])
@@ -460,15 +455,13 @@ transpose (short **R_arg, int n)
   short **new_R;
   short **temp_R;
   short *nedges;
-  short *sp;
   int i;
-  int k;
 
   nedges = XCALLOC (short, n);
 
   for (i = 0; i < n; i++)
     {
-      sp = R_arg[i];
+      short *sp = R_arg[i];
       if (sp)
 	{
 	  while (*sp >= 0)
@@ -480,27 +473,22 @@ transpose (short **R_arg, int n)
   temp_R = XCALLOC (short *, n);
 
   for (i = 0; i < n; i++)
-    {
-      k = nedges[i];
-      if (k > 0)
-	{
-	  sp = XCALLOC (short, k + 1);
-	  new_R[i] = sp;
-	  temp_R[i] = sp;
-	  sp[k] = -1;
-	}
-    }
+    if (nedges[i] > 0)
+      {
+	short *sp = XCALLOC (short, nedges[i] + 1);
+	new_R[i] = sp;
+	temp_R[i] = sp;
+	sp[nedges[i]] = -1;
+      }
 
   XFREE (nedges);
 
   for (i = 0; i < n; i++)
     {
-      sp = R_arg[i];
+      short *sp = R_arg[i];
       if (sp)
-	{
-	  while (*sp >= 0)
-	    *temp_R[*sp++]++ = i;
-	}
+	while (*sp >= 0)
+	  *temp_R[*sp++]++ = i;
     }
 
   XFREE (temp_R);
@@ -514,18 +502,13 @@ build_relations (void)
 {
   int i;
   int j;
-  int k;
   short *rulep;
   short *rp;
-  shifts *sp;
-  int length;
   int nedges;
   int done;
   int state1;
   int stateno;
   int symbol1;
-  int symbol2;
-  short *shortp;
   short *edge;
   short *states;
   short **new_includes;
@@ -542,17 +525,16 @@ build_relations (void)
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
 	{
-	  length = 1;
+	  int length = 1;
 	  states[0] = state1;
 	  stateno = state1;
 
 	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
 	    {
-	      symbol2 = *rp;
-	      sp = state_table[stateno].shift_table;
-	      k = sp->nshifts;
+	      int symbol2 = *rp;
+	      shifts *sp = state_table[stateno].shift_table;
 
-	      for (j = 0; j < k; j++)
+	      for (j = 0; j < sp->nshifts; j++)
 		{
 		  stateno = sp->shifts[j];
 		  if (state_table[stateno].accessing_symbol == symbol2)
@@ -584,19 +566,17 @@ build_relations (void)
 
       if (nedges)
 	{
-	  includes[i] = shortp = XCALLOC (short, nedges + 1);
+	  includes[i] = XCALLOC (short, nedges + 1);
 	  for (j = 0; j < nedges; j++)
-	    shortp[j] = edge[j];
-	  shortp[nedges] = -1;
+	    includes[i][j] = edge[j];
+	  includes[i][nedges] = -1;
 	}
     }
 
   new_includes = transpose (includes, ngotos);
 
   for (i = 0; i < ngotos; i++)
-    if (includes[i])
-      XFREE (includes[i]);
-
+    XFREE (includes[i]);
   XFREE (includes);
 
   includes = new_includes;
