@@ -107,20 +107,21 @@ print_token (struct obstack *out, bool first, char const *tok)
 void
 output_red (state const *s, reductions const *reds, FILE *fout)
 {
-  int source = s->number;
-  int i, j;
   bitset no_reduce_set;
-  no_reduce_bitset_init (s, &no_reduce_set);
-
+  int j;
+  int source = s->number;
   struct obstack oout;
+
+  no_reduce_bitset_init (s, &no_reduce_set);
   obstack_init (&oout);
 
   for (j = 0; j < reds->num; ++j)
     {
-      bool first = true;
       bool disabled = false;
+      bool first = true;
       int ruleno = reds->rules[j]->user_number;
       rule *default_reduction = NULL;
+
       if (yydefact[s->number] != 0)
         default_reduction = &rules[yydefact[s->number] - 1];
 
@@ -131,13 +132,16 @@ output_red (state const *s, reductions const *reds, FILE *fout)
       if (default_reduction && default_reduction == reds->rules[j])
         first = print_token (&oout, true, "$default");
       else
-        for (i = 0; i < ntokens; i++)
+        {
+          int i;
+          for (i = 0; i < ntokens; i++)
             if (bitset_test (reds->lookahead_tokens[j], i))
               {
                 first = print_token (&oout, first, symbols[i]->tag);
                 if (bitset_test (no_reduce_set, i))
                   disabled = true;
               }
+        }
       obstack_sgrow (&oout, "\" style=solid]\n");
 
       /* Then, print the reduction's representation. This most be done later
