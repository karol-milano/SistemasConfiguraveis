@@ -334,7 +334,7 @@ print_reductions (FILE *out, state *s)
   if (default_reduction)
     {
       char *default_reductions =
-        muscle_percent_define_get ("lr.default-reductions");
+        muscle_percent_define_get ("lr.default-reduction");
       print_reduction (out, width, _("$default"), default_reduction, true);
       aver (STREQ (default_reductions, "most")
             || (STREQ (default_reductions, "consistent")
