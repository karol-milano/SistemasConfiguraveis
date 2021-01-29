@@ -1,8 +1,5 @@
 /* Error handler for noninteractive utilities
-   Copyright (C) 1990-1998, 2000, 2001 Free Software Foundation, Inc.
-   This file is part of the GNU C Library.  Its master source is NOT part of
-   the C library, however.  The master source lives in /gd/gnu/lib.
-
+   Copyright (C) 1990-1998, 2000, 2001, 2002 Free Software Foundation, Inc.
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2, or (at your option)
@@ -13,8 +10,8 @@
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software Foundation,
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 /* Written by David MacKenzie <djm@gnu.ai.mit.edu>.  */
@@ -24,9 +21,14 @@
 #endif
 
 #include <stdio.h>
-#if HAVE_LIBINTL_H
+
+#ifdef _LIBC
 # include <libintl.h>
+#else
+# include "gettext.h"
 #endif
+#define _(msgid) gettext (msgid)
+
 #ifdef _LIBC
 # include <wchar.h>
 # define mbsrtowcs __mbsrtowcs
@@ -55,10 +57,6 @@ void exit ();
 #include "error.h"
 #include "unlocked-io.h"
 
-#ifndef _
-# define _(String) String
-#endif
-
 /* If NULL, error will flush stdout, then print on stderr the program
    name, a colon and a space.  Otherwise, error will call this
    function without parameters instead.  */
