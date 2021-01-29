@@ -710,13 +710,13 @@ rule_conflicts_print (void)
             complain (&r->location, complaint,
                       _("shift/reduce conflicts for rule %d:"
                         " %d found, %d expected"),
-                      r->user_number, sr, expected_sr);
+                      r->code, sr, expected_sr);
           int rr = count_rule_rr_conflicts (r);
           if (rr != expected_rr && (rr != 0 || expected_rr != -1))
             complain (&r->location, complaint,
                       _("reduce/reduce conflicts for rule %d:"
                         " %d found, %d expected"),
-                      r->user_number, rr, expected_rr);
+                      r->code, rr, expected_rr);
         }
     }
   if (warning_is_enabled (Wcounterexample))
