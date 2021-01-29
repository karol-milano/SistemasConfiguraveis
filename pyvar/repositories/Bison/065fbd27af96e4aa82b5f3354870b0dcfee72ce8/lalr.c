@@ -310,27 +310,18 @@ static void
 add_lookback_edge (int stateno, int ruleno, int gotono)
 {
   int i;
-  int k;
-  int found;
   shorts *sp;
 
-  i = state_table[stateno]->lookaheadsp;
-  k = state_table[stateno + 1]->lookaheadsp;
-  found = 0;
-  while (!found && i < k)
-    {
-      if (LAruleno[i] == ruleno)
-	found = 1;
-      else
-	i++;
-    }
+  for (i = 0; i < state_table[stateno]->nlookaheads; ++i)
+    if (LAruleno[state_table[stateno]->lookaheadsp + i] == ruleno)
+      break;
 
-  assert (found);
+  assert (LAruleno[state_table[stateno]->lookaheadsp + i] == ruleno);
 
   sp = XCALLOC (shorts, 1);
-  sp->next = lookback[i];
+  sp->next = lookback[state_table[stateno]->lookaheadsp + i];
   sp->value = gotono;
-  lookback[i] = sp;
+  lookback[state_table[stateno]->lookaheadsp + i] = sp;
 }
 
 
