@@ -1,5 +1,5 @@
 /* Find the length of STRING, but scan at most MAXLEN characters.
-   Copyright (C) 1996, 1997, 1998, 2000-2002 Free Software Foundation, Inc.
+   Copyright (C) 1996, 1997, 1998, 2000-2003 Free Software Foundation, Inc.
    This file is part of the GNU C Library.
 
    The GNU C Library is free software; you can redistribute it and/or
@@ -20,16 +20,13 @@
 #if HAVE_CONFIG_H
 # include <config.h>
 #endif
+#undef strnlen
 
 #if HAVE_STRING_H
 # if !STDC_HEADERS && HAVE_MEMORY_H
 #  include <memory.h>
 # endif
-/* Temporarily redefine strnlen so that an inconsistent prototype
-   (on at least AIX4.3.2.0 w/gcc-2.95.3) doesn't cause trouble.  */
-# define strnlen system_strnlen
 # include <string.h>
-# undef strnlen
 #else
 # include <strings.h>
 #endif
@@ -44,6 +41,10 @@ char *memchr ();
 #undef __strnlen
 #undef strnlen
 
+#ifndef _LIBC
+# define strnlen rpl_strnlen
+#endif
+
 #ifndef weak_alias
 # define __strnlen strnlen
 #endif
