@@ -369,13 +369,16 @@ set_conflicts (state *s, symbol **errors)
     s->solved_conflicts_xml = obstack_finish0 (&solved_conflicts_xml_obstack);
 
   /* Loop over all rules which require lookahead in this state.  Check
-     for conflicts not resolved above.  */
-  for (int i = 0; i < reds->num; ++i)
-    {
-      if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
-        conflicts[s->number] = 1;
-      bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
-    }
+     for conflicts not resolved above.
+
+     reds->lookahead_tokens can be NULL if the LR type is LR(0).  */
+  if (reds->lookahead_tokens)
+    for (int i = 0; i < reds->num; ++i)
+      {
+        if (!bitset_disjoint_p (reds->lookahead_tokens[i], lookahead_set))
+          conflicts[s->number] = 1;
+        bitset_or (lookahead_set, lookahead_set, reds->lookahead_tokens[i]);
+      }
 }
 
 
