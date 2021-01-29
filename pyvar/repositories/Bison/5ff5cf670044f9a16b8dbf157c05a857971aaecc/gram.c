@@ -304,13 +304,14 @@ grammar_dump (FILE *out, const char *title)
 void
 grammar_rules_useless_report (const char *message)
 {
-  rule_number r;
-  for (r = 0; r < nrules ; ++r)
-    if (!rules[r].useful)
-      {
-        complain_at (rules[r].location, Wother, "%s: ", message);
-        if (warnings_flag & Wother)
+  warnings w = Wother;
+  if (warnings_flag & w)
+    {
+      rule_number r;
+      for (r = 0; r < nrules ; ++r)
+        if (!rules[r].useful)
           {
+            complain_at (rules[r].location, w, "%s: ", message);
             rule_print (&rules[r], stderr);
             fflush (stderr);
           }
