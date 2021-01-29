@@ -25,7 +25,9 @@
 #include <quotearg.h>
 
 #include "files.h"
+#include "gram.h"
 #include "graphviz.h"
+#include "tables.h"
 
 /* Return an unambiguous printable representation for NAME, suitable
    for C strings.  Use slot 2 since the user may use slots 0 and 1.  */
@@ -78,6 +80,86 @@ escape (char const *name)
   return q + 1;
 }
 
+static void
+no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
+{
+  int n;
+  *no_reduce_set = bitset_create (ntokens, BITSET_FIXED);
+  bitset_zero (*no_reduce_set);
+  FOR_EACH_SHIFT (s->transitions, n)
+    bitset_set (*no_reduce_set, TRANSITION_SYMBOL (s->transitions, n));
+  for (n = 0; n < s->errs->num; ++n)
+    if (s->errs->symbols[n])
+      bitset_set (*no_reduce_set, s->errs->symbols[n]->number);
+}
+
+static bool
+print_token (struct obstack *out, bool first, char const *tok)
+{
+  char const *q = escape (tok);
+
+  if (! first)
+    obstack_sgrow (out, ",");
+  obstack_sgrow (out, q);
+  return false;
+}
+
+void
+output_red (state const *s, reductions const *reds, FILE *fout)
+{
+  int source = s->number;
+  int i, j;
+  bitset no_reduce_set;
+  no_reduce_bitset_init (s, &no_reduce_set);
+
+  struct obstack oout;
+  obstack_init (&oout);
+
+  for (j = 0; j < reds->num; ++j)
+    {
+      bool first = true;
+      bool disabled = false;
+      int ruleno = reds->rules[j]->user_number;
+      rule *default_reduction = NULL;
+      if (yydefact[s->number] != 0)
+        default_reduction = &rules[yydefact[s->number] - 1];
+
+      /* First, print the edges that represent each possible reduction for
+         the given state. */
+      obstack_printf (&oout, "  %1$d -> \"%1$dR%2$d\" [label=\"",
+                      source, ruleno);
+      if (default_reduction && default_reduction == reds->rules[j])
+        first = print_token (&oout, true, "$default");
+      else
+        for (i = 0; i < ntokens; i++)
+            if (bitset_test (reds->lookahead_tokens[j], i))
+              {
+                first = print_token (&oout, first, symbols[i]->tag);
+                if (bitset_test (no_reduce_set, i))
+                  disabled = true;
+              }
+      obstack_sgrow (&oout, "\" style=solid]\n");
+
+      /* Then, print the reduction's representation. This most be done later
+         because the we need the previously determined boolean to know if this
+         reduction is disabled or not. */
+      obstack_printf (&oout, " \"%dR%d\" "
+                             "[style=filled shape=diamond fillcolor=%s "
+                             "label=\"R%d\"]\n",
+                      source, ruleno,
+                      disabled ? "firebrick1" : "yellowgreen",
+                      ruleno);
+
+      /* If no lookahead tokens were valid transitions, this reduction is
+         actually disabled, so don't print it. */
+      if (first)
+        (void) obstack_finish0 (&oout);
+      else
+        fprintf (fout, obstack_finish0 (&oout));
+    }
+  obstack_free (&oout, 0);
+}
+
 void
 finish_graph (FILE *fout)
 {
