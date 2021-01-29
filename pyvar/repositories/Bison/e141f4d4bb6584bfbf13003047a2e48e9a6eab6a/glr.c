@@ -1,8 +1,7 @@
                                                                     -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free
-# Software Foundation, Inc.
+# Copyright (C) 2002-2010 Free Software Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -158,7 +157,7 @@ m4_changecom()
 m4_divert_push(0)dnl
 @output(b4_parser_file_name@)@
 b4_copyright([Skeleton implementation for Bison GLR parsers in C],
-             [2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009])
+             [2002-2010])
 [
 /* C GLR parser skeleton written by Paul Hilfinger.  */
 
@@ -2579,7 +2578,7 @@ m4_if(b4_skeleton, ["glr.c"],
 [b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison GLR parsers in C],
-             [2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009])
+             [2002-2010])
 
 b4_shared_declarations
 
