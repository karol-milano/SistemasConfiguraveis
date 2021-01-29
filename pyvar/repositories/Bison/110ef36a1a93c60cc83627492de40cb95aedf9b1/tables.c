@@ -240,7 +240,7 @@ static rule *
 action_row (state *s)
 {
   int i;
-  rule *default_rule = NULL;
+  rule *default_reduction = NULL;
   reductions *reds = s->reductions;
   transitions *trans = s->transitions;
   errs *errp = s->errs;
@@ -304,14 +304,15 @@ action_row (state *s)
       actrow[sym->number] = ACTION_NUMBER_MINIMUM;
     }
 
-  /* Turn off default rules where requested by the user.  See
+  /* Turn off default reductions where requested by the user.  See
      state_lookahead_tokens_count in lalr.c to understand when states are
      labeled as consistent.  */
   {
-    char *default_rules = muscle_percent_define_get ("lr.default_rules");
-    if (0 != strcmp (default_rules, "all") && !s->consistent)
+    char *default_reductions =
+      muscle_percent_define_get ("lr.default_reductions");
+    if (0 != strcmp (default_reductions, "all") && !s->consistent)
       nodefault = true;
-    free (default_rules);
+    free (default_reductions);
   }
 
   /* Now find the most common reduction and make it the default action
@@ -320,7 +321,7 @@ action_row (state *s)
   if (reds->num >= 1 && !nodefault)
     {
       if (s->consistent)
-	default_rule = reds->rules[0];
+	default_reduction = reds->rules[0];
       else
 	{
 	  int max = 0;
@@ -337,7 +338,7 @@ action_row (state *s)
 	      if (count > max)
 		{
 		  max = count;
-		  default_rule = r;
+		  default_reduction = r;
 		}
 	    }
 
@@ -351,17 +352,18 @@ action_row (state *s)
 	    {
 	      int j;
 	      for (j = 0; j < ntokens; j++)
-		if (actrow[j] == rule_number_as_item_number (default_rule->number)
+		if (actrow[j]
+                    == rule_number_as_item_number (default_reduction->number)
 		    && ! (nondeterministic_parser && conflrow[j]))
 		  actrow[j] = 0;
 	    }
 	}
     }
 
-  /* If have no default rule, the default is an error.
+  /* If have no default reduction, the default is an error.
      So replace any action which says "error" with "use default".  */
 
-  if (!default_rule)
+  if (!default_reduction)
     for (i = 0; i < ntokens; i++)
       if (actrow[i] == ACTION_NUMBER_MINIMUM)
 	actrow[i] = 0;
@@ -369,7 +371,7 @@ action_row (state *s)
   if (conflicted)
     conflict_row (s);
 
-  return default_rule;
+  return default_reduction;
 }
 
 
@@ -450,8 +452,8 @@ token_actions (void)
 
   for (i = 0; i < nstates; ++i)
     {
-      rule *default_rule = action_row (states[i]);
-      yydefact[i] = default_rule ? default_rule->number + 1 : 0;
+      rule *default_reduction = action_row (states[i]);
+      yydefact[i] = default_reduction ? default_reduction->number + 1 : 0;
       save_row (i);
 
       /* Now that the parser was computed, we can find which rules are
