@@ -308,7 +308,7 @@ action_row (state *s)
      labeled as consistent.  */
   {
     char *default_reductions =
-      muscle_percent_define_get ("lr.default-reductions");
+      muscle_percent_define_get ("lr.default-reduction");
     if (STRNEQ (default_reductions, "most") && !s->consistent)
       nodefault = true;
     free (default_reductions);
