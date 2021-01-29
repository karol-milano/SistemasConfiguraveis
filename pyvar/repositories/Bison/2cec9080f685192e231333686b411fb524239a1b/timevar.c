@@ -1,5 +1,5 @@
 /* Timing variables for measuring compiler performance.
-   Copyright (C) 2000, 2002, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2002, 2004, 2005 Free Software Foundation, Inc.
    Contributed by Alex Samuel <samuel@codesourcery.com>
 
 This file is part of Bison, the GNU Compiler Compiler.
@@ -19,9 +19,10 @@ along with Bison; see the file COPYING.  If not, write to the Free
 Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA
 02110-1301, USA.  */
 
+#include "config.h"
+
 #if IN_GCC
 
-#include "config.h"
 #include "system.h"
 #include "intl.h"
 #include "rtl.h"
