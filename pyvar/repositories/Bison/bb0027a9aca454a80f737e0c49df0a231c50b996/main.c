@@ -1,5 +1,5 @@
 /* Top level entry point of bison,
-   Copyright 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -84,8 +84,8 @@ main (int argc, char *argv[])
   /* Record other info about the grammar.  In files derives and
      nullable.  */
   timevar_push (TV_SETS);
-  set_derives ();
-  set_nullable ();
+  derives_compute ();
+  nullable_compute ();
   timevar_pop (TV_SETS);
 
   /* Convert to nondeterministic finite state machine.  In file LR0.
@@ -99,6 +99,11 @@ main (int argc, char *argv[])
   lalr ();
   timevar_pop (TV_LALR);
 
+  timevar_push (TV_FREE);
+  nullable_free ();
+  derives_free ();
+  timevar_pop (TV_FREE);
+
   /* Find and record any conflicts: places where one token of
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
@@ -152,8 +157,6 @@ main (int argc, char *argv[])
   states_free ();
   reduce_free ();
   conflicts_free ();
-  free_nullable ();
-  free_derives ();
   grammar_free ();
 
   /* The scanner memory cannot be released right after parsing, as it
