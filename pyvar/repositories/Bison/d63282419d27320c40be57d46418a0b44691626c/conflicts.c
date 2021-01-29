@@ -36,7 +36,8 @@
 #include "symtab.h"
 
 /* -1 stands for not specified. */
-int expected_conflicts = -1;
+int expected_sr_conflicts = -1;
+int expected_rr_conflicts = -1;
 static char *conflicts = NULL;
 struct obstack solved_conflicts_obstack;
 
@@ -464,6 +465,7 @@ conflicts_print (void)
      not set, and then we want 0 SR, or else it is specified, in which
      case we want equality.  */
   bool src_ok = false;
+  bool rrc_ok = false;
 
   int src_total = 0;
   int rrc_total = 0;
@@ -480,11 +482,20 @@ conflicts_print (void)
 	}
   }
 
-  src_ok = src_total == (expected_conflicts == -1 ? 0 : expected_conflicts);
+  if (! glr_parser && rrc_total > 0 && expected_rr_conflicts != -1)
+    {
+      warn (_("%expect-rr applies only to GLR parsers"));
+      expected_rr_conflicts = -1;
+    }
+
+  src_ok = 
+    src_total == (expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts);
+  rrc_ok = 
+    rrc_total == (expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts);
 
-  /* If there are no RR conflicts, and as many SR conflicts as
+  /* If there are as many RR conflicts and SR conflicts as
      expected, then there is nothing to report.  */
-  if (!rrc_total && src_ok)
+  if (rrc_ok && src_ok)
     return;
 
   /* Report the total number of conflicts on STDERR.  */
@@ -492,15 +503,18 @@ conflicts_print (void)
     fprintf (stderr, "%s: ", current_file);
   conflict_report (stderr, src_total, rrc_total);
 
-  if (expected_conflicts != -1)
+  if (expected_sr_conflicts != -1 || expected_rr_conflicts != -1)
     {
+      int sr = expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts;
+      int rr = expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts;
       if (! src_ok)
 	warn (ngettext ("expected %d shift/reduce conflict",
 			"expected %d shift/reduce conflicts",
-			expected_conflicts),
-	      expected_conflicts);
-      if (rrc_total)
-	warn (_("expected 0 reduce/reduce conflicts"));
+			sr), sr);
+      if (! rrc_ok)
+	warn (ngettext ("expected %d reduce/reduce conflict",
+			"expected %d reduce/reduce conflicts",
+			rr), rr);
     }
 }
 
