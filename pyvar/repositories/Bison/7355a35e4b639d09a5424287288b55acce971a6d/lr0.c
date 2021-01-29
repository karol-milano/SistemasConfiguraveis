@@ -314,7 +314,7 @@ void
 generate_states (void)
 {
   allocate_storage ();
-  new_closure (nritems);
+  closure_new (nritems);
 
   /* Create the initial state.  The 0 at the lhs is the index of the
      item of this initial rule.  */
@@ -345,7 +345,7 @@ generate_states (void)
     }
 
   /* discard various storage */
-  free_closure ();
+  closure_free ();
   free_storage ();
 
   /* Set up STATES. */
