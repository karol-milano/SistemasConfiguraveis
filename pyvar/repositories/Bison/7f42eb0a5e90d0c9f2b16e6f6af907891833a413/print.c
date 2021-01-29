@@ -406,7 +406,6 @@ print_grammar (FILE *out)
 {
   symbol_number i;
   char buffer[90];
-  int column = 0;
 
   grammar_rules_print (out);
 
@@ -416,11 +415,11 @@ print_grammar (FILE *out)
     if (token_translations[i] != undeftoken->content->number)
       {
         const char *tag = symbols[token_translations[i]]->tag;
+        int column = strlen (tag);
         rule_number r;
         item_number *rhsp;
 
         buffer[0] = 0;
-        column = strlen (tag);
         fputs (tag, out);
         END_TEST (65);
         sprintf (buffer, " (%d)", i);
@@ -441,9 +440,10 @@ print_grammar (FILE *out)
   fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
   for (i = ntokens; i < nsyms; i++)
     {
+      const char *tag = symbols[i]->tag;
+      int column = strlen (tag);
       int left_count = 0, right_count = 0;
       rule_number r;
-      const char *tag = symbols[i]->tag;
 
       for (r = 0; r < nrules; r++)
         {
@@ -460,7 +460,6 @@ print_grammar (FILE *out)
 
       buffer[0] = 0;
       fputs (tag, out);
-      column = strlen (tag);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
 
@@ -504,8 +503,6 @@ print_grammar (FILE *out)
 void
 print_results (void)
 {
-  state_number i;
-
   /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
      that conflicts with Posix.  */
   FILE *out = xfopen (spec_verbose_file, "w");
@@ -524,8 +521,11 @@ print_results (void)
     new_closure (nritems);
   /* Storage for print_reductions.  */
   no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
-  for (i = 0; i < nstates; i++)
-    print_state (out, states[i]);
+  {
+    state_number i;
+    for (i = 0; i < nstates; i++)
+      print_state (out, states[i]);
+  }
   bitset_free (no_reduce_set);
   if (report_flag & report_itemsets)
     free_closure ();
