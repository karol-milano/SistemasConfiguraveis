@@ -686,7 +686,8 @@ conflicts_print (void)
       expected_rr_conflicts = -1;
     }
 
-  bool has_unexpected_conflicts = false;
+  // The warning flags used to emit a diagnostic, if we did.
+  warnings unexpected_conflicts_warning = Wnone;
   /* The following two blocks scream for factoring, but i18n support
      would make it ugly.  */
   {
@@ -703,7 +704,8 @@ conflicts_print (void)
             complain (NULL, complaint,
                       _("shift/reduce conflicts: %d found, %d expected"),
                       total, expected);
-            has_unexpected_conflicts = true;
+            if (total)
+              unexpected_conflicts_warning = complaint;
           }
       }
     else if (total)
@@ -713,7 +715,7 @@ conflicts_print (void)
                             "%d shift/reduce conflicts",
                             total),
                   total);
-        has_unexpected_conflicts = true;
+        unexpected_conflicts_warning = Wconflicts_sr;
       }
   }
 
@@ -731,7 +733,8 @@ conflicts_print (void)
             complain (NULL, complaint,
                       _("reduce/reduce conflicts: %d found, %d expected"),
                       total, expected);
-            has_unexpected_conflicts = true;
+            if (total)
+              unexpected_conflicts_warning = complaint;
           }
       }
     else if (total)
@@ -741,15 +744,16 @@ conflicts_print (void)
                             "%d reduce/reduce conflicts",
                             total),
                   total);
-        has_unexpected_conflicts = true;
+        unexpected_conflicts_warning = Wconflicts_rr;
       }
   }
 
   if (warning_is_enabled (Wcounterexamples))
     report_counterexamples ();
-  else if (has_unexpected_conflicts)
-    complain (NULL, Wother,
-              _("rerun with option '-Wcounterexamples' to generate conflict counterexamples"));
+  else if (unexpected_conflicts_warning != Wnone)
+    subcomplain (NULL, unexpected_conflicts_warning,
+                 _("rerun with option '-Wcounterexamples'"
+                   " to generate conflict counterexamples"));
 }
 
 void
