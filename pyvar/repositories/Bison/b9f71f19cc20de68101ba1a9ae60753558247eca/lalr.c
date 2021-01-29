@@ -401,7 +401,7 @@ static void
 build_relations (void)
 {
   short *edge = XCALLOC (short, ngotos + 1);
-  short *states = XCALLOC (short, ritem_longest_rhs () + 1);
+  short *states1 = XCALLOC (short, ritem_longest_rhs () + 1);
   int i;
 
   includes = XCALLOC (short *, ngotos);
@@ -418,7 +418,7 @@ build_relations (void)
 	  int length = 1;
 	  short *rp;
 	  state_t *state = state_table[from_state[i]];
-	  states[0] = state->number;
+	  states1[0] = state->number;
 
 	  for (rp = &ritem[rules[*rulep].rhs]; *rp >= 0; rp++)
 	    {
@@ -431,7 +431,7 @@ build_relations (void)
 		    break;
 		}
 
-	      states[length++] = state->number;
+	      states1[length++] = state->number;
 	    }
 
 	  if (!state->consistent)
@@ -446,7 +446,7 @@ build_relations (void)
 	      /* JF added rp>=ritem &&   I hope to god its right! */
 	      if (rp >= ritem && ISVAR (*rp))
 		{
-		  edge[nedges++] = map_goto (states[--length], *rp);
+		  edge[nedges++] = map_goto (states1[--length], *rp);
 		  if (nullable[*rp])
 		    done = 0;
 		}
@@ -464,7 +464,7 @@ build_relations (void)
     }
 
   XFREE (edge);
-  XFREE (states);
+  XFREE (states1);
 
   includes = transpose (includes, ngotos);
 }
