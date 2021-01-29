@@ -561,7 +561,7 @@ conflicts_print (void)
 {
   if (! glr_parser && expected_rr_conflicts != -1)
     {
-      complain (Wother, _("%%expect-rr applies only to GLR parsers"));
+      complain (NULL, Wother, _("%%expect-rr applies only to GLR parsers"));
       expected_rr_conflicts = -1;
     }
 
@@ -577,12 +577,12 @@ conflicts_print (void)
     if (expected != -1)
       {
         if (expected != total)
-          complain (complaint,
+          complain (NULL, complaint,
                     _("shift/reduce conflicts: %d found, %d expected"),
                     total, expected);
       }
     else if (total)
-      complain (Wconflicts_sr,
+      complain (NULL, Wconflicts_sr,
                 ngettext ("%d shift/reduce conflict",
                           "%d shift/reduce conflicts",
                           total),
@@ -599,12 +599,12 @@ conflicts_print (void)
     if (expected != -1)
       {
         if (expected != total)
-          complain (complaint,
+          complain (NULL, complaint,
                     _("reduce/reduce conflicts: %d found, %d expected"),
                     total, expected);
       }
     else if (total)
-      complain (Wconflicts_rr,
+      complain (NULL, Wconflicts_rr,
                 ngettext ("%d reduce/reduce conflict",
                           "%d reduce/reduce conflicts",
                           total),
