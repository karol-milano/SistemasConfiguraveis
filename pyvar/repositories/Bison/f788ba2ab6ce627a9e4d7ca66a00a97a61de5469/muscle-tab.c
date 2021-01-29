@@ -128,6 +128,8 @@ muscle_init (void)
 
   muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
                                   hash_compare_muscles, muscle_entry_free);
+  if (!muscle_table)
+    xalloc_die ();
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
