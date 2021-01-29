@@ -1,5 +1,5 @@
 /* Associativity information.
-   Copyright (C) 2002, 2005, 2006 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2005, 2006, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -41,5 +41,8 @@ assoc_to_string (assoc a)
 
     case non_assoc:
       return "%nonassoc";
+
+    case precedence_assoc:
+      return "%precedence";
     }
 }
