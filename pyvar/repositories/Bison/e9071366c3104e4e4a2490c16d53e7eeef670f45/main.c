@@ -1,6 +1,7 @@
 /* Top level entry point of Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002, 2004, 2005
+   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002, 2004, 2005,
+   2006
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -169,7 +170,7 @@ main (int argc, char *argv[])
 
   /* The scanner memory cannot be released right after parsing, as it
      contains things such as user actions, prologue, epilogue etc.  */
-  scanner_free ();
+  gram_scanner_free ();
   muscle_free ();
   uniqstrs_free ();
   timevar_pop (TV_FREE);
