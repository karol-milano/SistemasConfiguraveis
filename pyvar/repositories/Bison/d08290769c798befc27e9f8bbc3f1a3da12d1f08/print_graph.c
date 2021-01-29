@@ -1,6 +1,6 @@
 /* Output a VCG description on generated parser, for Bison,
 
-   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -100,12 +100,13 @@ print_core (struct obstack *oout, state *s)
 	    {
 	      bitset_iterator biter;
 	      int k;
-	      int not_first = 0;
+	      char const *sep = "";
 	      obstack_sgrow (oout, "[");
 	      BITSET_FOR_EACH (biter, reds->lookaheads[redno], k, 0)
-		obstack_fgrow2 (oout, "%s%s",
-				not_first++ ? ", " : "",
-				symbols[k]->tag);
+		{
+		  obstack_fgrow2 (oout, "%s%s", sep, symbols[k]->tag);
+		  sep = ", ";
+		}
 	      obstack_sgrow (oout, "]");
 	    }
 	}
