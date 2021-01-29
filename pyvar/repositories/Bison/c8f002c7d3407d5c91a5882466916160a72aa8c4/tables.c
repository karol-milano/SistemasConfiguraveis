@@ -394,16 +394,6 @@ action_row (state_t *state)
 	}
     }
 
-  /* Find the rules which are reduced.  */
-  if (!glr_parser)
-    {
-      for (i = 0; i < ntokens; i++)
-	if (actrow[i] < 0 && actrow[i] != ACTION_MIN)
-	  rules[item_number_as_rule_number (actrow[i])].useful = TRUE;
-      if (default_rule)
-	default_rule->useful = TRUE;
-    }
-
   /* If have no default rule, the default is an error.
      So replace any action which says "error" with "use default".  */
 
@@ -477,7 +467,9 @@ static void
 token_actions (void)
 {
   state_number_t i;
+  symbol_number_t j;
   rule_number_t r;
+
   int nconflict = conflicts_total_count ();
 
   yydefact = XCALLOC (rule_number_t, nstates);
@@ -485,9 +477,7 @@ token_actions (void)
   actrow = XCALLOC (action_t, ntokens);
   conflrow = XCALLOC (unsigned int, ntokens);
 
-  /* Now that the parser was computed, we can find which rules are
-     really reduced, and which are not because of SR or RR conflicts.
-     */
+  /* Find the rules which are reduced.  */
   if (!glr_parser)
     for (r = 0; r < nrules; ++r)
       rules[r].useful = FALSE;
@@ -506,17 +496,19 @@ token_actions (void)
       rule_t *default_rule = action_row (states[i]);
       yydefact[i] = default_rule ? default_rule->number + 1 : 0;
       save_row (i);
-    }
 
-  if (!glr_parser)
-    for (r = 0; r < nrules ; ++r)
-      if (!rules[r].useful)
+      /* Now that the parser was computed, we can find which rules are
+	 really reduced, and which are not because of SR or RR
+	 conflicts.  */
+      if (!glr_parser)
 	{
-	  LOCATION_PRINT (stderr, rules[r].location);
-	  fprintf (stderr, ": %s: %s: ",
-		   _("warning"), _("rule never reduced because of conflicts"));
-	  rule_print (&rules[r], stderr);
+	  for (j = 0; j < ntokens; ++j)
+	    if (actrow[j] < 0 && actrow[j] != ACTION_MIN)
+	      rules[item_number_as_rule_number (actrow[j])].useful = TRUE;
+	  if (yydefact[i])
+	    rules[yydefact[i] - 1].useful = TRUE;
 	}
+    }
 
   free (actrow);
   free (conflrow);
