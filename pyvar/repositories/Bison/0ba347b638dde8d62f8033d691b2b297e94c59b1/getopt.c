@@ -1,14 +1,10 @@
 /* Getopt for GNU.
-   NOTE: getopt is now part of the C library, so if you don't know what
-   "Keep this file name-space clean" means, talk to drepper@gnu.org
-   before changing it!
+   NOTE: The canonical source of this file is maintained with the GNU
+   C Library.  Bugs can be reported to bug-glibc@gnu.org.
 
-   Copyright (C) 1987, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98
+   Copyright (C) 1987, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99
    	Free Software Foundation, Inc.
 
-   NOTE: The canonical source of this file is maintained with the GNU C Library.
-   Bugs can be reported to bug-glibc@gnu.org.
-
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2, or (at your option) any
@@ -20,9 +16,8 @@
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
-   USA.  */
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 /* This tells Alpha OSF/1 not to define a getopt prototype in <stdio.h>.
    Ditto for AIX 3.2 and <stdlib.h>.  */
@@ -32,13 +27,13 @@
 
 #ifdef HAVE_CONFIG_H
 # include <config.h>
-#endif
-
-#if !defined __STDC__ || !__STDC__
+#else
+# if !defined __STDC__ || !__STDC__
 /* This is a separate conditional since some stdc systems
    reject `defined (const)'.  */
-# ifndef const
-#  define const
+#  ifndef const
+#   define const
+#  endif
 # endif
 #endif
 
@@ -112,7 +107,7 @@
    Also, when `ordering' is RETURN_IN_ORDER,
    each non-option ARGV-element is returned here.  */
 
-char *optarg = NULL;
+char *optarg;
 
 /* Index in ARGV of the next element to be scanned.
    This is used for communication to and from the caller
@@ -133,7 +128,7 @@ int optind = 1;
    causes problems with re-calling getopt as programs generally don't
    know that. */
 
-int __getopt_initialized = 0;
+int __getopt_initialized;
 
 /* The next char to be scanned in the option-element
    in which the last option character we returned was found.
@@ -698,16 +693,18 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	      else
 		{
 		  if (opterr)
-		   if (argv[optind - 1][1] == '-')
-		    /* --option */
-		    fprintf (stderr,
-		     _("%s: option `--%s' doesn't allow an argument\n"),
-		     argv[0], pfound->name);
-		   else
-		    /* +option or -option */
-		    fprintf (stderr,
-		     _("%s: option `%c%s' doesn't allow an argument\n"),
-		     argv[0], argv[optind - 1][0], pfound->name);
+		    {
+		      if (argv[optind - 1][1] == '-')
+			/* --option */
+			fprintf (stderr,
+				 _("%s: option `--%s' doesn't allow an argument\n"),
+				 argv[0], pfound->name);
+		      else
+			/* +option or -option */
+			fprintf (stderr,
+				 _("%s: option `%c%s' doesn't allow an argument\n"),
+				 argv[0], argv[optind - 1][0], pfound->name);
+		    }
 
 		  nextchar += strlen (nextchar);
 
