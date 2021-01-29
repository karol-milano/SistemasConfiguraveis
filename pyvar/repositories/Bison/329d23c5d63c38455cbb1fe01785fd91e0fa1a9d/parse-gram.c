@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.875d.  */
+/* A Bison parser, made by GNU Bison 1.875e.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
@@ -1941,7 +1941,11 @@ lloc_default (YYLTYPE const *rhs, int n)
 {
   int i;
   YYLTYPE loc;
-  loc.start = loc.end = rhs[n].end;
+
+  /* SGI MIPSpro 7.4.1m miscompiles "loc.start = loc.end = rhs[n].end;".
+     The bug is fixed in 7.4.2m, but play it safe for now.  */
+  loc.start = rhs[n].end;
+  loc.end = rhs[n].end;
 
   /* Ignore empty nonterminals the start of the the right-hand side.
      Do not bother to ignore them at the end of the right-hand side,
