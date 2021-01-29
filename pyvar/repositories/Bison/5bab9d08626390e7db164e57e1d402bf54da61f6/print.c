@@ -335,7 +335,7 @@ print_reductions (FILE *out, state *s)
   if (default_reduction)
     {
       char *default_reductions =
-        muscle_percent_define_get ("lr.default_reductions");
+        muscle_percent_define_get ("lr.default-reductions");
       print_reduction (out, width, _("$default"), default_reduction, true);
       aver (0 == strcmp (default_reductions, "all")
             || (0 == strcmp (default_reductions, "consistent")
