@@ -1,48 +1,45 @@
 /* Part of the bison parser generator,
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
 
 
-/* set up nullable, a vector saying which nonterminals can expand into
-   the null string.  nullable[i - ntokens] is nonzero if symbol i can
+/* Set up NULLABLE, a vector saying which nonterminals can expand into
+   the null string.  NULLABLE[I - NTOKENS] is nonzero if symbol I can
    do so.  */
 
 #include "system.h"
 #include "types.h"
 #include "gram.h"
 #include "alloc.h"
+#include "nullable.h"
 
-
-char *nullable;
-
-extern void free_nullable PARAMS((void));
-extern void set_nullable PARAMS((void));
+char *nullable = NULL;
 
 void
 set_nullable (void)
 {
-  register short *r;
-  register short *s1;
-  register short *s2;
-  register int ruleno;
-  register int symbol;
-  register shorts *p;
+  short *r;
+  short *s1;
+  short *s2;
+  int ruleno;
+  int symbol;
+  shorts *p;
 
   short *squeue;
   short *rcount;
@@ -52,20 +49,20 @@ set_nullable (void)
   short *r1;
 
 #ifdef	TRACE
-  fprintf(stderr, _("Entering set_nullable"));
+  fprintf (stderr, _("Entering set_nullable"));
 #endif
 
-  nullable = NEW2(nvars, char) - ntokens;
+  nullable = NEW2 (nvars, char) - ntokens;
 
-  squeue = NEW2(nvars, short);
+  squeue = NEW2 (nvars, short);
   s1 = s2 = squeue;
 
-  rcount = NEW2(nrules + 1, short);
-  rsets = NEW2(nvars, shorts *) - ntokens;
+  rcount = NEW2 (nrules + 1, short);
+  rsets = NEW2 (nvars, shorts *) - ntokens;
   /* This is said to be more elements than we actually use.
      Supposedly nitems - nrules is enough.
      But why take the risk?  */
-  relts = NEW2(nitems + nvars + 1, shorts);
+  relts = NEW2 (nitems + nvars + 1, shorts);
   p = relts;
 
   r = ritem;
@@ -86,7 +83,7 @@ set_nullable (void)
 	  any_tokens = 0;
 	  for (symbol = *r++; symbol > 0; symbol = *r++)
 	    {
-	      if (ISTOKEN(symbol))
+	      if (ISTOKEN (symbol))
 		any_tokens = 1;
 	    }
 
@@ -125,15 +122,15 @@ set_nullable (void)
 	}
     }
 
-  FREE(squeue);
-  FREE(rcount);
-  FREE(rsets + ntokens);
-  FREE(relts);
+  FREE (squeue);
+  FREE (rcount);
+  FREE (rsets + ntokens);
+  FREE (relts);
 }
 
 
 void
 free_nullable (void)
 {
-  FREE(nullable + ntokens);
+  FREE (nullable + ntokens);
 }
