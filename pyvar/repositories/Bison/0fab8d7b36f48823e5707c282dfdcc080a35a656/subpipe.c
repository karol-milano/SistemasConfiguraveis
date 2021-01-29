@@ -100,27 +100,17 @@ pid_t
 create_subpipe (char const * const *argv, int fd[2])
 {
   int pipe_fd[2];
-  int from_in_fd;
-  int from_out_fd;
-  int to_in_fd;
-  int to_out_fd;
+  int child_fd[2];
   pid_t pid;
 
-  if (pipe (pipe_fd) != 0
-      || (to_in_fd = fd_safer (pipe_fd[0])) < 0
-      || (to_out_fd = fd_safer (pipe_fd[1])) < 0
+  if (pipe (child_fd) != 0
+      || (child_fd[0] = fd_safer (child_fd[0])) < 0
+      || (fd[0] = fd_safer (child_fd[1])) < 0
       || pipe (pipe_fd) != 0
-      || (from_in_fd = fd_safer (pipe_fd[0])) < 0
-      || (from_out_fd = fd_safer (pipe_fd[1])) < 0)
+      || (fd[1] = fd_safer (pipe_fd[0])) < 0
+      || (child_fd[1] = fd_safer (pipe_fd[1])) < 0)
     error (EXIT_FAILURE, errno, "pipe");
 
-  /* Save the local variables in the parent now, in case vfork
-     clobbers them.  */
-  fd[0] = to_out_fd;
-  fd[1] = from_in_fd;
-  pipe_fd[0] = to_in_fd;
-  pipe_fd[1] = from_out_fd;
-
   pid = vfork ();
   if (pid < 0)
     error (EXIT_FAILURE, errno, "fork");
@@ -128,12 +118,12 @@ create_subpipe (char const * const *argv, int fd[2])
   if (! pid)
     {
       /* Child.  */
-      close (to_out_fd);
-      close (from_in_fd);
-      dup2 (to_in_fd, STDIN_FILENO);
-      close (to_in_fd);
-      dup2 (from_out_fd, STDOUT_FILENO);
-      close (from_out_fd);
+      close (fd[0]);
+      close (fd[1]);
+      dup2 (child_fd[0], STDIN_FILENO);
+      close (child_fd[0]);
+      dup2 (child_fd[1], STDOUT_FILENO);
+      close (child_fd[1]);
 
       /* The cast to (char **) rather than (char * const *) is needed
 	 for portability to older hosts with a nonstandard prototype
@@ -144,8 +134,8 @@ create_subpipe (char const * const *argv, int fd[2])
     }
 
   /* Parent.  */
-  close (pipe_fd[0]);
-  close (pipe_fd[1]);
+  close (child_fd[0]);
+  close (child_fd[1]);
   return pid;
 }
 
