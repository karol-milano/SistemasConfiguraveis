@@ -1,47 +1,47 @@
 /* Subroutines for bison
-   Copyright (C) 1984, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to the Free
+   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+   02111-1307, USA.  */
 
 
-/* subroutines of file LR0.c.
+/* Subroutines of file LR0.c.
 
 Entry points:
 
   closure (items, n)
 
-Given a vector of item numbers items, of length n,
-set up ruleset and itemset to indicate what rules could be run
-and which items could be accepted when those items are the active ones.
+Given a vector of item numbers items, of length n, set up ruleset and
+itemset to indicate what rules could be run and which items could be
+accepted when those items are the active ones.
 
-ruleset contains a bit for each rule.  closure sets the bits
-for all rules which could potentially describe the next input to be read.
+ruleset contains a bit for each rule.  closure sets the bits for all
+rules which could potentially describe the next input to be read.
 
-itemset is a vector of item numbers; itemsetend points to just beyond the end
- of the part of it that is significant.
-closure places there the indices of all items which represent units of
-input that could arrive next.
+itemset is a vector of item numbers; itemsetend points to just beyond
+the end of the part of it that is significant.  closure places there
+the indices of all items which represent units of input that could
+arrive next.
 
   initialize_closure (n)
 
-Allocates the itemset and ruleset vectors,
-and precomputes useful data so that closure can be called.
-n is the number of elements to allocate for itemset.
+Allocates the itemset and ruleset vectors, and precomputes useful data
+so that closure can be called.  n is the number of elements to
+allocate for itemset.
 
   finalize_closure ()
 
@@ -155,11 +155,15 @@ set_fderives (void)
 
 
 
-/* set firsts to be an nvars by nvars bit matrix indicating which items
-   can represent the beginning of the input corresponding to which other items.
-   For example, if some rule expands symbol 5 into the sequence of symbols 8 3 20,
-   the symbol 8 can be the beginning of the data for symbol 5,
-   so the bit [8 - ntokens, 5 - ntokens] in firsts is set. */
+/* set firsts to be an nvars by nvars bit matrix indicating which
+   items can represent the beginning of the input corresponding to
+   which other items.
+
+   For example, if some rule expands symbol 5 into the sequence of
+   symbols 8 3 20, the symbol 8 can be the beginning of the data for
+   symbol 5, so the bit [8 - ntokens, 5 - ntokens] in firsts is
+   set. */
+
 void
 set_firsts (void)
 {
@@ -195,7 +199,7 @@ set_firsts (void)
   RTC(firsts, nvars);
 
 #ifdef	DEBUG
-  print_firsts();
+  print_firsts ();
 #endif
 }
 
@@ -299,9 +303,9 @@ int n;
 {
   register short *isp;
 
-  printf("\n\nn = %d\n\n", n);
+  printf ("\n\nn = %d\n\n", n);
   for (isp = itemset; isp < itemsetend; isp++)
-    printf("   %d\n", *isp);
+    printf ("   %d\n", *isp);
 }
 
 
@@ -312,17 +316,17 @@ print_firsts (void)
   register int j;
   register unsigned *rowp;
 
-  printf(_("\n\n\nFIRSTS\n\n"));
+  printf ("\n\n\nFIRSTS\n\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf(_("\n\n%s firsts\n\n"), tags[i]);
+      printf ("\n\n%s firsts\n\n", tags[i]);
 
       rowp = firsts + ((i - ntokens) * varsetsize);
 
       for (j = 0; j < nvars; j++)
 	if (BITISSET (rowp, j))
-	  printf("   %s\n", tags[j + ntokens]);
+	  printf ("   %s\n", tags[j + ntokens]);
     }
 }
 
@@ -334,16 +338,16 @@ print_fderives (void)
   register int j;
   register unsigned *rp;
 
-  printf(_("\n\n\nFDERIVES\n"));
+  printf ("\n\n\nFDERIVES\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf(_("\n\n%s derives\n\n"), tags[i]);
+      printf ("\n\n%s derives\n\n", tags[i]);
       rp = fderives + i * rulesetsize;
 
       for (j = 0; j <= nrules; j++)
 	if (BITISSET (rp, j))
-	  printf("   %d\n", j);
+	  printf ("   %d\n", j);
     }
 
   fflush(stdout);
