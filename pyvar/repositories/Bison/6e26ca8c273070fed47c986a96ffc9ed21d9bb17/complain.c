@@ -1,5 +1,5 @@
 /* Declaration for error-reporting function for Bison.
-   Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2001, 2002, 2004 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
@@ -22,42 +22,14 @@
 #include "system.h"
 
 #include <stdarg.h>
-#if ! (HAVE_VPRINTF || defined vfprintf)
-# define vfprintf(stream, message, args) _doprnt (message, args, stream)
-#endif
 
 #include "complain.h"
 #include "files.h"
 
-#ifndef _
-# define _(String) String
-#endif
-
 /* The calling program should define program_name and set it to the
    name of the executing program.  */
 extern char *program_name;
 
-#if HAVE_STRERROR
-# ifndef HAVE_DECL_STRERROR
-"this configure-time declaration test was not run"
-# endif
-# if !HAVE_DECL_STRERROR && !defined strerror
-char *strerror (int);
-# endif
-#else
-static char *
-private_strerror (int errnum)
-{
-  extern char *sys_errlist[];
-  extern int sys_nerr;
-
-  if (errnum > 0 && errnum <= sys_nerr)
-    return _(sys_errlist[errnum]);
-  return _("Unknown system error");
-}
-# define strerror private_strerror
-#endif /* HAVE_STRERROR */
-
 /* This variable is set each time `warn' is called.  */
 bool warning_issued;
 
