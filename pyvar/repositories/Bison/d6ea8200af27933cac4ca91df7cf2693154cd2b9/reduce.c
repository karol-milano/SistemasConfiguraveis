@@ -1,5 +1,5 @@
 /* Grammar reduction for Bison.
-   Copyright (C) 1988, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
+   Copyright (C) 1988, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -297,9 +297,7 @@ nonterminals_reduce (void)
     if (!bitset_test (V, i))
       {
 	nontermmap[i] = n++;
-	LOCATION_PRINT (stderr, symbols[i]->location);
-	fprintf (stderr, ": %s: %s: %s\n",
-		 _("warning"), _("useless nonterminal"),
+	warn_at (symbols[i]->location, _("useless nonterminal: %s"),
 		 symbols[i]->tag);
       }
 
