@@ -166,3 +166,8 @@ reap_subpipe (pid_t pid, char const *program)
     }
 #endif
 }
+
+void
+end_of_output_subpipe (pid_t pid, int fd[2])
+{
+}
