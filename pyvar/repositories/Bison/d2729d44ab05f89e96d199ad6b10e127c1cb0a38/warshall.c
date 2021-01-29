@@ -22,14 +22,14 @@ the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 #include "system.h"
 #include "machine.h"
 
+void RTC PARAMS((unsigned *, int));
+
 
 /* given n by n matrix of bits R, modify its contents
    to be the transive closure of what was given.  */
 
-void
-TC(R, n)
-unsigned *R;
-int n;
+static void
+TC (unsigned *R, int n)
 {
   register int rowsize;
   register unsigned mask;
@@ -87,9 +87,7 @@ int n;
    and then set all the bits on the diagonal of R.  */
 
 void
-RTC(R, n)
-unsigned *R;
-int n;
+RTC (unsigned *R, int n)
 {
   register int rowsize;
   register unsigned mask;
