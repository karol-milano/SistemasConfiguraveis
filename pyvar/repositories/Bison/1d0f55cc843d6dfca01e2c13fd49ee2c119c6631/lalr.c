@@ -372,7 +372,7 @@ initialize_LA (void)
   bool default_reduction_only_for_accept;
   {
     char *default_reductions =
-      muscle_percent_define_get ("lr.default_reductions");
+      muscle_percent_define_get ("lr.default-reductions");
     default_reduction_only_for_accept =
       0 == strcmp (default_reductions, "accepting");
     free (default_reductions);
