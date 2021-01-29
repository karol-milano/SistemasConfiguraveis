@@ -1,23 +1,25 @@
 /* Getopt for GNU.
-   NOTE: The canonical source of this file is maintained with the GNU
-   C Library.  Bugs can be reported to bug-glibc@gnu.org.
-
-   Copyright (C) 1987, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
+   NOTE: getopt is now part of the C library, so if you don't know what
+   "Keep this file name-space clean" means, talk to drepper@gnu.org
+   before changing it!
+   Copyright (C) 1987,88,89,90,91,92,93,94,95,96,98,99,2000,2001
    	Free Software Foundation, Inc.
+   This file is part of the GNU C Library.
 
-   This program is free software; you can redistribute it and/or modify it
-   under the terms of the GNU General Public License as published by the
-   Free Software Foundation; either version 2, or (at your option) any
-   later version.
+   The GNU C Library is free software; you can redistribute it and/or
+   modify it under the terms of the GNU Lesser General Public
+   License as published by the Free Software Foundation; either
+   version 2.1 of the License, or (at your option) any later version.
 
-   This program is distributed in the hope that it will be useful,
+   The GNU C Library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   Lesser General Public License for more details.
 
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software Foundation,
-   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
+   You should have received a copy of the GNU Lesser General Public
+   License along with the GNU C Library; if not, write to the Free
+   Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+   02111-1307 USA.  */
 
 /* This tells Alpha OSF/1 not to define a getopt prototype in <stdio.h>.
    Ditto for AIX 3.2 and <stdlib.h>.  */
@@ -27,13 +29,13 @@
 
 #ifdef HAVE_CONFIG_H
 # include <config.h>
-#else
-# if !defined __STDC__ || !__STDC__
+#endif
+
+#if !defined __STDC__ || !__STDC__
 /* This is a separate conditional since some stdc systems
    reject `defined (const)'.  */
-#  ifndef const
-#   define const
-#  endif
+# ifndef const
+#  define const
 # endif
 #endif
 
@@ -75,11 +77,12 @@
 #endif
 
 #ifndef _
-/* This is for other GNU distributions with internationalized messages.
-   When compiling libc, the _ macro is predefined.  */
-# ifdef HAVE_LIBINTL_H
+/* This is for other GNU distributions with internationalized messages.  */
+# if (HAVE_LIBINTL_H && ENABLE_NLS) || defined _LIBC
 #  include <libintl.h>
-#  define _(msgid)	gettext (msgid)
+#  ifndef _
+#   define _(msgid)	gettext (msgid)
+#  endif
 # else
 #  define _(msgid)	(msgid)
 # endif
@@ -250,11 +253,13 @@ static int last_nonopt;
 /* Bash 2.0 gives us an environment variable containing flags
    indicating ARGV elements that should not be considered arguments.  */
 
+#ifdef USE_NONOPTION_FLAGS
 /* Defined in getopt_init.c  */
 extern char *__getopt_nonoption_flags;
 
 static int nonoption_flags_max_len;
 static int nonoption_flags_len;
+#endif
 
 static int original_argc;
 static char *const *original_argv;
@@ -275,13 +280,17 @@ store_args_and_env (int argc, char *const *argv)
 text_set_element (__libc_subinit, store_args_and_env);
 # endif /* text_set_element */
 
-# define SWAP_FLAGS(ch1, ch2) \
+# ifdef USE_NONOPTION_FLAGS
+#  define SWAP_FLAGS(ch1, ch2) \
   if (nonoption_flags_len > 0)						      \
     {									      \
       char __tmp = __getopt_nonoption_flags[ch1];			      \
       __getopt_nonoption_flags[ch1] = __getopt_nonoption_flags[ch2];	      \
       __getopt_nonoption_flags[ch2] = __tmp;				      \
     }
+# else
+#  define SWAP_FLAGS(ch1, ch2)
+# endif
 #else	/* !_LIBC */
 # define SWAP_FLAGS(ch1, ch2)
 #endif	/* _LIBC */
@@ -313,7 +322,7 @@ exchange (argv)
      It leaves the longer segment in the right place overall,
      but it consists of two parts that need to be swapped next.  */
 
-#ifdef _LIBC
+#if defined _LIBC && defined USE_NONOPTION_FLAGS
   /* First make sure the handling of the `__getopt_nonoption_flags'
      string can work normally.  Our top argument must be in the range
      of the string.  */
