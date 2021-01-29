@@ -339,6 +339,12 @@ grammar_rule_check (const symbol_list *r)
     complain (&r->percent_empty_loc, complaint,
               _("%%empty on non-empty rule"));
 
+  /* Check that empty rule => %empty.  */
+  if (!(r->next && r->next->content.sym)
+      && !r->midrule_parent_rule
+      && !r->percent_empty_loc.start.file)
+    complain (&r->location, Wempty_rule, _("empty rule without %%empty"));
+
   /* See comments in grammar_current_rule_prec_set for how POSIX
      mandates this complaint.  It's only for identifiers, so skip
      it for char literals and strings, which are always tokens.  */
