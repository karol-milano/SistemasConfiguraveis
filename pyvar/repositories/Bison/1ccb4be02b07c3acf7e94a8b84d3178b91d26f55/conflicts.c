@@ -220,7 +220,7 @@ log_resolution (rule *r, symbol_number token,
 
 /*------------------------------------------------------------------.
 | Turn off the shift recorded for the specified token in the        |
-| specified state.  Used when we resolve a shift-reduce conflict in |
+| specified state.  Used when we resolve a shift/reduce conflict in |
 | favor of the reduction or as an error (%nonassoc).                |
 `------------------------------------------------------------------*/
 
@@ -239,7 +239,7 @@ flush_shift (state *s, int token)
 
 /*--------------------------------------------------------------------.
 | Turn off the reduce recorded for the specified token in the         |
-| specified lookahead set.  Used when we resolve a shift-reduce       |
+| specified lookahead set.  Used when we resolve a shift/reduce       |
 | conflict in favor of the shift or as an error (%nonassoc).          |
 `--------------------------------------------------------------------*/
 
@@ -251,7 +251,7 @@ flush_reduce (bitset lookahead_tokens, int token)
 
 
 /*------------------------------------------------------------------.
-| Attempt to resolve shift-reduce conflict for one rule by means of |
+| Attempt to resolve shift/reduce conflict for one rule by means of |
 | precedence declarations.  It has already been checked that the    |
 | rule has a precedence.  A conflict is resolved by modifying the   |
 | shift or reduce tables so that there is no longer a conflict.     |
@@ -276,7 +276,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
         && bitset_test (lookahead_set, i)
         && symbols[i]->content->prec)
       {
-        /* Shift-reduce conflict occurs for token number i
+        /* Shift/reduce conflict occurs for token number i
            and it has a precedence.
            The precedence of shifting is that of token i.  */
         if (symbols[i]->content->prec < redprec)
@@ -358,7 +358,7 @@ set_conflicts (state *s, symbol **errors)
   }
 
   /* Loop over all rules which require lookahead in this state.  First
-     check for shift-reduce conflict, and try to resolve using
+     check for shift/reduce conflict, and try to resolve using
      precedence.  */
   for (int i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec
