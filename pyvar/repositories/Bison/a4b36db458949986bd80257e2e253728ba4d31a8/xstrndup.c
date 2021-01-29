@@ -1,7 +1,4 @@
-/* Copyright (C) 1996, 1997, 1998, 2000 Free Software Foundation, Inc.
-
-   NOTE: The canonical source of this file is maintained with the GNU C Library.
-   Bugs can be reported to bug-glibc@prep.ai.mit.edu.
+/* Copyright (C) 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -17,20 +14,20 @@
    along with this program; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
-#ifdef HAVE_CONFIG_H
-# include "config.h"
+#if HAVE_CONFIG_H
+# include <config.h>
 #endif
 
-#include <stdio.h>
-#include <sys/types.h>
-
-#if defined _LIBC || defined STDC_HEADERS
-# include <stdlib.h>
+#if STDC_HEADERS || HAVE_STRING_H
 # include <string.h>
 #else
-char *malloc ();
+# include <strings.h>
 #endif
 
+#include <sys/types.h>
+
+#include "xalloc.h"
+
 #ifndef HAVE_DECL_STRNLEN
 "this configure-time declaration test was not run"
 #endif
@@ -38,18 +35,13 @@ char *malloc ();
 size_t strnlen ();
 #endif
 
-#undef __strndup
-#undef strndup
-
-#ifndef weak_alias
-# define __strndup strndup
-#endif
+char *xstrndup (const char *s, size_t n);
 
 char *
-__strndup (const char *s, size_t n)
+xstrndup (const char *s, size_t n)
 {
   size_t len = strnlen (s, n);
-  char *new = malloc (len + 1);
+  char *new = xmalloc (len + 1);
 
   if (new == NULL)
     return NULL;
@@ -57,6 +49,3 @@ __strndup (const char *s, size_t n)
   new[len] = '\0';
   return (char *) memcpy (new, s, len);
 }
-#ifdef weak_alias
-weak_alias (__strndup, strndup)
-#endif
