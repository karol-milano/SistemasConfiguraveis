@@ -191,7 +191,7 @@ set_conflicts (int state)
   unsigned *fp1;
   int symbol;
 
-  if (consistent[state])
+  if (state_table[state].consistent)
     return;
 
   for (i = 0; i < tokensetsize; i++)
