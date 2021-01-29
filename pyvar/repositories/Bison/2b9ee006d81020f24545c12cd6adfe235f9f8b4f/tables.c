@@ -236,22 +236,16 @@ conflict_row (state *s)
 static rule *
 action_row (state *s)
 {
-  rule *default_reduction = NULL;
-  reductions *reds = s->reductions;
-  transitions *trans = s->transitions;
-  errs *errp = s->errs;
-  /* Set to nonzero to inhibit having any default reduction.  */
-  bool nodefault = false;
-  bool conflicted = false;
-
   for (state_number i = 0; i < ntokens; i++)
     actrow[i] = conflrow[i] = 0;
 
+  reductions *reds = s->reductions;
+  bool conflicted = false;
   if (reds->lookahead_tokens)
     /* loop over all the rules available here which require
        lookahead (in reverse order to give precedence to the first
        rule) */
-    for (int i = reds->num - 1; i >= 0; --i)
+    for (int i = reds->num - 1; 0 <= i; --i)
       /* and find each token which the rule finds acceptable
          to come next */
       {
@@ -273,6 +267,9 @@ action_row (state *s)
   /* Now see which tokens are allowed for shifts in this state.  For
      them, record the shift as the thing to do.  So shift is preferred
      to reduce.  */
+  transitions *trans = s->transitions;
+  /* Set to nonzero to inhibit having any default reduction.  */
+  bool nodefault = false;
   {
     int i;
     FOR_EACH_SHIFT (trans, i)
@@ -297,6 +294,7 @@ action_row (state *s)
   /* See which tokens are an explicit error in this state (due to
      %nonassoc).  For them, record ACTION_NUMBER_MINIMUM as the
      action.  */
+  errs *errp = s->errs;
   for (int i = 0; i < errp->num; i++)
     {
       symbol *sym = errp->symbols[i];
@@ -316,7 +314,7 @@ action_row (state *s)
 
   /* Now find the most common reduction and make it the default action
      for this state.  */
-
+  rule *default_reduction = NULL;
   if (reds->num >= 1 && !nodefault)
     {
       if (s->consistent)
@@ -345,14 +343,12 @@ action_row (state *s)
              actions that match the default are replaced with zero,
              which means "use the default". */
 
-          if (max > 0)
-            {
-              for (symbol_number j = 0; j < ntokens; j++)
-                if (actrow[j]
-                    == rule_number_as_item_number (default_reduction->number)
-                    && ! (nondeterministic_parser && conflrow[j]))
-                  actrow[j] = 0;
-            }
+          if (0 < max)
+            for (symbol_number j = 0; j < ntokens; j++)
+              if (actrow[j]
+                  == rule_number_as_item_number (default_reduction->number)
+                  && ! (nondeterministic_parser && conflrow[j]))
+                actrow[j] = 0;
         }
     }
 
@@ -606,7 +602,6 @@ matching_state (vector_number vector)
     {
       size_t t = tally[i];
       int w = width[i];
-      int prev;
 
       /* If VECTOR has GLR conflicts, return -1 */
       if (conflict_tos[i] != NULL)
@@ -614,7 +609,7 @@ matching_state (vector_number vector)
           if (conflict_tos[i][j] != 0)
             return -1;
 
-      for (prev = vector - 1; 0 <= prev; prev--)
+      for (int prev = vector - 1; 0 <= prev; prev--)
         {
           vector_number j = order[prev];
           /* Given how ORDER was computed, if the WIDTH or TALLY is
