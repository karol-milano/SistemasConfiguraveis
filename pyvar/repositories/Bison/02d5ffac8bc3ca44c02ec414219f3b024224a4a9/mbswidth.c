@@ -1,5 +1,5 @@
 /* Determine the number of screen columns needed for a string.
-   Copyright (C) 2000-2002 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -21,6 +21,15 @@
 # include <config.h>
 #endif
 
+/* Get mbstate_t, mbrtowc(), mbsinit(), wcwidth().  This must be
+   included before "mbswidth.h", because UnixWare 7.1.1 <wchar.h>
+   declares its own mbswidth and we want mbswidth.h's "#define
+   mbswidth gnu_mbswidth" to take effect after <wchar.h> is
+   included.  */
+#if HAVE_WCHAR_H
+# include <wchar.h>
+#endif
+
 /* Specification.  */
 #include "mbswidth.h"
 
@@ -32,11 +41,6 @@
 /* Get isprint().  */
 #include <ctype.h>
 
-/* Get mbstate_t, mbrtowc(), mbsinit(), wcwidth().  */
-#if HAVE_WCHAR_H
-# include <wchar.h>
-#endif
-
 /* Get iswprint(), iswcntrl().  */
 #if HAVE_WCTYPE_H
 # include <wctype.h>
