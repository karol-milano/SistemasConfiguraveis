@@ -638,7 +638,7 @@ prepare_percent_define_front_end_variables (void)
        default.  */
     muscle_percent_define_default ("lr.type", "lalr");
     lr_type = muscle_percent_define_get ("lr.type");
-    if (0 != strcmp (lr_type, "canonical-lr"))
+    if (STRNEQ (lr_type, "canonical-lr"))
       muscle_percent_define_default ("lr.default-reductions", "most");
     else
       muscle_percent_define_default ("lr.default-reductions", "accepting");
