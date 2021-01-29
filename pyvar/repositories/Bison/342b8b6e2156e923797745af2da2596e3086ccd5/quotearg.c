@@ -63,6 +63,11 @@
 #endif
 
 #if HAVE_WCHAR_H
+
+/* BSD/OS 4.1 wchar.h requires FILE and struct tm to be declared.  */
+# include <stdio.h>
+# include <time.h>
+
 # include <wchar.h>
 #endif
 
@@ -73,8 +78,12 @@
 # undef MB_CUR_MAX
 # define MB_CUR_MAX 1
 # define mbrtowc(pwc, s, n, ps) ((*(pwc) = *(s)) != 0)
-# define mbsinit(ps) 1
 # define iswprint(wc) ISPRINT ((unsigned char) (wc))
+# undef HAVE_MBSINIT
+#endif
+
+#if !defined mbsinit && !HAVE_MBSINIT
+# define mbsinit(ps) 1
 #endif
 
 #ifndef iswprint
