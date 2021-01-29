@@ -1,6 +1,6 @@
 /* Subprocesses with pipes.
 
-   Copyright (C) 2002, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2004, 2005 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -68,6 +68,7 @@
 #endif
 
 #include "error.h"
+#include "unistd-safer.h"
 
 #include "gettext.h"
 #define _(Msgid)  gettext (Msgid)
@@ -105,15 +106,13 @@ create_subpipe (char const * const *argv, int fd[2])
   int to_out_fd;
   pid_t pid;
 
-  if (pipe (pipe_fd) != 0)
+  if (pipe (pipe_fd) != 0
+      || (to_in_fd = fd_safer (pipe_fd[0])) < 0
+      || (to_out_fd = fd_safer (pipe_fd[1])) < 0
+      || pipe (pipe_fd) != 0
+      || (from_in_fd = fd_safer (pipe_fd[0])) < 0
+      || (from_out_fd = fd_safer (pipe_fd[1])) < 0)
     error (EXIT_FAILURE, errno, "pipe");
-  to_in_fd = pipe_fd[0];
-  to_out_fd = pipe_fd[1];
-
-  if (pipe (pipe_fd) != 0)
-    error (EXIT_FAILURE, errno, "pipe");
-  from_in_fd = pipe_fd[0];
-  from_out_fd = pipe_fd[1];
 
   pid = vfork ();
   if (pid < 0)
@@ -124,23 +123,16 @@ create_subpipe (char const * const *argv, int fd[2])
       /* Child.  */
       close (to_out_fd);
       close (from_in_fd);
-
-      if (to_in_fd != STDIN_FILENO)
-	{
-	  dup2 (to_in_fd, STDIN_FILENO);
-	  close (to_in_fd);
-	}
-      if (from_out_fd != STDOUT_FILENO)
-	{
-	  dup2 (from_out_fd, STDOUT_FILENO);
-	  close (from_out_fd);
-	}
+      dup2 (to_in_fd, STDIN_FILENO);
+      close (to_in_fd);
+      dup2 (from_out_fd, STDOUT_FILENO);
+      close (from_out_fd);
 
       /* The cast to (char **) rather than (char * const *) is needed
 	 for portability to older hosts with a nonstandard prototype
 	 for execvp.  */
       execvp (argv[0], (char **) argv);
-    
+
       _exit (errno == ENOENT ? 127 : 126);
     }
 
