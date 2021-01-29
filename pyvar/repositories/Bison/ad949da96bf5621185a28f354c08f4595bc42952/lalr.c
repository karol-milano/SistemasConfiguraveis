@@ -27,6 +27,7 @@
 #include "reader.h"
 #include "types.h"
 #include "LR0.h"
+#include "symtab.h"
 #include "gram.h"
 #include "complain.h"
 #include "lalr.h"
@@ -566,7 +567,7 @@ lookaheads_print (FILE *out)
 	for (k = 0; k < ntokens; ++k)
 	  if (BITISSET (LA (state_table[i]->lookaheadsp + j), j))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
-		     k, tags[k],
+		     k, symbols[k]->tag,
 		     -LAruleno[state_table[i]->lookaheadsp + j] - 1);
     }
   fprintf (out, "Lookaheads: END\n");
