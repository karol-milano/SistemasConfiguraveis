@@ -37,7 +37,7 @@ static struct hash_table *struniqs_table = NULL;
 | Create the struniq for S if needed.  |
 `-------------------------------------*/
 
-const struniq_t
+struniq_t
 struniq_new (const char *s)
 {
   struniq_t res = hash_lookup (struniqs_table, s);
