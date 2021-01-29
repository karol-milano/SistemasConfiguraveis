@@ -1,27 +1,27 @@
 /* Compute look-ahead criteria for bison,
-   Copyright (C) 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000 Free Software Foundation, Inc.
 
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
 
 
 /* Compute how to make the finite state machine deterministic; find
    which rules need lookahead in each state, and which lookahead
-   tokens they accept. */
+   tokens they accept.  */
 
 #include "system.h"
 #include "types.h"
@@ -31,8 +31,7 @@ Boston, MA 02111-1307, USA.  */
 #include "complain.h"
 #include "lalr.h"
 #include "nullable.h"
-
-extern short **derives;
+#include "derives.h"
 
 int tokensetsize;
 short *lookaheads;
@@ -481,8 +480,7 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
 	i++;
     }
 
-  if (found == 0)
-    berror ("add_lookback_edge");
+  assert (found);
 
   sp = NEW (shorts);
   sp->next = lookback[i];
