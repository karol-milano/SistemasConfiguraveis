@@ -28,11 +28,11 @@
 #include "bitset.h"
 #include "bitsetv.h"
 #include "quotearg.h"
+#include "symtab.h"
+#include "gram.h"
 #include "reader.h"
 #include "types.h"
 #include "LR0.h"
-#include "symtab.h"
-#include "gram.h"
 #include "complain.h"
 #include "lalr.h"
 #include "nullable.h"
@@ -170,8 +170,8 @@ set_goto_map (void)
       shifts *sp = states[state]->shifts;
       for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
 	{
-	  if (ngotos == MAXSHORT)
-	    fatal (_("too many gotos (max %d)"), MAXSHORT);
+	  if (ngotos == SHRT_MAX)
+	    fatal (_("too many gotos (max %d)"), SHRT_MAX);
 
 	  ngotos++;
 	  goto_map[SHIFT_SYMBOL (sp, i)]++;
@@ -275,7 +275,7 @@ initialize_F (void)
       if (nedges)
 	{
 	  reads[i] = XCALLOC (short, nedges + 1);
-	  shortcpy (reads[i], edge, nedges);
+	  memcpy (reads[i], edge, nedges * sizeof (edge[0]));
 	  reads[i][nedges] = -1;
 	  nedges = 0;
 	}
@@ -415,7 +415,7 @@ build_relations (void)
 	{
 	  int done;
 	  int length = 1;
-	  short *rp;
+	  item_number_t *rp;
 	  state_t *state = states[from_state[i]];
 	  states1[0] = state->number;
 
