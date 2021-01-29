@@ -395,9 +395,10 @@ generate_states (void)
   /* Create the initial state, whose accessing symbol (by convention)
      is 0, aka $end.  */
   {
-    /* The items of its core.  */
-    kernel_size[0] = 1;
-    kernel_base[0][0] = 0;
+    /* The items of its core: beginning of all the rules of $accept.  */
+    kernel_size[0] = 0;
+    for (rule_number r = 0; r < nrules && rules[r].lhs->symbol == acceptsymbol; ++r)
+      kernel_base[0][kernel_size[0]++] = rules[r].rhs - ritem;
     state_list_append (0, kernel_size[0], kernel_base[0]);
   }
 
