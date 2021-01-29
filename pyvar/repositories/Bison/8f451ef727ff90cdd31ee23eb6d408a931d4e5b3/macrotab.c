@@ -20,6 +20,7 @@
 
 #include <string.h>
 
+#include "xalloc.h"
 #include "system.h"
 #include "hash.h"
 #include "files.h"
@@ -110,16 +111,16 @@ macro_init (void)
 }
 
 void 
-macro_insert (char* key, char* value)
+macro_insert (const char *key, const char *value)
 {
-  macro_entry_t* pair = (macro_entry_t*) xmalloc (sizeof (macro_entry_t));
+  macro_entry_t* pair = XMALLOC (macro_entry_t, 1);
   pair->key = key;
   pair->value = value;
   hash_insert (&macro_table, pair);
 }
 
-char*
-macro_find (char* key)
+const char*
+macro_find (const char *key)
 {
   macro_entry_t pair = { key, 0 };
   macro_entry_t* result = hash_find_item (&macro_table, &pair);
