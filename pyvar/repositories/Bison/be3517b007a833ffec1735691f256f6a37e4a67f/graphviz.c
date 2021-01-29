@@ -106,7 +106,7 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
     return (void) obstack_finish0 (out);
   else
     {
-      char const *ed = enabled ? "e" : "d";
+      char const *ed = enabled ? "" : "d";
       char const *color = enabled ? ruleno ? "3" : "1" : "5";
 
       /* First, build the edge's head. The name of reduction nodes is "nRm",
@@ -116,24 +116,28 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
       fprintf (fout, "  %1$d -> \"%1$dR%2$d%3$s\" [",
                source, ruleno, ed);
 
+      /* (The lookahead tokens have been added to the beginning of the
+         obstack, in the caller function.) */
       if (! obstack_empty_p (out))
-        /* (The lookahead tokens have been added to the beginning of the
-           obstack, in the caller function.) */
-        fprintf (fout, "label = \"[%s]\" ", obstack_finish0 (out));
+        {
+          char *label = obstack_finish0 (out);
+          fprintf (fout, "label=\"[%s]\", ", label);
+          obstack_free (out, label);
+        }
 
       /* Then, the edge's tail. */
-      fprintf (fout, "style = solid]\n");
+      fprintf (fout, "style=solid]\n");
 
       /* Build the associated diamond representation of the target rule. */
-      fprintf (fout, " \"%dR%d%s\" [style = filled, "
-                    "shape = diamond, fillcolor = %s, ",
-               source, ruleno, ed, color);
-
-     if (ruleno)
-        fprintf (fout, "label = \"R%d\"]\n", ruleno);
+      fprintf (fout, " \"%dR%d%s\" [label=\"",
+               source, ruleno, ed);
+      if (ruleno)
+        fprintf (fout, "R%d", ruleno);
       else
-        fprintf (fout, "label = \"Acc\"]\n");
+        fprintf (fout, "Acc");
 
+      fprintf (fout, "\", fillcolor=%s, shape=diamond, style=filled]\n",
+               color);
     }
 }
 
@@ -171,7 +175,7 @@ output_red (state const *s, reductions const *reds, FILE *fout)
       bool defaulted = false;
       bool firstd = true;
       bool firste = true;
-      rule_number ruleno = reds->rules[j]->user_number;
+      rule_number ruleno = reds->rules[j]->number;
       rule *default_reduction = NULL;
 
       if (yydefact[s->number] != 0)
@@ -199,11 +203,11 @@ output_red (state const *s, reductions const *reds, FILE *fout)
         }
 
       /* Do the actual output. */
-      conclude_red (&eout, source, ruleno, true, firste && !defaulted, fout);
       conclude_red (&dout, source, ruleno, false, firstd, fout);
+      conclude_red (&eout, source, ruleno, true, firste && !defaulted, fout);
     }
-  obstack_free (&eout, 0);
   obstack_free (&dout, 0);
+  obstack_free (&eout, 0);
   bitset_free (no_reduce_set);
 }
 
