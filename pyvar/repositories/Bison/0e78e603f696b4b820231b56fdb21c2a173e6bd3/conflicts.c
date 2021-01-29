@@ -21,6 +21,7 @@
 #include "system.h"
 #include "complain.h"
 #include "getargs.h"
+#include "symtab.h"
 #include "files.h"
 #include "gram.h"
 #include "state.h"
@@ -99,17 +100,17 @@ resolve_sr_conflict (state_t *state, int lookahead)
   for (i = 0; i < ntokens; i++)
     if (BITISSET (LA (lookahead), i)
 	&& BITISSET (lookaheadset, i)
-	&& sprec[i])
+	&& symbols[i]->prec)
       {
 	/* Shift-reduce conflict occurs for token number i
 	   and it has a precedence.
 	   The precedence of shifting is that of token i.  */
-	if (sprec[i] < redprec)
+	if (symbols[i]->prec < redprec)
 	  {
 	    log_resolution (state, lookahead, i, _("reduce"));
 	    flush_shift (state, i);
 	  }
-	else if (sprec[i] > redprec)
+	else if (symbols[i]->prec > redprec)
 	  {
 	    log_resolution (state, lookahead, i, _("shift"));
 	    flush_reduce (lookahead, i);
