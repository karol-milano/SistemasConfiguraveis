@@ -1,22 +1,22 @@
 /* Top level entry point of bison,
-   Copyright (C) 1984, 1986, 1989, 1992, 1995 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000 Free Software Foundation, Inc.
 
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
 
 
 #include <stdio.h>
@@ -145,13 +145,22 @@ int_to_string (int i)
   return buf;
 }
 
+/* Display filename and lino if available.  */
+
 static void
-fatal_banner (void)
+banner (void)
 {
   if (infile == 0)
-    fprintf(stderr, _("%s: fatal error: "), program_name);
+    fprintf(stderr, "%s: ", program_name);
   else
-    fprintf(stderr, _("%s:%d: fatal error: "), infile, lineno);
+    fprintf(stderr, "%s:%d: ", infile, lineno);
+}
+
+static void
+fatal_banner (void)
+{
+  banner ();
+  fputs (_("fatal error: "), stderr);
 }
 
 /* Print the message S for a fatal error.  */
@@ -181,10 +190,7 @@ fatals (char *fmt, char *x1)
 static void
 warn_banner (void)
 {
-  if (infile == 0)
-    fprintf(stderr, _("%s: "), program_name);
-  else
-    fprintf(stderr, _("%s:%d: "), infile, lineno);
+  banner ();
   failure = 1;
 }
 
