@@ -113,6 +113,7 @@ allocate_storage (void)
   shiftset = XCALLOC (short, nsyms);
   redset = XCALLOC (short, nrules + 1);
   state_hash = XCALLOC (state_t *, STATE_HASH_SIZE);
+  shift_symbol = XCALLOC (short, nsyms);
 }
 
 
@@ -154,7 +155,6 @@ new_itemsets (void)
   for (i = 0; i < nsyms; i++)
     kernel_size[i] = 0;
 
-  shift_symbol = XCALLOC (short, nsyms);
   nshifts = 0;
 
   for (i = 0; i < nitemset; ++i)
