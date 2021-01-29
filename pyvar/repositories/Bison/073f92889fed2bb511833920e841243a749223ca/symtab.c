@@ -1,7 +1,7 @@
 /* Symbol table manager for Bison.
 
-   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1989, 2000, 2001, 2002, 2004, 2005, 2006 Free
+   Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -65,6 +65,7 @@ symbol_new (uniqstr tag, location loc)
 
   res->alias = NULL;
   res->class = unknown_sym;
+  res->declared = false;
 
   if (nsyms == SYMBOL_NUMBER_MAXIMUM)
     fatal (_("too many symbols in input grammar (limit is %d)"),
@@ -182,7 +183,7 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
     }
 
   /* Only terminals have a precedence. */
-  symbol_class_set (sym, token_sym, loc);
+  symbol_class_set (sym, token_sym, loc, false);
 }
 
 
@@ -191,10 +192,13 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 `------------------------------------*/
 
 void
-symbol_class_set (symbol *sym, symbol_class class, location loc)
+symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 {
   if (sym->class != unknown_sym && sym->class != class)
-    complain_at (loc, _("symbol %s redefined"), sym->tag);
+    {
+      complain_at (loc, _("symbol %s redefined"), sym->tag);
+      sym->declared = false;
+    }
 
   if (class == nterm_sym && sym->class != nterm_sym)
     sym->number = nvars++;
@@ -202,6 +206,13 @@ symbol_class_set (symbol *sym, symbol_class class, location loc)
     sym->number = ntokens++;
 
   sym->class = class;
+
+  if (declaring)
+    {
+      if (sym->declared)
+	warn_at (loc, _("symbol %s redeclared"), sym->tag);
+      sym->declared = true;
+    }
 }
 
 
