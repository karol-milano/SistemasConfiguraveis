@@ -1,8 +1,8 @@
                                                                     -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software Foundation,
-# Inc.
+# Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008 Free Software
+# Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -2644,10 +2644,10 @@ b4_copyright([Skeleton interface for Bison GLR parsers in C],
 b4_shared_declarations
 
 b4_pure_if([],
-[[extern YYSTYPE b4_prefix][lval;]])
+[[extern YYSTYPE ]b4_prefix[lval;]])
 
 b4_locations_if([b4_pure_if([],
-[extern YYLTYPE b4_prefix[]lloc;])
+[extern YYLTYPE ]b4_prefix[lloc;])
 ])
 ])])
 m4_divert_pop(0)
