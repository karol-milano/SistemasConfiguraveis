@@ -309,7 +309,7 @@ action_row (state *s)
      labeled as consistent.  */
   {
     char *default_reductions =
-      muscle_percent_define_get ("lr.default_reductions");
+      muscle_percent_define_get ("lr.default-reductions");
     if (0 != strcmp (default_reductions, "all") && !s->consistent)
       nodefault = true;
     free (default_reductions);
