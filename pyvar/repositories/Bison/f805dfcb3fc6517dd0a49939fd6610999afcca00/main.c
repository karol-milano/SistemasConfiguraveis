@@ -1,7 +1,7 @@
 /* Top level entry point of Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 1995, 2000, 2001, 2002, 2004,
-   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -35,6 +35,7 @@
 #include "getargs.h"
 #include "gram.h"
 #include "lalr.h"
+#include "ielr.h"
 #include "muscle_tab.h"
 #include "nullable.h"
 #include "output.h"
@@ -102,10 +103,10 @@ main (int argc, char *argv[])
   generate_states ();
   timevar_pop (TV_LR0);
 
-  /* make it deterministic.  In file lalr.  */
-  timevar_push (TV_LALR);
-  lalr ();
-  timevar_pop (TV_LALR);
+  /* Make it deterministic by computing lookahead sets.  Except when LALR(1) is
+     requested, split states to eliminate LR(1)-relative inadequacies.  In file
+     lalr and ielr.  */
+  ielr ();
 
   /* Find and record any conflicts: places where one token of
      lookahead is not enough to disambiguate the parsing.  In file
