@@ -1,5 +1,5 @@
 /* dirname.c -- return all but the last element in a path
-   Copyright 1990, 1998, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1990, 1998, 2000, 2001, 2003 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -67,9 +67,13 @@ dir_name (char const *path)
 
 Run the test like this (expect no output):
   gcc -DHAVE_CONFIG_H -DTEST_DIRNAME -I.. -O -Wall \
-     basename.c dirname.c xmalloc.c
+     basename.c dirname.c xmalloc.c error.c
   sed -n '/^BEGIN-DATA$/,/^END-DATA$/p' dirname.c|grep -v DATA|./a.out
 
+If it's been built on a DOS or Windows platforms, run another test like
+this (again, expect no output):
+  sed -n '/^BEGIN-DOS-DATA$/,/^END-DOS-DATA$/p' dirname.c|grep -v DATA|./a.out
+
 BEGIN-DATA
 foo//// .
 bar/foo//// bar
@@ -79,16 +83,28 @@ foo/ .
 a .
 END-DATA
 
+BEGIN-DOS-DATA
+c:///// c:/
+c:/ c:/
+c:/. c:/
+c:foo c:.
+c:foo/bar c:foo
+END-DOS-DATA
+
 */
 
 # define MAX_BUFF_LEN 1024
 # include <stdio.h>
 
+char *program_name;
+
 int
-main ()
+main (int argc, char *argv[])
 {
   char buff[MAX_BUFF_LEN + 1];
 
+  program_name = argv[0];
+
   buff[MAX_BUFF_LEN] = 0;
   while (fgets (buff, MAX_BUFF_LEN, stdin) && buff[0])
     {
