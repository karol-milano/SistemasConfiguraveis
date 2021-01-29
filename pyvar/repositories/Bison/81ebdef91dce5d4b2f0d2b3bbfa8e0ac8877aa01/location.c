@@ -19,15 +19,17 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
-#include "location.h"
+
 #include <quotearg.h>
 
-location_t const empty_location;
+#include "location.h"
+
+location const empty_location;
 
 /* Output to OUT the location LOC.
    Warning: it uses quotearg's slot 3.  */
 void
-location_print (FILE *out, location_t loc)
+location_print (FILE *out, location loc)
 {
   fprintf (out, "%s:%d.%d",
 	   quotearg_n_style (3, escape_quoting_style, loc.start.file),
