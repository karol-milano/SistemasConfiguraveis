@@ -87,12 +87,14 @@ escape (char const *name)
 static void
 no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
 {
-  int n;
   *no_reduce_set = bitset_create (ntokens, BITSET_FIXED);
   bitset_zero (*no_reduce_set);
-  FOR_EACH_SHIFT (s->transitions, n)
-    bitset_set (*no_reduce_set, TRANSITION_SYMBOL (s->transitions, n));
-  for (n = 0; n < s->errs->num; ++n)
+  {
+    int n;
+    FOR_EACH_SHIFT (s->transitions, n)
+      bitset_set (*no_reduce_set, TRANSITION_SYMBOL (s->transitions, n));
+  }
+  for (int n = 0; n < s->errs->num; ++n)
     if (s->errs->symbols[n])
       bitset_set (*no_reduce_set, s->errs->symbols[n]->content->number);
 }
@@ -145,11 +147,9 @@ conclude_red (struct obstack *out, int source, rule_number ruleno,
 static bool
 print_token (struct obstack *out, bool first, char const *tok)
 {
-  char const *q = escape (tok);
-
   if (! first)
     obstack_sgrow (out, ", ");
-  obstack_sgrow (out, q);
+  obstack_sgrow (out, escape (tok));
   return false;
 }
 
@@ -157,8 +157,7 @@ void
 output_red (state const *s, reductions const *reds, FILE *fout)
 {
   bitset no_reduce_set;
-  int j;
-  int source = s->number;
+  no_reduce_bitset_init (s, &no_reduce_set);
 
   /* Two obstacks are needed: one for the enabled reductions, and one
      for the disabled reductions, because in the end we want two
@@ -166,42 +165,38 @@ output_red (state const *s, reductions const *reds, FILE *fout)
      be printed. */
   struct obstack dout;
   struct obstack eout;
-
-  no_reduce_bitset_init (s, &no_reduce_set);
   obstack_init (&dout);
   obstack_init (&eout);
 
-  for (j = 0; j < reds->num; ++j)
+  const int source = s->number;
+  for (int j = 0; j < reds->num; ++j)
     {
-      bool defaulted = false;
-      bool firstd = true;
-      bool firste = true;
-      rule_number ruleno = reds->rules[j]->number;
-      rule *default_reduction = NULL;
+      rule *default_reduction =
+        yydefact[s->number]
+        ? &rules[yydefact[s->number] - 1]
+        : NULL;
 
-      if (yydefact[s->number] != 0)
-        default_reduction = &rules[yydefact[s->number] - 1];
+      bool defaulted = default_reduction && default_reduction == reds->rules[j];
 
       /* Build the lookahead tokens lists, one for enabled transitions and one
          for disabled transistions. */
-      if (default_reduction && default_reduction == reds->rules[j])
-        defaulted = true;
+      bool firstd = true;
+      bool firste = true;
+      rule_number ruleno = reds->rules[j]->number;
+
       if (reds->lookahead_tokens)
-        {
-          int i;
-          for (i = 0; i < ntokens; i++)
-            if (bitset_test (reds->lookahead_tokens[j], i))
-              {
-                if (bitset_test (no_reduce_set, i))
-                  firstd = print_token (&dout, firstd, symbols[i]->tag);
-                else
-                  {
-                    if (! defaulted)
-                      firste = print_token (&eout, firste, symbols[i]->tag);
-                    bitset_set (no_reduce_set, i);
-                  }
-              }
-        }
+        for (int i = 0; i < ntokens; i++)
+          if (bitset_test (reds->lookahead_tokens[j], i))
+            {
+              if (bitset_test (no_reduce_set, i))
+                firstd = print_token (&dout, firstd, symbols[i]->tag);
+              else
+                {
+                  if (! defaulted)
+                    firste = print_token (&eout, firste, symbols[i]->tag);
+                  bitset_set (no_reduce_set, i);
+                }
+            }
 
       /* Do the actual output. */
       conclude_red (&dout, source, ruleno, false, firstd, fout);
