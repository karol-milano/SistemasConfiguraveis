@@ -20,9 +20,16 @@
 
 
 #include "system.h"
+#include "complain.h"
 #include "gram.h"
 #include "state.h"
 
+
+			/*-------------------.
+			| Shifts and Gotos.  |
+			`-------------------*/
+
+
 /*---------------------------------.
 | Create a new array of N shitfs.  |
 `---------------------------------*/
@@ -40,6 +47,13 @@ shifts_new (int n)
 }
 
 
+
+
+			/*--------------------.
+			| Error transitions.  |
+			`--------------------*/
+
+
 /*-------------------------------.
 | Create a new array of N errs.  |
 `-------------------------------*/
@@ -66,6 +80,14 @@ errs_dup (errs *src)
   return res;
 }
 
+
+
+
+			/*-------------.
+			| Reductions.  |
+			`-------------*/
+
+
 /*-------------------------------------.
 | Create a new array of N reductions.  |
 `-------------------------------------*/
@@ -83,6 +105,47 @@ reductions_new (int n)
 }
 
 
+
+			/*---------.
+			| States.  |
+			`---------*/
+
+
+state_number_t nstates = 0;
+/* FINAL_STATE is properly set by new_state when it recognizes its
+   accessing symbol: EOF.  */
+state_t *final_state = NULL;
+
+/*------------------------------------------------------------.
+| Create a new state with ACCESSING_SYMBOL, for those items.  |
+`------------------------------------------------------------*/
+
+state_t *
+state_new (symbol_number_t accessing_symbol,
+	   size_t core_size, item_number_t *core)
+{
+  state_t *res;
+
+  if (nstates >= STATE_NUMBER_MAX)
+    fatal (_("too many states (max %d)"), STATE_NUMBER_MAX);
+
+#define STATE_ALLOC(Nitems)						\
+  (state_t *) xcalloc ((unsigned) (sizeof (state_t) 			\
+                                  + (Nitems - 1) * sizeof (item_number_t)), 1)
+
+  res = STATE_ALLOC (core_size);
+  res->accessing_symbol = accessing_symbol;
+  res->number = nstates;
+  ++nstates;
+  res->solved_conflicts = NULL;
+
+  res->nitems = core_size;
+  memcpy (res->items, core, core_size * sizeof (core[0]));
+
+  return res;
+}
+
+
 /*--------------------------------------------------------------.
 | Print on OUT all the lookaheads such that this STATE wants to |
 | reduce this RULE.                                             |
