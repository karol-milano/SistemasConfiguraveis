@@ -1,6 +1,6 @@
 /* Open and close files for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004, 2005
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -95,7 +95,7 @@ xfopen (const char *name, const char *mode)
 {
   FILE *ptr;
 
-  ptr = fopen (name, mode);
+  ptr = fopen_safer (name, mode);
   if (!ptr)
     error (EXIT_FAILURE, get_errno (), _("cannot open file `%s'"), name);
 
