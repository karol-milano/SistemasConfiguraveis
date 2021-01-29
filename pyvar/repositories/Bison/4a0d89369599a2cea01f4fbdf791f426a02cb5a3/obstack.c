@@ -1,26 +1,25 @@
 /* obstack.c - subroutines used implicitly by object stack macros
-   Copyright (C) 1988-1994,96,97,98,99,2000 Free Software Foundation, Inc.
-
+   Copyright (C) 1988-1994,96,97,98,99,2000,2001 Free Software Foundation, Inc.
    This file is part of the GNU C Library.  Its master source is NOT part of
    the C library, however.  The master source lives in /gd/gnu/lib.
 
    The GNU C Library is free software; you can redistribute it and/or
-   modify it under the terms of the GNU Library General Public License as
-   published by the Free Software Foundation; either version 2 of the
-   License, or (at your option) any later version.
+   modify it under the terms of the GNU Lesser General Public
+   License as published by the Free Software Foundation; either
+   version 2.1 of the License, or (at your option) any later version.
 
    The GNU C Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
-   Library General Public License for more details.
+   Lesser General Public License for more details.
 
-   You should have received a copy of the GNU Library General Public
-   License along with the GNU C Library; see the file COPYING.LIB.  If not,
-   write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU Lesser General Public
+   License along with the GNU C Library; if not, write to the Free
+   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307 USA.  */
 
 #ifdef HAVE_CONFIG_H
-#include <config.h>
+# include <config.h>
 #endif
 
 #include "obstack.h"
@@ -40,40 +39,43 @@
    files, it is simpler to just do this in the source for each such file.  */
 
 #include <stdio.h>		/* Random thing to get __GNU_LIBRARY__.  */
-#if !defined (_LIBC) && defined (__GNU_LIBRARY__) && __GNU_LIBRARY__ > 1
-#include <gnu-versions.h>
-#if _GNU_OBSTACK_INTERFACE_VERSION == OBSTACK_INTERFACE_VERSION
-#define ELIDE_CODE
-#endif
+#if !defined _LIBC && defined __GNU_LIBRARY__ && __GNU_LIBRARY__ > 1
+# include <gnu-versions.h>
+# if _GNU_OBSTACK_INTERFACE_VERSION == OBSTACK_INTERFACE_VERSION
+#  define ELIDE_CODE
+# endif
 #endif
 
+#if defined _LIBC && defined USE_IN_LIBIO
+# include <wchar.h>
+#endif
 
 #ifndef ELIDE_CODE
 
 
-#if defined (__STDC__) && __STDC__
-#define POINTER void *
-#else
-#define POINTER char *
-#endif
+# if defined __STDC__ && __STDC__
+#  define POINTER void *
+# else
+#  define POINTER char *
+# endif
 
 /* Determine default alignment.  */
 struct fooalign {char x; double d;};
-#define DEFAULT_ALIGNMENT  \
+# define DEFAULT_ALIGNMENT  \
   ((PTR_INT_TYPE) ((char *) &((struct fooalign *) 0)->d - (char *) 0))
 /* If malloc were really smart, it would round addresses to DEFAULT_ALIGNMENT.
    But in fact it might be less smart and round addresses to as much as
    DEFAULT_ROUNDING.  So we prepare for it to do that.  */
 union fooround {long x; double d;};
-#define DEFAULT_ROUNDING (sizeof (union fooround))
+# define DEFAULT_ROUNDING (sizeof (union fooround))
 
 /* When we copy a long block of data, this is the unit to do it with.
    On some machines, copying successive ints does not work;
    in such a case, redefine COPYING_UNIT to `long' (if that works)
    or `char' as a last resort.  */
-#ifndef COPYING_UNIT
-#define COPYING_UNIT int
-#endif
+# ifndef COPYING_UNIT
+#  define COPYING_UNIT int
+# endif
 
 
 /* The functions allocating more room by calling `obstack_chunk_alloc'
@@ -82,21 +84,21 @@ union fooround {long x; double d;};
    abort gracefully or use longjump - but shouldn't return.  This
    variable by default points to the internal function
    `print_and_abort'.  */
-#if defined (__STDC__) && __STDC__
+# if defined __STDC__ && __STDC__
 static void print_and_abort (void);
 void (*obstack_alloc_failed_handler) (void) = print_and_abort;
-#else
+# else
 static void print_and_abort ();
 void (*obstack_alloc_failed_handler) () = print_and_abort;
