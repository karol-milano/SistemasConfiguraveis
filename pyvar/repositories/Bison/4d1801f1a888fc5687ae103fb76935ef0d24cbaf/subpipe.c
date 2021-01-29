@@ -114,6 +114,13 @@ create_subpipe (char const * const *argv, int fd[2])
       || (from_out_fd = fd_safer (pipe_fd[1])) < 0)
     error (EXIT_FAILURE, errno, "pipe");
 
+  /* Save the local variables in the parent now, in case vfork
+     clobbers them.  */
+  fd[0] = to_out_fd;
+  fd[1] = from_in_fd;
+  pipe_fd[0] = to_in_fd;
+  pipe_fd[1] = from_out_fd;
+
   pid = vfork ();
   if (pid < 0)
     error (EXIT_FAILURE, errno, "fork");
@@ -137,10 +144,8 @@ create_subpipe (char const * const *argv, int fd[2])
     }
 
   /* Parent.  */
-  close (to_in_fd);
-  close (from_out_fd);
-  fd[0] = to_out_fd;
-  fd[1] = from_in_fd;
+  close (pipe_fd[0]);
+  close (pipe_fd[1]);
   return pid;
 }
 
