@@ -1,7 +1,7 @@
 /* Input parser for Bison
 
-   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002, 2003
-   Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002, 2003,
+   2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -74,7 +74,7 @@ prologue_augment (const char *prologue, location loc)
   struct obstack *oout =
     !typed ? &pre_prologue_obstack : &post_prologue_obstack;
 
-  obstack_fgrow1 (oout, "]b4_syncline([[%d]], [[", loc.start.line);
+  obstack_fgrow1 (oout, "]b4_syncline(%d, [[", loc.start.line);
   MUSCLE_OBSTACK_SGROW (oout,
 			quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (oout, "]])[\n");
