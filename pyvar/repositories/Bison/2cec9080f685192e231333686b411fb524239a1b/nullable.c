@@ -1,6 +1,6 @@
 /* Calculate which nonterminals can expand into the null string for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003, 2004 Free
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2003, 2004, 2005 Free
    Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -25,6 +25,7 @@
    the null string.  NULLABLE[I - NTOKENS] is nonzero if symbol I can
    do so.  */
 
+#include <config.h>
 #include "system.h"
 
 #include "getargs.h"