@@ -417,7 +426,7 @@ _getopt_initialize (argc, argv, optstring)
   else
     ordering = PERMUTE;
 
-#ifdef _LIBC
+#if defined _LIBC && defined USE_NONOPTION_FLAGS
   if (posixly_correct == NULL
       && argc == original_argc && argv == original_argv)
     {
@@ -515,6 +524,13 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
      int *longind;
      int long_only;
 {
+  int print_errors = opterr;
+  if (optstring[0] == ':')
+    print_errors = 0;
+
+  if (argc < 1)
+    return -1;
+
   optarg = NULL;
 
   if (optind == 0 || !__getopt_initialized)
@@ -529,7 +545,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
      Either it does not have option syntax, or there is an environment flag
      from the shell indicating it is not an option.  The later information
      is only used when the used in the GNU libc.  */
-#ifdef _LIBC
+#if defined _LIBC && defined USE_NONOPTION_FLAGS
 # define NONOPTION_P (argv[optind][0] != '-' || argv[optind][1] == '\0'	      \
 		      || (optind < nonoption_flags_len			      \
 			  && __getopt_nonoption_flags[optind] == '1'))
@@ -664,14 +680,17 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		pfound = p;
 		indfound = option_index;
 	      }
-	    else
+	    else if (long_only
+		     || pfound->has_arg != p->has_arg
+		     || pfound->flag != p->flag
+		     || pfound->val != p->val)
 	      /* Second or later nonexact match found.  */
 	      ambig = 1;
 	  }
 
       if (ambig && !exact)
 	{
-	  if (opterr)
+	  if (print_errors)
 	    fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
 		     argv[0], argv[optind]);
 	  nextchar += strlen (nextchar);
@@ -692,7 +711,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		optarg = nameend + 1;
 	      else
 		{
-		  if (opterr)
+		  if (print_errors)
 		    {
 		      if (argv[optind - 1][1] == '-')
 			/* --option */
@@ -718,7 +737,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		optarg = argv[optind++];
 	      else
 		{
-		  if (opterr)
+		  if (print_errors)
 		    fprintf (stderr,
 			   _("%s: option `%s' requires an argument\n"),
 			   argv[0], argv[optind - 1]);
@@ -745,7 +764,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
       if (!long_only || argv[optind][1] == '-'
 	  || my_index (optstring, *nextchar) == NULL)
 	{
-	  if (opterr)
+	  if (print_errors)
 	    {
 	      if (argv[optind][1] == '-')
 		/* --option */
@@ -775,7 +794,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 
     if (temp == NULL || c == ':')
       {
-	if (opterr)
+	if (print_errors)
 	  {
 	    if (posixly_correct)
 	      /* 1003.2 specifies the format of this message.  */
@@ -809,7 +828,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	  }
 	else if (optind == argc)
 	  {
-	    if (opterr)
+	    if (print_errors)
 	      {
 		/* 1003.2 specifies the format of this message.  */
 		fprintf (stderr, _("%s: option requires an argument -- %c\n"),
@@ -858,7 +877,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	    }
 	if (ambig && !exact)
 	  {
-	    if (opterr)
+	    if (print_errors)
 	      fprintf (stderr, _("%s: option `-W %s' is ambiguous\n"),
 		       argv[0], argv[optind]);
 	    nextchar += strlen (nextchar);
@@ -876,7 +895,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		  optarg = nameend + 1;
 		else
 		  {
-		    if (opterr)
+		    if (print_errors)
 		      fprintf (stderr, _("\
 %s: option `-W %s' doesn't allow an argument\n"),
 			       argv[0], pfound->name);
@@ -891,7 +910,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		  optarg = argv[optind++];
 		else
 		  {
-		    if (opterr)
+		    if (print_errors)
 		      fprintf (stderr,
 			       _("%s: option `%s' requires an argument\n"),
 			       argv[0], argv[optind - 1]);
@@ -938,12 +957,12 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	      }
 	    else if (optind == argc)
 	      {
-		if (opterr)
+		if (print_errors)
 		  {
 		    /* 1003.2 specifies the format of this message.  */
 		    fprintf (stderr,
-			   _("%s: option requires an argument -- %c\n"),
-			   argv[0], c);
+			     _("%s: option requires an argument -- %c\n"),
+			     argv[0], c);
 		  }
 		optopt = c;
 		if (optstring[0] == ':')
