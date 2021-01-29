@@ -576,7 +576,7 @@ conflicts_print (void)
         }
   }
 
-  if (! glr_parser && rrc_total > 0 && expected_rr_conflicts != -1)
+  if (! glr_parser && expected_rr_conflicts != -1)
     {
       complain (Wother, _("%%expect-rr applies only to GLR parsers"));
       expected_rr_conflicts = -1;
