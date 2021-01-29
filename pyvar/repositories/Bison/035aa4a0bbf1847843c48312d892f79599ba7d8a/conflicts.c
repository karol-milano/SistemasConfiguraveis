@@ -1,6 +1,6 @@
 /* Find and resolve or report look-ahead conflicts for bison,
 
-   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004
+   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -464,11 +464,13 @@ conflicts_print (void)
   /* Is the number of SR conflicts OK?  Either EXPECTED_CONFLICTS is
      not set, and then we want 0 SR, or else it is specified, in which
      case we want equality.  */
-  bool src_ok = false;
-  bool rrc_ok = false;
+  bool src_ok;
+  bool rrc_ok;
 
   int src_total = 0;
   int rrc_total = 0;
+  int src_expected;
+  int rrc_expected;
 
   /* Conflicts by state.  */
   {
@@ -488,33 +490,36 @@ conflicts_print (void)
       expected_rr_conflicts = -1;
     }
 
-  src_ok =
-    src_total == (expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts);
-  rrc_ok =
-    rrc_total == (expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts);
+  src_expected = expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts;
+  rrc_expected = expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts;
+  src_ok = src_total == src_expected;
+  rrc_ok = rrc_total == rrc_expected;
 
   /* If there are as many RR conflicts and SR conflicts as
      expected, then there is nothing to report.  */
-  if (rrc_ok && src_ok)
+  if (rrc_ok & src_ok)
     return;
 
   /* Report the total number of conflicts on STDERR.  */
-  if (! yacc_flag)
-    fprintf (stderr, "%s: ", current_file);
-  conflict_report (stderr, src_total, rrc_total);
+  if (src_total | rrc_total)
+    {
+      if (! yacc_flag)
+	fprintf (stderr, "%s: ", current_file);
+      conflict_report (stderr, src_total, rrc_total);
+    }
 
   if (expected_sr_conflicts != -1 || expected_rr_conflicts != -1)
     {
-      int sr = expected_sr_conflicts == -1 ? 0 : expected_sr_conflicts;
-      int rr = expected_rr_conflicts == -1 ? 0 : expected_rr_conflicts;
       if (! src_ok)
-	warn (ngettext ("expected %d shift/reduce conflict",
-			"expected %d shift/reduce conflicts",
-			sr), sr);
+	complain (ngettext ("expected %d shift/reduce conflict",
+			    "expected %d shift/reduce conflicts",
+			    src_expected),
+		  src_expected);
       if (! rrc_ok)
-	warn (ngettext ("expected %d reduce/reduce conflict",
-			"expected %d reduce/reduce conflicts",
-			rr), rr);
+	complain (ngettext ("expected %d reduce/reduce conflict",
+			    "expected %d reduce/reduce conflicts",
+			    rrc_expected),
+		  rrc_expected);
     }
 }
 
