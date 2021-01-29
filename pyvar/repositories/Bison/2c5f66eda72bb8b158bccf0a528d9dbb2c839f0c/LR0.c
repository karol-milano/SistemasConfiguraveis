@@ -198,8 +198,8 @@ new_state (int symbol)
   core *p;
 
 #if TRACE
-  fprintf (stderr, "Entering new_state, symbol = %d, state = %d\n",
-	   symbol, nstates);
+  fprintf (stderr, "Entering new_state, state = %d, symbol = %d\n",
+	   nstates, symbol);
 #endif
 
   if (nstates >= MAXSHORT)
@@ -242,7 +242,8 @@ get_state (int symbol)
   int n;
 
 #if TRACE
-  fprintf (stderr, "Entering get_state, symbol = %d\n", symbol);
+  fprintf (stderr, "Entering get_state, state = %d, symbol = %d\n",
+	   nstates, symbol);
 #endif
 
   isp1 = kernel_base[symbol];
