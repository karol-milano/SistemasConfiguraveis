@@ -1,7 +1,7 @@
 /* Top level entry point of Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002, 2004,
-   2005, 2006, 2007 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -62,6 +62,7 @@ main (int argc, char *argv[])
   (void) textdomain (PACKAGE);
 
   uniqstrs_new ();
+  muscle_init ();
 
   getargs (argc, argv);
 
@@ -72,8 +73,6 @@ main (int argc, char *argv[])
   if (trace_flag & trace_bitsets)
     bitset_stats_enable ();
 
-  muscle_init ();
-
   /* Read the input.  Copy some parts of it to FGUARD, FACTION, FTABLE
      and FATTRS.  In file reader.c.  The other parts are recorded in
      the grammar; see gram.h.  */
