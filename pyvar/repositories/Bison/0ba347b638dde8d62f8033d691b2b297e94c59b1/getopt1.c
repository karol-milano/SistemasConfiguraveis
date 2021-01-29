@@ -1,7 +1,6 @@
 /* getopt_long and getopt_long_only entry points for GNU getopt.
    Copyright (C) 1987,88,89,90,91,92,93,94,96,97,98
      Free Software Foundation, Inc.
-
    NOTE: The canonical source of this file is maintained with the GNU C Library.
    Bugs can be reported to bug-glibc@gnu.org.
 
@@ -16,16 +15,12 @@
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,
-   USA.  */
+   along with this program; if not, write to the Free Software Foundation,
+   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
-#endif
-
-#include "getopt.h"
-
+#else
 #if !defined __STDC__ || !__STDC__
 /* This is a separate conditional since some stdc systems
    reject `defined (const)'.  */
@@ -33,6 +28,9 @@
 #define const
 #endif
 #endif
+#endif
+
+#include "getopt.h"
 
 #include <stdio.h>
 
