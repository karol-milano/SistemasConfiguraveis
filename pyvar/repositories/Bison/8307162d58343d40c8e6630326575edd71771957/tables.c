@@ -418,7 +418,7 @@ token_actions (void)
   /* Find the rules which are reduced.  */
   if (!glr_parser)
     for (r = 0; r < nrules; ++r)
-      rules[r].useful = FALSE;
+      rules[r].useful = false;
 
   for (i = 0; i < nstates; ++i)
     {
@@ -433,9 +433,9 @@ token_actions (void)
 	{
 	  for (j = 0; j < ntokens; ++j)
 	    if (actrow[j] < 0 && actrow[j] != ACTION_MIN)
-	      rules[item_number_as_rule_number (actrow[j])].useful = TRUE;
+	      rules[item_number_as_rule_number (actrow[j])].useful = true;
 	  if (yydefact[i])
-	    rules[yydefact[i] - 1].useful = TRUE;
+	    rules[yydefact[i] - 1].useful = true;
 	}
     }
 
