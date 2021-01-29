@@ -336,8 +336,8 @@ print_reductions (FILE *out, state *s)
       char *default_reductions =
         muscle_percent_define_get ("lr.default-reductions");
       print_reduction (out, width, _("$default"), default_reduction, true);
-      aver (0 == strcmp (default_reductions, "most")
-            || (0 == strcmp (default_reductions, "consistent")
+      aver (STREQ (default_reductions, "most")
+            || (STREQ (default_reductions, "consistent")
                 && default_reduction_only)
             || (reds->num == 1 && reds->rules[0]->number == 0));
       free (default_reductions);
