@@ -1,5 +1,5 @@
 /* dirname.c -- return all but the last element in a path
-   Copyright (C) 1990, 1998, 2000 Free Software Foundation, Inc.
+   Copyright 1990, 1998, 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -19,126 +19,43 @@
 # include <config.h>
 #endif
 
-#ifdef STDC_HEADERS
-# include <stdlib.h>
-#else
-char *malloc ();
-#endif
-#if defined STDC_HEADERS || defined HAVE_STRING_H
+#if STDC_HEADERS || HAVE_STRING_H
 # include <string.h>
-#else
-# include <strings.h>
-# ifndef strrchr
-#  define strrchr rindex
-# endif
-#endif
-#include <assert.h>
-
-#ifndef HAVE_DECL_MEMRCHR
-"this configure-time declaration test was not run"
-#endif
-#if !HAVE_DECL_MEMRCHR
-void *memrchr ();
 #endif
 
 #include "dirname.h"
+#include "xalloc.h"
 
-#ifndef FILESYSTEM_PREFIX_LEN
-# define FILESYSTEM_PREFIX_LEN(Filename) 0
-#endif
-
-#ifndef ISSLASH
-# define ISSLASH(C) ((C) == '/')
-#endif
-
-#define BACKSLASH_IS_PATH_SEPARATOR ISSLASH ('\\')
-
-/* Return the length of `dirname (PATH)' and set *RESULT to point
-   to PATH or to `"."', as appropriate.  Works properly even if
-   there are trailing slashes (by effectively ignoring them).
-   WARNING: This function doesn't work for cwd-relative names like
-   `a:foo' that are specified with a drive-letter prefix.  That case
-   is handled in the caller.  */
-static size_t
-dir_name_r (char const *path, char const **result)
+/* Return the length of `dirname (PATH)', or zero if PATH is
+   in the working directory.  Works properly even if
+   there are trailing slashes (by effectively ignoring them).  */
+size_t
+dir_len (char const *path)
 {
-  char const *slash;
-  size_t length;		/* Length of result, not including NUL.  */
-
-  slash = strrchr (path, '/');
-  if (BACKSLASH_IS_PATH_SEPARATOR)
-    {
-      char const *b = strrchr (path, '\\');
-      if (b && slash < b)
-	slash = b;
-    }
+  size_t prefix_length = FILESYSTEM_PREFIX_LEN (path);
+  size_t length;
 
-  /* If the last byte of PATH is a slash, decrement SLASH until it's
-     pointing at the leftmost in a sequence of trailing slashes.  */
-  if (slash && slash[1] == 0)
-    {
-      while (path < slash && ISSLASH (slash[-1]))
-	{
-	  --slash;
-	}
-
-      if (path < slash)
-	{
-	  size_t len = slash - path;
-	  slash = memrchr (path, '/', len);
-	  if (BACKSLASH_IS_PATH_SEPARATOR)
-	    {
-	      char const *b = memrchr (path, '\\', len);
-	      if (b && slash < b)
-		slash = b;
-	    }
-	}
-    }
-
-  if (slash == 0)
-    {
-      /* File is in the current directory.  */
-
-      length = FILESYSTEM_PREFIX_LEN (path);
-
-      if (length == 0)
-	{
-	  path = ".";
-	  length = 1;
-	}
-    }
-  else
-    {
-      /* Remove any trailing slashes from the result.  If we have a
-	 canonicalized "d:/path", leave alone the root case "d:/".  */
-      char const *lim = path + FILESYSTEM_PREFIX_LEN (path);
-
-      while (lim < slash && ISSLASH (*slash))
-	--slash;
+  /* Strip the basename and any redundant slashes before it.  */
+  for (length = base_name (path) - path;  prefix_length < length;  length--)
+    if (! ISSLASH (path[length - 1]))
+      return length;
 
-      length = slash - path + 1;
-    }
-
-  *result = path;
-  return length;
+  /* But don't strip the only slash from "/".  */
+  return prefix_length + ISSLASH (path[prefix_length]);
 }
 
 /* Return the leading directories part of PATH,
-   allocated with malloc.  If out of memory, return 0.
+   allocated with xmalloc.
    Works properly even if there are trailing slashes
    (by effectively ignoring them).  */
 
 char *
 dir_name (char const *path)
 {
-  char const *result;
-  size_t length = dir_name_r (path, &result);
-  int append_dot = (length && length == FILESYSTEM_PREFIX_LEN (newpath));
-  char *newpath = (char *) malloc (length + append_dot + 1);
-  if (newpath == 0)
-    return 0;
-  strncpy (newpath, result, length);
-  /* If PATH is "d:foo", return "d:.", the CWD on drive d:  */
+  size_t length = dir_len (path);
+  int append_dot = (length == FILESYSTEM_PREFIX_LEN (path));
+  char *newpath = xmalloc (length + append_dot + 1);
+  memcpy (newpath, path, length);
   if (append_dot)
     newpath[length++] = '.';
   newpath[length] = 0;
@@ -149,7 +66,8 @@ dir_name (char const *path)
 /*
 
 Run the test like this (expect no output):
-  gcc -DHAVE_CONFIG_H -DTEST_DIRNAME -I.. -O -Wall memrchr.c dirname.c
+  gcc -DHAVE_CONFIG_H -DTEST_DIRNAME -I.. -O -Wall \
+     basename.c dirname.c xmalloc.c
   sed -n '/^BEGIN-DATA$/,/^END-DATA$/p' dirname.c|grep -v DATA|./a.out
 
 BEGIN-DATA
@@ -165,7 +83,6 @@ END-DATA
 
 # define MAX_BUFF_LEN 1024
 # include <stdio.h>
-# include <stdlib.h>
 
 int
 main ()
@@ -183,7 +100,6 @@ main ()
       if (strcmp (result, expected_result))
 	printf ("%s: got %s, expected %s\n", path, result, expected_result);
     }
-  exit (0);
-
+  return 0;
 }
 #endif
