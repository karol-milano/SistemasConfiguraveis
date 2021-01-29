@@ -29,7 +29,8 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #include "state.h"
 
 
-#ifdef __GNUC__
+#ifndef __GNUC__
+#undef alloca
 #define alloca __builtin_alloca
 #else
 #ifdef HAVE_ALLOCA_H
