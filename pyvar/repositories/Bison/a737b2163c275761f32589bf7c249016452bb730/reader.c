@@ -1,6 +1,6 @@
 /* Input parser for Bison
 
-   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002, 2003
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -47,14 +47,14 @@ int typed = 0;
 `-----------------------*/
 
 void
-grammar_start_symbol_set (symbol *s, location loc)
+grammar_start_symbol_set (symbol *sym, location loc)
 {
   if (start_flag)
     complain_at (loc, _("multiple %s declarations"), "%start");
   else
     {
       start_flag = 1;
-      startsymbol = s;
+      startsymbol = sym;
       startsymbol_location = loc;
     }
 }
