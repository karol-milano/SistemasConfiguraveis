@@ -810,9 +810,8 @@ tables_generate (void)
   /* This is a poor way to make sure the sizes are properly
      correlated.  In particular the signedness is not taken into
      account.  But it's not useless.  */
-  verify (sizes_are_properly_correlated,
-	  (sizeof nstates <= sizeof nvectors
-	   && sizeof nvars <= sizeof nvectors));
+  verify (sizeof nstates <= sizeof nvectors
+	  && sizeof nvars <= sizeof nvectors);
 
   nvectors = state_number_as_int (nstates) + nvars;
 
