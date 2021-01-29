@@ -1,22 +1,24 @@
 /* obstack.c - subroutines used implicitly by object stack macros
-   Copyright (C) 1988-1994,96,97,98,99,2000,2001 Free Software Foundation, Inc.
+
+   Copyright (C) 1988-1994, 1996, 1997, 1998, 1999, 2000, 2001, 2002
+   Free Software Foundation, Inc.
+
    This file is part of the GNU C Library.  Its master source is NOT part of
    the C library, however.  The master source lives in /gd/gnu/lib.
 
-   The GNU C Library is free software; you can redistribute it and/or
-   modify it under the terms of the GNU Lesser General Public
-   License as published by the Free Software Foundation; either
-   version 2.1 of the License, or (at your option) any later version.
+   This program is free software; you can redistribute it and/or modify
+   it under the terms of the GNU General Public License as published by
+   the Free Software Foundation; either version 2, or (at your option)
+   any later version.
 
-   The GNU C Library is distributed in the hope that it will be useful,
+   This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-   Lesser General Public License for more details.
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+   GNU General Public License for more details.
 
-   You should have received a copy of the GNU Lesser General Public
-   License along with the GNU C Library; if not, write to the Free
-   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
-   02111-1307 USA.  */
+   You should have received a copy of the GNU General Public License
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #ifdef HAVE_CONFIG_H
 # include <config.h>
@@ -53,7 +55,7 @@
 #ifndef ELIDE_CODE
 
 
-# if defined __STDC__ && __STDC__
+# ifdef __STDC__
 #  define POINTER void *
 # else
 #  define POINTER char *
@@ -84,7 +86,7 @@ union fooround {long x; double d;};
    abort gracefully or use longjump - but shouldn't return.  This
    variable by default points to the internal function
    `print_and_abort'.  */
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
 static void print_and_abort (void);
 void (*obstack_alloc_failed_handler) (void) = print_and_abort;
 # else
@@ -112,7 +114,7 @@ struct obstack *_obstack;
    For free, do not use ?:, since some compilers, like the MIPS compilers,
    do not allow (expr) ? void : void.  */
 
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
 #  define CALL_CHUNKFUN(h, size) \
   (((h) -> use_extra_arg) \
    ? (*(h)->chunkfun) ((h)->extra_arg, (size)) \
@@ -154,7 +156,7 @@ _obstack_begin (h, size, alignment, chunkfun, freefun)
      struct obstack *h;
      int size;
      int alignment;
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
      POINTER (*chunkfun) (long);
      void (*freefun) (void *);
 # else
@@ -183,7 +185,7 @@ _obstack_begin (h, size, alignment, chunkfun, freefun)
       size = 4096 - extra;
     }
 
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
   h->chunkfun = (struct _obstack_chunk * (*)(void *, long)) chunkfun;
   h->freefun = (void (*) (void *, struct _obstack_chunk *)) freefun;
 # else
@@ -212,7 +214,7 @@ _obstack_begin_1 (h, size, alignment, chunkfun, freefun, arg)
      struct obstack *h;
      int size;
      int alignment;
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
      POINTER (*chunkfun) (POINTER, long);
      void (*freefun) (POINTER, POINTER);
 # else
@@ -242,7 +244,7 @@ _obstack_begin_1 (h, size, alignment, chunkfun, freefun, arg)
       size = 4096 - extra;
     }
 
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
   h->chunkfun = (struct _obstack_chunk * (*)(void *,long)) chunkfun;
   h->freefun = (void (*) (void *, struct _obstack_chunk *)) freefun;
 # else
@@ -343,7 +345,7 @@ _obstack_newchunk (h, length)
    This is here for debugging.
    If you use it in a program, you are probably losing.  */
 
-# if defined __STDC__ && __STDC__
+# if PROTOTYPES || (defined __STDC__ && __STDC__)
 /* Suppress -Wmissing-prototypes warning.  We don't want to declare this in
    obstack.h because it is just for debugging.  */
 int _obstack_allocated_p (struct obstack *h, POINTER obj);
@@ -505,7 +507,7 @@ print_and_abort ()
 /* Now define the functional versions of the obstack macros.
    Define them to simply use the corresponding macros to do the job.  */
 
-#  if defined __STDC__ && __STDC__
+#  if PROTOTYPES || (defined __STDC__ && __STDC__)
 /* These function definitions do not work with non-ANSI preprocessors;
    they won't pass through the macro names in parentheses.  */
 
@@ -616,7 +618,7 @@ POINTER (obstack_copy0) (obstack, address, length)
   return obstack_copy0 (obstack, address, length);
 }
 
-#  endif /* __STDC__ */
+#  endif /* PROTOTYPES || (defined __STDC__ && __STDC__) */
 
 # endif /* 0 */
 
