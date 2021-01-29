@@ -1,5 +1,5 @@
 /* Implementation of gettext(3) function.
-   Copyright (C) 1995, 1997 Free Software Foundation, Inc.
+   Copyright (C) 1995, 1997, 2000, 2001 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -23,21 +23,14 @@
 # define __need_NULL
 # include <stddef.h>
 #else
-# ifdef STDC_HEADERS
-#  include <stdlib.h>		/* Just for NULL.  */
-# else
-#  ifdef HAVE_STRING_H
-#   include <string.h>
-#  else
-#   define NULL ((void *) 0)
-#  endif
-# endif
+# include <stdlib.h>		/* Just for NULL.  */
 #endif
 
+#include "gettextP.h"
 #ifdef _LIBC
 # include <libintl.h>
 #else
-# include "libgettext.h"
+# include "libgnuintl.h"
 #endif
 
 /* @@ end of prolog @@ */
@@ -48,10 +41,10 @@
    prefix.  So we have to make a difference here.  */
 #ifdef _LIBC
 # define GETTEXT __gettext
-# define DGETTEXT __dgettext
+# define DCGETTEXT __dcgettext
 #else
 # define GETTEXT gettext__
-# define DGETTEXT dgettext__
+# define DCGETTEXT dcgettext__
 #endif
 
 /* Look up MSGID in the current default message catalog for the current
@@ -61,7 +54,7 @@ char *
 GETTEXT (msgid)
      const char *msgid;
 {
-  return DGETTEXT (NULL, msgid);
+  return DCGETTEXT (NULL, msgid, LC_MESSAGES);
 }
 
 #ifdef _LIBC
