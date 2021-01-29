@@ -1,52 +1,47 @@
 /* Open and close files for bison,
-   Copyright (C) 1984, 1986, 1989, 1992 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.
 
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
 
 
 #include "system.h"
 
 #if defined (VMS) & !defined (__VMS_POSIX)
-#include <ssdef.h>
-#define unlink delete
-#ifndef XPFILE
-#define XPFILE "GNU_BISON:[000000]BISON.SIMPLE"
-#endif
-#ifndef XPFILE1
-#define XPFILE1 "GNU_BISON:[000000]BISON.HAIRY"
-#endif
+# include <ssdef.h>
+# define unlink delete
+# ifndef XPFILE
+#  define XPFILE "GNU_BISON:[000000]BISON.SIMPLE"
+# endif
+# ifndef XPFILE1
+#  define XPFILE1 "GNU_BISON:[000000]BISON.HAIRY"
+# endif
 #endif
 
 #if defined (_MSC_VER)
-#ifndef XPFILE
-#define XPFILE "c:/usr/local/lib/bison.simple"
-#endif
-#ifndef XPFILE1
-#define XPFILE1 "c:/usr/local/lib/bison.hairy"
-#endif
-#endif
-
-#include <stdio.h>
-
-#ifdef HAVE_UNISTD_H
-#include <unistd.h>
+# ifndef XPFILE
+#  define XPFILE "c:/usr/local/lib/bison.simple"
+# endif
+# ifndef XPFILE1
+#  define XPFILE1 "c:/usr/local/lib/bison.hairy"
+# endif
 #endif
 
+#include "getargs.h"
 #include "files.h"
 #include "alloc.h"
 #include "gram.h"
@@ -76,8 +71,6 @@ static char *tmpattrsfile;
 static char *tmptabfile;
 static char *tmpdefsfile;
 
-extern int noparserflag;
-
 extern char	*mktemp();	/* So the compiler won't complain */
 extern char	*getenv();
 
@@ -88,8 +81,6 @@ extern void open_extra_files PARAMS((void));
 int fixed_outfiles = 0;
 
 extern char *program_name;
-extern int verboseflag;
-extern int definesflag;
 
 
 char *
