@@ -22,13 +22,21 @@ Boston, MA 02111-1307, USA.  */
 #include <stdio.h>
 #include "system.h"
 
+#ifdef NEED_DECLARATION_CALLOC
 #if defined (__STDC__) || defined (_MSC_VER)
 extern void *calloc ();
-extern void *realloc ();
 #else
 extern char *calloc ();
+#endif
+#endif  /* NEED_DECLARATION_CALLOC */
+
+#ifdef NEED_DECLARATION_REALLOC
+#if defined (__STDC__) || defined (_MSC_VER)
+extern void *realloc ();
+#else
 extern char *realloc ();
 #endif
+#endif  /* NEED_DECLARATION_REALLOC */
 
 char *xmalloc PARAMS((register unsigned));
 char *xrealloc PARAMS((register char *, register unsigned));
