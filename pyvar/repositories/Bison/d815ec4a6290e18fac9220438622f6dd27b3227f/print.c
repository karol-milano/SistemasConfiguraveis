@@ -337,7 +337,7 @@ print_reductions (FILE *out, state *s)
       char *default_reductions =
         muscle_percent_define_get ("lr.default-reductions");
       print_reduction (out, width, _("$default"), default_reduction, true);
-      aver (0 == strcmp (default_reductions, "all")
+      aver (0 == strcmp (default_reductions, "full")
             || (0 == strcmp (default_reductions, "consistent")
                 && default_reduction_only)
             || (reds->num == 1 && reds->rules[0]->number == 0));
