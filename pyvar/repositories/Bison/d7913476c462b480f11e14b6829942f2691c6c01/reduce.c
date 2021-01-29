@@ -29,7 +29,7 @@
 #include "getargs.h"
 #include "files.h"
 #include "gram.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "complain.h"
 #include "reduce.h"
 #include "reader.h"
@@ -122,7 +122,7 @@ useless_nonterminals (void)
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
 
-  Np = NEW2 (WORDSIZE (nvars), unsigned);
+  Np = XCALLOC (unsigned, WORDSIZE (nvars));
 
   /* The set being computed is a set of nonterminals which can derive
      the empty string or strings consisting of all terminals. At each
@@ -162,7 +162,7 @@ useless_nonterminals (void)
       Np = N;
       N = Ns;
     }
-  FREE (N);
+  XFREE (N);
   N = Np;
 }
 
@@ -198,8 +198,8 @@ inaccessable_symbols (void)
      terminals are printed (if running in verbose mode) so that the
      user can know.  */
 
-  Vp = NEW2 (WORDSIZE (nsyms), unsigned);
-  Pp = NEW2 (WORDSIZE (nrules + 1), unsigned);
+  Vp = XCALLOC (unsigned, WORDSIZE (nsyms));
+  Pp = XCALLOC (unsigned, WORDSIZE (nrules + 1));
 
   /* If the start symbol isn't useful, then nothing will be useful. */
   if (!BITISSET (N, start_symbol - ntokens))
@@ -236,7 +236,7 @@ inaccessable_symbols (void)
     }
 end_iteration:
 
-  FREE (V);
+  XFREE (V);
   V = Vp;
 
   /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
@@ -244,7 +244,7 @@ end_iteration:
   SETBIT (V, 1);		/* error token */
   SETBIT (V, 2);		/* some undefined token */
 
-  FREE (P);
+  XFREE (P);
   P = Pp;
 
   nuseful_productions = bits_size (P, WORDSIZE (nrules + 1));
@@ -340,7 +340,7 @@ reduce_grammar_tables (void)
 	 number. -1 in the map means it was useless and is being
 	 eliminated.  */
 
-      nontermmap = NEW2 (nvars, short) - ntokens;
+      nontermmap = XCALLOC (short, nvars) - ntokens;
       for (i = ntokens; i < nsyms; i++)
 	nontermmap[i] = -1;
 
@@ -513,10 +513,10 @@ reduce_grammar (void)
 
   /* Allocate the global sets used to compute the reduced grammar */
 
-  N = NEW2 (WORDSIZE (nvars), unsigned);
-  P = NEW2 (WORDSIZE (nrules + 1), unsigned);
-  V = NEW2 (WORDSIZE (nsyms), unsigned);
-  V1 = NEW2 (WORDSIZE (nsyms), unsigned);
+  N = XCALLOC (unsigned, WORDSIZE (nvars));
+  P = XCALLOC (unsigned, WORDSIZE (nrules + 1));
+  V = XCALLOC (unsigned, WORDSIZE (nsyms));
+  V1 = XCALLOC (unsigned, WORDSIZE (nsyms));
 
   useless_nonterminals ();
   inaccessable_symbols ();
@@ -558,7 +558,7 @@ reduce_grammar (void)
 done_reducing:
   /* Free the global sets used to compute the reduced grammar */
 
-  FREE (N);
-  FREE (V);
-  FREE (P);
+  XFREE (N);
+  XFREE (V);
+  XFREE (P);
 }
