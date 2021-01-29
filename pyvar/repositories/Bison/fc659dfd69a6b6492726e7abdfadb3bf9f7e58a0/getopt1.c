@@ -1,5 +1,5 @@
 /* getopt_long and getopt_long_only entry points for GNU getopt.
-   Copyright (C) 1987,88,89,90,91,92,93,94,96,97,98, 2002
+   Copyright (C) 1987,88,89,90,91,92,93,94,96,97,98
      Free Software Foundation, Inc.
    This file is part of the GNU C Library.
 
@@ -13,15 +13,28 @@
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
 
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software Foundation,
+   You should have received a copy of the GNU General Public License along
+   with this program; if not, write to the Free Software Foundation,
    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
 
 #ifdef HAVE_CONFIG_H
 #include <config.h>
 #endif
 
-#include "getopt.h"
+#ifdef _LIBC
+# include <getopt.h>
+#else
+# include "getopt.h"
+#endif
+
+#if !defined __STDC__ || !__STDC__
+/* This is a separate conditional since some stdc systems
+   reject `defined (const)'.  */
+#ifndef const
+#define const
+#endif
+#endif
+
 #include <stdio.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
@@ -80,6 +93,10 @@ getopt_long_only (argc, argv, options, long_options, opt_index)
   return _getopt_internal (argc, argv, options, long_options, opt_index, 1);
 }
 
+# ifdef _LIBC
+libc_hidden_def (getopt_long)
+libc_hidden_def (getopt_long_only)
+# endif
 
 #endif	/* Not ELIDE_CODE.  */
 
