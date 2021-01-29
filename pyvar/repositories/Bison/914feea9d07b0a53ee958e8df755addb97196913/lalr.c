@@ -25,6 +25,7 @@
 
 #include "system.h"
 #include "bitset.h"
+#include "bitsetv.h"
 #include "reader.h"
 #include "types.h"
 #include "LR0.h"
@@ -40,7 +41,7 @@
 state_t **states = NULL;
 
 short *LAruleno = NULL;
-bitset *LA = NULL;
+bitsetv LA = NULL;
 size_t nLA;
 
 static int ngotos;
@@ -50,7 +51,7 @@ short *to_state = NULL;
 
 /* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
-static bitset *F = NULL;
+static bitsetv F = NULL;
 
 static short **includes;
 static shorts **lookback;
@@ -139,9 +140,7 @@ initialize_LA (void)
   if (!nLA)
     nLA = 1;
 
-  LA = XCALLOC (bitset, nLA);
-  for (i = 0; i < nLA; ++i)
-    LA[i] = bitset_create (ntokens, BITSET_FIXED);
+  LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
   LAruleno = XCALLOC (short, nLA);
   lookback = XCALLOC (shorts *, nLA);
 
@@ -253,9 +252,7 @@ initialize_F (void)
 
   int i;
 
-  F = XCALLOC (bitset, ngotos);
-  for (i = 0; i < ngotos; ++i)
-    F[i] = bitset_create (ntokens, BITSET_FIXED);
+  F = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -500,9 +497,7 @@ compute_lookaheads (void)
     LIST_FREE (shorts, lookback[i]);
 
   XFREE (lookback);
-  for (i = 0; i < (unsigned) ngotos; ++i)
-    bitset_free (F[i]);
-  XFREE (F);
+  bitsetv_free (F);
 }
 
 
