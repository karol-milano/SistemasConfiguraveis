@@ -310,7 +310,7 @@ action_row (state *s)
   {
     char *default_reductions =
       muscle_percent_define_get ("lr.default-reductions");
-    if (0 != strcmp (default_reductions, "full") && !s->consistent)
+    if (0 != strcmp (default_reductions, "most") && !s->consistent)
       nodefault = true;
     free (default_reductions);
   }
