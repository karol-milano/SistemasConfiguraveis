@@ -1,7 +1,7 @@
 /* Symbol table manager for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006, 2007 Free
-   Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006, 2007, 2008
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -358,8 +358,6 @@ symbol_user_token_number_set (symbol *sym, int user_token_number, location loc)
 {
   int *user_token_numberp;
 
-  aver (sym->class == token_sym);
-
   if (sym->user_token_number != USER_NUMBER_ALIAS)
     user_token_numberp = &sym->user_token_number;
   else
