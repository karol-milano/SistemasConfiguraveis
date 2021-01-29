@@ -23,6 +23,7 @@
 #include <error.h>
 #include <hash.h>
 #include <quotearg.h>
+#include <stdarg.h>
 
 #include "uniqstr.h"
 
@@ -53,6 +54,21 @@ uniqstr_new (char const *str)
   return res;
 }
 
+uniqstr
+uniqstr_vsprintf (char const *format, ...)
+{
+  va_list args;
+  size_t length;
+  va_start (args, format);
+  length = vsnprintf (NULL, 0, format, args);
+  va_end (args);
+
+  char res[length + 1];
+  va_start (args, format);
+  vsprintf (res, format, args);
+  va_end (args);
+  return uniqstr_new (res);
+}
 
 /*------------------------------.
 | Abort if S is not a uniqstr.  |
