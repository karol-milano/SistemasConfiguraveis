@@ -1,5 +1,6 @@
 /* Declaration for error-reporting function for Bison.
-   Copyright (C) 2000, 2001, 2002, 2004 Free Software Foundation, Inc.
+
+   Copyright (C) 2000, 2001, 2002, 2004, 2005 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -19,6 +20,7 @@
 /* Based on error.c and error.h,
    written by David MacKenzie <djm@gnu.ai.mit.edu>.  */
 
+#include <config.h>
 #include "system.h"
 
 #include <stdarg.h>
