@@ -1,6 +1,6 @@
 /* Subprocesses with pipes.
 
-   Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2004, 2005, 2006 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -71,6 +71,18 @@
 #include "gettext.h"
 #define _(Msgid)  gettext (Msgid)
 
+#ifndef __attribute__
+/* This feature is available in gcc versions 2.5 and later.  */
+# if !defined (__GNUC__) || __GNUC__ < 2 || \
+(__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
+#  define __attribute__(Spec) /* empty */
+# endif
+#endif
+
+#ifndef ATTRIBUTE_UNUSED
+# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
+#endif
+
 
 /* Initialize this module.  */
 
@@ -168,6 +180,7 @@ reap_subpipe (pid_t pid, char const *program)
 }
 
 void
-end_of_output_subpipe (pid_t pid, int fd[2])
+end_of_output_subpipe (pid_t pid ATTRIBUTE_UNUSED,
+		       int fd[2] ATTRIBUTE_UNUSED)
 {
 }
