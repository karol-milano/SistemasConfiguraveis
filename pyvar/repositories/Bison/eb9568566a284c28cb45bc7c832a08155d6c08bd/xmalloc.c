@@ -1,5 +1,5 @@
 /* xmalloc.c -- malloc with out of memory checking
-   Copyright (C) 1990-1999, 2000 Free Software Foundation, Inc.
+   Copyright (C) 1990-1999, 2000, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -46,12 +46,12 @@ void free ();
 # define EXIT_FAILURE 1
 #endif
 
-#ifndef HAVE_DONE_WORKING_MALLOC_CHECK
-"you must run the autoconf test for a properly working malloc -- see malloc.m4"
+#ifndef HAVE_MALLOC
+"you must run the autoconf test for a properly working malloc"
 #endif
 
-#ifndef HAVE_DONE_WORKING_REALLOC_CHECK
-"you must run the autoconf test for a properly working realloc --see realloc.m4"
+#ifndef HAVE_REALLOC
+"you must run the autoconf test for a properly working realloc"
 #endif
 
 /* Exit value when the requested amount of memory is not available.
