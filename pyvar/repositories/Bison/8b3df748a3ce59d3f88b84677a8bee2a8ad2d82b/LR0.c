@@ -24,6 +24,7 @@
 
 #include "system.h"
 #include "bitset.h"
+#include "quotearg.h"
 #include "symtab.h"
 #include "getargs.h"
 #include "reader.h"
@@ -190,7 +191,8 @@ new_state (int symbol)
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
-	     nstates, symbol, symbols[symbol]->tag);
+	     nstates, symbol, quotearg_style (escape_quoting_style,
+					      symbols[symbol]->tag));
 
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
@@ -234,7 +236,8 @@ get_state (int symbol)
 
   if (trace_flag)
     fprintf (stderr, "Entering get_state, state = %d, symbol = %d (%s)\n",
-	     this_state->number, symbol, symbols[symbol]->tag);
+	     this_state->number, symbol, quotearg_style (escape_quoting_style,
+					      symbols[symbol]->tag));
 
   /* Add up the target state's active item numbers to get a hash key.
      */
@@ -416,7 +419,8 @@ generate_states (void)
       if (trace_flag)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
 		 this_state->number,
-		 symbols[this_state->accessing_symbol]->tag);
+		 quotearg_style (escape_quoting_style,
+				 symbols[this_state->accessing_symbol]->tag));
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
