@@ -1,29 +1,46 @@
 /* Timing variables for measuring compiler performance.
-   Copyright (C) 2000 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2002 Free Software Foundation, Inc.
    Contributed by Alex Samuel <samuel@codesourcery.com>
 
-This file is part of GCC.
+This file is part of Bison, the GNU Compiler Compiler.
 
-GCC is free software; you can redistribute it and/or modify it under
+Bison is free software; you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free
 Software Foundation; either version 2, or (at your option) any later
 version.
 
-GCC is distributed in the hope that it will be useful, but WITHOUT ANY
+Bison is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or
 FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 for more details.
 
 You should have received a copy of the GNU General Public License
-along with GCC; see the file COPYING.  If not, write to the Free
+along with Bison; see the file COPYING.  If not, write to the Free
 Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 02111-1307, USA.  */
 
+#if IN_GCC
+
 #include "config.h"
 #include "system.h"
 #include "intl.h"
 #include "rtl.h"
 
+#else
+
+/* This source file is taken from the GCC source code, with slight
+   modifications that are under control of the IN_GCC preprocessor
+   variable.  The !IN_GCC part of this file is specific to Bison.  */
+   
+# include "../src/system.h"
+# if HAVE_SYS_TIME_H
+#  include <sys/time.h>
+# endif
+int time_report = 0;
+
+#endif
+
+
 #ifdef HAVE_SYS_TIMES_H
 # include <sys/times.h>
 #endif
@@ -109,7 +126,9 @@ static float clocks_to_msec;
 #define CLOCKS_TO_MSEC (1 / (float)CLOCKS_PER_SEC)
 #endif
 
+#if IN_GCC
 #include "flags.h"
+#endif
 #include "timevar.h"
 
 /* See timevar.h for an explanation of timing variables.  */
@@ -193,12 +212,21 @@ get_time (now)
 #ifdef USE_TIMES
     struct tms tms;
     now->wall = times (&tms)  * ticks_to_msec;
+#if IN_GCC
     now->user = tms.tms_utime * ticks_to_msec;
     now->sys  = tms.tms_stime * ticks_to_msec;
+#else
+    now->user = (tms.tms_utime + tms.tms_cutime) * ticks_to_msec;
+    now->sys  = (tms.tms_stime + tms.tms_cstime) * ticks_to_msec;
+#endif
 #endif
 #ifdef USE_GETRUSAGE
     struct rusage rusage;
+#if IN_GCC
     getrusage (RUSAGE_SELF, &rusage);
+#else
+    getrusage (RUSAGE_CHILDREN, &rusage);
+#endif
     now->user = rusage.ru_utime.tv_sec + rusage.ru_utime.tv_usec * 1e-6;
     now->sys  = rusage.ru_stime.tv_sec + rusage.ru_stime.tv_usec * 1e-6;
 #endif
