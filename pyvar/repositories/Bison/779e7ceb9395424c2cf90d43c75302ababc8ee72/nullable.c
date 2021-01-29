@@ -1,7 +1,7 @@
 /* Calculate which nonterminals can expand into the null string for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003, 2004 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -62,7 +62,7 @@ nullable_compute (void)
   rule_list *p;
 
   symbol_number *squeue = CALLOC (squeue, nvars);
-  short *rcount = CALLOC (rcount, nrules);
+  short int *rcount = CALLOC (rcount, nrules);
   /* RITEM contains all the rules, including useless productions.
      Hence we must allocate room for useless nonterminals too.  */
   rule_list **rsets = CALLOC (rsets, nvars);
