@@ -103,7 +103,7 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
   /* If no lookahead tokens were valid transitions, this reduction is
      actually hidden, so cancel everything. */
   if (first)
-    return (void) obstack_finish0 (out);
+    (void) obstack_finish0 (out);
   else
     {
       char const *ed = enabled ? "" : "d";
