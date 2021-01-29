@@ -150,12 +150,6 @@ set_state_table (void)
       state_table[sp->number] = sp;
   }
 
-  {
-    shifts *sp;
-    for (sp = first_shift; sp; sp = sp->next)
-      assert (state_table[sp->number]->shifts == sp);
-  }
-
   /* Pessimization, but simplification of the code: make sure all the
      states have a shifts, even if reduced to 0 shifts.  */
   {
@@ -228,29 +222,31 @@ initialize_LA (void)
 static void
 set_goto_map (void)
 {
-  shifts *sp;
+  int state;
   int i;
   int symbol;
   int k;
   short *temp_map;
   int state2;
-  int state1;
 
   goto_map = XCALLOC (short, nvars + 1) - ntokens;
   temp_map = XCALLOC (short, nvars + 1) - ntokens;
 
   ngotos = 0;
-  for (sp = first_shift; sp; sp = sp->next)
-    for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
-      {
-	symbol = state_table[sp->shifts[i]]->accessing_symbol;
+  for (state = 0; state < nstates; ++state)
+    {
+      shifts *sp = state_table[state]->shifts;
+      for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
+	{
+	  symbol = state_table[sp->shifts[i]]->accessing_symbol;
 
-	if (ngotos == MAXSHORT)
-	  fatal (_("too many gotos (max %d)"), MAXSHORT);
+	  if (ngotos == MAXSHORT)
+	    fatal (_("too many gotos (max %d)"), MAXSHORT);
 
-	ngotos++;
-	goto_map[symbol]++;
-      }
+	  ngotos++;
+	  goto_map[symbol]++;
+	}
+    }
 
   k = 0;
   for (i = ntokens; i < nsyms; i++)
@@ -268,17 +264,20 @@ set_goto_map (void)
   from_state = XCALLOC (short, ngotos);
   to_state = XCALLOC (short, ngotos);
 
-  for (sp = first_shift; sp; sp = sp->next)
+  for (state = 0; state < nstates; ++state)
     {
-      state1 = sp->number;
+      shifts *sp = state_table[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
-	  state2 = sp->shifts[i];
-	  symbol = state_table[state2]->accessing_symbol;
+	  for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
+	    {
+	      state2 = sp->shifts[i];
+	      symbol = state_table[state2]->accessing_symbol;
 
-	  k = temp_map[symbol]++;
-	  from_state[k] = state1;
-	  to_state[k] = state2;
+	      k = temp_map[symbol]++;
+	      from_state[k] = state;
+	      to_state[k] = state2;
+	    }
 	}
     }
 
