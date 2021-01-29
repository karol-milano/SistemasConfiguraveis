@@ -1,6 +1,6 @@
 /* Top level entry point of Bison.
 
-   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002, 2004
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -107,7 +107,7 @@ main (int argc, char *argv[])
   timevar_pop (TV_LALR);
 
   /* Find and record any conflicts: places where one token of
-     lookahead is not enough to disambiguate the parsing.  In file
+     look-ahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
   timevar_push (TV_CONFLICTS);
@@ -147,7 +147,7 @@ main (int argc, char *argv[])
   if (complaint_issued)
     goto finish;
 
-  /* Lookaheads are no longer needed. */
+  /* Look-ahead tokens are no longer needed. */
   timevar_push (TV_FREE);
   lalr_free ();
   timevar_pop (TV_FREE);
