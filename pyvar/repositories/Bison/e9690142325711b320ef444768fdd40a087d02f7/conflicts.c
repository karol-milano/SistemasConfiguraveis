@@ -64,75 +64,75 @@ enum conflict_resolution
 
 static inline void
 log_resolution (rule *r, symbol_number token,
-		enum conflict_resolution resolution)
+                enum conflict_resolution resolution)
 {
   if (report_flag & report_solved_conflicts)
     {
       /* The description of the resolution. */
       switch (resolution)
-	{
-	case shift_resolution:
-	case right_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  _("    Conflict between rule %d and token %s"
-			    " resolved as shift"),
-			  r->number,
-			  symbols[token]->tag);
-	  break;
-
-	case reduce_resolution:
-	case left_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  _("    Conflict between rule %d and token %s"
-			    " resolved as reduce"),
-			  r->number,
-			  symbols[token]->tag);
-	  break;
-
-	case nonassoc_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  _("    Conflict between rule %d and token %s"
-			    " resolved as an error"),
-			  r->number,
-			  symbols[token]->tag);
-	  break;
-	}
+        {
+        case shift_resolution:
+        case right_resolution:
+          obstack_fgrow2 (&solved_conflicts_obstack,
+                          _("    Conflict between rule %d and token %s"
+                            " resolved as shift"),
+                          r->number,
+                          symbols[token]->tag);
+          break;
+
+        case reduce_resolution:
+        case left_resolution:
+          obstack_fgrow2 (&solved_conflicts_obstack,
+                          _("    Conflict between rule %d and token %s"
+                            " resolved as reduce"),
+                          r->number,
+                          symbols[token]->tag);
+          break;
+
+        case nonassoc_resolution:
+          obstack_fgrow2 (&solved_conflicts_obstack,
+                          _("    Conflict between rule %d and token %s"
+                            " resolved as an error"),
+                          r->number,
+                          symbols[token]->tag);
+          break;
+        }
 
       /* The reason. */
       switch (resolution)
-	{
-	case shift_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  " (%s < %s)",
-			  r->prec->tag,
-			  symbols[token]->tag);
-	  break;
-
-	case reduce_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
-			  " (%s < %s)",
-			  symbols[token]->tag,
-			  r->prec->tag);
-	  break;
-
-	case left_resolution:
-	  obstack_fgrow1 (&solved_conflicts_obstack,
-			  " (%%left %s)",
-			  symbols[token]->tag);
-	  break;
-
-	case right_resolution:
-	  obstack_fgrow1 (&solved_conflicts_obstack,
-			  " (%%right %s)",
-			  symbols[token]->tag);
-	  break;
-
-	case nonassoc_resolution:
-	  obstack_fgrow1 (&solved_conflicts_obstack,
-			  " (%%nonassoc %s)",
-			  symbols[token]->tag);
-	  break;
-	}
+        {
+        case shift_resolution:
+          obstack_fgrow2 (&solved_conflicts_obstack,
+                          " (%s < %s)",
+                          r->prec->tag,
+                          symbols[token]->tag);
+          break;
+
+        case reduce_resolution:
+          obstack_fgrow2 (&solved_conflicts_obstack,
+                          " (%s < %s)",
+                          symbols[token]->tag,
+                          r->prec->tag);
+          break;
+
+        case left_resolution:
+          obstack_fgrow1 (&solved_conflicts_obstack,
+                          " (%%left %s)",
+                          symbols[token]->tag);
+          break;
+
+        case right_resolution:
+          obstack_fgrow1 (&solved_conflicts_obstack,
+                          " (%%right %s)",
+                          symbols[token]->tag);
+          break;
+
+        case nonassoc_resolution:
+          obstack_fgrow1 (&solved_conflicts_obstack,
+                          " (%%nonassoc %s)",
+                          symbols[token]->tag);
+          break;
+        }
 
       obstack_sgrow (&solved_conflicts_obstack, ".\n");
     }
