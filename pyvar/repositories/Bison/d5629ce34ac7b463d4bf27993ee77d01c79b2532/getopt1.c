@@ -1,37 +1,27 @@
 /* getopt_long and getopt_long_only entry points for GNU getopt.
-   Copyright (C) 1987,88,89,90,91,92,93,94,96,97,98
+   Copyright (C) 1987,88,89,90,91,92,93,94,96,97,98, 2002
      Free Software Foundation, Inc.
    This file is part of the GNU C Library.
 
-   The GNU C Library is free software; you can redistribute it and/or
-   modify it under the terms of the GNU Lesser General Public
-   License as published by the Free Software Foundation; either
-   version 2.1 of the License, or (at your option) any later version.
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-   The GNU C Library is distributed in the hope that it will be useful,
+   This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-   Lesser General Public License for more details.
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-   You should have received a copy of the GNU Lesser General Public
-   License along with the GNU C Library; if not, write to the Free
-   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
-   02111-1307 USA.  */
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
 
 #include "getopt.h"
-
-#if !defined __STDC__ || !__STDC__
-/* This is a separate conditional since some stdc systems
-   reject `defined (const)'.  */
-#ifndef const
-#define const
-#endif
-#endif
-
 #include <stdio.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
