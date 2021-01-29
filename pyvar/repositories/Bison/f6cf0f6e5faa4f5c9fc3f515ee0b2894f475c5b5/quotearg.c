@@ -21,52 +21,19 @@
 # include <config.h>
 #endif
 
-#if HAVE_STDDEF_H
-# include <stddef.h>  /* For the definition of size_t on windows w/MSVC.  */
-#endif
-#include <sys/types.h>
 #include "quotearg.h"
+
 #include "xalloc.h"
 
 #include <ctype.h>
+#include <errno.h>
+#include <limits.h>
+#include <stdlib.h>
+#include <string.h>
 
-#if ENABLE_NLS
-# include <libintl.h>
-# define _(text) gettext (text)
-#else
-# define _(text) text
-#endif
-#define N_(text) text
-
-#if HAVE_LIMITS_H
-# include <limits.h>
-#endif
-#ifndef CHAR_BIT
-# define CHAR_BIT 8
-#endif
-#ifndef SIZE_MAX
-# define SIZE_MAX ((size_t) -1)
-#endif
-#ifndef UCHAR_MAX
-# define UCHAR_MAX ((unsigned char) -1)
-#endif
-#ifndef UINT_MAX
-# define UINT_MAX ((unsigned int) -1)
-#endif
-
-#if HAVE_C_BACKSLASH_A
-# define ALERT_CHAR '\a'
-#else
-# define ALERT_CHAR '\7'
-#endif
-
-#if HAVE_STDLIB_H
-# include <stdlib.h>
-#endif
-
-#if HAVE_STRING_H
-# include <string.h>
-#endif
+#include "gettext.h"
+#define _(msgid) gettext (msgid)
+#define N_(msgid) msgid
 
 #if HAVE_WCHAR_H
 
@@ -84,7 +51,7 @@
 # undef MB_CUR_MAX
 # define MB_CUR_MAX 1
 # define mbrtowc(pwc, s, n, ps) ((*(pwc) = *(s)) != 0)
-# define iswprint(wc) ISPRINT ((unsigned char) (wc))
+# define iswprint(wc) isprint ((unsigned char) (wc))
 # undef HAVE_MBSINIT
 #endif
 
@@ -101,17 +68,11 @@
 # endif
 #endif
 
-#define INT_BITS (sizeof (int) * CHAR_BIT)
-
-#if defined (STDC_HEADERS) || (!defined (isascii) && !defined (HAVE_ISASCII))
-# define IN_CTYPE_DOMAIN(c) 1
-#else
-# define IN_CTYPE_DOMAIN(c) isascii(c)
+#ifndef SIZE_MAX
+# define SIZE_MAX ((size_t) -1)
 #endif
 
