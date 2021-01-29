@@ -358,6 +358,8 @@ grammar_rule_check_and_complete (symbol_list *r)
       && warning_is_enabled (Wempty_rule))
     {
       complain (&r->rhs_loc, Wempty_rule, _("empty rule without %%empty"));
+      if (feature_flag & feature_caret)
+        location_caret_suggestion (r->rhs_loc, "%empty", stderr);
       location loc = r->rhs_loc;
       loc.end = loc.start;
       fixits_register (&loc, " %empty ");
