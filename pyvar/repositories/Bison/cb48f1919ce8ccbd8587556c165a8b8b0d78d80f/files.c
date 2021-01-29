@@ -1,7 +1,7 @@
 /* Open and close files for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005
-   Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
+   2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -24,16 +24,16 @@
 #include "system.h"
 
 #include <error.h>
+#include <dirname.h>
 #include <get-errno.h>
 #include <quote.h>
+#include <stdio-safer.h>
 #include <xstrndup.h>
 
 #include "complain.h"
-#include "dirname.h"
 #include "files.h"
 #include "getargs.h"
 #include "gram.h"
-#include "stdio-safer.h"
 
 struct obstack pre_prologue_obstack;
 struct obstack post_prologue_obstack;
@@ -208,7 +208,7 @@ static void
 file_name_split (const char *file_name,
 		 const char **base, const char **tab, const char **ext)
 {
-  *base = base_name (file_name);
+  *base = last_component (file_name);
 
   /* Look for the extension, i.e., look for the last dot. */
   *ext = strrchr (*base, '.');
