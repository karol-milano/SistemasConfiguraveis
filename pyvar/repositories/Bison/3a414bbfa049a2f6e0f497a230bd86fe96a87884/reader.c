@@ -608,9 +608,9 @@ prepare_percent_define_front_end_variables (void)
     char *lr_type;
     /* IELR would be a better default, but LALR is historically the
        default.  */
-    muscle_percent_define_default ("lr.type", "LALR");
+    muscle_percent_define_default ("lr.type", "lalr");
     lr_type = muscle_percent_define_get ("lr.type");
-    if (0 != strcmp (lr_type, "canonical LR"))
+    if (0 != strcmp (lr_type, "canonical-lr"))
       muscle_percent_define_default ("lr.default-reductions", "all");
     else
       muscle_percent_define_default ("lr.default-reductions", "accepting");
@@ -620,7 +620,7 @@ prepare_percent_define_front_end_variables (void)
   /* Check %define front-end variables.  */
   {
     static char const * const values[] = {
-      "lr.type", "LALR", "IELR", "canonical LR", NULL,
+      "lr.type", "lalr", "ielr", "canonical-lr", NULL,
       "lr.default-reductions", "all", "consistent", "accepting", NULL,
       NULL
     };
