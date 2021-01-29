@@ -754,11 +754,12 @@ prepare_percent_define_front_end_variables (void)
 
   /* Check %define front-end variables.  */
   {
-    static char const * const values[] = {
-      "lr.type", "lalr", "ielr", "canonical-lr", NULL,
-      "lr.default-reduction", "most", "consistent", "accepting", NULL,
-      NULL
-    };
+    static char const * const values[] =
+      {
+       "lr.type", "lr(0)", "lalr", "ielr", "canonical-lr", NULL,
+       "lr.default-reduction", "most", "consistent", "accepting", NULL,
+       NULL
+      };
     muscle_percent_define_check_values (values);
   }
 }
