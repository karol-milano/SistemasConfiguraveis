@@ -1,3 +1,20 @@
+/* quote.c - quote arguments for output
+   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
+
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
+
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
+
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+
 /* Written by Paul Eggert <eggert@twinsun.com> */
 
 #if HAVE_CONFIG_H
@@ -8,8 +25,8 @@
 # include <stddef.h>  /* For the definition of size_t on windows w/MSVC.  */
 #endif
 #include <sys/types.h>
-#include <quotearg.h>
-#include <quote.h>
+#include "quotearg.h"
+#include "quote.h"
 
 /* Return an unambiguous printable representated, allocated in slot N,
    for NAME, suitable for diagnostics.  */
