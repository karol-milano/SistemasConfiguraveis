@@ -200,7 +200,7 @@ conflict_row (state *s)
         /* Find all reductions for token J, and record all that do not
            match ACTROW[J].  */
         for (int i = 0; i < reds->num; i += 1)
-          if (bitset_test (reds->lookahead_tokens[i], j)
+          if (bitset_test (reds->lookaheads[i], j)
               && (actrow[j]
                   != rule_number_as_item_number (reds->rules[i]->number)))
             {
@@ -247,7 +247,7 @@ action_row (state *s)
 
   reductions *reds = s->reductions;
   bool conflicted = false;
-  if (reds->lookahead_tokens)
+  if (reds->lookaheads)
     /* loop over all the rules available here which require
        lookahead (in reverse order to give precedence to the first
        rule) */
@@ -257,7 +257,7 @@ action_row (state *s)
       {
         bitset_iterator biter;
         int j;
-        BITSET_FOR_EACH (biter, reds->lookahead_tokens[i], j, 0)
+        BITSET_FOR_EACH (biter, reds->lookaheads[i], j, 0)
           {
             /* and record this rule as the rule to use if that
                token follows.  */
@@ -308,7 +308,7 @@ action_row (state *s)
     }
 
   /* Turn off default reductions where requested by the user.  See
-     state_lookahead_tokens_count in lalr.c to understand when states are
+     state_lookaheads_count in lalr.c to understand when states are
      labeled as consistent.  */
   {
     char *default_reductions =
