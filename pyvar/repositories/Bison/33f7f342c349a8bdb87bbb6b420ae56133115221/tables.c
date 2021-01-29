@@ -424,10 +424,6 @@ save_row (state_number s)
 static void
 token_actions (void)
 {
-  state_number i;
-  symbol_number j;
-  rule_number r;
-
   int nconflict = nondeterministic_parser ? conflicts_total_count () : 0;
 
   yydefact = xnmalloc (nstates, sizeof *yydefact);
@@ -441,28 +437,34 @@ token_actions (void)
 
   /* Find the rules which are reduced.  */
   if (!nondeterministic_parser)
-    for (r = 0; r < nrules; ++r)
-      rules[r].useful = false;
-
-  for (i = 0; i < nstates; ++i)
     {
-      rule *default_reduction = action_row (states[i]);
-      yydefact[i] = default_reduction ? default_reduction->number + 1 : 0;
-      save_row (i);
-
-      /* Now that the parser was computed, we can find which rules are
-         really reduced, and which are not because of SR or RR
-         conflicts.  */
-      if (!nondeterministic_parser)
-        {
-          for (j = 0; j < ntokens; ++j)
-            if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
-              rules[item_number_as_rule_number (actrow[j])].useful = true;
-          if (yydefact[i])
-            rules[yydefact[i] - 1].useful = true;
-        }
+      rule_number r;
+      for (r = 0; r < nrules; ++r)
+        rules[r].useful = false;
     }
 
+  {
+    state_number i;
+    for (i = 0; i < nstates; ++i)
+      {
+        rule *default_reduction = action_row (states[i]);
+        yydefact[i] = default_reduction ? default_reduction->number + 1 : 0;
+        save_row (i);
+
+        /* Now that the parser was computed, we can find which rules are
+           really reduced, and which are not because of SR or RR
+           conflicts.  */
+        if (!nondeterministic_parser)
+          {
+            symbol_number j;
+            for (j = 0; j < ntokens; ++j)
+              if (actrow[j] < 0 && actrow[j] != ACTION_NUMBER_MINIMUM)
+                rules[item_number_as_rule_number (actrow[j])].useful = true;
+            if (yydefact[i])
+              rules[yydefact[i] - 1].useful = true;
+          }
+      }
+  }
   free (actrow);
   free (conflrow);
 }