-#endif
+# endif
 
 /* Exit value used when `print_and_abort' is used.  */
-#if defined __GNU_LIBRARY__ || defined HAVE_STDLIB_H
-#include <stdlib.h>
-#endif
-#ifndef EXIT_FAILURE
-#define EXIT_FAILURE 1
-#endif
+# if defined __GNU_LIBRARY__ || defined HAVE_STDLIB_H
+#  include <stdlib.h>
+# endif
+# ifndef EXIT_FAILURE
+#  define EXIT_FAILURE 1
+# endif
 int obstack_exit_failure = EXIT_FAILURE;
 
 /* The non-GNU-C macros copy the obstack into this global variable
@@ -110,33 +112,33 @@ struct obstack *_obstack;
    For free, do not use ?:, since some compilers, like the MIPS compilers,
    do not allow (expr) ? void : void.  */
 
-#if defined (__STDC__) && __STDC__
-#define CALL_CHUNKFUN(h, size) \
+# if defined __STDC__ && __STDC__
+#  define CALL_CHUNKFUN(h, size) \
   (((h) -> use_extra_arg) \
    ? (*(h)->chunkfun) ((h)->extra_arg, (size)) \
    : (*(struct _obstack_chunk *(*) (long)) (h)->chunkfun) ((size)))
 
-#define CALL_FREEFUN(h, old_chunk) \
+#  define CALL_FREEFUN(h, old_chunk) \
   do { \
     if ((h) -> use_extra_arg) \
       (*(h)->freefun) ((h)->extra_arg, (old_chunk)); \
     else \
       (*(void (*) (void *)) (h)->freefun) ((old_chunk)); \
   } while (0)
-#else
-#define CALL_CHUNKFUN(h, size) \
+# else
+#  define CALL_CHUNKFUN(h, size) \
   (((h) -> use_extra_arg) \
    ? (*(h)->chunkfun) ((h)->extra_arg, (size)) \
    : (*(struct _obstack_chunk *(*) ()) (h)->chunkfun) ((size)))
 
-#define CALL_FREEFUN(h, old_chunk) \
+#  define CALL_FREEFUN(h, old_chunk) \
   do { \
     if ((h) -> use_extra_arg) \
       (*(h)->freefun) ((h)->extra_arg, (old_chunk)); \
     else \
       (*(void (*) ()) (h)->freefun) ((old_chunk)); \
   } while (0)
-#endif
+# endif
 
 
 /* Initialize an obstack H for use.  Specify chunk size SIZE (0 means default).
@@ -152,13 +154,13 @@ _obstack_begin (h, size, alignment, chunkfun, freefun)
      struct obstack *h;
      int size;
      int alignment;
-#if defined (__STDC__) && __STDC__
+# if defined __STDC__ && __STDC__
      POINTER (*chunkfun) (long);
      void (*freefun) (void *);
-#else
+# else
      POINTER (*chunkfun) ();
      void (*freefun) ();
-#endif
+# endif
 {
   register struct _obstack_chunk *chunk; /* points to new chunk */
 
@@ -181,13 +183,13 @@ _obstack_begin (h, size, alignment, chunkfun, freefun)
       size = 4096 - extra;
     }
 
-#if defined (__STDC__) && __STDC__
+# if defined __STDC__ && __STDC__
   h->chunkfun = (struct _obstack_chunk * (*)(void *, long)) chunkfun;
   h->freefun = (void (*) (void *, struct _obstack_chunk *)) freefun;
-#else
+# else
   h->chunkfun = (struct _obstack_chunk * (*)()) chunkfun;
   h->freefun = freefun;
-#endif
+# endif
   h->chunk_size = size;
   h->alignment_mask = alignment - 1;
   h->use_extra_arg = 0;
@@ -210,13 +212,13 @@ _obstack_begin_1 (h, size, alignment, chunkfun, freefun, arg)
      struct obstack *h;
      int size;
      int alignment;
-#if defined (__STDC__) && __STDC__
+# if defined __STDC__ && __STDC__
      POINTER (*chunkfun) (POINTER, long);
      void (*freefun) (POINTER, POINTER);
-#else
+# else
      POINTER (*chunkfun) ();
      void (*freefun) ();
-#endif
+# endif
      POINTER arg;
 {
   register struct _obstack_chunk *chunk; /* points to new chunk */
@@ -240,13 +242,13 @@ _obstack_begin_1 (h, size, alignment, chunkfun, freefun, arg)
       size = 4096 - extra;
     }
 
