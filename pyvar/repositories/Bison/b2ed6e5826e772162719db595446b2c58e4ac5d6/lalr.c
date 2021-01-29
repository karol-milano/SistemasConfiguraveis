@@ -561,7 +561,7 @@ build_relations (void)
 	  states[0] = state1;
 	  stateno = state1;
 
-	  for (rp = ritem + rrhs[*rulep]; *rp > 0; rp++)
+	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
 	    {
 	      symbol2 = *rp;
 	      sp = state_table[stateno].shift_table;
