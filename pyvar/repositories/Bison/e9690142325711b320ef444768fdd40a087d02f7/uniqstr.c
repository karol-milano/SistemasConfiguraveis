@@ -80,7 +80,7 @@ uniqstr_assert (char const *str)
   if (!hash_lookup (uniqstrs_table, str))
     {
       error (0, 0,
-	     "not a uniqstr: %s", quotearg (str));
+             "not a uniqstr: %s", quotearg (str));
       abort ();
     }
 }
@@ -128,10 +128,10 @@ void
 uniqstrs_new (void)
 {
   uniqstrs_table = hash_initialize (HT_INITIAL_CAPACITY,
-				    NULL,
-				    hash_uniqstr,
-				    hash_compare_uniqstr,
-				    free);
+                                    NULL,
+                                    hash_uniqstr,
+                                    hash_compare_uniqstr,
+                                    free);
 }
 
 
