@@ -1,7 +1,7 @@
 /* Output the generated parsing program for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -702,7 +702,6 @@ prepare (void)
   /* Flags. */
   MUSCLE_INSERT_BOOL ("debug_flag", debug_flag);
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
-  MUSCLE_INSERT_BOOL ("error_verbose_flag", error_verbose);
   MUSCLE_INSERT_BOOL ("glr_flag", glr_parser);
   MUSCLE_INSERT_BOOL ("locations_flag", locations_flag);
   MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
