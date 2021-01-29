@@ -93,6 +93,40 @@ no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
       bitset_set (*no_reduce_set, s->errs->symbols[n]->number);
 }
 
+static void
+conclude_red (struct obstack *out, int source, int ruleno, bool enabled,
+              bool first, FILE *fout)
+{
+  /* If no lookahead tokens were valid transitions, this reduction is
+     actually hidden, so cancel everything. */
+  if (first)
+    return (void) obstack_finish0 (out);
+  else
+    {
+      char const *ed = enabled ? "e" : "d";
+
+      /* First, build the edge's head. */
+      if (! first)
+        fprintf (fout, "  %1$d -> \"%1$dR%2$d%3$s\" [label = \"",
+                 source, ruleno, ed);
+
+      /* (The lookahead tokens have been added to the beginning of the
+         obstack, in the caller function.) */
+
+      /* Then, the edge's tail. */
+      obstack_sgrow (out, "\" style = solid]\n");
+
+      /* Build the associated diamond representation or the target rule. */
+      obstack_printf (out, " \"%dR%d%s\" "
+                           "[style = filled shape = diamond fillcolor = %s "
+                           "label = \"R%d\"]\n",
+                      source, ruleno, ed,
+                      enabled ? "yellowgreen" : "firebrick1",
+                      ruleno);
+      fprintf (fout, obstack_finish0 (out));
+    }
+}
+
 static bool
 print_token (struct obstack *out, bool first, char const *tok)
 {
@@ -110,58 +144,52 @@ output_red (state const *s, reductions const *reds, FILE *fout)
   bitset no_reduce_set;
   int j;
   int source = s->number;
-  struct obstack oout;
+  struct obstack dout, eout;
 
   no_reduce_bitset_init (s, &no_reduce_set);
-  obstack_init (&oout);
+  obstack_init (&dout);
+  obstack_init (&eout);
 
   for (j = 0; j < reds->num; ++j)
     {
-      bool disabled = false;
-      bool first = true;
+      bool defaulted = false;
+      bool firstd = true, firste = true; // first{en,dis}abled
       int ruleno = reds->rules[j]->user_number;
       rule *default_reduction = NULL;
 
       if (yydefact[s->number] != 0)
         default_reduction = &rules[yydefact[s->number] - 1];
 
-      /* First, print the edges that represent each possible reduction for
-         the given state. */
-      obstack_printf (&oout, "  %1$d -> \"%1$dR%2$d\" [label=\"",
-                      source, ruleno);
+      /* Build the lookahead tokens lists, one for enabled transitions and one
+         for disabled transistions. */
       if (default_reduction && default_reduction == reds->rules[j])
-        first = print_token (&oout, true, "$default");
-      else
+        {
+          firste = print_token (&eout, true, "$default");
+          defaulted = true;
+        }
+      if (reds->lookahead_tokens)
         {
           int i;
           for (i = 0; i < ntokens; i++)
             if (bitset_test (reds->lookahead_tokens[j], i))
               {
-                first = print_token (&oout, first, symbols[i]->tag);
                 if (bitset_test (no_reduce_set, i))
-                  disabled = true;
+                  firstd = print_token (&dout, firstd, symbols[i]->tag);
+                else
+                  {
+                    if (! defaulted)
+                      firste = print_token (&eout, firste, symbols[i]->tag);
+                    bitset_set (no_reduce_set, i);
+                  }
               }
         }
-      obstack_sgrow (&oout, "\" style=solid]\n");
-
-      /* Then, print the reduction's representation. Done later since
-         we need to know whether this reduction is disabled. */
-      obstack_printf (&oout,
-                      " \"%dR%d\" "
-                      "[style=filled shape=diamond fillcolor=%s "
-                      "label=\"R%d\"]\n",
-                      source, ruleno,
-                      disabled ? "firebrick1" : "yellowgreen",
-                      ruleno);
 
-      /* If no lookahead tokens were valid transitions, this reduction is
-         actually disabled, so don't print it. */
-      if (first)
-        (void) obstack_finish0 (&oout);
-      else
-        fprintf (fout, obstack_finish0 (&oout));
+      /* Do the actual output. */
+      conclude_red (&eout, source, ruleno, true, firste, fout);
+      conclude_red (&dout, source, ruleno, false, firstd, fout);
     }
-  obstack_free (&oout, 0);
+  obstack_free (&eout, 0);
+  obstack_free (&dout, 0);
 }
 
 void
