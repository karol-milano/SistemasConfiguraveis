@@ -159,6 +159,9 @@ output_red (state const *s, reductions const *reds, FILE *fout)
   bitset no_reduce_set;
   no_reduce_bitset_init (s, &no_reduce_set);
 
+  rule *default_reduction
+    = yydefact[s->number] ? &rules[yydefact[s->number] - 1] : NULL;
+
   /* Two obstacks are needed: one for the enabled reductions, and one
      for the disabled reductions, because in the end we want two
      separate edges, even though in most cases only one will actually
@@ -171,11 +174,6 @@ output_red (state const *s, reductions const *reds, FILE *fout)
   const int source = s->number;
   for (int j = 0; j < reds->num; ++j)
     {
-      rule *default_reduction =
-        yydefact[s->number]
-        ? &rules[yydefact[s->number] - 1]
-        : NULL;
-
       bool defaulted = default_reduction && default_reduction == reds->rules[j];
 
       /* Build the lookahead tokens lists, one for enabled transitions
