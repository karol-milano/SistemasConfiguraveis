@@ -1,5 +1,5 @@
 /* Find and resolve or report look-ahead conflicts for bison,
-   Copyright (C) 1984, 1989 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1992 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -17,9 +17,6 @@ You should have received a copy of the GNU General Public License
 along with Bison; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
-#ifdef _AIX
- #pragma alloca
-#endif
 #include <stdio.h>
 #include "system.h"
 #include "machine.h"
@@ -29,19 +26,6 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #include "state.h"
 
 
-#ifndef __GNUC__
-#undef alloca
-#define alloca __builtin_alloca
-#else
-#ifdef HAVE_ALLOCA_H
-#include <alloca.h>
-#else
-#ifndef _AIX
-extern char *alloca ();
-#endif
-#endif
-#endif
-
 extern char **tags;
 extern int tokensetsize;
 extern char *consistent;
@@ -190,8 +174,7 @@ int lookaheadnum;
   register unsigned *fp1;
   register unsigned *fp2;
   register int redprec;
-  /* Extra parens avoid errors on Ultrix 4.3.  */
-  errs *errp = (errs *) alloca ((sizeof(errs) + ntokens * sizeof(short)));
+  errs *errp = (errs *) xmalloc (sizeof(errs) + ntokens * sizeof(short));
   short *errtokens = errp->errs;
 
   /* find the rule to reduce by to get precedence of reduction  */
@@ -276,6 +259,7 @@ int lookaheadnum;
     }
   else
     err_table[state] = 0;
+  free(errp);
 }
 
 
@@ -644,7 +628,7 @@ int state;
 	    fp3 = lookaheadset;
   
 	    while (fp3 < fp4)
-	      *fp3++ = *fp1++ & ( ~ (*fp2++));
+	      *fp3++ = *fp1++ & (~(*fp2++));
   
 	    count = 0;
 	    mask = 1;
