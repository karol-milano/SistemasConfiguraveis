@@ -24,9 +24,10 @@
 #include <configmake.h>
 #include <error.h>
 #include <get-errno.h>
+#include <pipe.h>
 #include <quotearg.h>
-#include <subpipe.h>
 #include <timevar.h>
+#include <wait-process.h>
 
 #include "complain.h"
 #include "files.h"
@@ -639,8 +640,9 @@ output_skeleton (void)
     aver (i <= ARRAY_CARDINALITY (argv));
   }
 
-  init_subpipe ();
-  pid = create_subpipe (argv, filter_fd);
+  /* The ugly cast is because gnulib gets the const-ness wrong.  */
+  pid = create_pipe_bidi ("m4", m4, (char **)(void*)argv, false, true,
+                          true, filter_fd);
   free (full_m4sugar);
   free (full_m4bison);
   free (full_skeleton);
@@ -648,7 +650,7 @@ output_skeleton (void)
   if (trace_flag & trace_muscles)
     muscles_output (stderr);
   {
-    FILE *out = fdopen (filter_fd[0], "w");
+    FILE *out = fdopen (filter_fd[1], "w");
     if (! out)
       error (EXIT_FAILURE, get_errno (),
              "fdopen");
@@ -658,14 +660,17 @@ output_skeleton (void)
 
   /* Read and process m4's output.  */
   timevar_push (TV_M4);
-  end_of_output_subpipe (pid, filter_fd);
-  in = fdopen (filter_fd[1], "r");
+  in = fdopen (filter_fd[0], "r");
   if (! in)
     error (EXIT_FAILURE, get_errno (),
 	   "fdopen");
   scan_skel (in);
+  /* scan_skel should have read all of M4's output.  Otherwise, when we
+     close the pipe, we risk letting M4 report a broken-pipe to the
+     Bison user.  */
+  aver (feof (in));
   xfclose (in);
-  reap_subpipe (pid, m4);
+  wait_subprocess (pid, "m4", false, false, true, true, NULL);
   timevar_pop (TV_M4);
 }
 
