@@ -1,5 +1,7 @@
 /* argmatch.c -- find a match for a string in an array
-   Copyright (C) 1990, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.
+
+   Copyright (C) 1990, 1998, 1999, 2001, 2002, 2003 Free Software
+   Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -44,6 +46,10 @@
 # define ARGMATCH_QUOTING_STYLE locale_quoting_style
 #endif
 
+#ifndef EXIT_FAILURE
+# define EXIT_FAILURE 1
+#endif
+
 /* Non failing version of argmatch call this function after failing. */
 #ifndef ARGMATCH_DIE
 # define ARGMATCH_DIE exit (EXIT_FAILURE)
