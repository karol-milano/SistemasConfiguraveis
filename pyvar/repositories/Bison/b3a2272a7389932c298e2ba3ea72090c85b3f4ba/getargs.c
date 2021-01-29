@@ -1,7 +1,7 @@
 /* Parse command line arguments for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -56,8 +56,6 @@ bool no_lines_flag;
 bool token_table_flag;
 bool yacc_flag;	/* for -y */
 
-bool error_verbose = false;
-
 bool nondeterministic_parser = false;
 bool glr_parser = false;
 
