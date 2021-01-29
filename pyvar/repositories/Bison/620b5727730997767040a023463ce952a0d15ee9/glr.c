@@ -1,8 +1,8 @@
                                                                     -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
-# Foundation, Inc.
+# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free
+# Software Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -150,7 +150,7 @@ m4_changecom()
 m4_divert_push(0)dnl
 @output(b4_parser_file_name@)@
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
-             [2002, 2003, 2004, 2005, 2006, 2007, 2008])
+             [2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009])
 [
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
@@ -412,9 +412,9 @@ static const ]b4_int_type_for([b4_merger])[ yymerger[] =
   ]b4_merger[
 };
 
-/* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
-   doesn't specify something else to do.  Zero means the default is an
-   error.  */
+/* YYDEFACT[S] -- default reduction number in state S.  Performed when
+   YYTABLE doesn't specify something else to do.  Zero means the default
+   is an error.  */
 static const ]b4_int_type_for([b4_defact])[ yydefact[] =
 {
   ]b4_defact[
@@ -2639,7 +2639,7 @@ m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
-             [2002, 2003, 2004, 2005, 2006, 2007, 2008])
+             [2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009])
 
 b4_shared_declarations
 
