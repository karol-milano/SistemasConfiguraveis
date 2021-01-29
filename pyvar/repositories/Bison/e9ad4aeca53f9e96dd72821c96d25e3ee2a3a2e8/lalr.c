@@ -1,7 +1,7 @@
 /* Compute look-ahead criteria for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005
-   Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005,
+   2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -247,11 +247,11 @@ build_relations (void)
 	{
 	  bool done;
 	  int length = 1;
-	  item_number *rp;
+	  item_number const *rp;
 	  state *s = states[from_state[i]];
 	  states1[0] = s->number;
 
-	  for (rp = (*rulep)->rhs; *rp >= 0; rp++)
+	  for (rp = (*rulep)->rhs; ! item_number_is_rule_number (*rp); rp++)
 	    {
 	      s = transitions_to (s->transitions,
 				  item_number_as_symbol_number (*rp));
@@ -266,9 +266,11 @@ build_relations (void)
 	  while (!done)
 	    {
 	      done = true;
+	      /* Each rhs ends in an item number, and there is a
+		 sentinel before the first rhs, so it is safe to
+		 decrement RP here.  */
 	      rp--;
-	      /* JF added rp>=ritem &&   I hope to god its right! */
-	      if (rp >= ritem && ISVAR (*rp))
+	      if (ISVAR (*rp))
 		{
 		  /* Downcasting from item_number to symbol_number.  */
 		  edge[nedges++] = map_goto (states1[--length],
