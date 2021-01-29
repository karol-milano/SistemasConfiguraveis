@@ -158,7 +158,7 @@ free_storage (void)
   free (shiftset);
   free (kernel_base);
   free (kernel_size);
-  XFREE (kernel_items);
+  free (kernel_items);
   state_hash_free ();
 }
 
