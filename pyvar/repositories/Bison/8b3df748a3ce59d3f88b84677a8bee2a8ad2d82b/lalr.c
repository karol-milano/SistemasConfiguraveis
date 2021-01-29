@@ -27,6 +27,7 @@
 #include "system.h"
 #include "bitset.h"
 #include "bitsetv.h"
+#include "quotearg.h"
 #include "reader.h"
 #include "types.h"
 #include "LR0.h"
@@ -559,9 +560,9 @@ lookaheads_print (FILE *out)
 
       for (j = 0; j < states[i]->nlookaheads; ++j)
 	for (k = 0; k < ntokens; ++k)
-	  if (bitset_test (LA[states[i]->lookaheadsp + j], j))
+	  if (bitset_test (LA[states[i]->lookaheadsp + j], k))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
-		     k, symbols[k]->tag,
+		     k, quotearg_style (escape_quoting_style, symbols[k]->tag),
 		     LArule[states[i]->lookaheadsp + j]->number - 1);
     }
   fprintf (out, "Lookaheads: END\n");
