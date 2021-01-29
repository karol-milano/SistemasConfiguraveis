@@ -327,6 +327,16 @@ conflicts_solve (void)
 }
 
 
+void
+conflicts_update_state_numbers (state_number old_to_new[],
+                                state_number nstates_old)
+{
+  for (state_number i = 0; i < nstates_old; ++i)
+    if (old_to_new[i] != nstates_old)
+      conflicts[old_to_new[i]] = conflicts[i];
+}
+
+
 /*---------------------------------------------.
 | Count the number of shift/reduce conflicts.  |
 `---------------------------------------------*/
