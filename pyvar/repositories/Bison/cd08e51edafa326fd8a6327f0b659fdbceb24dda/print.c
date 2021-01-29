@@ -244,25 +244,25 @@ state_default_rule (state_t *state)
 	bitset_set (shiftset, errp->symbols[i]->number);
   }
 
-  for (i = 0; i < state->nlookaheads; ++i)
+  for (i = 0; i < redp->num; ++i)
     {
       int count = 0;
 
       /* How many non-masked lookaheads are there for this reduction?
 	 */
-      bitset_andn (lookaheadset, state->lookaheads[i], shiftset);
+      bitset_andn (lookaheadset, redp->lookaheads[i], shiftset);
       count = bitset_count (lookaheadset);
 
       if (count > cmax)
 	{
 	  cmax = count;
-	  default_rule = state->lookaheads_rule[i];
+	  default_rule = redp->rules[i];
 	}
 
       /* 3. And finally, each reduction is possibly masked by previous
 	 reductions (in R/R conflicts, we keep the first reductions).
 	 */
-      bitset_or (shiftset, shiftset, state->lookaheads[i]);
+      bitset_or (shiftset, shiftset, redp->lookaheads[i]);
     }
 
   return default_rule;
@@ -322,25 +322,27 @@ print_reductions (FILE *out, state_t *state)
   /* Compute the width of the lookaheads column.  */
   if (default_rule)
     width = strlen (_("$default"));
-  for (i = 0; i < ntokens; i++)
-    {
-      int count = bitset_test (shiftset, i);
 
-      for (j = 0; j < state->nlookaheads; ++j)
-	if (bitset_test (state->lookaheads[j], i))
-	  {
-	    if (count == 0)
-	      {
-		if (state->lookaheads_rule[j] != default_rule)
+  if (redp->lookaheads)
+    for (i = 0; i < ntokens; i++)
+      {
+	int count = bitset_test (shiftset, i);
+
+	for (j = 0; j < redp->num; ++j)
+	  if (bitset_test (redp->lookaheads[j], i))
+	    {
+	      if (count == 0)
+		{
+		  if (redp->rules[j] != default_rule)
+		    max_length (&width, symbols[i]->tag);
+		  count++;
+		}
+	      else
+		{
 		  max_length (&width, symbols[i]->tag);
-		count++;
-	      }
-	    else
-	      {
-		max_length (&width, symbols[i]->tag);
-	      }
-	  }
-    }
+		}
+	    }
+      }
 
   /* Nothing to report. */
   if (!width)
@@ -350,37 +352,38 @@ print_reductions (FILE *out, state_t *state)
   width += 2;
 
   /* Report lookaheads (or $default) and reductions.  */
-  for (i = 0; i < ntokens; i++)
-    {
-      int defaulted = 0;
-      int count = bitset_test (shiftset, i);
+  if (redp->lookaheads)
+    for (i = 0; i < ntokens; i++)
+      {
+	int defaulted = 0;
+	int count = bitset_test (shiftset, i);
 
-      for (j = 0; j < state->nlookaheads; ++j)
-	if (bitset_test (state->lookaheads[j], i))
-	  {
-	    if (count == 0)
-	      {
-		if (state->lookaheads_rule[j] != default_rule)
-		  print_reduction (out, width,
-				   symbols[i]->tag,
-				   state->lookaheads_rule[j], TRUE);
-		else
-		  defaulted = 1;
-		count++;
-	      }
-	    else
-	      {
-		if (defaulted)
+	for (j = 0; j < redp->num; ++j)
+	  if (bitset_test (redp->lookaheads[j], i))
+	    {
+	      if (count == 0)
+		{
+		  if (redp->rules[j] != default_rule)
+		    print_reduction (out, width,
+				     symbols[i]->tag,
+				     redp->rules[j], TRUE);
+		  else
+		    defaulted = 1;
+		  count++;
+		}
+	      else
+		{
+		  if (defaulted)
+		    print_reduction (out, width,
+				     symbols[i]->tag,
+				     default_rule, TRUE);
+		  defaulted = 0;
 		  print_reduction (out, width,
 				   symbols[i]->tag,
-				   default_rule, TRUE);
-		defaulted = 0;
-		print_reduction (out, width,
-				 symbols[i]->tag,
-				 state->lookaheads_rule[j], FALSE);
-	      }
-	  }
-    }
+				   redp->rules[j], FALSE);
+		}
+	    }
+      }
 
   if (default_rule)
     print_reduction (out, width,
