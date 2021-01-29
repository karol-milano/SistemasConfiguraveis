@@ -641,7 +641,7 @@ static void
 prepare_percent_define_front_end_variables (void)
 {
   /* Set %define front-end variable defaults.  */
-  muscle_percent_define_default ("lr.keep-unreachable-states", "false");
+  muscle_percent_define_default ("lr.keep-unreachable-state", "false");
   {
     char *lr_type;
     /* IELR would be a better default, but LALR is historically the
@@ -649,9 +649,9 @@ prepare_percent_define_front_end_variables (void)
     muscle_percent_define_default ("lr.type", "lalr");
     lr_type = muscle_percent_define_get ("lr.type");
     if (STRNEQ (lr_type, "canonical-lr"))
-      muscle_percent_define_default ("lr.default-reductions", "most");
+      muscle_percent_define_default ("lr.default-reduction", "most");
     else
-      muscle_percent_define_default ("lr.default-reductions", "accepting");
+      muscle_percent_define_default ("lr.default-reduction", "accepting");
     free (lr_type);
   }
 
@@ -659,7 +659,7 @@ prepare_percent_define_front_end_variables (void)
   {
     static char const * const values[] = {
       "lr.type", "lalr", "ielr", "canonical-lr", NULL,
-      "lr.default-reductions", "most", "consistent", "accepting", NULL,
+      "lr.default-reduction", "most", "consistent", "accepting", NULL,
       NULL
     };
     muscle_percent_define_check_values (values);
