@@ -534,11 +534,16 @@ conflicts_print (void)
   else
     warn ("%s", conflict_report (src_total, rrc_total));
 
-  if (expected_conflicts != -1 && !src_ok)
-    complain (ngettext ("expected %d shift/reduce conflict",
-			"expected %d shift/reduce conflicts",
-			expected_conflicts),
-	      expected_conflicts);
+  if (expected_conflicts != -1)
+    {
+      if (! src_ok)
+	complain (ngettext ("expected %d shift/reduce conflict",
+			    "expected %d shift/reduce conflicts",
+			    expected_conflicts),
+		  expected_conflicts);
+      if (rrc_total)
+	complain (_("expected 0 reduce/reduce conflicts"));
+    }
 }
 
 
