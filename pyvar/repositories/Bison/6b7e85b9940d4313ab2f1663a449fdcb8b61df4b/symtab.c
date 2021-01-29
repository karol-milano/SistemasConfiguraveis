@@ -1,5 +1,5 @@
 /* Symbol table manager for Bison,
-   Copyright 1984, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -58,7 +58,7 @@ bucket_new (const char *tag, int hashval)
   res->value = 0;
   res->prec = 0;
   res->assoc = right_assoc;
-  res->user_token_number = 0;
+  res->user_token_number = SUNDEF;
   res->alias = NULL;
   res->class = unknown_sym;
 
