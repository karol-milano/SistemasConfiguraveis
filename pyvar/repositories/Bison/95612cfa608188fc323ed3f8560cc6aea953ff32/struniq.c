@@ -20,6 +20,7 @@
 
 #include "system.h"
 #include "quotearg.h"
+#include "error.h"
 #include "hash.h"
 #include "struniq.h"
 
@@ -39,20 +40,36 @@ static struct hash_table *struniqs_table = NULL;
 const struniq_t
 struniq_new (const char *s)
 {
-  /* Keep the struniqs in a printable form.  */
-  struniq_t res = hash_lookup (struniqs_table, 
-			       quotearg_style (escape_quoting_style, s));
-
+  struniq_t res = hash_lookup (struniqs_table, s);
   if (!res)
     {
       /* First insertion in the hash. */
-      res = xstrdup (quotearg_style (escape_quoting_style, s));
+      res = xstrdup (s);
       hash_insert (struniqs_table, res);
     }
   return res;
 }
 
 
+/*---------------------------------.
+| Return TRUE iff S is a struniq.  |
+`---------------------------------*/
+
+bool
+struniq_assert_p (const char *s)
+{
+  if (!hash_lookup (struniqs_table, s))
+    {
+      error (0, 0, "not a struniq: %s", quotearg (s));
+      return false;
+    }
+  else
+    {
+      return true;
+    }
+}
+
+
 /*--------------------.
 | Print the struniq.  |
 `--------------------*/
