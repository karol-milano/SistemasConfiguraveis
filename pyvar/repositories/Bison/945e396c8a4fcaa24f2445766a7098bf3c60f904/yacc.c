@@ -2,8 +2,8 @@ m4_divert(-1)                                                -*- C -*-
 
 # Yacc compatible skeleton for Bison
 
-# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
-# Free Software Foundation, Inc.
+# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
+# 2007 Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -20,6 +20,9 @@ m4_divert(-1)                                                -*- C -*-
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 # 02110-1301  USA
 
+# Handle BISON_USE_PUSH_FOR_PULL for the test suite.
+b4_use_push_for_pull_if([m4_include(b4_pkgdatadir/[push.c])m4_exit])
+
 m4_include(b4_pkgdatadir/[c.m4])
 
 ## ---------------- ##
