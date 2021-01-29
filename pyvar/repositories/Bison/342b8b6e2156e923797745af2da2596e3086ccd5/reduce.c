@@ -29,7 +29,6 @@
 #include "getargs.h"
 #include "files.h"
 #include "gram.h"
-#include "xalloc.h"
 #include "complain.h"
 #include "reduce.h"
 #include "reader.h"
@@ -117,7 +116,7 @@ static void
 useless_nonterminals (void)
 {
   BSet Np, Ns;
-  int i, n;
+  int i;
 
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
@@ -140,7 +139,6 @@ useless_nonterminals (void)
      saved to be used when finding useful productions: only
      productions in this set will appear in the final grammar.  */
 
-  n = 0;
   while (1)
     {
       for (i = WORDSIZE (nvars) - 1; i >= 0; i--)
@@ -171,7 +169,7 @@ static void
 inaccessable_symbols (void)
 {
   BSet Vp, Vs, Pp;
-  int i, n;
+  int i;
   short t;
   rule r;
 
@@ -207,7 +205,6 @@ inaccessable_symbols (void)
 
   SETBIT (V, start_symbol);
 
-  n = 0;
   while (1)
     {
       for (i = WORDSIZE (nsyms) - 1; i >= 0; i--)
