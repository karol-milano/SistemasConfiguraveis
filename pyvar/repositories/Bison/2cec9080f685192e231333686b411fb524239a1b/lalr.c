@@ -1,6 +1,6 @@
 /* Compute look-ahead criteria for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003, 2004, 2005
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -25,6 +25,7 @@
    which rules need look-ahead in each state, and which look-ahead
    tokens they accept.  */
 
+#include <config.h>
 #include "system.h"
 
 #include <bitset.h>
