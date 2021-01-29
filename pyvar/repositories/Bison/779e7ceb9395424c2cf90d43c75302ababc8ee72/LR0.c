@@ -1,7 +1,7 @@
 /* Generate the nondeterministic finite state machine for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2004 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -106,7 +106,8 @@ allocate_itemsets (void)
      browsed too, hence we need to allocate room for _all_ the
      symbols.  */
   int count = 0;
-  short *symbol_count = CALLOC (symbol_count, nsyms + nuseless_nonterminals);
+  short int *symbol_count = CALLOC (symbol_count,
+				    nsyms + nuseless_nonterminals);
 
   for (r = 0; r < nrules; ++r)
     for (rhsp = rules[r].rhs; *rhsp >= 0; ++rhsp)
