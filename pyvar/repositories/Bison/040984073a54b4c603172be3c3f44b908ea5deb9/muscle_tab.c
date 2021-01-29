@@ -41,7 +41,7 @@ struct obstack muscle_obstack;
 /* Initial capacity of muscles hash table.  */
 #define HT_INITIAL_CAPACITY 257
 
-struct hash_table *muscle_table = NULL;
+static struct hash_table *muscle_table = NULL;
 
 static bool
 hash_compare_muscles (void const *x, void const *y)
