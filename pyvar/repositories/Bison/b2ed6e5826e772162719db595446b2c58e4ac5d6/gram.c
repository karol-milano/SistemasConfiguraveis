@@ -1,5 +1,5 @@
 /* Allocate input grammar variables for bison,
-   Copyright 1984, 1986, 1989 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2001 Free Software Foundation, Inc.
 
 This file is part of Bison, the GNU Compiler Compiler.
 
@@ -20,6 +20,7 @@ Boston, MA 02111-1307, USA.  */
 
 
 #include "system.h"
+#include "gram.h"
 
 void dummy PARAMS((void));
 
@@ -32,8 +33,7 @@ int ntokens;
 int nvars;
 
 short *ritem = NULL;
-short *rlhs = NULL;
-short *rrhs = NULL;
+rule_t *rule_table = NULL;
 short *rprec = NULL;
 short *rprecsym = NULL;
 short *sprec = NULL;
