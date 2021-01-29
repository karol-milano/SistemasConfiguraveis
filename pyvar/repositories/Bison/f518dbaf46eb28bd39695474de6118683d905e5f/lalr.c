@@ -372,8 +372,7 @@ initialize_LA (void)
   {
     char *default_reductions =
       muscle_percent_define_get ("lr.default-reductions");
-    default_reduction_only_for_accept =
-      0 == strcmp (default_reductions, "accepting");
+    default_reduction_only_for_accept = STREQ (default_reductions, "accepting");
     free (default_reductions);
   }
 
