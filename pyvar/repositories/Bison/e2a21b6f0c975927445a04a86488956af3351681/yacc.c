@@ -2,7 +2,7 @@ m4_divert(-1)                                                -*- C -*-
 
 # Yacc compatible skeleton for Bison
 
-# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005
+# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
 # Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
@@ -135,7 +135,7 @@ m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005])[
+  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
@@ -311,7 +311,7 @@ b4_syncline([@oline@], [@ofile@])[
        and a page size can be as small as 4096 bytes.  So we cannot safely
        invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
        to allow for a few compiler-allocated temporary stack slots.  */
-#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
+#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
 #  endif
 # else
 #  define YYSTACK_ALLOC YYMALLOC
@@ -1497,7 +1497,7 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005])
+  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