-/* Undefine to protect against the definition in wctype.h of solaris2.6.   */
-#undef ISPRINT
-#define ISPRINT(c) (IN_CTYPE_DOMAIN (c) && isprint (c))
+#define INT_BITS (sizeof (int) * CHAR_BIT)
 
 struct quoting_options
 {
@@ -157,9 +118,10 @@ static struct quoting_options default_quoting_options;
 struct quoting_options *
 clone_quoting_options (struct quoting_options *o)
 {
-  struct quoting_options *p
-    = (struct quoting_options *) xmalloc (sizeof (struct quoting_options));
+  int e = errno;
+  struct quoting_options *p = xmalloc (sizeof *p);
   *p = *(o ? o : &default_quoting_options);
+  errno = e;
   return p;
 }
 
@@ -291,7 +253,7 @@ quotearg_buffer_restyled (char *buffer, size_t buffersize,
       break;
     }
 
-  for (i = 0;  ! (argsize == (size_t) -1 ? arg[i] == '\0' : i == argsize);  i++)
+  for (i = 0;  ! (argsize == SIZE_MAX ? arg[i] == '\0' : i == argsize);  i++)
     {
       unsigned char c;
       unsigned char esc;
@@ -344,7 +306,7 @@ quotearg_buffer_restyled (char *buffer, size_t buffersize,
 	    }
 	  break;
 
-	case ALERT_CHAR: esc = 'a'; goto c_escape;
+	case '\a': esc = 'a'; goto c_escape;
 	case '\b': esc = 'b'; goto c_escape;
 	case '\f': esc = 'f'; goto c_escape;
 	case '\n': esc = 'n'; goto c_and_shell_escape;
@@ -432,7 +394,7 @@ quotearg_buffer_restyled (char *buffer, size_t buffersize,
 	    if (unibyte_locale)
 	      {
 		m = 1;
-		printable = ISPRINT (c);
+		printable = isprint (c);
 	      }
 	    else
 	      {
@@ -441,7 +403,7 @@ quotearg_buffer_restyled (char *buffer, size_t buffersize,
 
 		m = 0;
 		printable = 1;
-		if (argsize == (size_t) -1)
+		if (argsize == SIZE_MAX)
 		  argsize = strlen (arg);
 
 		do
@@ -537,8 +499,11 @@ quotearg_buffer (char *buffer, size_t buffersize,
 		 struct quoting_options const *o)
 {
   struct quoting_options const *p = o ? o : &default_quoting_options;
-  return quotearg_buffer_restyled (buffer, buffersize, arg, argsize,
-				   p->style, p);
+  int e = errno;
+  size_t r = quotearg_buffer_restyled (buffer, buffersize, arg, argsize,
+				       p->style, p);
+  errno = e;
+  return r;
 }
 
 /* Use storage slot N to return a quoted version of argument ARG.
@@ -552,6 +517,8 @@ static char *
 quotearg_n_options (int n, char const *arg, size_t argsize,
 		    struct quoting_options const *options)
 {
+  int e = errno;
+
   /* Preallocate a slot 0 buffer, so that the caller can always quote
      one small component of a "memory exhausted" message in slot 0.  */
   static char slot0[256];
@@ -579,10 +546,10 @@ quotearg_n_options (int n, char const *arg, size_t argsize,
 
       if (slotvec == &slotvec0)
 	{
-	  slotvec = (struct slotvec *) xmalloc (sizeof *slotvec);
+	  slotvec = xmalloc (sizeof *slotvec);
 	  *slotvec = slotvec0;
 	}
-      slotvec = (struct slotvec *) xrealloc (slotvec, s);
+      slotvec = xrealloc (slotvec, s);
       memset (slotvec + nslots, 0, (n1 - nslots) * sizeof *slotvec);
       nslots = n1;
     }
@@ -599,6 +566,7 @@ quotearg_n_options (int n, char const *arg, size_t argsize,
 	quotearg_buffer (val, size, arg, argsize, options);
       }
 
+    errno = e;
     return val;
   }
 }
@@ -606,7 +574,7 @@ quotearg_n_options (int n, char const *arg, size_t argsize,
 char *
 quotearg_n (int n, char const *arg)
 {
-  return quotearg_n_options (n, arg, (size_t) -1, &default_quoting_options);
+  return quotearg_n_options (n, arg, SIZE_MAX, &default_quoting_options);
 }
 
 char *
@@ -629,7 +597,7 @@ char *
 quotearg_n_style (int n, enum quoting_style s, char const *arg)
 {
   struct quoting_options const o = quoting_options_from_style (s);
-  return quotearg_n_options (n, arg, (size_t) -1, &o);
+  return quotearg_n_options (n, arg, SIZE_MAX, &o);
 }
 
 char *
@@ -652,7 +620,7 @@ quotearg_char (char const *arg, char ch)
   struct quoting_options options;
   options = default_quoting_options;
   set_char_quoting (&options, ch, 1);
-  return quotearg_n_options (0, arg, (size_t) -1, &options);
+  return quotearg_n_options (0, arg, SIZE_MAX, &options);
 }
 
 char *
