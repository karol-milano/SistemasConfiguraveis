@@ -4,6 +4,9 @@
 # include <config.h>
 #endif
 
+#if HAVE_STDDEF_H
+# include <stddef.h>  /* For the definition of size_t on windows w/MSVC.  */
+#endif
 #include <sys/types.h>
 #include <quotearg.h>
 #include <quote.h>
