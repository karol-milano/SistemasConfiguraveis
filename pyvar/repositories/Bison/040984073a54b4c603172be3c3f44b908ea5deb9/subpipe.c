@@ -44,9 +44,7 @@
 # define STDOUT_FILENO 1
 #endif
 #if ! HAVE_DUP2 && ! defined dup2
-# if HAVE_FCNTL_H
-#  include <fcntl.h>
-# endif
+# include <fcntl.h>
 # define dup2(f, t) (close (t), fcntl (f, F_DUPFD, t))
 #endif
 
@@ -109,11 +107,13 @@ create_subpipe (char const * const *argv, int fd[2])
       || pipe (pipe_fd) != 0
       || (fd[1] = fd_safer (pipe_fd[0])) < 0
       || (child_fd[1] = fd_safer (pipe_fd[1])) < 0)
-    error (EXIT_FAILURE, errno, "pipe");
+    error (EXIT_FAILURE, errno,
+	   "pipe");
 
   pid = vfork ();
   if (pid < 0)
-    error (EXIT_FAILURE, errno, "fork");
+    error (EXIT_FAILURE, errno,
+	   "fork");
 
   if (! pid)
     {
@@ -148,7 +148,8 @@ reap_subpipe (pid_t pid, char const *program)
 #if HAVE_WAITPID || defined waitpid
   int wstatus;
   if (waitpid (pid, &wstatus, 0) < 0)
-    error (EXIT_FAILURE, errno, "waitpid");
+    error (EXIT_FAILURE, errno,
+	   "waitpid");
   else
     {
       int status = WIFEXITED (wstatus) ? WEXITSTATUS (wstatus) : -1;
