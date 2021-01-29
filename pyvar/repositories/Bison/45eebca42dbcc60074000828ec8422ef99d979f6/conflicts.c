@@ -403,7 +403,7 @@ conflicts_solve (void)
       set_conflicts (states[i], errors);
 
       /* For uniformity of the code, make sure all the states have a valid
-         `errs' member.  */
+         'errs' member.  */
       if (!states[i]->errs)
         states[i]->errs = errs_new (0, 0);
     }
