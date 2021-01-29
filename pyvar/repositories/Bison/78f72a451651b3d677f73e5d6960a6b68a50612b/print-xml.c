@@ -86,12 +86,12 @@ print_core (FILE *out, int level, state *s)
           reductions *reds = s->reductions;
           int red = state_reduction_find (s, r);
           /* Print item with lookaheads if there are. */
-          if (reds->lookahead_tokens && red != -1)
+          if (reds->lookaheads && red != -1)
             {
               xml_printf (out, level + 1,
                           "<item rule-number=\"%d\" dot=\"%d\">",
                           r->number, sp1 - sp);
-              state_rule_lookahead_tokens_print_xml (s, r,
+              state_rule_lookaheads_print_xml (s, r,
                                                      out, level + 2);
               xml_puts (out, level + 1, "</item>");
               printed = true;
@@ -203,25 +203,25 @@ print_errs (FILE *out, int level, state *s)
 
 
 /*-------------------------------------------------------------------------.
-| Report a reduction of RULE on LOOKAHEAD_TOKEN (which can be 'default').  |
+| Report a reduction of RULE on LOOKAHEAD (which can be 'default').  |
 | If not ENABLED, the rule is masked by a shift or a reduce (S/R and       |
 | R/R conflicts).                                                          |
 `-------------------------------------------------------------------------*/
 
 static void
-print_reduction (FILE *out, int level, char const *lookahead_token,
+print_reduction (FILE *out, int level, char const *lookahead,
                  rule *r, bool enabled)
 {
   if (r->number)
     xml_printf (out, level,
                 "<reduction symbol=\"%s\" rule=\"%d\" enabled=\"%s\"/>",
-                xml_escape (lookahead_token),
+                xml_escape (lookahead),
                 r->number,
                 enabled ? "true" : "false");
   else
     xml_printf (out, level,
                 "<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
-                xml_escape (lookahead_token),
+                xml_escape (lookahead),
                 enabled ? "true" : "false");
 }
 
@@ -258,13 +258,13 @@ print_reductions (FILE *out, int level, state *s)
   if (default_reduction)
     report = true;
 
-  if (reds->lookahead_tokens)
+  if (reds->lookaheads)
     for (i = 0; i < ntokens; i++)
       {
         bool count = bitset_test (no_reduce_set, i);
 
         for (j = 0; j < reds->num; ++j)
-          if (bitset_test (reds->lookahead_tokens[j], i))
+          if (bitset_test (reds->lookaheads[j], i))
             {
               if (! count)
                 {
@@ -289,14 +289,14 @@ print_reductions (FILE *out, int level, state *s)
   xml_puts (out, level, "<reductions>");
 
   /* Report lookahead tokens (or $default) and reductions.  */
-  if (reds->lookahead_tokens)
+  if (reds->lookaheads)
     for (i = 0; i < ntokens; i++)
       {
         bool defaulted = false;
         bool count = bitset_test (no_reduce_set, i);
 
         for (j = 0; j < reds->num; ++j)
-          if (bitset_test (reds->lookahead_tokens[j], i))
+          if (bitset_test (reds->lookaheads[j], i))
             {
               if (! count)
                 {
