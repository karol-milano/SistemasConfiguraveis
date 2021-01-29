@@ -261,7 +261,7 @@ static struct hash_table *state_table = NULL;
 static inline bool
 state_compare (state const *s1, state const *s2)
 {
-  int i;
+  size_t i;
 
   if (s1->nitems != s2->nitems)
     return false;
@@ -284,7 +284,7 @@ state_hash (state const *s, size_t tablesize)
 {
   /* Add up the state's item numbers to get a hash key.  */
   size_t key = 0;
-  int i;
+  size_t i;
   for (i = 0; i < s->nitems; ++i)
     key += s->items[i];
   return key % tablesize;
