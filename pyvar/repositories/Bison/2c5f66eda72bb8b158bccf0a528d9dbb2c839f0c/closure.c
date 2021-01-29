@@ -1,5 +1,5 @@
 /* Subroutines for bison
-   Copyright 1984, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,6 +20,7 @@
 
 #include "system.h"
 #include "gram.h"
+#include "reader.h"
 #include "closure.h"
 #include "derives.h"
 #include "warshall.h"
@@ -38,7 +39,7 @@ static int rulesetsize;
 /* number of words required to hold a bit for each variable */
 static int varsetsize;
 
-#if DEBUG
+#if TRACE
 
 /*-----------------.
 | Debugging code.  |
@@ -49,9 +50,9 @@ print_closure (int n)
 {
   short *isp;
 
-  printf ("\n\nn = %d\n\n", n);
+  fprintf (stderr, "\n\nn = %d\n\n", n);
   for (isp = itemset; isp < itemsetend; isp++)
-    printf ("   %d\n", *isp);
+    fprintf (stderr, "   %d\n", *isp);
 }
 
 
@@ -62,17 +63,17 @@ print_firsts (void)
   int j;
   unsigned *rowp;
 
-  printf ("\n\n\nFIRSTS\n\n");
+  fprintf (stderr, "\n\n\nFIRSTS\n\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf ("\n\n%s firsts\n\n", tags[i]);
+      fprintf (stderr, "\n\n%s firsts\n\n", tags[i]);
 
       rowp = firsts + ((i - ntokens) * varsetsize);
 
       for (j = 0; j < nvars; j++)
 	if (BITISSET (rowp, j))
-	  printf ("   %s\n", tags[j + ntokens]);
+	  fprintf (stderr, "   %s\n", tags[j + ntokens]);
     }
 }
 
@@ -84,19 +85,17 @@ print_fderives (void)
   int j;
   unsigned *rp;
 
-  printf ("\n\n\nFDERIVES\n");
+  fprintf (stderr, "\n\n\nFDERIVES\n");
 
   for (i = ntokens; i < nsyms; i++)
     {
-      printf ("\n\n%s derives\n\n", tags[i]);
+      fprintf (stderr, "\n\n%s derives\n\n", tags[i]);
       rp = fderives + i * rulesetsize;
 
       for (j = 0; j <= nrules; j++)
 	if (BITISSET (rp, j))
-	  printf ("   %d\n", j);
+	  fprintf (stderr, "   %d\n", j);
     }
-
-  fflush (stdout);
 }
 #endif
 
@@ -143,7 +142,7 @@ set_firsts (void)
 
   RTC (firsts, nvars);
 
-#ifdef	DEBUG
+#ifdef TRACE
   print_firsts ();
 #endif
 }
@@ -204,7 +203,7 @@ set_fderives (void)
       rrow += rulesetsize;
     }
 
-#ifdef	DEBUG
+#ifdef TRACE
   print_fderives ();
 #endif
 
@@ -301,7 +300,7 @@ closure (short *core, int n)
   while (csp < csend)
     *itemsetend++ = *csp++;
 
-#if DEBUG
+#if TRACE
   print_closure (n);
 #endif
 }
