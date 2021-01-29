@@ -40,7 +40,7 @@
 #include "symtab.h"
 #include "tables.h"
 
-static bitset shift_set;
+static bitset no_reduce_set;
 
 #if 0
 static void
@@ -252,9 +252,12 @@ print_reductions (FILE *out, state *s)
   if (yydefact[s->number] != 0)
     default_rule = &rules[yydefact[s->number] - 1];
 
-  bitset_zero (shift_set);
+  bitset_zero (no_reduce_set);
   FOR_EACH_SHIFT (trans, i)
-    bitset_set (shift_set, TRANSITION_SYMBOL (trans, i));
+    bitset_set (no_reduce_set, TRANSITION_SYMBOL (trans, i));
+  for (i = 0; i < s->errs->num; ++i)
+    if (s->errs->symbols[i])
+      bitset_set (no_reduce_set, s->errs->symbols[i]->number);
 
   /* Compute the width of the lookahead token column.  */
   if (default_rule)
@@ -263,7 +266,7 @@ print_reductions (FILE *out, state *s)
   if (reds->lookahead_tokens)
     for (i = 0; i < ntokens; i++)
       {
-	bool count = bitset_test (shift_set, i);
+	bool count = bitset_test (no_reduce_set, i);
 
 	for (j = 0; j < reds->num; ++j)
 	  if (bitset_test (reds->lookahead_tokens[j], i))
@@ -293,7 +296,7 @@ print_reductions (FILE *out, state *s)
     for (i = 0; i < ntokens; i++)
       {
 	bool defaulted = false;
-	bool count = bitset_test (shift_set, i);
+	bool count = bitset_test (no_reduce_set, i);
 
 	for (j = 0; j < reds->num; ++j)
 	  if (bitset_test (reds->lookahead_tokens[j], i))
@@ -498,10 +501,10 @@ print_results (void)
   if (report_flag & report_itemsets)
     new_closure (nritems);
   /* Storage for print_reductions.  */
-  shift_set =  bitset_create (ntokens, BITSET_FIXED);
+  no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
   for (i = 0; i < nstates; i++)
     print_state (out, states[i]);
-  bitset_free (shift_set);
+  bitset_free (no_reduce_set);
   if (report_flag & report_itemsets)
     free_closure ();
 
