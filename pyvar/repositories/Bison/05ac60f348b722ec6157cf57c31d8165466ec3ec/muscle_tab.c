@@ -1,6 +1,7 @@
 /* Muscle table manager for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -163,7 +164,7 @@ void
 muscle_code_grow (const char *key, const char *val, location loc)
 {
   char *extension = NULL;
-  obstack_fgrow1 (&muscle_obstack, "]b4_syncline([[%d]], [[", loc.start.line);
+  obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, [[", loc.start.line);
   MUSCLE_OBSTACK_SGROW (&muscle_obstack,
 			quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, "]])[\n");
