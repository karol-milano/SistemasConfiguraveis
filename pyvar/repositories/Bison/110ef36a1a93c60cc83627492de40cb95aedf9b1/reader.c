@@ -561,9 +561,9 @@ reader (void)
     muscle_percent_define_default ("lr.type", "LALR");
     lr_type = muscle_percent_define_get ("lr.type");
     if (0 != strcmp (lr_type, "canonical LR"))
-      muscle_percent_define_default ("lr.default_rules", "all");
+      muscle_percent_define_default ("lr.default_reductions", "all");
     else
-      muscle_percent_define_default ("lr.default_rules", "accepting");
+      muscle_percent_define_default ("lr.default_reductions", "accepting");
     free (lr_type);
   }
 
@@ -571,7 +571,7 @@ reader (void)
   {
     static char const * const values[] = {
       "lr.type", "LALR", "IELR", "canonical LR", NULL,
-      "lr.default_rules", "all", "consistent", "accepting", NULL,
+      "lr.default_reductions", "all", "consistent", "accepting", NULL,
       NULL
     };
     muscle_percent_define_check_values (values);
