@@ -1,5 +1,5 @@
 /* quote.c - quote arguments for output
-   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1998, 1999, 2000, 2001, 2003 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -21,23 +21,19 @@
 # include <config.h>
 #endif
 
-#if HAVE_STDDEF_H
-# include <stddef.h>  /* For the definition of size_t on windows w/MSVC.  */
-#endif
-#include <sys/types.h>
 #include "quotearg.h"
 #include "quote.h"
 
-/* Return an unambiguous printable representated, allocated in slot N,
-   for NAME, suitable for diagnostics.  */
+/* Return an unambiguous printable representation of NAME,
+   allocated in slot N, suitable for diagnostics.  */
 char const *
 quote_n (int n, char const *name)
 {
   return quotearg_n_style (n, locale_quoting_style, name);
 }
 
-/* Return an unambiguous printable representation of NAME, suitable
-   for diagnostics.  */
+/* Return an unambiguous printable representation of NAME,
+   suitable for diagnostics.  */
 char const *
 quote (char const *name)
 {
