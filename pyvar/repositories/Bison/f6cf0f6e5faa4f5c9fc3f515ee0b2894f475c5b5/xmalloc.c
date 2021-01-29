@@ -30,14 +30,9 @@ void *realloc ();
 void free ();
 #endif
 
-#if ENABLE_NLS
-# include <libintl.h>
-# define _(Text) gettext (Text)
-#else
-# define textdomain(Domain)
-# define _(Text) Text
-#endif
-#define N_(Text) Text
+#include "gettext.h"
+#define _(msgid) gettext (msgid)
+#define N_(msgid) msgid
 
 #include "error.h"
 #include "xalloc.h"
@@ -46,12 +41,14 @@ void free ();
 # define EXIT_FAILURE 1
 #endif
 
+/* The following tests require AC_PREREQ(2.54).  */
+
 #ifndef HAVE_MALLOC
-"you must run the autoconf test for a properly working malloc"
+"you must run the autoconf test for a GNU libc compatible malloc"
 #endif
 
 #ifndef HAVE_REALLOC
-"you must run the autoconf test for a properly working realloc"
+"you must run the autoconf test for a GNU libc compatible realloc"
 #endif
 
 /* Exit value when the requested amount of memory is not available.
