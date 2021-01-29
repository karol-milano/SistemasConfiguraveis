@@ -343,6 +343,7 @@ print_reductions (FILE *out, state *s)
             || (STREQ (default_reductions, "consistent")
                 && default_reduction_only)
             || (reds->num == 1 && reds->rules[0]->number == 0));
+      (void) default_reduction_only;
       free (default_reductions);
     }
 }
