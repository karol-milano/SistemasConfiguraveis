@@ -1,5 +1,5 @@
 /* Symbol table manager for Bison,
-   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -55,7 +55,7 @@ bucket_new (const char *tag, int hashval)
   res->next = NULL;
   res->tag = xstrdup (tag);
   res->type_name = NULL;
-  res->value = -1;
+  res->number = -1;
   res->prec = 0;
   res->assoc = right_assoc;
   res->user_token_number = SUNDEF;
