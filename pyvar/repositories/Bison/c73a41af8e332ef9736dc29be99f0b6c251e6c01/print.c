@@ -173,7 +173,7 @@ print_actions (FILE *out, int state)
     }
   else if (redp)
     {
-      print_reductions (state);
+      print_reductions (out, state);
     }
 
   if (i < k)
