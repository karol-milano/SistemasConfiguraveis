@@ -1,5 +1,5 @@
 /* quotearg.c - quote arguments for output
-   Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.
+   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -21,6 +21,9 @@
 # include <config.h>
 #endif
 
+#if HAVE_STDDEF_H
+# include <stddef.h>  /* For the definition of size_t on windows w/MSVC.  */
+#endif
 #include <sys/types.h>
 #include <quotearg.h>
 #include <xalloc.h>
@@ -63,13 +66,7 @@
 # include <wchar.h>
 #endif
 
-#if HAVE_MBRTOWC
-size_t mbrtowc ();
-# ifdef mbstate_t
-#  define mbrtowc(pwc, s, n, ps) (mbrtowc) (pwc, s, n, 0)
-#  define mbsinit(ps) 1
-# endif
-#else
+#if !HAVE_MBRTOWC
 /* Disable multibyte processing entirely.  Since MB_CUR_MAX is 1, the
    other macros are defined only for documentation and to satisfy C
    syntax.  */
