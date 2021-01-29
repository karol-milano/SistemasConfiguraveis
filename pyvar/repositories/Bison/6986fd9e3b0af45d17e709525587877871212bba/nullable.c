@@ -1,5 +1,5 @@
 /* Part of the bison parser generator,
-   Copyright 1984, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -48,7 +48,7 @@ set_nullable (void)
   short *r1;
 
 #ifdef	TRACE
-  fprintf (stderr, _("Entering set_nullable"));
+  fprintf (stderr, "Entering set_nullable\n");
 #endif
 
   nullable = XCALLOC (char, nvars) - ntokens;
