@@ -1,6 +1,6 @@
 /* Output a VCG description on generated parser, for Bison,
 
-   Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -88,21 +88,21 @@ print_core (struct obstack *oout, state *s)
       for (/* Nothing */; *sp >= 0; ++sp)
 	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
 
-      /* Experimental feature: display the lookaheads. */
-      if (report_flag & report_lookaheads)
+      /* Experimental feature: display the look-ahead tokens. */
+      if (report_flag & report_look_ahead_tokens)
 	{
 	  /* Find the reduction we are handling.  */
 	  reductions *reds = s->reductions;
 	  int redno = state_reduction_find (s, &rules[r]);
 
 	  /* Print them if there are.  */
-	  if (reds->lookaheads && redno != -1)
+	  if (reds->look_ahead_tokens && redno != -1)
 	    {
 	      bitset_iterator biter;
 	      int k;
 	      char const *sep = "";
 	      obstack_sgrow (oout, "[");
-	      BITSET_FOR_EACH (biter, reds->lookaheads[redno], k, 0)
+	      BITSET_FOR_EACH (biter, reds->look_ahead_tokens[redno], k, 0)
 		{
 		  obstack_fgrow2 (oout, "%s%s", sep, symbols[k]->tag);
 		  sep = ", ";
