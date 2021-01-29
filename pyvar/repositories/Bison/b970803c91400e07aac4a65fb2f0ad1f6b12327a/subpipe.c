@@ -1,6 +1,6 @@
 /* Subprocesses with pipes.
 
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2004 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -23,30 +23,16 @@
 # include <config.h>
 #endif
 
-#if HAVE_SYS_TYPES_H
-# include <sys/types.h>
-#endif
+#include "subpipe.h"
 
 #include <errno.h>
-#ifndef errno
-extern int errno;
-#endif
 
 #include <signal.h>
 #if ! defined SIGCHLD && defined SIGCLD
 # define SIGCHLD SIGCLD
 #endif
 
-#if HAVE_STDLIB_H
-# include <stdlib.h>
-#endif
-/* The following test is to work around the gross typo in
-   systems like Sony NEWS-OS Release 4.0C, whereby EXIT_FAILURE
-   is defined to 0, not 1.  */
-#if ! EXIT_FAILURE
-# undef EXIT_FAILURE
-# define EXIT_FAILURE 1
-#endif
+#include <stdlib.h>
 
 #if HAVE_UNISTD_H
 # include <unistd.h>
@@ -86,8 +72,6 @@ extern int errno;
 #include "gettext.h"
 #define _(Msgid)  gettext (Msgid)
 
-#include "subpipe.h"
-
 
 /* Initialize this module.  */
 
