@@ -1,6 +1,7 @@
 /* Symbol table manager for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006, 2007, 2008
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006, 2007,
+   2008, 2009
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -58,6 +59,13 @@ symbol_new (uniqstr tag, location loc)
   symbol *res = xmalloc (sizeof *res);
 
   uniqstr_assert (tag);
+
+  /* If the tag is not a string (starts with a double quote), check
+     that it is valid for Yacc. */
+  if (tag[0] != '\"' && tag[0] != '\'' && strchr (tag, '-'))
+    yacc_at (loc, _("POSIX Yacc forbids dashes in symbol names: %s"),
+             tag);
+
   res->tag = tag;
   res->location = loc;
 
