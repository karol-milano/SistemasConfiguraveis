@@ -1,21 +1,20 @@
 /* Find the length of STRING, but scan at most MAXLEN characters.
-   Copyright (C) 1996, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.
+   Copyright (C) 1996, 1997, 1998, 2000-2002 Free Software Foundation, Inc.
    This file is part of the GNU C Library.
 
-   The GNU C Library is free software; you can redistribute it and/or
-   modify it under the terms of the GNU Library General Public License as
-   published by the Free Software Foundation; either version 2 of the
-   License, or (at your option) any later version.
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-   The GNU C Library is distributed in the hope that it will be useful,
+   This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-   Library General Public License for more details.
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-   You should have received a copy of the GNU Library General Public
-   License along with the GNU C Library; see the file COPYING.LIB.  If not,
-   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #if HAVE_CONFIG_H
 # include <config.h>
@@ -25,7 +24,11 @@
 # if !STDC_HEADERS && HAVE_MEMORY_H
 #  include <memory.h>
 # endif
+/* Temporarily redefine strnlen so that an inconsistent prototype
+   (on at least AIX4.3.2.0 w/gcc-2.95.3) doesn't cause trouble.  */
+# define strnlen system_strnlen
 # include <string.h>
+# undef strnlen
 #else
 # include <strings.h>
 #endif
