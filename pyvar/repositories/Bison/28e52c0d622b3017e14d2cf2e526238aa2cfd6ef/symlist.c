@@ -1,6 +1,6 @@
 /* Lists of symbols for Bison
 
-   Copyright (C) 2002, 2005, 2006 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006, 2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -207,18 +207,6 @@ symbol_list_n_type_name_get (symbol_list *l, location loc, int n)
 }
 
 
-/*--------------------------------------.
-| The item N in symbol list L is USED.  |
-`--------------------------------------*/
-
-void
-symbol_list_n_used_set (symbol_list *l, int n, bool used)
-{
-  l = symbol_list_n_get (l, n);
-  if (l)
-    l->used = used;
-}
-
 void
 symbol_list_destructor_set (symbol_list *node, const char *destructor,
                             location loc)
