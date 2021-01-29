@@ -127,9 +127,6 @@ muscle_init (void)
 
   muscle_table = hash_xinitialize (HT_INITIAL_CAPACITY, NULL, hash_muscle,
                                    hash_compare_muscles, muscle_entry_free);
-
-  /* Version and input file.  */
-  MUSCLE_INSERT_STRING ("version", VERSION);
 }
 
 
