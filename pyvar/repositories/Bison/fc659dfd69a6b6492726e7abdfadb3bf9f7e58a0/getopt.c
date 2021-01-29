@@ -16,8 +16,8 @@
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software Foundation,
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 /* This tells Alpha OSF/1 not to define a getopt prototype in <stdio.h>.
@@ -30,6 +30,14 @@
 # include <config.h>
 #endif
 
+#if !defined __STDC__ || !__STDC__
+/* This is a separate conditional since some stdc systems
+   reject `defined (const)'.  */
+# ifndef const
+#  define const
+# endif
+#endif
+
 #include <stdio.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
@@ -51,12 +59,14 @@
 #ifndef ELIDE_CODE
 
 
-#if HAVE_STDLIB_H || defined __GNU_LIBRARY__
+/* This needs to come after some library #include
+   to get __GNU_LIBRARY__ defined.  */
+#ifdef	__GNU_LIBRARY__
+/* Don't include stdlib.h for non-GNU C libraries because some of them
+   contain conflicting prototypes for getopt.  */
 # include <stdlib.h>
-#endif
-#if HAVE_UNISTD_H || defined __GNU_LIBRARY__
 # include <unistd.h>
-#endif
+#endif	/* GNU C library.  */
 
 #ifdef VMS
 # include <unixlib.h>
@@ -65,16 +75,20 @@
 # endif
 #endif
 
-#ifndef _
+#ifdef _LIBC
+# include <libintl.h>
+#else
 /* This is for other GNU distributions with internationalized messages.  */
-# if (HAVE_LIBINTL_H && ENABLE_NLS) || defined _LIBC
-#  include <libintl.h>
-#  ifndef _
-#   define _(msgid)	gettext (msgid)
-#  endif
-# else
-#  define _(msgid)	(msgid)
-# endif
+# include "gettext.h"
+#endif
+#define _(msgid) gettext (msgid)
+
+#if defined _LIBC && defined USE_IN_LIBIO
+# include <wchar.h>
+#endif
+
+#ifndef attribute_hidden
+# define attribute_hidden
 #endif
 
 /* This version of `getopt' appears to the caller like standard Unix `getopt'
@@ -120,7 +134,7 @@ int optind = 1;
    causes problems with re-calling getopt as programs generally don't
    know that. */
 
-int __getopt_initialized;
+int __getopt_initialized attribute_hidden;
 
 /* The next char to be scanned in the option-element
    in which the last option character we returned was found.
@@ -179,18 +193,30 @@ static enum
 /* Value of POSIXLY_CORRECT environment variable.  */
 static char *posixly_correct;
 
-#if HAVE_STRING_H || defined __GNU_LIBRARY__
+#ifdef	__GNU_LIBRARY__
+/* We want to avoid inclusion of string.h with non-GNU libraries
+   because there are many ways it can cause trouble.
+   On some systems, it contains special magic macros that don't work
+   in GCC.  */
 # include <string.h>
+# define my_index	strchr
 #else
-# if HAVE_STRINGS_H
+
+# if HAVE_STRING_H
+#  include <string.h>
+# else
 #  include <strings.h>
 # endif
+
+/* Avoid depending on library functions or files
+   whose names are inconsistent.  */
+
+#ifndef getenv
+extern char *getenv ();
 #endif
 
-#if !HAVE_STRCHR && !defined strchr && !defined __GNU_LIBRARY__
-# define strchr my_strchr
 static char *
-strchr (str, chr)
+my_index (str, chr)
      const char *str;
      int chr;
 {
@@ -202,11 +228,20 @@ strchr (str, chr)
     }
   return 0;
 }
-#endif
 
-#if !HAVE_DECL_GETENV && !defined getenv && !defined __GNU_LIBRARY__
-char *getenv ();
-#endif
+/* If using GCC, we can safely declare strlen this way.
+   If not using GCC, it is ok not to declare it.  */
+#ifdef __GNUC__
+/* Note that Motorola Delta 68k R3V7 comes with GCC but not stddef.h.
+   That was relevant to code that was here before.  */
+# if (!defined __STDC__ || !__STDC__) && !defined strlen
+/* gcc with -traditional declares the built-in strlen to return int,
+   and has done so at least since version 2.4.5. -- rms.  */
+extern int strlen (const char *);
+# endif /* not __STDC__ */
+#endif /* __GNUC__ */
+
+#endif /* not __GNU_LIBRARY__ */
 
 /* Handle permutation of arguments.  */
 
@@ -218,35 +253,22 @@ static int first_nonopt;
 static int last_nonopt;
 
 #ifdef _LIBC
