@@ -138,7 +138,7 @@ log_resolution (rule *r, symbol_number token,
 /*------------------------------------------------------------------.
 | Turn off the shift recorded for the specified token in the        |
 | specified state.  Used when we resolve a shift-reduce conflict in |
-| favor of the reduction.                                           |
+| favor of the reduction or as an error (%nonassoc).                |
 `------------------------------------------------------------------*/
 
 static void
@@ -156,9 +156,9 @@ flush_shift (state *s, int token)
 
 
 /*--------------------------------------------------------------------.
-| Turn off the reduce recorded for the specified token for the        |
-| specified lookahead.  Used when we resolve a shift-reduce conflict  |
-| in favor of the shift.                                              |
+| Turn off the reduce recorded for the specified token in the         |
+| specified lookahead set.  Used when we resolve a shift-reduce       |
+| conflict in favor of the shift or as an error (%nonassoc).          |
 `--------------------------------------------------------------------*/
 
 static void
@@ -176,11 +176,12 @@ flush_reduce (bitset lookahead_tokens, int token)
 |                                                                   |
 | RULENO is the number of the lookahead bitset to consider.         |
 |                                                                   |
-| ERRORS can be used to store discovered explicit errors.           |
+| ERRORS and NERRS can be used to store discovered explicit         |
+| errors.                                                           |
 `------------------------------------------------------------------*/
 
 static void
-resolve_sr_conflict (state *s, int ruleno, symbol **errors)
+resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
 {
   symbol_number i;
   reductions *reds = s->reductions;
@@ -188,7 +189,6 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
   rule *redrule = reds->rules[ruleno];
   int redprec = redrule->prec->prec;
   bitset lookahead_tokens = reds->lookahead_tokens[ruleno];
-  int nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
     if (bitset_test (lookahead_tokens, i)
@@ -234,23 +234,10 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors)
 	      flush_shift (s, i);
 	      flush_reduce (lookahead_tokens, i);
 	      /* Record an explicit error for this token.  */
-	      errors[nerrs++] = symbols[i];
+	      errors[(*nerrs)++] = symbols[i];
 	      break;
 	    }
       }
-
-  if (nerrs)
-    {
-      /* Some tokens have been explicitly made errors.  Allocate a
-	 permanent errs structure for this state, to record them.  */
-      state_errs_set (s, nerrs, errors);
-    }
-
-  if (obstack_object_size (&solved_conflicts_obstack))
-    {
-      obstack_1grow (&solved_conflicts_obstack, '\0');
-      s->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
-    }
 }
 
 
@@ -267,6 +254,7 @@ set_conflicts (state *s, symbol **errors)
   int i;
   transitions *trans = s->transitions;
   reductions *reds = s->reductions;
+  int nerrs = 0;
 
   if (s->consistent)
     return;
@@ -282,7 +270,19 @@ set_conflicts (state *s, symbol **errors)
   for (i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
 	&& !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
-      resolve_sr_conflict (s, i, errors);
+      resolve_sr_conflict (s, i, errors, &nerrs);
+
+  if (nerrs)
+    {
+      /* Some tokens have been explicitly made errors.  Allocate a
+         permanent errs structure for this state, to record them.  */
+      state_errs_set (s, nerrs, errors);
+    }
+  if (obstack_object_size (&solved_conflicts_obstack))
+    {
+      obstack_1grow (&solved_conflicts_obstack, '\0');
+      s->solved_conflicts = obstack_finish (&solved_conflicts_obstack);
+    }
 
   /* Loop over all rules which require lookahead in this state.  Check
      for conflicts not resolved above.  */
@@ -290,7 +290,6 @@ set_conflicts (state *s, symbol **errors)
     {
       if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
 	conflicts[s->number] = 1;
-
       bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
     }
 }
