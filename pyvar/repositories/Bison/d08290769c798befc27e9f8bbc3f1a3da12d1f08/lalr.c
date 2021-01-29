@@ -1,6 +1,6 @@
 /* Compute look-ahead criteria for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -239,7 +239,7 @@ build_relations (void)
 
       for (rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
 	{
-	  int done;
+	  bool done;
 	  int length = 1;
 	  item_number *rp;
 	  state *s = states[from_state[i]];
@@ -256,10 +256,10 @@ build_relations (void)
 	    add_lookback_edge (s, *rulep, i);
 
 	  length--;
-	  done = 0;
+	  done = false;
 	  while (!done)
 	    {
-	      done = 1;
+	      done = true;
 	      rp--;
 	      /* JF added rp>=ritem &&   I hope to god its right! */
 	      if (rp >= ritem && ISVAR (*rp))
@@ -268,7 +268,7 @@ build_relations (void)
 		  edge[nedges++] = map_goto (states1[--length],
 					     item_number_as_symbol_number (*rp));
 		  if (nullable[*rp - ntokens])
-		    done = 0;
+		    done = false;
 		}
 	    }
 	}
