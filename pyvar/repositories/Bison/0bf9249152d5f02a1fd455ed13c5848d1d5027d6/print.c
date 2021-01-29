@@ -38,9 +38,9 @@
 #include "reduce.h"
 #include "state.h"
 #include "symtab.h"
+#include "tables.h"
 
 static bitset shift_set;
-static bitset lookahead_set;
 
 #if 0
 static void
@@ -206,71 +206,6 @@ print_errs (FILE *out, state *s)
 }
 
 
-/*-------------------------------------------------------------.
-| Return the default rule of S if it has one, NULL otherwise.  |
-`-------------------------------------------------------------*/
-
-static rule *
-state_default_rule (state *s)
-{
-  reductions *reds = s->reductions;
-  rule *default_rule = NULL;
-  int cmax = 0;
-  int i;
-
-  /* No need for a lookahead.  */
-  if (s->consistent)
-    return reds->rules[0];
-
-  /* 1. Each reduction is possibly masked by the lookahead tokens on which
-     we shift (S/R conflicts)...  */
-  bitset_zero (shift_set);
-  {
-    transitions *trans = s->transitions;
-    FOR_EACH_SHIFT (trans, i)
-      {
-	/* If this state has a shift for the error token, don't use a
-	     default rule.  */
-	if (TRANSITION_IS_ERROR (trans, i))
-	  return NULL;
-	bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
-      }
-  }
-
-  /* 2. Each reduction is possibly masked by the lookahead tokens on which
-     we raise an error (due to %nonassoc).  */
-  {
-    errs *errp = s->errs;
-    for (i = 0; i < errp->num; i++)
-      if (errp->symbols[i])
-	bitset_set (shift_set, errp->symbols[i]->number);
-  }
-
-  for (i = 0; i < reds->num; ++i)
-    {
-      int count = 0;
-
-      /* How many non-masked lookahead tokens are there for this
-	 reduction?  */
-      bitset_andn (lookahead_set, reds->lookahead_tokens[i], shift_set);
-      count = bitset_count (lookahead_set);
-
-      if (count > cmax)
-	{
-	  cmax = count;
-	  default_rule = reds->rules[i];
-	}
-
-      /* 3. And finally, each reduction is possibly masked by previous
-	 reductions (in R/R conflicts, we keep the first reductions).
-	 */
-      bitset_or (shift_set, shift_set, reds->lookahead_tokens[i]);
-    }
-
-  return default_rule;
-}
-
-
 /*-------------------------------------------------------------------------.
 | Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be `default').  |
 | If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
@@ -314,7 +249,8 @@ print_reductions (FILE *out, state *s)
   if (reds->num == 0)
     return;
 
-  default_rule = state_default_rule (s);
+  if (yydefact[s->number] != 0)
+    default_rule = &rules[yydefact[s->number] - 1];
 
   bitset_zero (shift_set);
   FOR_EACH_SHIFT (trans, i)
@@ -563,11 +499,9 @@ print_results (void)
     new_closure (nritems);
   /* Storage for print_reductions.  */
   shift_set =  bitset_create (ntokens, BITSET_FIXED);
-  lookahead_set = bitset_create (ntokens, BITSET_FIXED);
   for (i = 0; i < nstates; i++)
     print_state (out, states[i]);
   bitset_free (shift_set);
-  bitset_free (lookahead_set);
   if (report_flag & report_itemsets)
     free_closure ();
 
