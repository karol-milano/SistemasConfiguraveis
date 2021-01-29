@@ -1,25 +1,24 @@
 /* Timing variables for measuring compiler performance.
-   Copyright (C) 2000, 2002, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2002, 2004, 2005, 2006 Free Software Foundation, Inc.
    Contributed by Alex Samuel <samuel@codesourcery.com>
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2 of the License, or
+   (at your option) any later version.
 
-Bison is free software; you can redistribute it and/or modify it under
-the terms of the GNU General Public License as published by the Free
-Software Foundation; either version 2, or (at your option) any later
-version.
+   This program is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-Bison is distributed in the hope that it will be useful, but WITHOUT ANY
-WARRANTY; without even the implied warranty of MERCHANTABILITY or
-FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
-for more details.
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to the Free
-Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
-02110-1301, USA.  */
-
-#include "config.h"
+#ifdef HAVE_CONFIG_H
+# include <config.h>
+#endif
 
 #if IN_GCC
 
@@ -448,7 +447,7 @@ timevar_print (fp)
      FILE *fp;
 {
   /* Only print stuff if we have some sort of time information.  */
-#if defined (HAVE_USER_TIME) || defined (HAVE_SYS_TIME) || defined (HAVE_WALL_TIME)
+#if defined HAVE_USER_TIME || defined HAVE_SYS_TIME || defined HAVE_WALL_TIME
   unsigned int /* timevar_id_t */ id;
   struct timevar_time_def *total = &timevars[TV_TOTAL].elapsed;
   struct timevar_time_def now;
@@ -489,7 +488,7 @@ timevar_print (fp)
 	continue;
 
       /* Don't print timing variables if we're going to get a row of
-         zeroes.  */
+	 zeroes.  */
       if (tv->elapsed.user < tiny
 	  && tv->elapsed.sys < tiny
 	  && tv->elapsed.wall < tiny)
