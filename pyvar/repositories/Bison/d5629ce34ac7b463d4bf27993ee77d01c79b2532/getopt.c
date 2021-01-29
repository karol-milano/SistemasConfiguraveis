@@ -2,24 +2,23 @@
    NOTE: getopt is now part of the C library, so if you don't know what
    "Keep this file name-space clean" means, talk to drepper@gnu.org
    before changing it!
-   Copyright (C) 1987,88,89,90,91,92,93,94,95,96,98,99,2000,2001
+   Copyright (C) 1987,88,89,90,91,92,93,94,95,96,98,99,2000,2001,2002
    	Free Software Foundation, Inc.
    This file is part of the GNU C Library.
 
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
 
 /* This tells Alpha OSF/1 not to define a getopt prototype in <stdio.h>.
    Ditto for AIX 3.2 and <stdlib.h>.  */
@@ -31,14 +30,6 @@
 # include <config.h>
 #endif
 
-#if !defined __STDC__ || !__STDC__
-/* This is a separate conditional since some stdc systems
-   reject `defined (const)'.  */
-# ifndef const
-#  define const
-# endif
-#endif
-
 #include <stdio.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
@@ -60,14 +51,12 @@
 #ifndef ELIDE_CODE
 
 
-/* This needs to come after some library #include
-   to get __GNU_LIBRARY__ defined.  */
-#ifdef	__GNU_LIBRARY__
-/* Don't include stdlib.h for non-GNU C libraries because some of them
-   contain conflicting prototypes for getopt.  */
+#if HAVE_STDLIB_H || defined __GNU_LIBRARY__
 # include <stdlib.h>
+#endif
+#if HAVE_UNISTD_H || defined __GNU_LIBRARY__
 # include <unistd.h>
-#endif	/* GNU C library.  */
+#endif
 
 #ifdef VMS
 # include <unixlib.h>
@@ -190,30 +179,18 @@ static enum
 /* Value of POSIXLY_CORRECT environment variable.  */
 static char *posixly_correct;
 
-#ifdef	__GNU_LIBRARY__
-/* We want to avoid inclusion of string.h with non-GNU libraries
-   because there are many ways it can cause trouble.
-   On some systems, it contains special magic macros that don't work
-   in GCC.  */
+#if HAVE_STRING_H || defined __GNU_LIBRARY__
 # include <string.h>
-# define my_index	strchr
 #else
-
-# if HAVE_STRING_H
-#  include <string.h>
-# else
+# if HAVE_STRINGS_H
 #  include <strings.h>
 # endif
-
-/* Avoid depending on library functions or files
-   whose names are inconsistent.  */
-
-#ifndef getenv
-extern char *getenv ();
 #endif
 
+#if !HAVE_STRCHR && !defined strchr && !defined __GNU_LIBRARY__
+# define strchr my_strchr
 static char *
-my_index (str, chr)
+strchr (str, chr)
      const char *str;
      int chr;
 {
@@ -225,20 +202,11 @@ my_index (str, chr)
     }
   return 0;
 }
+#endif
 
-/* If using GCC, we can safely declare strlen this way.
-   If not using GCC, it is ok not to declare it.  */
-#ifdef __GNUC__
-/* Note that Motorola Delta 68k R3V7 comes with GCC but not stddef.h.
-   That was relevant to code that was here before.  */
-# if (!defined __STDC__ || !__STDC__) && !defined strlen
-/* gcc with -traditional declares the built-in strlen to return int,
-   and has done so at least since version 2.4.5. -- rms.  */
-extern int strlen (const char *);
-# endif /* not __STDC__ */
-#endif /* __GNUC__ */
-
-#endif /* not __GNU_LIBRARY__ */
+#if !HAVE_DECL_GETENV && !defined getenv && !defined __GNU_LIBRARY__
+char *getenv ();
+#endif
 
 /* Handle permutation of arguments.  */
 
@@ -647,7 +615,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 
   if (longopts != NULL
       && (argv[optind][1] == '-'
-	  || (long_only && (argv[optind][2] || !my_index (optstring, argv[optind][1])))))
+	  || (long_only && (argv[optind][2] || !strchr (optstring, argv[optind][1])))))
     {
       char *nameend;
       const struct option *p;
@@ -762,7 +730,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	 option, then it's an error.
 	 Otherwise interpret it as a short option.  */
       if (!long_only || argv[optind][1] == '-'
-	  || my_index (optstring, *nextchar) == NULL)
+	  || strchr (optstring, *nextchar) == NULL)
 	{
 	  if (print_errors)
 	    {
@@ -786,7 +754,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 
   {
     char c = *nextchar++;
-    char *temp = my_index (optstring, c);
+    char *temp = strchr (optstring, c);
 
     /* Increment `optind' when we start to process its last character.  */
     if (*nextchar == '\0')
