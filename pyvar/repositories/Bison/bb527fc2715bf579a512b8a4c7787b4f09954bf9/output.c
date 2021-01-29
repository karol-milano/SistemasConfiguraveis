@@ -354,7 +354,7 @@ action_row (int state)
 	  for (i = n - 1; i >= m; i--)
 	    {
 	      rule = -LAruleno[i];
-	      wordp = LA + i * tokensetsize;
+	      wordp = LA (i);
 	      mask = 1;
 
 	      /* and find each token which the rule finds acceptable
