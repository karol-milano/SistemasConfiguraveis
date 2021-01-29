@@ -1,5 +1,8 @@
 /* hash - hashing table processing.
-   Copyright (C) 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
+
+   Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003 Free Software
+   Foundation, Inc.
+
    Written by Jim Meyering, 1992.
 
    This program is free software; you can redistribute it and/or modify
@@ -27,11 +30,25 @@
 #if HAVE_STDLIB_H
 # include <stdlib.h>
 #endif
+
 #if HAVE_STDBOOL_H
 # include <stdbool.h>
 #else
-typedef enum {false = 0, true = 1} bool;
+# ifndef __bool_true_false_are_defined
+#  if ! HAVE__BOOL
+#   ifdef __cplusplus
+typedef bool _Bool;
+#   else
+typedef unsigned char _Bool;
+#   endif
+#  endif
+#  define bool _Bool
+#  define false 0
+#  define true 1
+#  define __bool_true_false_are_defined 1
+# endif
 #endif
+
 #include <stdio.h>
 
 #ifndef HAVE_DECL_FREE
