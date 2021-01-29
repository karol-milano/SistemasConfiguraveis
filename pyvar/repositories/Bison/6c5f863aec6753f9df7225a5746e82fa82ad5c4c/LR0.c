@@ -157,7 +157,7 @@ free_storage (void)
   free (shiftset);
   free (kernel_base);
   free (kernel_size);
-  free (kernel_items);
+  XFREE (kernel_items);
   state_hash_free ();
 }
 
