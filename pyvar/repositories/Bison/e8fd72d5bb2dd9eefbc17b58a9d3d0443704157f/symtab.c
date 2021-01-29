@@ -1,6 +1,6 @@
 /* Symbol table manager for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004 Free Software
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005 Free Software
    Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -264,6 +264,7 @@ symbol_make_alias (symbol *sym, symbol *symval, location loc)
 	abort ();
       sym->number = symval->number =
 	(symval->number < sym->number) ? symval->number : sym->number;
+      symbol_type_set (symval, sym->type_name, loc);
     }
 }
 
@@ -283,7 +284,7 @@ symbol_check_alias_consistency (symbol *this)
   if (!(this->alias && this->user_token_number == USER_NUMBER_ALIAS))
     return;
 
-  if (orig->type_name || alias->type_name)
+  if (orig->type_name != alias->type_name)
     {
       if (orig->type_name)
 	symbol_type_set (alias, orig->type_name, orig->type_location);
