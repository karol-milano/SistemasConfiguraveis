@@ -1,7 +1,7 @@
 /* Muscle table manager for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free
-   Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -429,6 +429,28 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
                               variable_loc);
 }
 
+/* This is used for backward compatibility, e.g., "%define api.pure"
+   supersedes "%pure-parser".  */
+void
+muscle_percent_define_ensure (char const *variable, location loc,
+                              bool value)
+{
+  char const *val = value ? "" : "false";
+  char const *name;
+  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+
+  /* %pure-parser is deprecated in favor of `%define api.pure', so use
+     `%define api.pure' in a backward-compatible manner here.  First,
+     don't complain if %pure-parser is specified multiple times.  */
+  if (!muscle_find_const (name))
+    muscle_percent_define_insert (variable, loc, val);
+  /* In all cases, use api.pure now so that the backend doesn't complain if
+     the skeleton ignores api.pure, but do warn now if there's a previous
+     conflicting definition from an actual %define.  */
+  if (muscle_percent_define_flag_if (variable) != value)
+    muscle_percent_define_insert (variable, loc, val);
+}
+
 char *
 muscle_percent_define_get (char const *variable)
 {
