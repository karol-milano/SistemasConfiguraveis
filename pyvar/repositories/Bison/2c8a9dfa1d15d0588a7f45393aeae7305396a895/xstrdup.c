@@ -1,5 +1,5 @@
 /* xstrdup.c -- copy a string with out of memory checking
-   Copyright (C) 1990, 1996, 1998 Free Software Foundation, Inc.
+   Copyright (C) 1990, 1996, 1998, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -19,14 +19,6 @@
 # include <config.h>
 #endif
 
-#ifndef PARAMS
-# if defined PROTOTYPES || (defined __STDC__ && __STDC__)
-#  define PARAMS(Args) Args
-# else
-#  define PARAMS(Args) ()
-# endif
-#endif
-
 #if STDC_HEADERS || HAVE_STRING_H
 # include <string.h>
 #else
@@ -35,7 +27,7 @@
 
 #include <sys/types.h>
 
-char *xmalloc PARAMS ((size_t n));
+#include "xalloc.h"
 
 /* Return a newly allocated copy of STRING.  */
 
