@@ -1,6 +1,6 @@
 /* Match rules with nonterminals for bison,
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002 Free Software
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003 Free Software
    Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -65,7 +65,7 @@ void
 derives_compute (void)
 {
   symbol_number i;
-  int r;
+  rule_number r;
   rule **q;
 
   /* DSET[NTERM - NTOKENS] -- A linked list of the numbers of the rules
