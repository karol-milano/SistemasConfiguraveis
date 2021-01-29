@@ -413,7 +413,6 @@ void
 print_reductions (FILE *out, int state)
 {
   int i;
-  int j;
   int m = state_table[state]->lookaheadsp;
   int n = state_table[state + 1]->lookaheadsp;
   shifts *shiftp = state_table[state]->shifts;
@@ -457,8 +456,6 @@ print_reductions (FILE *out, int state)
     }
   else if (n - m >= 1)
     {
-      int k;
-
       int cmax = 0;
       int default_LA = -1;
       int default_rule = 0;
@@ -467,6 +464,7 @@ print_reductions (FILE *out, int state)
 	for (i = m; i < n; i++)
 	  {
 	    int count = 0;
+	    int j, k;
 
 	    for (k = 0; k < tokensetsize; ++k)
 	      lookaheadset[k] = LA (i)[k] & ~shiftset[k];
@@ -495,12 +493,13 @@ print_reductions (FILE *out, int state)
 
       for (i = 0; i < ntokens; i++)
 	{
+	  int j;
 	  int defaulted = 0;
 	  int count = BITISSET (shiftset, i);
 
 	  for (j = m; j < n; j++)
 	    {
-	      if (BITISSET (LA (m), j))
+	      if (BITISSET (LA (j), i))
 		{
 		  if (count == 0)
 		    {
