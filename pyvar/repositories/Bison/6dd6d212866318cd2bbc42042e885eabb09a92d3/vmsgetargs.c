@@ -1,19 +1,21 @@
 /* VMS version of getargs; Uses DCL command parsing.
-   Copyright (C) 1989 Free Software Foundation, Inc.
+   Copyright (C) 1989, 1992 Free Software Foundation, Inc.
 
-   This program is free software; you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2, or (at your option)
-   any later version.
+This file is part of Bison, the GNU Compiler Compiler.
 
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
+Bison is free software; you can redistribute it and/or modify
+it under the terms of the GNU General Public License as published by
+the Free Software Foundation; either version 2, or (at your option)
+any later version.
 
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
+Bison is distributed in the hope that it will be useful,
+but WITHOUT ANY WARRANTY; without even the implied warranty of
+MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+GNU General Public License for more details.
+
+You should have received a copy of the GNU General Public License
+along with Bison; see the file COPYING.  If not, write to
+the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 
 #include <ctype.h>
@@ -21,13 +23,16 @@
 #include "files.h"
 
 /*
- *	VMS version of getargs(): Uses DCL command parsing
+ *	VMS version of getargs: Uses DCL command parsing
  *		(argc and argv are ignored)
  */
 int verboseflag;
 int definesflag;
 int debugflag;
 int nolinesflag;
+extern int noparserflag;
+extern int toknumflag;
+extern int rawtoknumflag;
 extern int fixed_outfiles;
 extern char * version_string;
 
@@ -49,6 +54,9 @@ getargs(argc,argv)
   debugflag = 0;
   fixed_outfiles = 0;
   nolinesflag = 0;
+  noparserflag = 0;
+  toknumflag = 0;
+  rawtoknumflag = 0;
   /*
    *	Check for /VERBOSE qualifier
    */
@@ -70,6 +78,18 @@ getargs(argc,argv)
    *	Check for /NOLINES qualifier
    */
   if (cli_present("BISON$NOLINES")) nolinesflag = 1;
+  /*
+   *	Check for /NOPARSER qualifier
+   */
+  if (cli_present("BISON$NOPARSER")) noparserflag = 1;
+  /*
+   *	Check for /RAW qualifier
+   */
+  if (cli_present("BISON$RAW")) rawtoknumflag = 1;
+  /*
+   *	Check for /TOKEN_TABLE qualifier
+   */
+  if (cli_present("BISON$TOKEN_TABLE")) toknumflag = 1;
   /*
    *	Check for /DEBUG qualifier
    */
