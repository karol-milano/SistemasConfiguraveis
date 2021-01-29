@@ -1,5 +1,5 @@
 /* argmatch.c -- find a match for a string in an array
-   Copyright (C) 1990, 1998, 1999, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1990, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -18,28 +18,23 @@
 /* Written by David MacKenzie <djm@ai.mit.edu>
    Modified by Akim Demaille <demaille@inf.enst.fr> */
 
+#if HAVE_CONFIG_H
+# include <config.h>
+#endif
+
 #include "argmatch.h"
 
 #include <stdio.h>
-#ifdef STDC_HEADERS
-# include <stdlib.h>
-# include <string.h>
-#endif
-
-#if HAVE_LOCALE_H
-# include <locale.h>
-#endif
+#include <stdlib.h>
+#include <string.h>
 
-#if ENABLE_NLS
-# include <libintl.h>
-# define _(Text) gettext (Text)
-#else
-# define _(Text) Text
-#endif
+#include "gettext.h"
+#define _(msgid) gettext (msgid)
 
 #include "error.h"
 #include "quotearg.h"
 #include "quote.h"
+#include "unlocked-io.h"
 
 /* When reporting an invalid argument, show nonprinting characters
    by using the quoting style ARGMATCH_QUOTING_STYLE.  Do not use
@@ -48,14 +43,6 @@
 # define ARGMATCH_QUOTING_STYLE locale_quoting_style
 #endif
 
-/* The following test is to work around the gross typo in
-   systems like Sony NEWS-OS Release 4.0C, whereby EXIT_FAILURE
-   is defined to 0, not 1.  */
-#if !EXIT_FAILURE
-# undef EXIT_FAILURE
-# define EXIT_FAILURE 1
-#endif
-
 /* Non failing version of argmatch call this function after failing. */
 #ifndef ARGMATCH_DIE
 # define ARGMATCH_DIE exit (EXIT_FAILURE)
