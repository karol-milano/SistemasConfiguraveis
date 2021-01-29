@@ -584,7 +584,7 @@ conflicts_print (void)
 
   if (! glr_parser && rrc_total > 0 && expected_rr_conflicts != -1)
     {
-      warn (_("%%expect-rr applies only to GLR parsers"));
+      complain (Wother, _("%%expect-rr applies only to GLR parsers"));
       expected_rr_conflicts = -1;
     }
 
@@ -618,14 +618,14 @@ conflicts_print (void)
   if (expected_sr_conflicts != -1 || expected_rr_conflicts != -1)
     {
       if (! src_ok)
-        complain (ngettext ("expected %d shift/reduce conflict",
-                            "expected %d shift/reduce conflicts",
-                            src_expected),
+        complain (complaint, ngettext ("expected %d shift/reduce conflict",
+                                       "expected %d shift/reduce conflicts",
+                                       src_expected),
                   src_expected);
       if (! rrc_ok)
-        complain (ngettext ("expected %d reduce/reduce conflict",
-                            "expected %d reduce/reduce conflicts",
-                            rrc_expected),
+        complain (complaint, ngettext ("expected %d reduce/reduce conflict",
+                                       "expected %d reduce/reduce conflicts",
+                                       rrc_expected),
                   rrc_expected);
     }
 }
