@@ -208,13 +208,13 @@ print_reductions (FILE *out, state_t *state)
 
       bitset_and (lookaheadset, state->lookaheads[0], shiftset);
 
-      for (i = 0; i < ntokens; i++)
-	if (bitset_test (lookaheadset, i))
-	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
-		   symbol_tag_get (symbols[i]),
-		   default_rule->number - 1,
-		   symbol_tag_get_n (default_rule->lhs, 1));
-
+      BITSET_EXECUTE (lookaheadset, 0, i,
+      {
+	fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
+		 symbol_tag_get (symbols[i]),
+		 default_rule->number - 1,
+		 symbol_tag_get_n (default_rule->lhs, 1));
+      });
       fprintf (out, _("    $default\treduce using rule %d (%s)\n\n"),
 	       default_rule->number - 1,
 	       symbol_tag_get (default_rule->lhs));
@@ -229,13 +229,9 @@ print_reductions (FILE *out, state_t *state)
 	for (i = 0; i < state->nlookaheads; ++i)
 	  {
 	    int count = 0;
-	    int j;
 
 	    bitset_andn (lookaheadset, state->lookaheads[i], shiftset);
-
-	    for (j = 0; j < ntokens; j++)
-	      if (bitset_test (lookaheadset, j))
-		count++;
+	    count = bitset_count (lookaheadset);
 
 	    if (count > cmax)
 	      {
