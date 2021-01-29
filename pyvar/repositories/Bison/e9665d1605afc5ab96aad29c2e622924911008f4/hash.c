@@ -31,6 +31,7 @@
 # include <stdlib.h>
 #endif
 
+#include <limits.h>
 #include <stdbool.h>
 #include <stdio.h>
 
@@ -403,9 +404,6 @@ hash_do_for_each (const Hash_table *table, Hash_processor processor,
 unsigned
 hash_string (const char *string, unsigned n_buckets)
 {
-# ifndef CHAR_BIT
-#  define CHAR_BIT 8
-# endif
 # define ROTATE_LEFT(Value, Shift) \
   ((Value) << (Shift) | (Value) >> ((sizeof (unsigned) * CHAR_BIT) - (Shift)))
 # define HASH_ONE_CHAR(Value, Byte) \
