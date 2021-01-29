@@ -1,5 +1,6 @@
 /* Print information on generated parser, for bison,
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002
+
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2003
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -92,7 +93,7 @@ print_core (FILE *out, state *s)
     {
       item_number *sp;
       item_number *sp1;
-      int r;
+      rule_number r;
 
       sp1 = sp = ritem + sitems[i];
 
