@@ -1,5 +1,6 @@
 /* Top level entry point of bison,
-   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,14 +20,11 @@
    Boston, MA 02111-1307, USA.  */
 
 
-#include <stdio.h>
 #include "system.h"
-#include "machine.h"	/* for MAXSHORT */
+#include "getargs.h"
 #include "files.h"
 #include "complain.h"
 
-extern	int verboseflag;
-
 #if 0                           /* XXX currently unused.  */
 /* Nonzero means failure has been detected; don't write a parser file.  */
 static int failure;
@@ -38,7 +36,6 @@ char *program_name;
 extern char *printable_version PARAMS((int));
 extern void berror PARAMS((const char *));
 
-extern void getargs PARAMS((int, char *[]));
 extern void openfiles PARAMS((void));
 extern void reader PARAMS((void));
 extern void reduce_grammar PARAMS((void));
