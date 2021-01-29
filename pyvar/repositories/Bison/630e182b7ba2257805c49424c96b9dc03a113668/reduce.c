@@ -54,7 +54,7 @@ static BSet V1;
 static int nuseful_productions;
 static int nuseless_productions;
 static int nuseful_nonterminals;
-static int nuseless_nonterminals;
+int nuseless_nonterminals;
 
 static bool
 bits_equal (BSet L, BSet R, int n)
