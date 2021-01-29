@@ -1,7 +1,7 @@
 /* Open and close files for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -136,15 +136,6 @@ xfclose (FILE *ptr)
 | Compute ALL_BUT_EXT, ALL_BUT_TAB_EXT and output files extensions. |
 `------------------------------------------------------------------*/
 
-/* In the string S, replace all characters FROM by TO.  */
-static void
-tr (char *s, char from, char to)
-{
-  for (; *s; s++)
-    if (*s == from)
-      *s = to;
-}
-
 /* Compute extensions from the grammar file extension.  */
 static void
 compute_exts_from_gf (const char *ext)