+/* Stored original parameters.
+   XXX This is no good solution.  We should rather copy the args so
+   that we can compare them later.  But we must not use malloc(3).  */
+extern int __libc_argc;
+extern char **__libc_argv;
+
 /* Bash 2.0 gives us an environment variable containing flags
    indicating ARGV elements that should not be considered arguments.  */
 
-#ifdef USE_NONOPTION_FLAGS
+# ifdef USE_NONOPTION_FLAGS
 /* Defined in getopt_init.c  */
 extern char *__getopt_nonoption_flags;
 
 static int nonoption_flags_max_len;
 static int nonoption_flags_len;
-#endif
-
-static int original_argc;
-static char *const *original_argv;
-
-/* Make sure the environment variable bash 2.0 puts in the environment
-   is valid for the getopt call we must make sure that the ARGV passed
-   to getopt is that one passed to the process.  */
-static void
-__attribute__ ((unused))
-store_args_and_env (int argc, char *const *argv)
-{
-  /* XXX This is no good solution.  We should rather copy the args so
-     that we can compare them later.  But we must not use malloc(3).  */
-  original_argc = argc;
-  original_argv = argv;
-}
-# ifdef text_set_element
-text_set_element (__libc_subinit, store_args_and_env);
-# endif /* text_set_element */
+# endif
 
 # ifdef USE_NONOPTION_FLAGS
 #  define SWAP_FLAGS(ch1, ch2) \
