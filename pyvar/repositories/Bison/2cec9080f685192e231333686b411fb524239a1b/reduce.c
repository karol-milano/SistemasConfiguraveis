@@ -1,7 +1,7 @@
 /* Grammar reduction for Bison.
 
-   Copyright (C) 1988, 1989, 2000, 2001, 2002, 2003 Free Software
-   Foundation, Inc.
+   Copyright (C) 1988, 1989, 2000, 2001, 2002, 2003, 2005 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -27,6 +27,7 @@
 /* Don't eliminate unreachable terminals: They may be used by the
    user's parser.  */
 
+#include <config.h>
 #include "system.h"
 
 #include <bitset.h>
