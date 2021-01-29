@@ -19,12 +19,19 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
-#include "hash.h"
-#include "quotearg.h"
+
+#include <hash.h>
+#include <quotearg.h>
+
 #include "files.h"
 #include "muscle_tab.h"
 #include "getargs.h"
 
+typedef struct
+{
+  const char *key;
+  char *value;
+} muscle_entry;
 
 /* An obstack used to create some entries.  */
 struct obstack muscle_obstack;
@@ -37,15 +44,15 @@ struct hash_table *muscle_table = NULL;
 static bool
 hash_compare_muscles (void const *x, void const *y)
 {
-  const muscle_entry_t *m1 = x;
-  const muscle_entry_t *m2 = y;
+  muscle_entry const *m1 = x;
+  muscle_entry const *m2 = y;
   return strcmp (m1->key, m2->key) == 0;
 }
 
 static unsigned int
 hash_muscle (const void *x, unsigned int tablesize)
 {
-  const muscle_entry_t *m = x;
+  muscle_entry const *m = x;
   return hash_string (m->key, tablesize);
 }
 
@@ -90,8 +97,8 @@ muscle_free (void)
 void
 muscle_insert (const char *key, char *value)
 {
-  muscle_entry_t probe;
-  muscle_entry_t *entry = NULL;
+  muscle_entry probe;
+  muscle_entry *entry = NULL;
 
   probe.key = key;
   entry = hash_lookup (muscle_table, &probe);
@@ -99,7 +106,7 @@ muscle_insert (const char *key, char *value)
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = XMALLOC (muscle_entry_t, 1);
+      entry = XMALLOC (muscle_entry, 1);
       entry->key = key;
       hash_insert (muscle_table, entry);
     }
@@ -116,8 +123,8 @@ muscle_insert (const char *key, char *value)
 void
 muscle_grow (const char *key, const char *val, const char *separator)
 {
-  muscle_entry_t probe;
-  muscle_entry_t *entry = NULL;
+  muscle_entry probe;
+  muscle_entry *entry = NULL;
 
   probe.key = key;
   entry = hash_lookup (muscle_table, &probe);
@@ -125,7 +132,7 @@ muscle_grow (const char *key, const char *val, const char *separator)
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = XMALLOC (muscle_entry_t, 1);
+      entry = XMALLOC (muscle_entry, 1);
       entry->key = key;
       hash_insert (muscle_table, entry);
       entry->value = xstrdup (val);
@@ -171,8 +178,8 @@ void muscle_pair_list_grow (const char *muscle,
 char*
 muscle_find (const char *key)
 {
-  muscle_entry_t probe;
-  muscle_entry_t *result = NULL;
+  muscle_entry probe;
+  muscle_entry *result = NULL;
 
   probe.key = key;
   result = hash_lookup (muscle_table, &probe);
@@ -185,7 +192,7 @@ muscle_find (const char *key)
 `------------------------------------------------*/
 
 static int
-muscle_m4_output (muscle_entry_t *entry, FILE *out)
+muscle_m4_output (muscle_entry *entry, FILE *out)
 {
   fprintf (out, "m4_define([b4_%s],\n", entry->key);
   fprintf (out, "[[%s]])\n\n\n", entry->value);
