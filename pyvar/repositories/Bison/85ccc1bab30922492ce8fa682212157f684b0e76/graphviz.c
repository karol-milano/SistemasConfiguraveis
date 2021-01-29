@@ -101,6 +101,7 @@ no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
       bitset_set (*no_reduce_set, s->errs->symbols[n]->content->number);
 }
 
+/* Show the reductions from state SOURCE on rule RULENO. */
 static void
 conclude_red (struct obstack *out, int source, rule_number ruleno,
               bool enabled, bool first, FILE *fout)
@@ -112,8 +113,6 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
   else
     {
       char const *ed = enabled ? "" : "d";
-      char const *color = enabled ? ruleno ? "3" : "1" : "5";
-
       /* First, build the edge's head. The name of reduction nodes is "nRm",
          with n the source state and m the rule number. This is because we
          don't want all the reductions bearing a same rule number to point to
@@ -136,11 +135,16 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
       /* Build the associated diamond representation of the target rule. */
       fprintf (fout, " \"%dR%d%s\" [label=\"",
                source, ruleno, ed);
-      if (ruleno)
-        fprintf (fout, "R%d", ruleno);
-      else
+      bool final = rules[ruleno].lhs->symbol == acceptsymbol;
+      if (final)
         fprintf (fout, "Acc");
+      else
+        fprintf (fout, "R%d", ruleno);
 
+      char const *color
+        = !enabled ? "5"
+        : final    ? "1"
+        :            "3";
       fprintf (fout, "\", fillcolor=%s, shape=diamond, style=filled]\n",
                color);
     }
