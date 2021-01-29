@@ -94,7 +94,7 @@ set_goto_map (void)
 	  ngotos++;
 
 	  /* Abort if (ngotos + 1) would overflow.  */
-	  assert (ngotos != GOTO_NUMBER_MAXIMUM);
+	  aver (ngotos != GOTO_NUMBER_MAXIMUM);
 
 	  goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
 	}
@@ -153,7 +153,7 @@ map_goto (state_number s0, symbol_number sym)
 
   for (;;)
     {
-      assert (low <= high);
+      aver (low <= high);
       middle = (low + high) / 2;
       s = from_state[middle];
       if (s == s0)