@@ -226,7 +226,7 @@ flush_shift (state *s, int token)
   bitset_reset (lookahead_set, token);
   for (i = 0; i < trans->num; i++)
     if (!TRANSITION_IS_DISABLED (trans, i)
-	&& TRANSITION_SYMBOL (trans, i) == token)
+        && TRANSITION_SYMBOL (trans, i) == token)
       TRANSITION_DISABLE (trans, i);
 }
 
@@ -268,23 +268,23 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
 
   for (i = 0; i < ntokens; i++)
     if (bitset_test (lookahead_tokens, i)
-	&& bitset_test (lookahead_set, i)
-	&& symbols[i]->prec)
+        && bitset_test (lookahead_set, i)
+        && symbols[i]->prec)
       {
-	/* Shift-reduce conflict occurs for token number i
-	   and it has a precedence.
-	   The precedence of shifting is that of token i.  */
-	if (symbols[i]->prec < redprec)
-	  {
-	    log_resolution (redrule, i, reduce_resolution);
-	    flush_shift (s, i);
-	  }
-	else if (symbols[i]->prec > redprec)
-	  {
-	    log_resolution (redrule, i, shift_resolution);
-	    flush_reduce (lookahead_tokens, i);
-	  }
-	else
+        /* Shift-reduce conflict occurs for token number i
+           and it has a precedence.
+           The precedence of shifting is that of token i.  */
+        if (symbols[i]->prec < redprec)
+          {
+            log_resolution (redrule, i, reduce_resolution);
+            flush_shift (s, i);
+          }
+        else if (symbols[i]->prec > redprec)
+          {
+            log_resolution (redrule, i, shift_resolution);
+            flush_reduce (lookahead_tokens, i);
+          }
+        else
           /* Matching precedence levels.
              For non-defined associativity, keep both: unexpected
              associativity conflict.
@@ -292,32 +292,32 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
              For right associativity, keep only the shift.
              For nonassociativity, keep neither.  */
 
-	  switch (symbols[i]->assoc)
-	    {
+          switch (symbols[i]->assoc)
+            {
             case undef_assoc:
-	      abort ();
+              abort ();
 
             case precedence_assoc:
               break;
 
-	    case right_assoc:
-	      log_resolution (redrule, i, right_resolution);
-	      flush_reduce (lookahead_tokens, i);
-	      break;
-
-	    case left_assoc:
-	      log_resolution (redrule, i, left_resolution);
-	      flush_shift (s, i);
-	      break;
-
-	    case non_assoc:
-	      log_resolution (redrule, i, nonassoc_resolution);
-	      flush_shift (s, i);
-	      flush_reduce (lookahead_tokens, i);
-	      /* Record an explicit error for this token.  */
-	      errors[(*nerrs)++] = symbols[i];
-	      break;
-	    }
+            case right_assoc:
+              log_resolution (redrule, i, right_resolution);
+              flush_reduce (lookahead_tokens, i);
+              break;
+
+            case left_assoc:
+              log_resolution (redrule, i, left_resolution);
+              flush_shift (s, i);
+              break;
+
+            case non_assoc:
+              log_resolution (redrule, i, nonassoc_resolution);
+              flush_shift (s, i);
+              flush_reduce (lookahead_tokens, i);
+              /* Record an explicit error for this token.  */
+              errors[(*nerrs)++] = symbols[i];
+              break;
+            }
       }
 }
 
@@ -350,7 +350,7 @@ set_conflicts (state *s, symbol **errors)
      precedence.  */
   for (i = 0; i < reds->num; ++i)
     if (reds->rules[i]->prec && reds->rules[i]->prec->prec
-	&& !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
+        && !bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
       resolve_sr_conflict (s, i, errors, &nerrs);
 
   if (nerrs)
@@ -375,7 +375,7 @@ set_conflicts (state *s, symbol **errors)
   for (i = 0; i < reds->num; ++i)
     {
       if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
-	conflicts[s->number] = 1;
+        conflicts[s->number] = 1;
       bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
     }
 }
