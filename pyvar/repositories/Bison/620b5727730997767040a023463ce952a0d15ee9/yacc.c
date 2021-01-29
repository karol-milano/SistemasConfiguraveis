@@ -3,7 +3,7 @@
 # Yacc compatible skeleton for Bison
 
 # Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-# 2007, 2008 Free Software Foundation, Inc.
+# 2007, 2008, 2009 Free Software Foundation, Inc.
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -155,7 +155,8 @@ m4_changecom()
 m4_divert_push(0)dnl
 @output(b4_parser_file_name@)@
 b4_copyright([Skeleton implementation for Bison's Yacc-like parsers in C],dnl '
-  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])[
+  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008,
+   2009])[
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -547,8 +548,8 @@ static const ]b4_int_type_for([b4_r2])[ yyr2[] =
   ]b4_r2[
 };
 
-/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
-   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
+/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
+   Performed when YYTABLE doesn't specify something else to do.  Zero
    means the default is an error.  */
 static const ]b4_int_type_for([b4_defact])[ yydefact[] =
 {
@@ -1676,7 +1677,8 @@ yypushreturn:
 b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
-  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006])
+  [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008,
+   2009])
 
 b4_percent_code_get([[requires]])[]dnl
 
