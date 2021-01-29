@@ -171,13 +171,11 @@ set_goto_map (void)
       shifts *sp = state_table[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
-	  int symbol = state_table[sp->shifts[i]]->accessing_symbol;
-
 	  if (ngotos == MAXSHORT)
 	    fatal (_("too many gotos (max %d)"), MAXSHORT);
 
 	  ngotos++;
-	  goto_map[symbol]++;
+	  goto_map[SHIFT_SYMBOL (sp, i)]++;
 	}
     }
 
@@ -204,12 +202,9 @@ set_goto_map (void)
       shifts *sp = state_table[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
-	  int state2 = sp->shifts[i];
-	  int symbol = state_table[state2]->accessing_symbol;
-
-	  int k = temp_map[symbol]++;
+	  int k = temp_map[SHIFT_SYMBOL (sp, i)]++;
 	  from_state[k] = state;
-	  to_state[k] = state2;
+	  to_state[k] = sp->shifts[i];
 	}
     }
 
@@ -269,14 +264,11 @@ initialize_F (void)
 
       int j;
       for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
-	{
-	  int symbol = state_table[sp->shifts[j]]->accessing_symbol;
-	  SETBIT (F (i), symbol);
-	}
+	SETBIT (F (i), SHIFT_SYMBOL (sp, j));
 
       for (; j < sp->nshifts; j++)
 	{
-	  int symbol = state_table[sp->shifts[j]]->accessing_symbol;
+	  int symbol = SHIFT_SYMBOL (sp, j);
 	  if (nullable[symbol])
 	    edge[nedges++] = map_goto (stateno, symbol);
 	}
