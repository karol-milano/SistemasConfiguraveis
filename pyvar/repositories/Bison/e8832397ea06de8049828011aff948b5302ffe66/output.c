@@ -598,6 +598,16 @@ action_row (state_t *state)
 	}
     }
 
+  /* Find the rules which are reduced.  */
+  if (!glr_parser)
+    {
+      for (i = 0; i < ntokens; i++)
+	if (actrow[i] < 0 && actrow[i] != ACTION_MIN)
+	  rules[item_number_as_rule_number (actrow[i])].useful = TRUE;
+      if (default_rule)
+	default_rule->useful = TRUE;
+    }
+
   /* If have no default rule, the default is an error.
      So replace any action which says "error" with "use default".  */
 
@@ -671,6 +681,7 @@ static void
 token_actions (void)
 {
   state_number_t i;
+  rule_number_t r;
   int nconflict = conflicts_total_count ();
 
   rule_number_t *yydefact = XCALLOC (rule_number_t, nstates);
@@ -678,6 +689,13 @@ token_actions (void)
   actrow = XCALLOC (action_t, ntokens);
   conflrow = XCALLOC (unsigned int, ntokens);
 
+  /* Now that the parser was computed, we can find which rules are
+     really reduced, and which are not because of SR or RR conflicts.
+     */
+  if (!glr_parser)
+    for (r = 0; r < nrules; ++r)
+      rules[r].useful = FALSE;
+
   if (glr_parser)
     {
       conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
@@ -696,6 +714,17 @@ token_actions (void)
 
   muscle_insert_rule_number_table ("defact", yydefact,
 				   yydefact[0], 1, nstates);
+
+  if (!glr_parser)
+    for (r = 0; r < nrules ; ++r)
+      if (!rules[r].useful)
+	{
+	  LOCATION_PRINT (stderr, rules[r].location);
+	  fprintf (stderr, ": %s: %s: ",
+		   _("warning"), _("rule never reduced because of conflicts"));
+	  rule_print (&rules[r], stderr);
+	}
+
   XFREE (actrow);
   XFREE (conflrow);
   XFREE (yydefact);
