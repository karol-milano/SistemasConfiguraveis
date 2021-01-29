@@ -60,7 +60,7 @@ static char tmp_file_name[2][L_tmpnam];
   do {                                                                \
     close ((fd));                                                     \
     if (unlink ((name)))                                              \
-      error (EXIT_FAILURE, 0, _("removing of `%s' failed"), (name));  \
+      error (EXIT_FAILURE, 0, _("removing of '%s' failed"), (name));  \
   } while (0)
 
 
@@ -231,17 +231,17 @@ end_of_output_subpipe(pid_t pid, int fd[2])
   {
     remove_tmp_file(STDIN_FILENO, tmp_file_name[0]);
     remove_tmp_file(STDOUT_FILENO, tmp_file_name[1]);
-    error(EXIT_FAILURE, 0, _("subsidiary program `%s' interrupted"), program);
+    error(EXIT_FAILURE, 0, _("subsidiary program '%s' interrupted"), program);
   }
   if (status)
   {
     remove_tmp_file(STDIN_FILENO, tmp_file_name[0]);
     remove_tmp_file(STDOUT_FILENO, tmp_file_name[1]);
     error(EXIT_FAILURE, 0, _(errno == ENOENT
-			     ? "subsidiary program `%s' not found"
+			     ? "subsidiary program '%s' not found"
 			     : status < 1
-			     ? "subsidiary program `%s' failed"
-			     : "subsidiary program `%s' failed (status=%i, errno=%i)"), program, status, errno);
+			     ? "subsidiary program '%s' failed"
+			     : "subsidiary program '%s' failed (status=%i, errno=%i)"), program, status, errno);
   }
 
 
@@ -283,9 +283,9 @@ reap_subpipe(pid_t pid, char const *program)
   free(arguments);
 
   if (unlink(tmp_file_name[0]))
-    error(EXIT_FAILURE, 0, _("removing of `%s' failed"), tmp_file_name[0]);
+    error(EXIT_FAILURE, 0, _("removing of '%s' failed"), tmp_file_name[0]);
   if (unlink(tmp_file_name[1]))
-    error(EXIT_FAILURE, 0, _("removing of `%s' failed"), tmp_file_name[1]);
+    error(EXIT_FAILURE, 0, _("removing of '%s' failed"), tmp_file_name[1]);
 
   if (dup2(old_stdin, STDIN_FILENO) < 0)
     error(EXIT_FAILURE, 0, "restore of bison's stdin failed");
