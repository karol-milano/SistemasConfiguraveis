@@ -371,7 +371,7 @@ initialize_LA (void)
   bool default_reduction_only_for_accept;
   {
     char *default_reductions =
-      muscle_percent_define_get ("lr.default-reductions");
+      muscle_percent_define_get ("lr.default-reduction");
     default_reduction_only_for_accept = STREQ (default_reductions, "accepting");
     free (default_reductions);
   }
