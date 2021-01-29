@@ -1,6 +1,6 @@
 /* Subprocesses with pipes.
 
-   Copyright (C) 2005, 2006 Free Software Foundation, Inc.
+   Copyright (C) 2005, 2006, 2007, 2008 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -67,15 +67,26 @@ static char tmp_file_name[2][L_tmpnam];
 void
 init_subpipe(void)
 {
+  char *tmpdir;
   int fd;
 
-  strcpy(tmp_file_name[0], "/dev/env/TMPDIR/bnXXXXXX");
+  tmpdir = getenv("TMPDIR");
+  if (tmpdir == NULL)
+    tmpdir = getenv("TMP");
+  if (tmpdir == NULL)
+    tmpdir = getenv("TEMP");
+  if (access(tmpdir, D_OK))
+    tmpdir = ".";
+
+  strcpy(tmp_file_name[0], tmpdir);
+  strcat(tmp_file_name[0], "/bnXXXXXX");
   fd = mkstemp(tmp_file_name[0]);
   if (fd < 0)
     error(EXIT_FAILURE, 0, _("creation of a temporary file failed"));
   close (fd);
 
-  strcpy(tmp_file_name[1], "/dev/env/TMPDIR/bnXXXXXX");
+  strcpy(tmp_file_name[1], tmpdir);
+  strcat(tmp_file_name[1], "/bnXXXXXX");
   fd = mkstemp(tmp_file_name[1]);
   if (fd < 0)
     error(EXIT_FAILURE, 0, _("creation of a temporary file failed"));
