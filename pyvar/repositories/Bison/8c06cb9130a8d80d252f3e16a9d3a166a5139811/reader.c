@@ -357,9 +357,10 @@ grammar_rule_check_and_complete (symbol_list *r)
       && !r->percent_empty_loc.start.file
       && warning_is_enabled (Wempty_rule))
     {
-      complain (&r->rhs_loc, Wempty_rule,
-                _("empty rule without %%empty"));
-      fixits_register (&r->rhs_loc, " %empty ");
+      complain (&r->rhs_loc, Wempty_rule, _("empty rule without %%empty"));
+      location loc = r->rhs_loc;
+      loc.end = loc.start;
+      fixits_register (&loc, " %empty ");
     }
 
   /* See comments in grammar_current_rule_prec_set for how POSIX
