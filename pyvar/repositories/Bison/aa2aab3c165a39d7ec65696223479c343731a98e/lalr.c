@@ -42,15 +42,11 @@ int tokensetsize;
 short *LAruleno;
 unsigned *LA;
 
+static int ngotos;
 short *goto_map;
 short *from_state;
 short *to_state;
 
-extern void berror PARAMS ((const char *));
-
-static int infinity;
-static int ngotos;
-
 /* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
 static unsigned *F = NULL;
@@ -58,11 +54,20 @@ static unsigned *F = NULL;
 
 static short **includes;
 static shorts **lookback;
+
+
+/*---------------------------------------------------------------.
+| digraph & traverse.                                            |
+|                                                                |
+| The following variables are used as common storage between the |
+| two.                                                           |
+`---------------------------------------------------------------*/
+
 static short **R;
 static short *INDEX;
 static short *VERTICES;
 static int top;
-
+static int infinity;
 
 static void
 traverse (int i)
@@ -175,16 +180,14 @@ set_state_table (void)
 	state_table[i].lookaheads = count;
 
 	if (rp
-	    && (rp->nreds > 1
-		|| (sp && !ISVAR (state_table[sp->shifts[0]].accessing_symbol))))
+	    && (rp->nreds > 1 || (sp && SHIFT_IS_SHIFT (sp, 0))))
 	  count += rp->nreds;
 	else
 	  state_table[i].consistent = 1;
 
 	if (sp)
 	  for (k = 0; k < sp->nshifts; k++)
-	    if (state_table[sp->shifts[k]].accessing_symbol
-		== error_token_number)
+	    if (SHIFT_IS_ERROR (sp, k))
 	      {
 		state_table[i].consistent = 0;
 		break;
@@ -237,13 +240,10 @@ set_goto_map (void)
   ngotos = 0;
   for (sp = first_shift; sp; sp = sp->next)
     {
-      for (i = sp->nshifts - 1; i >= 0; i--)
+      for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  symbol = state_table[sp->shifts[i]].accessing_symbol;
 
-	  if (ISTOKEN (symbol))
-	    break;
-
 	  if (ngotos == MAXSHORT)
 	    fatal (_("too many gotos (max %d)"), MAXSHORT);
 
@@ -271,14 +271,11 @@ set_goto_map (void)
   for (sp = first_shift; sp; sp = sp->next)
     {
       state1 = sp->number;
-      for (i = sp->nshifts - 1; i >= 0; i--)
+      for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
 	  state2 = sp->shifts[i];
 	  symbol = state_table[state2].accessing_symbol;
 
-	  if (ISTOKEN (symbol))
-	    break;
-
 	  k = temp_map[symbol]++;
 	  from_state[k] = state1;
 	  to_state[k] = state2;
@@ -342,11 +339,9 @@ initialize_F (void)
       if (sp)
 	{
 	  int j;
-	  for (j = 0; j < sp->nshifts; j++)
+	  for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
 	    {
 	      int symbol = state_table[sp->shifts[j]].accessing_symbol;
-	      if (ISVAR (symbol))
-		break;
 	      SETBIT (F + i * tokensetsize, symbol);
 	    }
 
