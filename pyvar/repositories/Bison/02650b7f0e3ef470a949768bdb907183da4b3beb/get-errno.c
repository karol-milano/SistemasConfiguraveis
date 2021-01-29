@@ -1,6 +1,6 @@
-/* get-errno.h - get and set errno.
+/* get-errno.c - get and set errno.
 
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2006 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -18,7 +18,7 @@
 
 /* Written by Paul Eggert.  */
 
-#if HAVE_CONFIG_H
+#ifdef HAVE_CONFIG_H
 # include <config.h>
 #endif
 
