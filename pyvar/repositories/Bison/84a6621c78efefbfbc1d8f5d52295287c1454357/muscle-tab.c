@@ -126,10 +126,8 @@ muscle_init (void)
   /* Initialize the muscle obstack.  */
   obstack_init (&muscle_obstack);
 
-  muscle_table = hash_initialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
-                                  hash_compare_muscles, muscle_entry_free);
-  if (!muscle_table)
-    xalloc_die ();
+  muscle_table = hash_xinitialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
+                                   hash_compare_muscles, muscle_entry_free);
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
