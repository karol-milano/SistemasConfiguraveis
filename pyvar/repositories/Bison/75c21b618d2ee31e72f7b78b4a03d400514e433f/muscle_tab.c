@@ -1,7 +1,7 @@
 /* Muscle table manager for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2009 Free Software
-   Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -85,7 +85,6 @@ muscle_init (void)
 
   /* Version and input file.  */
   MUSCLE_INSERT_STRING ("version", VERSION);
-  MUSCLE_INSERT_C_STRING ("file_name", grammar_file);
 }
 
 