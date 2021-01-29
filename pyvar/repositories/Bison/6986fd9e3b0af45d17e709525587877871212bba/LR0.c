@@ -200,7 +200,8 @@ new_state (int symbol)
   short *iend;
 
 #if TRACE
-  fprintf (stderr, "Entering new_state, symbol = %d\n", symbol);
+  fprintf (stderr, "Entering new_state, symbol = %d, state = %d\n",
+	   symbol, nstates);
 #endif
 
   if (nstates >= MAXSHORT)
