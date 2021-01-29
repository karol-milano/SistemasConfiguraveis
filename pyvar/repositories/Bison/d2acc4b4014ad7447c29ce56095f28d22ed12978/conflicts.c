@@ -723,7 +723,7 @@ rule_conflicts_print (void)
                       r->code, rr, expected_rr);
         }
     }
-  if (warning_is_enabled (Wcounterexample))
+  if (warning_is_enabled (Wcounterexamples))
     report_counterexamples ();
 }
 
