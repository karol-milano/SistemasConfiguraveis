@@ -1,5 +1,5 @@
-/* Implementation of the dgettext(3) function
-   Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.
+/* Implementation of the dgettext(3) function.
+   Copyright (C) 1995-1997, 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -19,14 +19,13 @@
 # include <config.h>
 #endif
 
-#if defined HAVE_LOCALE_H || defined _LIBC
-# include <locale.h>
-#endif
+#include <locale.h>
 
+#include "gettextP.h"
 #ifdef _LIBC
 # include <libintl.h>
 #else
-# include "libgettext.h"
+# include "libgnuintl.h"
 #endif
 
 /* @@ end of prolog @@ */
