@@ -345,7 +345,6 @@ generate_states (void)
     }
 
   /* discard various storage */
-  closure_free ();
   free_storage ();
 
   /* Set up STATES. */