@@ -404,9 +404,9 @@ conflicts_solve (void)
       set_conflicts (states[i], errors);
 
       /* For uniformity of the code, make sure all the states have a valid
-	 `errs' member.  */
+         `errs' member.  */
       if (!states[i]->errs)
-	states[i]->errs = errs_new (0, 0);
+        states[i]->errs = errs_new (0, 0);
     }
 
   free (errors);
@@ -475,11 +475,11 @@ count_rr_conflicts (state *s, bool one_per_token)
       int count = 0;
       int j;
       for (j = 0; j < reds->num; ++j)
-	if (bitset_test (reds->lookahead_tokens[j], i))
-	  count++;
+        if (bitset_test (reds->lookahead_tokens[j], i))
+          count++;
 
       if (count >= 2)
-	rrc_count += one_per_token ? 1 : count-1;
+        rrc_count += one_per_token ? 1 : count-1;
     }
 
   return rrc_count;
@@ -495,7 +495,7 @@ conflict_report (FILE *out, int src_num, int rrc_num)
 {
   if (src_num && rrc_num)
     fprintf (out, _("conflicts: %d shift/reduce, %d reduce/reduce\n"),
-	     src_num, rrc_num);
+             src_num, rrc_num);
   else if (src_num)
     fprintf (out, _("conflicts: %d shift/reduce\n"), src_num);
   else if (rrc_num)
@@ -516,12 +516,12 @@ conflicts_output (FILE *out)
     {
       state *s = states[i];
       if (conflicts[i])
-	{
-	  fprintf (out, _("State %d "), i);
-	  conflict_report (out, count_sr_conflicts (s),
-			   count_rr_conflicts (s, true));
-	  printed_sth = true;
-	}
+        {
+          fprintf (out, _("State %d "), i);
+          conflict_report (out, count_sr_conflicts (s),
+                           count_rr_conflicts (s, true));
+          printed_sth = true;
+        }
     }
   if (printed_sth)
     fputs ("\n\n", out);
@@ -531,7 +531,7 @@ conflicts_output (FILE *out)
 | Total the number of S/R and R/R conflicts.  Unlike the  |
 | code in conflicts_output, however, count EACH pair of   |
 | reductions for the same state and lookahead as one      |
-| conflict.						  |
+| conflict.                                               |
 `--------------------------------------------------------*/
 
 int
@@ -545,8 +545,8 @@ conflicts_total_count (void)
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
       {
-	count += count_sr_conflicts (states[i]);
-	count += count_rr_conflicts (states[i], false);
+        count += count_sr_conflicts (states[i]);
+        count += count_rr_conflicts (states[i], false);
       }
   return count;
 }
@@ -576,10 +576,10 @@ conflicts_print (void)
 
     for (i = 0; i < nstates; i++)
       if (conflicts[i])
-	{
-	  src_total += count_sr_conflicts (states[i]);
-	  rrc_total += count_rr_conflicts (states[i], true);
-	}
+        {
+          src_total += count_sr_conflicts (states[i]);
+          rrc_total += count_rr_conflicts (states[i], true);
+        }
   }
 
   if (! glr_parser && rrc_total > 0 && expected_rr_conflicts != -1)
@@ -611,22 +611,22 @@ conflicts_print (void)
       if (expected_sr_conflicts == -1 && expected_rr_conflicts == -1)
         set_warning_issued ();
       if (! yacc_flag)
-	fprintf (stderr, "%s: ", current_file);
+        fprintf (stderr, "%s: ", current_file);
       conflict_report (stderr, src_total, rrc_total);
     }
 
   if (expected_sr_conflicts != -1 || expected_rr_conflicts != -1)
     {
       if (! src_ok)
-	complain (ngettext ("expected %d shift/reduce conflict",
-			    "expected %d shift/reduce conflicts",
-			    src_expected),
-		  src_expected);
+        complain (ngettext ("expected %d shift/reduce conflict",
+                            "expected %d shift/reduce conflicts",
+                            src_expected),
+                  src_expected);
       if (! rrc_ok)
-	complain (ngettext ("expected %d reduce/reduce conflict",
-			    "expected %d reduce/reduce conflicts",
-			    rrc_expected),
-		  rrc_expected);
+        complain (ngettext ("expected %d reduce/reduce conflict",
+                            "expected %d reduce/reduce conflicts",
+                            rrc_expected),
+                  rrc_expected);
     }
 }
 
