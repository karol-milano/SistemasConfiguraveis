@@ -2,8 +2,8 @@ m4_divert(-1)                                                -*- C -*-
 
 # Yacc compatible skeleton for Bison
 
-# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
-# Free Software Foundation, Inc.
+# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
+# 2007 Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -20,6 +20,18 @@ m4_divert(-1)                                                -*- C -*-
 # Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 # 02110-1301  USA
 
+# Handle BISON_USE_PUSH_FOR_PULL for the test suite.  So that push parsing
+# tests function as written, don't let BISON_USE_PUSH_FOR_PULL modify Bison's
+# behavior at all when push parsing is already requested.
+b4_use_push_for_pull_if([
+  b4_push_if([
+    m4_define([b4_use_push_for_pull_flag], [[0]])
+    b4_define_flag_if([use_push_for_pull])
+  ], [
+    m4_define([b4_push_flag], [[1]])
+    b4_define_flag_if([push])
+  ])])
+
 m4_include(b4_pkgdatadir/[c.m4])
 
 ## ---------------- ##
@@ -1317,8 +1329,9 @@ yybackup:
     {
 ]b4_push_if([[      if (!yyps->yynew)
         {
-          YYDPRINTF ((stderr, "Return for a new token:\n"));
-          yyresult = YYPUSH_MORE;
+]b4_use_push_for_pull_if([],
+[[          YYDPRINTF ((stderr, "Return for a new token:\n"));
+]])[          yyresult = YYPUSH_MORE;
           goto yypushreturn;
         }
       yyps->yynew = 0;
