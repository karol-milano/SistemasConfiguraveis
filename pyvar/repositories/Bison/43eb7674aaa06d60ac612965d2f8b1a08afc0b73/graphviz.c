@@ -144,12 +144,12 @@ output_red (state const *s, reductions const *reds, FILE *fout)
         }
       obstack_sgrow (&oout, "\" style=solid]\n");
 
-      /* Then, print the reduction's representation. This most be done later
-         because the we need the previously determined boolean to know if this
-         reduction is disabled or not. */
-      obstack_printf (&oout, " \"%dR%d\" "
-                             "[style=filled shape=diamond fillcolor=%s "
-                             "label=\"R%d\"]\n",
+      /* Then, print the reduction's representation. Done later since
+         we need to know whether this reduction is disabled. */
+      obstack_printf (&oout,
+                      " \"%dR%d\" "
+                      "[style=filled shape=diamond fillcolor=%s "
+                      "label=\"R%d\"]\n",
                       source, ruleno,
                       disabled ? "firebrick1" : "yellowgreen",
                       ruleno);
