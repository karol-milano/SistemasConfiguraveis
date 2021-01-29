@@ -250,10 +250,7 @@ reduce_grammar_tables (void)
 
   /* Adjust NRITEMS.  */
   for (rule_number r = nrules; r < nrules + nuseless_productions; ++r)
-    {
-      int length = rule_rhs_length (&rules[r]);
-      nritems -= length + 1;
-  }
+    nritems -= rule_rhs_length (&rules[r]) + 1;
 }
 
 
