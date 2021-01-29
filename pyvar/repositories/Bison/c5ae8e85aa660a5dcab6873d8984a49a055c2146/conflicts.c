@@ -569,7 +569,7 @@ conflicts_print (void)
      different strings to translate.  */
   {
     int total = count_sr_conflicts ();
-    // If %expect is not used, but %expect-rr is, then expect 0 sr.
+    /* If %expect is not used, but %expect-rr is, then expect 0 sr.  */
     int expected =
       (expected_sr_conflicts == -1 && expected_rr_conflicts != -1)
       ? 0
@@ -591,7 +591,7 @@ conflicts_print (void)
 
   {
     int total = count_rr_conflicts (true);
-    // If %expect-rr is not used, but %expect is, then expect 0 rr.
+    /* If %expect-rr is not used, but %expect is, then expect 0 rr.  */
     int expected =
       (expected_rr_conflicts == -1 && expected_sr_conflicts != -1)
       ? 0
