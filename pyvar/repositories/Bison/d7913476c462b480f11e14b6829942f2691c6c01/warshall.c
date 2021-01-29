@@ -1,41 +1,39 @@
 /* Generate transitive closure of a matrix,
-   Copyright (C) 1984, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to
+   the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA 02111-1307, USA.  */
 
 
 #include "system.h"
+#include "warshall.h"
 
-void RTC PARAMS((unsigned *, int));
-
-
-/* given n by n matrix of bits R, modify its contents
-   to be the transive closure of what was given.  */
+/* Given n by n matrix of bits R, modify its contents to be the
+   transive closure of what was given.  */
 
 static void
 TC (unsigned *R, int n)
 {
-  register int rowsize;
-  register unsigned mask;
-  register unsigned *rowj;
-  register unsigned *rp;
-  register unsigned *rend;
-  register unsigned *ccol;
+  int rowsize;
+  unsigned mask;
+  unsigned *rowj;
+  unsigned *rp;
+  unsigned *rend;
+  unsigned *ccol;
 
   unsigned *relend;
   unsigned *cword;
@@ -88,10 +86,10 @@ TC (unsigned *R, int n)
 void
 RTC (unsigned *R, int n)
 {
-  register int rowsize;
-  register unsigned mask;
-  register unsigned *rp;
-  register unsigned *relend;
+  int rowsize;
+  unsigned mask;
+  unsigned *rp;
+  unsigned *relend;
 
   TC(R, n);
 
