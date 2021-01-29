@@ -19,53 +19,61 @@
 # include <config.h>
 #endif
 
-#include <stdio.h>
-#include <assert.h>
-
-#ifndef FILESYSTEM_PREFIX_LEN
-# define FILESYSTEM_PREFIX_LEN(Filename) 0
-#endif
-
-#ifndef PARAMS
-# if defined PROTOTYPES || (defined __STDC__ && __STDC__)
-#  define PARAMS(Args) Args
-# else
-#  define PARAMS(Args) ()
-# endif
-#endif
-
-#ifndef ISSLASH
-# define ISSLASH(C) ((C) == '/')
+#if STDC_HEADERS || HAVE_STRING_H
+# include <string.h>
 #endif
-
-char *base_name PARAMS ((char const *name));
+#include "dirname.h"
 
 /* In general, we can't use the builtin `basename' function if available,
    since it has different meanings in different environments.
    In some environments the builtin `basename' modifies its argument.
-   If NAME is all slashes, be sure to return `/'.  */
+
+   Return the address of the last file name component of NAME.  If
+   NAME has no file name components because it is all slashes, return
+   NAME if it is empty, the address of its last slash otherwise.  */
 
 char *
 base_name (char const *name)
 {
-  char const *base = name += FILESYSTEM_PREFIX_LEN (name);
-  int all_slashes = 1;
+  char const *base = name + FILESYSTEM_PREFIX_LEN (name);
   char const *p;
 
-  for (p = name; *p; p++)
+  for (p = base; *p; p++)
     {
       if (ISSLASH (*p))
-	base = p + 1;
-      else
-	all_slashes = 0;
-    }
+	{
+	  /* Treat multiple adjacent slashes like a single slash.  */
+	  do p++;
+	  while (ISSLASH (*p));
 
-  /* If NAME is all slashes, arrange to return `/'.  */
-  if (*base == '\0' && ISSLASH (*name) && all_slashes)
-    --base;
+	  /* If the file name ends in slash, use the trailing slash as
+	     the basename if no non-slashes have been found.  */
+	  if (! *p)
+	    {
+	      if (ISSLASH (*base))
+		base = p - 1;
+	      break;
+	    }
 
-  /* Make sure the last byte is not a slash.  */
-  assert (all_slashes || !ISSLASH (*(p - 1)));
+	  /* *P is a non-slash preceded by a slash.  */
+	  base = p;
+	}
+    }
 
   return (char *) base;
 }
+
+/* Return the length of of the basename NAME.  Typically NAME is the
+   value returned by base_name.  Act like strlen (NAME), except omit
+   redundant trailing slashes.  */
+
+size_t
+base_len (char const *name)
+{
+  size_t len;
+
+  for (len = strlen (name);  1 < len && ISSLASH (name[len - 1]);  len--)
+    continue;
+
+  return len;
+}
