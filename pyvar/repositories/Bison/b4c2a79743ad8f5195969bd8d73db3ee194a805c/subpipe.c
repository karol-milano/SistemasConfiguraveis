@@ -113,19 +113,15 @@ create_subpipe (char const * const *argv, int fd[2])
   int child_fd[2];
   pid_t pid;
 
-  if (pipe (child_fd) != 0
-      || (child_fd[0] = fd_safer (child_fd[0])) < 0
-      || (fd[0] = fd_safer (child_fd[1])) < 0
-      || pipe (pipe_fd) != 0
-      || (fd[1] = fd_safer (pipe_fd[0])) < 0
-      || (child_fd[1] = fd_safer (pipe_fd[1])) < 0)
-    error (EXIT_FAILURE, errno,
-	   "pipe");
+  if (pipe_safer (child_fd) != 0 || pipe_safer (pipe_fd) != 0)
+    error (EXIT_FAILURE, errno, "pipe");
+  fd[0] = child_fd[1];
+  fd[1] = pipe_fd[0];
+  child_fd[1] = pipe_fd[1];
 
   pid = vfork ();
   if (pid < 0)
-    error (EXIT_FAILURE, errno,
-	   "fork");
+    error (EXIT_FAILURE, errno, "fork");
 
   if (! pid)
     {
@@ -160,8 +156,7 @@ reap_subpipe (pid_t pid, char const *program)
 #if HAVE_WAITPID || defined waitpid
   int wstatus;
   if (waitpid (pid, &wstatus, 0) < 0)
-    error (EXIT_FAILURE, errno,
-	   "waitpid");
+    error (EXIT_FAILURE, errno, "waitpid");
   else
     {
       int status = WIFEXITED (wstatus) ? WEXITSTATUS (wstatus) : -1;
