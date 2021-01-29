@@ -420,16 +420,8 @@ build_relations (void)
 
 	  for (rp = rules[*rulep].rhs; *rp >= 0; rp++)
 	    {
-	      shifts_t *sp = state->shifts;
-	      int j;
-	      for (j = 0; j < sp->nshifts; j++)
-		{
-		  state = states[sp->shifts[j]];
-		  if (state->accessing_symbol
-		      == item_number_as_symbol_number (*rp))
-		    break;
-		}
-
+	      state = shifts_to (state->shifts,
+				 item_number_as_symbol_number (*rp));
 	      states1[length++] = state->number;
 	    }
 
