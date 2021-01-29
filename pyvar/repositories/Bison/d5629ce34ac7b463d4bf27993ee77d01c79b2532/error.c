@@ -3,20 +3,19 @@
    This file is part of the GNU C Library.  Its master source is NOT part of
    the C library, however.  The master source lives in /gd/gnu/lib.
 
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
 
 /* Written by David MacKenzie <djm@gnu.ai.mit.edu>.  */
 
@@ -54,6 +53,7 @@ void exit ();
 #endif
 
 #include "error.h"
+#include "unlocked-io.h"
 
 #ifndef _
 # define _(String) String
