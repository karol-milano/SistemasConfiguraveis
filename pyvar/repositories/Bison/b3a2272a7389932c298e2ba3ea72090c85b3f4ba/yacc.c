@@ -2,10 +2,10 @@
 # Yacc compatible skeleton for Bison
 
 # Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
-# 2007, 2008 Free Software Foundation, Inc.
+# 2007, 2008, 2009 Free Software Foundation, Inc.
 
 m4_pushdef([b4_copyright_years],
-[1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008])
+[1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009])
 
 # This program is free software: you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -200,7 +200,7 @@ m4_if(b4_prefix, [yy], [],
 # undef YYERROR_VERBOSE
 # define YYERROR_VERBOSE 1
 #else
-# define YYERROR_VERBOSE ]b4_error_verbose_flag[
+# define YYERROR_VERBOSE ]b4_error_verbose_if([1], [0])[
 #endif
 
 /* Enabling the token table.  */
