@@ -28,6 +28,7 @@ Boston, MA 02111-1307, USA.  */
 #include "alloc.h"
 #include "gram.h"
 #include "state.h"
+#include "complain.h"
 
 
 extern char *nullable;
@@ -58,7 +59,6 @@ void insert_start_shift PARAMS((void));
 extern void initialize_closure PARAMS((int));
 extern void closure PARAMS((short *, int));
 extern void finalize_closure PARAMS((void));
-extern void toomany PARAMS((char *));
 
 static core *this_state;
 static core *last_state;
@@ -374,7 +374,7 @@ new_state (int symbol)
 #endif
 
   if (nstates >= MAXSHORT)
-    toomany("states");
+    fatal (_("too many states (max %d)"), MAXSHORT);
 
   isp1 = kernel_base[symbol];
   iend = kernel_end[symbol];
