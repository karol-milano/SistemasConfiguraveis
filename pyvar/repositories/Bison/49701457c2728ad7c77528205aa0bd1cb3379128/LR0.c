@@ -30,18 +30,17 @@
 #include "complain.h"
 #include "closure.h"
 #include "LR0.h"
+#include "lalr.h"
 #include "reduce.h"
 
 int nstates;
 int final_state;
 state_t *first_state = NULL;
 shifts *first_shift = NULL;
-reductions *first_reduction = NULL;
 
 static state_t *this_state = NULL;
 static state_t *last_state = NULL;
 static shifts *last_shift = NULL;
-static reductions *last_reduction = NULL;
 
 static int nshifts;
 static short *shift_symbol = NULL;
@@ -551,17 +550,10 @@ save_reductions (void)
   if (count)
     {
       reductions *p = REDUCTIONS_ALLOC (count);
-
-      p->number = this_state->number;
       p->nreds = count;
-
       shortcpy (p->rules, redset, count);
 
-      if (last_reduction)
-	last_reduction->next = p;
-      else
-	first_reduction = p;
-      last_reduction = p;
+      this_state->reductions = p;
     }
 }
 
