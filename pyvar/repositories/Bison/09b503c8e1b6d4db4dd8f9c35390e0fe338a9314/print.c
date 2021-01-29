@@ -1,5 +1,5 @@
 /* Print information on generated parser, for bison,
-   Copyright 1984, 1986, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -29,6 +29,7 @@
 #include "state.h"
 #include "reader.h"
 #include "print.h"
+#include "reduce.h"
 
 #if 0
 static void
