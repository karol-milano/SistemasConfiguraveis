@@ -24,8 +24,8 @@
 #include "system.h"
 #include "xalloc.h"
 
-static void hash_rehash __P((struct hash_table* ht));
-static unsigned long round_up_2 __P((unsigned long rough));
+static void hash_rehash PARAMS((struct hash_table* ht));
+static unsigned long round_up_2 PARAMS((unsigned long rough));
 
 /* Implement double hashing with open addressing.  The table size is
    always a power of two.  The secondary (`increment') hash function
