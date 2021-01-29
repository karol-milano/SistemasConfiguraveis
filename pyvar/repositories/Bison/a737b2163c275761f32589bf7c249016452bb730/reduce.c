@@ -1,6 +1,7 @@
 /* Grammar reduction for Bison.
 
-   Copyright (C) 1988, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1988, 1989, 2000, 2001, 2002, 2003 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -267,7 +268,7 @@ reduce_grammar_tables (void)
 
   /* Adjust NRITEMS.  */
   {
-    int r;
+    rule_number r;
     int length;
     for (r = nrules; r < nrules + nuseless_productions; ++r)
       {
