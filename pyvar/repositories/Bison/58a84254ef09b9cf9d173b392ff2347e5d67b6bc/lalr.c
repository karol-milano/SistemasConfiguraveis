@@ -87,7 +87,8 @@ set_goto_map (void)
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  assert (ngotos < GOTO_NUMBER_MAX);
+	  if (ngotos >= GOTO_NUMBER_MAX)
+	    abort ();
 	  ngotos++;
 	  goto_map[TRANSITION_SYMBOL (sp, i)]++;
 	}
@@ -144,8 +145,10 @@ map_goto (state_number_t state, symbol_number_t symbol)
   low = goto_map[symbol];
   high = goto_map[symbol + 1] - 1;
 
-  while (low <= high)
+  for (;;)
     {
+      if (high < low)
+	abort ();
       middle = (low + high) / 2;
       s = from_state[middle];
       if (s == state)
@@ -155,10 +158,6 @@ map_goto (state_number_t state, symbol_number_t symbol)
       else
 	high = middle - 1;
     }
-
-  assert (0);
-  /* NOTREACHED */
-  return 0;
 }
 
 
