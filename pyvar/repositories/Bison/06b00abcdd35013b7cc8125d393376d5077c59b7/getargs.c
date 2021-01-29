@@ -1,5 +1,6 @@
 /* Parse command line arguments for bison.
-   Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -109,14 +110,13 @@ version (FILE *stream)
 {
   /* Some efforts were made to ease the translators' task, please
      continue.  */
-  fprintf (stream, _("\
-bison (GNU Bison) %s"), VERSION);
+  fprintf (stream, _("bison (GNU Bison) %s"), VERSION);
   putc ('\n', stream);
+  fputs (_("Written by Robert Corbett and Richard Stallman.\n"), stream);
   putc ('\n', stream);
 
-  fputs (_("\
-Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.\n"),
-	 stream);
+  fprintf (stream,
+	   _("Copyright (C) %d Free Software Foundation, Inc.\n"), 2002);
 
   fputs (_("\
 This is free software; see the source for copying conditions.  There is NO\n\
