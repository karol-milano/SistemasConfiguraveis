@@ -1,6 +1,6 @@
 /* Open and close files for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -26,6 +26,7 @@
 #include <error.h>
 #include <get-errno.h>
 #include <quote.h>
+#include <xstrndup.h>
 
 #include "complain.h"
 #include "files.h"
