@@ -53,7 +53,10 @@ start_graph (FILE *fout)
            "digraph %s\n"
            "{\n",
            quote (grammar_file));
-  fprintf (fout, "node [shape=box]\n");
+  fprintf (fout,
+           "  node [fontname = courier, shape = box, colorscheme = paired6]\n"
+           "  edge [fontname = courier]\n"
+           "\n");
 }
 
 void
@@ -94,8 +97,8 @@ no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
 }
 
 static void
-conclude_red (struct obstack *out, int source, int ruleno, bool enabled,
-              bool first, FILE *fout)
+conclude_red (struct obstack *out, int source, rule_number ruleno,
+              bool enabled, bool first, FILE *fout)
 {
   /* If no lookahead tokens were valid transitions, this reduction is
      actually hidden, so cancel everything. */
@@ -104,26 +107,33 @@ conclude_red (struct obstack *out, int source, int ruleno, bool enabled,
   else
     {
       char const *ed = enabled ? "e" : "d";
+      char const *color = enabled ? ruleno ? "3" : "1" : "5";
 
-      /* First, build the edge's head. */
-      if (! first)
-        fprintf (fout, "  %1$d -> \"%1$dR%2$d%3$s\" [label = \"",
-                 source, ruleno, ed);
+      /* First, build the edge's head. The name of reduction nodes is "nRm",
+         with n the source state and m the rule number. This is because we
+         don't want all the reductions bearing a same rule number to point to
+         the same state, since that is not the desired format. */
+      fprintf (fout, "  %1$d -> \"%1$dR%2$d%3$s\" [",
+               source, ruleno, ed);
 
-      /* (The lookahead tokens have been added to the beginning of the
-         obstack, in the caller function.) */
+      if (! obstack_empty_p (out))
+        /* (The lookahead tokens have been added to the beginning of the
+           obstack, in the caller function.) */
+        fprintf (fout, "label = \"[%s]\" ", obstack_finish0 (out));
 
       /* Then, the edge's tail. */
-      obstack_sgrow (out, "\" style = solid]\n");
-
-      /* Build the associated diamond representation or the target rule. */
-      obstack_printf (out, " \"%dR%d%s\" "
-                           "[style = filled shape = diamond fillcolor = %s "
-                           "label = \"R%d\"]\n",
-                      source, ruleno, ed,
-                      enabled ? "yellowgreen" : "firebrick1",
-                      ruleno);
-      fprintf (fout, obstack_finish0 (out));
+      fprintf (fout, "style = solid]\n");
+
+      /* Build the associated diamond representation of the target rule. */
+      fprintf (fout, " \"%dR%d%s\" [style = filled, "
+                    "shape = diamond, fillcolor = %s, ",
+               source, ruleno, ed, color);
+
+     if (ruleno)
+        fprintf (fout, "label = \"R%d\"]\n", ruleno);
+      else
+        fprintf (fout, "label = \"Acc\"]\n");
+
     }
 }
 
@@ -133,7 +143,7 @@ print_token (struct obstack *out, bool first, char const *tok)
   char const *q = escape (tok);
 
   if (! first)
-    obstack_sgrow (out, ",");
+    obstack_sgrow (out, ", ");
   obstack_sgrow (out, q);
   return false;
 }
@@ -144,7 +154,13 @@ output_red (state const *s, reductions const *reds, FILE *fout)
   bitset no_reduce_set;
   int j;
   int source = s->number;
-  struct obstack dout, eout;
+
+  /* Two obstacks are needed: one for the enabled reductions, and one
+     for the disabled reductions, because in the end we want two
+     separate edges, even though in most cases only one will actually
+     be printed. */
+  struct obstack dout;
+  struct obstack eout;
 
   no_reduce_bitset_init (s, &no_reduce_set);
   obstack_init (&dout);
@@ -153,8 +169,9 @@ output_red (state const *s, reductions const *reds, FILE *fout)
   for (j = 0; j < reds->num; ++j)
     {
       bool defaulted = false;
-      bool firstd = true, firste = true; // first{en,dis}abled
-      int ruleno = reds->rules[j]->user_number;
+      bool firstd = true;
+      bool firste = true;
+      rule_number ruleno = reds->rules[j]->user_number;
       rule *default_reduction = NULL;
 
       if (yydefact[s->number] != 0)
@@ -163,10 +180,7 @@ output_red (state const *s, reductions const *reds, FILE *fout)
       /* Build the lookahead tokens lists, one for enabled transitions and one
          for disabled transistions. */
       if (default_reduction && default_reduction == reds->rules[j])
-        {
-          firste = print_token (&eout, true, "$default");
-          defaulted = true;
-        }
+        defaulted = true;
       if (reds->lookahead_tokens)
         {
           int i;
@@ -185,7 +199,7 @@ output_red (state const *s, reductions const *reds, FILE *fout)
         }
 
       /* Do the actual output. */
-      conclude_red (&eout, source, ruleno, true, firste, fout);
+      conclude_red (&eout, source, ruleno, true, firste && !defaulted, fout);
       conclude_red (&dout, source, ruleno, false, firstd, fout);
     }
   obstack_free (&eout, 0);
