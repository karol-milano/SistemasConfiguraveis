@@ -632,7 +632,7 @@ prepare_percent_define_front_end_variables (void)
     muscle_percent_define_default ("lr.type", "lalr");
     lr_type = muscle_percent_define_get ("lr.type");
     if (0 != strcmp (lr_type, "canonical-lr"))
-      muscle_percent_define_default ("lr.default-reductions", "full");
+      muscle_percent_define_default ("lr.default-reductions", "most");
     else
       muscle_percent_define_default ("lr.default-reductions", "accepting");
     free (lr_type);
@@ -642,7 +642,7 @@ prepare_percent_define_front_end_variables (void)
   {
     static char const * const values[] = {
       "lr.type", "lalr", "ielr", "canonical-lr", NULL,
-      "lr.default-reductions", "full", "consistent", "accepting", NULL,
+      "lr.default-reductions", "most", "consistent", "accepting", NULL,
       NULL
     };
     muscle_percent_define_check_values (values);
