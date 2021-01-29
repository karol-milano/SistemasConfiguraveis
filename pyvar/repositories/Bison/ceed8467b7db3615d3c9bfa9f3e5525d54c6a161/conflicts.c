@@ -1,26 +1,25 @@
 /* Find and resolve or report look-ahead conflicts for bison,
-   Copyright (C) 1984, 1989, 1992 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1992, 2000 Free Software Foundation, Inc.
 
-This file is part of Bison, the GNU Compiler Compiler.
+   This file is part of Bison, the GNU Compiler Compiler.
 
-Bison is free software; you can redistribute it and/or modify
-it under the terms of the GNU General Public License as published by
-the Free Software Foundation; either version 2, or (at your option)
-any later version.
+   Bison is free software; you can redistribute it and/or modify it
+   under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-Bison is distributed in the hope that it will be useful,
-but WITHOUT ANY WARRANTY; without even the implied warranty of
-MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-GNU General Public License for more details.
+   Bison is distributed in the hope that it will be useful, but
+   WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   General Public License for more details.
 
-You should have received a copy of the GNU General Public License
-along with Bison; see the file COPYING.  If not, write to
-the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU General Public License
+   along with Bison; see the file COPYING.  If not, write to the Free
+   Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
+   02111-1307, USA.  */
 
-#include <stdio.h>
 #include "system.h"
-#include "machine.h"
+#include "getargs.h"
 #include "alloc.h"
 #include "files.h"
 #include "gram.h"
@@ -35,7 +34,6 @@ extern shifts **shift_table;
 extern unsigned *LA;
 extern short *LAruleno;
 extern short *lookaheads;
-extern int verboseflag;
 extern int fixed_outfiles;
 
 extern void initialize_conflicts PARAMS((void));
@@ -126,7 +124,7 @@ set_conflicts (int state)
 	fp1 = LA + i * tokensetsize;
 	fp2 = fp1;
 	fp3 = lookaheadset;
-  
+
 	while (fp3 < fp4)
 	  {
 	    if (*fp2++ & *fp3++)
@@ -323,7 +321,7 @@ conflict_log (void)
 
   total_conflicts();
 }
-  
+
 
 void
 verbose_conflict_log (void)
@@ -622,10 +620,10 @@ print_reductions (int state)
 	    fp1 = LA + i * tokensetsize;
 	    fp2 = shiftset;
 	    fp3 = lookaheadset;
-  
+
 	    while (fp3 < fp4)
 	      *fp3++ = *fp1++ & (~(*fp2++));
-  
+
 	    count = 0;
 	    mask = 1;
 	    fp3 = lookaheadset;
@@ -633,7 +631,7 @@ print_reductions (int state)
 	      {
 		if (mask & *fp3)
 		  count++;
-  
+
 		mask <<= 1;
 		if (mask == 0)
 		  {
@@ -641,17 +639,17 @@ print_reductions (int state)
 		    fp3++;
 		  }
 	      }
-  
+
 	    if (count > cmax)
 	      {
 		cmax = count;
 		default_LA = i;
 		default_rule = LAruleno[i];
 	      }
-  
+
 	    fp2 = shiftset;
 	    fp3 = lookaheadset;
-  
+
 	    while (fp3 < fp4)
 	      *fp2++ |= *fp3++;
 	  }
