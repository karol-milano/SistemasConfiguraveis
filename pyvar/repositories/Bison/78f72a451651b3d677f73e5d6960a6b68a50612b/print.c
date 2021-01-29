@@ -90,9 +90,9 @@ print_core (FILE *out, const state *s)
       previous_rule = r;
 
       /* Display the lookahead tokens?  */
-      if (report_flag & report_lookahead_tokens
+      if (report_flag & report_lookaheads
           && item_number_is_rule_number (*sp1))
-        state_rule_lookahead_tokens_print (s, r, out);
+        state_rule_lookaheads_print (s, r, out);
       fputc ('\n', out);
     }
 }
@@ -181,18 +181,18 @@ print_errs (FILE *out, const state *s)
 
 
 /*-------------------------------------------------------------------------.
-| Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be 'default').  |
+| Report a reduction of RULE on LOOKAHEAD (which can be 'default').  |
 | If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
 | R/R conflicts).                                                          |
 `-------------------------------------------------------------------------*/
 
 static void
 print_reduction (FILE *out, size_t width,
-                 const char *lookahead_token,
+                 const char *lookahead,
                  rule *r, bool enabled)
 {
-  fprintf (out, "    %s", lookahead_token);
-  for (int j = width - mbswidth (lookahead_token, 0); j > 0; --j)
+  fprintf (out, "    %s", lookahead);
+  for (int j = width - mbswidth (lookahead, 0); j > 0; --j)
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
@@ -239,13 +239,13 @@ print_reductions (FILE *out, const state *s)
   if (default_reduction)
     width = mbswidth (_("$default"), 0);
 
-  if (reds->lookahead_tokens)
+  if (reds->lookaheads)
     for (int i = 0; i < ntokens; i++)
       {
         bool count = bitset_test (no_reduce_set, i);
 
         for (int j = 0; j < reds->num; ++j)
-          if (bitset_test (reds->lookahead_tokens[j], i))
+          if (bitset_test (reds->lookaheads[j], i))
             {
               if (! count)
                 {
@@ -268,7 +268,7 @@ print_reductions (FILE *out, const state *s)
   bool default_reduction_only = true;
 
   /* Report lookahead tokens (or $default) and reductions.  */
-  if (reds->lookahead_tokens)
+  if (reds->lookaheads)
     for (int i = 0; i < ntokens; i++)
       {
         bool defaulted = false;
@@ -277,7 +277,7 @@ print_reductions (FILE *out, const state *s)
           default_reduction_only = false;
 
         for (int j = 0; j < reds->num; ++j)
-          if (bitset_test (reds->lookahead_tokens[j], i))
+          if (bitset_test (reds->lookaheads[j], i))
             {
               if (! count)
                 {
