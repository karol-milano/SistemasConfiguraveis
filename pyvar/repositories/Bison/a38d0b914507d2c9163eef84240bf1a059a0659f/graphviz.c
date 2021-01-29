@@ -135,7 +135,7 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
       /* Build the associated diamond representation of the target rule. */
       fprintf (fout, " \"%dR%d%s\" [label=\"",
                source, ruleno, ed);
-      bool final = rules[ruleno].lhs->symbol == acceptsymbol;
+      bool const final = rule_is_initial (&rules[ruleno]);
       if (final)
         fprintf (fout, "Acc");
       else
