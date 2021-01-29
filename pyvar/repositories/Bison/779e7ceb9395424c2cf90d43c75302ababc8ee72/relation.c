@@ -1,5 +1,5 @@
 /* Binary relations.
-   Copyright (C) 2002 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2004 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -28,7 +28,8 @@
 void
 relation_print (relation r, size_t size, FILE *out)
 {
-  unsigned i, j;
+  unsigned int i;
+  unsigned int j;
 
   for (i = 0; i < size; ++i)
     {
@@ -94,7 +95,7 @@ traverse (int i)
 void
 relation_digraph (relation r, size_t size, bitsetv *function)
 {
-  unsigned i;
+  unsigned int i;
 
   infinity = size + 2;
   CALLOC (INDEX, size + 1);
