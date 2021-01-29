@@ -1,5 +1,5 @@
 /* xmalloc.c -- malloc with out of memory checking
-   Copyright (C) 1990-1997, 98, 99 Free Software Foundation, Inc.
+   Copyright (C) 1990-1999, 2000 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -63,7 +63,7 @@ void (*xalloc_fail_func) PARAMS ((void)) = 0;
 
 /* If XALLOC_FAIL_FUNC is NULL, or does return, display this message
    before exiting when memory is exhausted.  Goes through gettext. */
-char *const xalloc_msg_memory_exhausted = N_("Memory exhausted");
+char const xalloc_msg_memory_exhausted[] = N_("memory exhausted");
 
 void
 xalloc_die (void)
@@ -91,8 +91,7 @@ xmalloc (size_t n)
 }
 
 /* Change the size of an allocated block of memory P to N bytes,
-   with error checking.
-   If P is NULL, run xmalloc.  */
+   with error checking.  */
 
 void *
 xrealloc (void *p, size_t n)