-#if defined(__STDC__) && __STDC__
+# if defined __STDC__ && __STDC__
   h->chunkfun = (struct _obstack_chunk * (*)(void *,long)) chunkfun;
   h->freefun = (void (*) (void *, struct _obstack_chunk *)) freefun;
-#else
+# else
   h->chunkfun = (struct _obstack_chunk * (*)()) chunkfun;
   h->freefun = freefun;
-#endif
+# endif
   h->chunk_size = size;
   h->alignment_mask = alignment - 1;
   h->extra_arg = arg;
@@ -341,11 +343,11 @@ _obstack_newchunk (h, length)
    This is here for debugging.
    If you use it in a program, you are probably losing.  */
 
-#if defined (__STDC__) && __STDC__
+# if defined __STDC__ && __STDC__
 /* Suppress -Wmissing-prototypes warning.  We don't want to declare this in
    obstack.h because it is just for debugging.  */
 int _obstack_allocated_p (struct obstack *h, POINTER obj);
-#endif
+# endif
 
 int
 _obstack_allocated_p (h, obj)
@@ -370,7 +372,7 @@ _obstack_allocated_p (h, obj)
 /* Free objects in obstack H, including OBJ and everything allocate
    more recently than OBJ.  If OBJ is zero, free everything in H.  */
 
-#undef obstack_free
+# undef obstack_free
 
 /* This function has two names with identical definitions.
    This is the first one, called from non-ANSI code.  */
@@ -456,37 +458,54 @@ _obstack_memory_used (h)
 }
 
 /* Define the error handler.  */
-#ifndef _
-# if defined HAVE_LIBINTL_H || defined _LIBC
-#  include <libintl.h>
-#  ifndef _
-#   define _(Str) gettext (Str)
+# ifndef _
+#  if (HAVE_LIBINTL_H && ENABLE_NLS) || defined _LIBC
+#   include <libintl.h>
+#   ifndef _
+#    define _(Str) gettext (Str)
+#   endif
+#  else
+#   define _(Str) (Str)
+#  endif
+# endif
+# if defined _LIBC && defined USE_IN_LIBIO
+#  include <libio/iolibio.h>
+#  define fputs(s, f) _IO_fputs (s, f)
+# endif
+
+# ifndef __attribute__
+/* This feature is available in gcc versions 2.5 and later.  */
+#  if __GNUC__ < 2 || (__GNUC__ == 2 && __GNUC_MINOR__ < 5)
+#   define __attribute__(Spec) /* empty */
 #  endif
-# else
-#  define _(Str) (Str)
 # endif
-#endif
-#if defined _LIBC && defined USE_IN_LIBIO
-# include <libio/iolibio.h>
-# define fputs(s, f) _IO_fputs (s, f)
-#endif
 
 static void
+__attribute__ ((noreturn))
 print_and_abort ()
 {
-  fputs (_("memory exhausted"), stderr);
-  fputc ('\n', stderr);
+  /* Don't change any of these strings.  Yes, it would be possible to add
+     the newline to the string and use fputs or so.  But this must not
+     happen because the "memory exhausted" message appears in other places
+     like this and the translation should be reused instead of creating
+     a very similar string which requires a separate translation.  */
+# if defined _LIBC && defined USE_IN_LIBIO
+  if (_IO_fwide (stderr, 0) > 0)
+    __fwprintf (stderr, L"%s\n", _("memory exhausted"));
+  else
+# endif
+    fprintf (stderr, "%s\n", _("memory exhausted"));
   exit (obstack_exit_failure);
 }
 
-#if 0
+# if 0
 /* These are now turned off because the applications do not use it
    and it uses bcopy via obstack_grow, which causes trouble on sysV.  */
 
 /* Now define the functional versions of the obstack macros.
    Define them to simply use the corresponding macros to do the job.  */
 
-#if defined (__STDC__) && __STDC__
+#  if defined __STDC__ && __STDC__
 /* These function definitions do not work with non-ANSI preprocessors;
    they won't pass through the macro names in parentheses.  */
 
@@ -597,8 +616,8 @@ POINTER (obstack_copy0) (obstack, address, length)
   return obstack_copy0 (obstack, address, length);
 }
 
-#endif /* __STDC__ */
+#  endif /* __STDC__ */
 
-#endif /* 0 */
+# endif /* 0 */
 
 #endif	/* !ELIDE_CODE */
