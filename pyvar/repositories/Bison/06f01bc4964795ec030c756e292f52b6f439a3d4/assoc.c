@@ -1,5 +1,5 @@
 /* Associativity information.
-   Copyright (C) 2002, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -29,6 +29,9 @@ assoc_to_string (assoc a)
 {
   switch (a)
     {
+    default:
+      abort ();
+
     case undef_assoc:
       return "undefined associativity";
 
@@ -41,5 +44,4 @@ assoc_to_string (assoc a)
     case non_assoc:
       return "%nonassoc";
     }
-  return NULL;
 }
