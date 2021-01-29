@@ -1,5 +1,4 @@
-/* Handle list of needed message catalogs
-   Copyright (C) 1995, 1996, 1997 Free Software Foundation, Inc.
+/* Copyright (C) 1995-1999, 2000, 2001 Free Software Foundation, Inc.
    Contributed by Ulrich Drepper <drepper@gnu.ai.mit.edu>, 1995.
 
    This program is free software; you can redistribute it and/or modify
@@ -16,22 +15,18 @@
    along with this program; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
+/* Tell glibc's <string.h> to provide a prototype for stpcpy().
+   This must come before <config.h> because <config.h> may include
+   <features.h>, and once <features.h> has been included, it's too late.  */
+#ifndef _GNU_SOURCE
+# define _GNU_SOURCE	1
+#endif
+
 #ifdef HAVE_CONFIG_H
 # include <config.h>
 #endif
 
-
-#if defined HAVE_STRING_H || defined _LIBC
-# ifndef _GNU_SOURCE
-#  define _GNU_SOURCE	1
-# endif
-# include <string.h>
-#else
-# include <strings.h>
-# ifndef memcpy
-#  define memcpy(Dst, Src, Num) bcopy (Src, Dst, Num)
-# endif
-#endif
+#include <string.h>
 #if !HAVE_STRCHR && !defined _LIBC
 # ifndef strchr
 #  define strchr index
@@ -43,10 +38,7 @@
 #endif
 #include <ctype.h>
 #include <sys/types.h>
-
-#if defined STDC_HEADERS || defined _LIBC
-# include <stdlib.h>
-#endif
+#include <stdlib.h>
 
 #include "loadinfo.h"
 
@@ -224,7 +216,7 @@ _nl_make_l10nflist (l10nfile_list, dirlist, dirlist_len, mask, language,
 
   /* Construct file name.  */
   memcpy (abs_filename, dirlist, dirlist_len);
-  __argz_stringify (abs_filename, dirlist_len, ':');
+  __argz_stringify (abs_filename, dirlist_len, PATH_SEPARATOR);
   cp = abs_filename + (dirlist_len - 1);
   *cp++ = '/';
   cp = stpcpy (cp, language);
@@ -349,10 +341,11 @@ _nl_make_l10nflist (l10nfile_list, dirlist, dirlist_len, mask, language,
 
 /* Normalize codeset name.  There is no standard for the codeset
    names.  Normalization allows the user to use any of the common
-   names.  */
+   names.  The return value is dynamically allocated and has to be
+   freed by the caller.  */
 const char *
 _nl_normalize_codeset (codeset, name_len)
-     const unsigned char *codeset;
+     const char *codeset;
      size_t name_len;
 {
   int len = 0;
