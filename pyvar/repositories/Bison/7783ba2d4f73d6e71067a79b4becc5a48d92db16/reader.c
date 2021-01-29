@@ -726,20 +726,20 @@ prepare_percent_define_front_end_variables (void)
 /* Find the first LHS which is not a dummy.  */
 
 static symbol *
-find_start_symbol ()
+find_start_symbol (void)
 {
   symbol_list *res = grammar;
   for (;
-       res != NULL && symbol_is_dummy (res->content.sym);
+       res && symbol_is_dummy (res->content.sym);
        res = res->next)
     {
       for (res = res->next;
-           res != NULL && res->content.sym != NULL;
+           res && res->content.sym;
            res = res->next)
         continue;
-      aver (res != NULL);
+      assume (res);
     }
-  aver (res != NULL);
+  assume (res);
   return res->content.sym;
 }
 
