@@ -113,8 +113,8 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
          with n the source state and m the rule number. This is because we
          don't want all the reductions bearing a same rule number to point to
          the same state, since that is not the desired format. */
-      fprintf (fout, "  %1$d -> \"%1$dR%2$d%3$s\" [",
-               source, ruleno, ed);
+      fprintf (fout, "  %d -> \"%dR%d%s\" [",
+               source, source, ruleno, ed);
 
       /* (The lookahead tokens have been added to the beginning of the
          obstack, in the caller function.) */
