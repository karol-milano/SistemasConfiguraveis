@@ -21,8 +21,14 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #include <stdio.h>
 #include "system.h"
 
+#if defined (__STDC__) || defined (_MSC_VER)
+extern void *calloc ();
+extern void *realloc ();
+#else
 extern char *calloc ();
 extern char *realloc ();
+#endif
+
 extern void done ();
 
 extern char *program_name;
