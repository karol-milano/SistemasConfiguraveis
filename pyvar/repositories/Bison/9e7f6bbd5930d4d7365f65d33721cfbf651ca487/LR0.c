@@ -391,7 +391,7 @@ void
 generate_states (void)
 {
   allocate_storage ();
-  new_closure (nitems);
+  new_closure (nritems);
   new_states ();
 
   while (this_state)
