@@ -1,6 +1,6 @@
 /* Lists of symbols for Bison
 
-   Copyright (C) 2002, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -38,6 +38,8 @@ symbol_list_new (symbol *sym, location loc)
   res->sym = sym;
   res->location = loc;
 
+  res->mid_rule = NULL;
+
   res->action = NULL;
   res->used = false;
 
