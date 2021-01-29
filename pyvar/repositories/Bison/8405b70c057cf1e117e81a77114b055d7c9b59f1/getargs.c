@@ -1,7 +1,7 @@
 /* Parse command line arguments for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006 Free Software Foundation, Inc.
+   2005, 2006, 2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -70,6 +70,7 @@ int warnings_flag = warnings_none;
 static struct bison_language const valid_languages[] = {
   { "c", "c-skel.m4", ".c", ".h", true },
   { "c++", "c++-skel.m4", ".cc", ".hh", true },
+  { "java", "java-skel.m4", ".java", ".java", false },
   { "", "", "", "", false }
 };
 
