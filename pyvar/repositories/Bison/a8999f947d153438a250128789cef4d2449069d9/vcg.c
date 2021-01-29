@@ -1,6 +1,6 @@
 /* VCG description handler for Bison.
 
-   Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -336,9 +336,10 @@ get_crossing_type_str (enum crossing_type crossing_type)
 static const char *
 get_view_str (enum view view)
 {
+  /* There is no way with vcg 1.30 to specify a normal view explicitly,
+     so it is an error here if view == normal_view.  */
   switch (view)
     {
-    case normal_view:	return "normal_view";
     case cfish:		return "cfish";
     case pfish:		return "pfish";
     case fcfish:	return "fcfish";
