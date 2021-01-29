@@ -19,6 +19,7 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 
 #include <stdio.h>
+#include "system.h"
 
 extern char *calloc ();
 extern char *realloc ();
@@ -38,7 +39,7 @@ xmalloc (n)
   block = calloc (n, 1);
   if (block == NULL)
     {
-      fprintf (stderr, "%s: memory exhausted\n", program_name);
+      fprintf (stderr, _("%s: memory exhausted\n"), program_name);
       done (1);
     }
 
@@ -56,7 +57,7 @@ xrealloc (block, n)
   block = realloc (block, n);
   if (block == NULL)
     {
-      fprintf (stderr, "%s: memory exhausted\n", program_name);
+      fprintf (stderr, _("%s: memory exhausted\n"), program_name);
       done (1);
     }
 
