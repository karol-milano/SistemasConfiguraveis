@@ -29,11 +29,13 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #include "types.h"
 #include "gram.h"
 
+void set_derives PARAMS((void));
+void free_derives PARAMS((void));
 
 short **derives;
 
 void
-set_derives()
+set_derives (void)
 {
   register int i;
   register int lhs;
@@ -82,7 +84,7 @@ set_derives()
 }
 
 void
-free_derives()
+free_derives (void)
 {
   FREE(derives[ntokens]);
   FREE(derives + ntokens);
@@ -92,7 +94,8 @@ free_derives()
 
 #ifdef	DEBUG
 
-print_derives()
+void
+print_derives (void)
 {
   register int i;
   register short *sp;
@@ -115,4 +118,3 @@ print_derives()
 }
 
 #endif
-