@@ -396,7 +418,7 @@ _getopt_initialize (argc, argv, optstring)
 
 #if defined _LIBC && defined USE_NONOPTION_FLAGS
   if (posixly_correct == NULL
-      && argc == original_argc && argv == original_argv)
+      && argc == __libc_argc && argv == __libc_argv)
     {
       if (nonoption_flags_max_len == 0)
 	{
@@ -615,7 +637,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 
   if (longopts != NULL
       && (argv[optind][1] == '-'
-	  || (long_only && (argv[optind][2] || !strchr (optstring, argv[optind][1])))))
+	  || (long_only && (argv[optind][2] || !my_index (optstring, argv[optind][1])))))
     {
       char *nameend;
       const struct option *p;
@@ -659,8 +681,26 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
       if (ambig && !exact)
 	{
 	  if (print_errors)
-	    fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
-		     argv[0], argv[optind]);
+	    {
+#if defined _LIBC && defined USE_IN_LIBIO
+	      char *buf;
+
+	      if (__asprintf (&buf, _("%s: option `%s' is ambiguous\n"),
+			      argv[0], argv[optind]) >= 0)
+		{
+
+		  if (_IO_fwide (stderr, 0) > 0)
+		    __fwprintf (stderr, L"%s", buf);
+		  else
+		    fputs (buf, stderr);
+
+		  free (buf);
+		}
+#else
+	      fprintf (stderr, _("%s: option `%s' is ambiguous\n"),
+		       argv[0], argv[optind]);
+#endif
+	    }
 	  nextchar += strlen (nextchar);
 	  optind++;
 	  optopt = 0;
@@ -681,16 +721,50 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		{
 		  if (print_errors)
 		    {
+#if defined _LIBC && defined USE_IN_LIBIO
+		      char *buf;
+		      int n;
+#endif
+
 		      if (argv[optind - 1][1] == '-')
-			/* --option */
-			fprintf (stderr,
-				 _("%s: option `--%s' doesn't allow an argument\n"),
-				 argv[0], pfound->name);
+			{
+			  /* --option */
+#if defined _LIBC && defined USE_IN_LIBIO
+			  n = __asprintf (&buf, _("\
+%s: option `--%s' doesn't allow an argument\n"),
+					  argv[0], pfound->name);
+#else
+			  fprintf (stderr, _("\
+%s: option `--%s' doesn't allow an argument\n"),
+				   argv[0], pfound->name);
+#endif
+			}
 		      else
-			/* +option or -option */
-			fprintf (stderr,
-				 _("%s: option `%c%s' doesn't allow an argument\n"),
-				 argv[0], argv[optind - 1][0], pfound->name);
+			{
+			  /* +option or -option */
+#if defined _LIBC && defined USE_IN_LIBIO
+			  n = __asprintf (&buf, _("\
+%s: option `%c%s' doesn't allow an argument\n"),
+					  argv[0], argv[optind - 1][0],
+					  pfound->name);
+#else
+			  fprintf (stderr, _("\
+%s: option `%c%s' doesn't allow an argument\n"),
+				   argv[0], argv[optind - 1][0], pfound->name);
+#endif
+			}
+
+#if defined _LIBC && defined USE_IN_LIBIO
+		      if (n >= 0)
+			{
+			  if (_IO_fwide (stderr, 0) > 0)
+			    __fwprintf (stderr, L"%s", buf);
+			  else
+			    fputs (buf, stderr);
+
+			  free (buf);
+			}
+#endif
 		    }
 
 		  nextchar += strlen (nextchar);
@@ -706,9 +780,27 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	      else
 		{
 		  if (print_errors)
-		    fprintf (stderr,
-			   _("%s: option `%s' requires an argument\n"),
-			   argv[0], argv[optind - 1]);
+		    {
+#if defined _LIBC && defined USE_IN_LIBIO
+		      char *buf;
+
+		      if (__asprintf (&buf, _("\
+%s: option `%s' requires an argument\n"),
+				      argv[0], argv[optind - 1]) >= 0)
+			{
+			  if (_IO_fwide (stderr, 0) > 0)
+			    __fwprintf (stderr, L"%s", buf);
+			  else
+			    fputs (buf, stderr);
+
+			  free (buf);
+			}
+#else
+		      fprintf (stderr,
+			       _("%s: option `%s' requires an argument\n"),
+			       argv[0], argv[optind - 1]);
+#endif
+		    }
 		  nextchar += strlen (nextchar);
 		  optopt = pfound->val;
 		  return optstring[0] == ':' ? ':' : '?';
@@ -730,18 +822,49 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	 option, then it's an error.
 	 Otherwise interpret it as a short option.  */
       if (!long_only || argv[optind][1] == '-'
-	  || strchr (optstring, *nextchar) == NULL)
+	  || my_index (optstring, *nextchar) == NULL)
 	{
 	  if (print_errors)
 	    {
+#if defined _LIBC && defined USE_IN_LIBIO
+	      char *buf;
+	      int n;
+#endif
+
 	      if (argv[optind][1] == '-')
-		/* --option */
-		fprintf (stderr, _("%s: unrecognized option `--%s'\n"),
-			 argv[0], nextchar);
+		{
+		  /* --option */
+#if defined _LIBC && defined USE_IN_LIBIO
+		  n = __asprintf (&buf, _("%s: unrecognized option `--%s'\n"),
+				  argv[0], nextchar);
+#else
+		  fprintf (stderr, _("%s: unrecognized option `--%s'\n"),
+			   argv[0], nextchar);
+#endif
+		}
 	      else
-		/* +option or -option */
-		fprintf (stderr, _("%s: unrecognized option `%c%s'\n"),
-			 argv[0], argv[optind][0], nextchar);
+		{
+		  /* +option or -option */
+#if defined _LIBC && defined USE_IN_LIBIO
+		  n = __asprintf (&buf, _("%s: unrecognized option `%c%s'\n"),
+				  argv[0], argv[optind][0], nextchar);
+#else
+		  fprintf (stderr, _("%s: unrecognized option `%c%s'\n"),
+			   argv[0], argv[optind][0], nextchar);
+#endif
+		}
+
+#if defined _LIBC && defined USE_IN_LIBIO
+	      if (n >= 0)
+		{
+		  if (_IO_fwide (stderr, 0) > 0)
+		    __fwprintf (stderr, L"%s", buf);
+		  else
+		    fputs (buf, stderr);
+
+		  free (buf);
+		}
+#endif
 	    }
 	  nextchar = (char *) "";
 	  optind++;
@@ -754,7 +877,7 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 
   {
     char c = *nextchar++;
-    char *temp = strchr (optstring, c);
+    char *temp = my_index (optstring, c);
 
     /* Increment `optind' when we start to process its last character.  */
     if (*nextchar == '\0')
@@ -764,13 +887,42 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
       {
 	if (print_errors)
 	  {
+#if defined _LIBC && defined USE_IN_LIBIO
+	      char *buf;
+	      int n;
+#endif
+
 	    if (posixly_correct)
-	      /* 1003.2 specifies the format of this message.  */
-	      fprintf (stderr, _("%s: illegal option -- %c\n"),
-		       argv[0], c);
+	      {
+		/* 1003.2 specifies the format of this message.  */
+#if defined _LIBC && defined USE_IN_LIBIO
+		n = __asprintf (&buf, _("%s: illegal option -- %c\n"),
+				argv[0], c);
+#else
+		fprintf (stderr, _("%s: illegal option -- %c\n"), argv[0], c);
+#endif
+	      }
 	    else
-	      fprintf (stderr, _("%s: invalid option -- %c\n"),
-		       argv[0], c);
+	      {
+#if defined _LIBC && defined USE_IN_LIBIO
+		n = __asprintf (&buf, _("%s: invalid option -- %c\n"),
+				argv[0], c);
+#else
+		fprintf (stderr, _("%s: invalid option -- %c\n"), argv[0], c);
+#endif
+	      }
+
+#if defined _LIBC && defined USE_IN_LIBIO
+	    if (n >= 0)
+	      {
+		if (_IO_fwide (stderr, 0) > 0)
+		  __fwprintf (stderr, L"%s", buf);
+		else
+		  fputs (buf, stderr);
+
+		free (buf);
+	      }
+#endif
 	  }
 	optopt = c;
 	return '?';
@@ -799,8 +951,24 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	    if (print_errors)
 	      {
 		/* 1003.2 specifies the format of this message.  */
+#if defined _LIBC && defined USE_IN_LIBIO
+		char *buf;
+
+		if (__asprintf (&buf,
+				_("%s: option requires an argument -- %c\n"),
+				argv[0], c) >= 0)
+		  {
+		    if (_IO_fwide (stderr, 0) > 0)
+		      __fwprintf (stderr, L"%s", buf);
+		    else
+		      fputs (buf, stderr);
+
+		    free (buf);
+		  }
+#else
 		fprintf (stderr, _("%s: option requires an argument -- %c\n"),
 			 argv[0], c);
+#endif
 	      }
 	    optopt = c;
 	    if (optstring[0] == ':')
@@ -846,8 +1014,25 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 	if (ambig && !exact)
 	  {
 	    if (print_errors)
-	      fprintf (stderr, _("%s: option `-W %s' is ambiguous\n"),
-		       argv[0], argv[optind]);
+	      {
+#if defined _LIBC && defined USE_IN_LIBIO
+		char *buf;
+
+		if (__asprintf (&buf, _("%s: option `-W %s' is ambiguous\n"),
+				argv[0], argv[optind]) >= 0)
+		  {
+		    if (_IO_fwide (stderr, 0) > 0)
+		      __fwprintf (stderr, L"%s", buf);
+		    else
+		      fputs (buf, stderr);
+
+		    free (buf);
+		  }
+#else
+		fprintf (stderr, _("%s: option `-W %s' is ambiguous\n"),
+			 argv[0], argv[optind]);
+#endif
+	      }
 	    nextchar += strlen (nextchar);
 	    optind++;
 	    return '?';
@@ -864,9 +1049,27 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		else
 		  {
 		    if (print_errors)
-		      fprintf (stderr, _("\
+		      {
+#if defined _LIBC && defined USE_IN_LIBIO
+			char *buf;
+
+			if (__asprintf (&buf, _("\
+%s: option `-W %s' doesn't allow an argument\n"),
+					argv[0], pfound->name) >= 0)
+			  {
+			    if (_IO_fwide (stderr, 0) > 0)
+			      __fwprintf (stderr, L"%s", buf);
+			    else
+			      fputs (buf, stderr);
+
+			    free (buf);
+			  }
+#else
+			fprintf (stderr, _("\
 %s: option `-W %s' doesn't allow an argument\n"),
-			       argv[0], pfound->name);
+				 argv[0], pfound->name);
+#endif
+		      }
 
 		    nextchar += strlen (nextchar);
 		    return '?';
@@ -879,9 +1082,27 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		else
 		  {
 		    if (print_errors)
-		      fprintf (stderr,
-			       _("%s: option `%s' requires an argument\n"),
-			       argv[0], argv[optind - 1]);
+		      {
+#if defined _LIBC && defined USE_IN_LIBIO
+			char *buf;
+
+			if (__asprintf (&buf, _("\
+%s: option `%s' requires an argument\n"),
+					argv[0], argv[optind - 1]) >= 0)
+			  {
+			    if (_IO_fwide (stderr, 0) > 0)
+			      __fwprintf (stderr, L"%s", buf);
+			    else
+			      fputs (buf, stderr);
+
+			    free (buf);
+			  }
+#else
+			fprintf (stderr,
+				 _("%s: option `%s' requires an argument\n"),
+				 argv[0], argv[optind - 1]);
+#endif
+		      }
 		    nextchar += strlen (nextchar);
 		    return optstring[0] == ':' ? ':' : '?';
 		  }
@@ -928,9 +1149,25 @@ _getopt_internal (argc, argv, optstring, longopts, longind, long_only)
 		if (print_errors)
 		  {
 		    /* 1003.2 specifies the format of this message.  */
+#if defined _LIBC && defined USE_IN_LIBIO
+		    char *buf;
+
+		    if (__asprintf (&buf, _("\
+%s: option requires an argument -- %c\n"),
+				    argv[0], c) >= 0)
+		      {
+			if (_IO_fwide (stderr, 0) > 0)
+			  __fwprintf (stderr, L"%s", buf);
+			else
+			  fputs (buf, stderr);
+
+			free (buf);
+		      }
+#else
 		    fprintf (stderr,
 			     _("%s: option requires an argument -- %c\n"),
 			     argv[0], c);
+#endif
 		  }
 		optopt = c;
 		if (optstring[0] == ':')
