@@ -159,12 +159,8 @@ initialize_LA (void)
 static void
 set_goto_map (void)
 {
-  int state;
-  int i;
-  int symbol;
-  int k;
+  int state, i;
   short *temp_map;
-  int state2;
 
   goto_map = XCALLOC (short, nvars + 1) - ntokens;
   temp_map = XCALLOC (short, nvars + 1) - ntokens;
@@ -175,7 +171,7 @@ set_goto_map (void)
       shifts *sp = state_table[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
-	  symbol = state_table[sp->shifts[i]]->accessing_symbol;
+	  int symbol = state_table[sp->shifts[i]]->accessing_symbol;
 
 	  if (ngotos == MAXSHORT)
 	    fatal (_("too many gotos (max %d)"), MAXSHORT);
@@ -185,18 +181,20 @@ set_goto_map (void)
 	}
     }
 
-  k = 0;
-  for (i = ntokens; i < nsyms; i++)
-    {
-      temp_map[i] = k;
-      k += goto_map[i];
-    }
+  {
+    int k = 0;
+    for (i = ntokens; i < nsyms; i++)
+      {
+	temp_map[i] = k;
+	k += goto_map[i];
+      }
 
-  for (i = ntokens; i < nsyms; i++)
-    goto_map[i] = temp_map[i];
+    for (i = ntokens; i < nsyms; i++)
+      goto_map[i] = temp_map[i];
 
-  goto_map[nsyms] = ngotos;
-  temp_map[nsyms] = ngotos;
+    goto_map[nsyms] = ngotos;
+    temp_map[nsyms] = ngotos;
+  }
 
   from_state = XCALLOC (short, ngotos);
   to_state = XCALLOC (short, ngotos);
@@ -206,15 +204,12 @@ set_goto_map (void)
       shifts *sp = state_table[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
-	  for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
-	    {
-	      state2 = sp->shifts[i];
-	      symbol = state_table[state2]->accessing_symbol;
+	  int state2 = sp->shifts[i];
+	  int symbol = state_table[state2]->accessing_symbol;
 
-	      k = temp_map[symbol]++;
-	      from_state[k] = state;
-	      to_state[k] = state2;
-	    }
+	  int k = temp_map[symbol]++;
+	  from_state[k] = state;
+	  to_state[k] = state2;
 	}
     }
 
